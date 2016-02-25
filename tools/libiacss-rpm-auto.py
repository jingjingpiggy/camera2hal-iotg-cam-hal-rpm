#!/usr/bin/python

#
#  Copyright (C) 2014-2016 Intel Corporation
#
#  Licensed under the Apache License, Version 2.0 (the "License");
#  you may not use this file except in compliance with the License.
#  You may obtain a copy of the License at
#
#       http://www.apache.org/licenses/LICENSE-2.0
#
#  Unless required by applicable law or agreed to in writing, software
#  distributed under the License is distributed on an "AS IS" BASIS,
#  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
#  See the License for the specific language governing permissions and
#  limitations under the License.
#

import os
import sys
import json

KERNEL_HEADER = "vied-viedandr-linux_drivers"
LIBIACSS = "vied-viedandr-libiacss"
RPM = "camera2hal-iotg-cam-hal-rpm"
SUPPORTED_PROJECTS = [KERNEL_HEADER, LIBIACSS, RPM]

def downloadRepositories():
    # download supported projects
    for project in SUPPORTED_PROJECTS:
        os.chdir(rootDir)
        if project not in os.listdir(rootDir):
            if project == RPM:
                os.system("git clone ssh://%s@git-ger-6.devtools.intel.com:29418/%s" % (OWNER, project))
            else:
                os.system('git clone ssh://icggerrit.ir.intel.com:29418/%s' % project)
        else:
            print "%s is alreay exist" % project

        # checkout remote branch in the libiacss
        if project == LIBIACSS:
            os.chdir("%s" % LIBIACSS)
            os.system("git checkout -b main remotes/origin/platform/android/main")

        # for all projects
        os.chdir(rootDir)
        os.chdir("%s" % project)
        os.system("git pull")

def applyPatches(patchesList):
    for patch in patchesList:
        os.chdir("%s" % rootDir)
        cmd = "ssh -p 29418 icggerrit.ir.intel.com gerrit query --current-patch-set --format=JSON %s" % patch
        print cmd
        pipe = os.popen(cmd)
        jsonStr = pipe.readlines()
        pipe.close()

        if len(jsonStr) < 2:
            print "get jsonStr wrong"
            return
    
        jsonData = json.loads(jsonStr[0])
        patchSetNum = jsonData.get("currentPatchSet").get("number");
        patchRef = jsonData.get("currentPatchSet").get("ref");
        print patchRef

        patchProject = jsonData.get("project")
        print patchProject
        if patchProject == LIBIACSS:
            os.chdir("%s" % libiacssDir)
        elif patchProject == KERNEL_HEADER:
            os.chdir("%s" % kernelHeaderDir)
        else:
            print "the project: %s is not supported right now" % patchProject
            continue

        cmd = "git fetch ssh://%s@icggerrit.ir.intel.com:29418/%s %s && git cherry-pick FETCH_HEAD" % (OWNER, patchProject, patchRef)
        print cmd
        os.system(cmd)

def makeLibiacss():
    os.chdir("%s" % libiacssDir)
    os.system("autoreconf --install")
    os.system("./configure --with-kernel-sources=%s --with-B0=yes --with-aiq=yes --prefix=/usr --libdir=/usr/lib64 --includedir=/usr/include/libiacss" % kernelHeaderDir)
    os.system("make -j")
    os.system("sudo make install")

def generateRPM():
    os.chdir("%s" % rpmDir)

    os.system("rm ./script/IACSS/libiacss/include/* -rf")
    os.system("rm ./script/IACSS/libiacss/lib/*")

    os.system("cp /usr/include/libiacss/* ./script/IACSS/libiacss/include/. -rf")
    os.system("cp /usr/lib64/libia_camera.* ./script/IACSS/libiacss/lib")
    os.system("cp /usr/lib64/libia_cipf.* ./script/IACSS/libiacss/lib")

    # update the libiacss.spec with new version
    specFile = "./script/IACSS/rpm/libiacss.spec"
    os.system("git checkout %s" % specFile) # refresh the libiacss.spec
    f = open(specFile, "r+")
    fLines = f.readlines()
    subVersion = fLines[2][len("Version: 1.0."):len(fLines[2])]
    newContent = "Version: 1.0." + str(int(subVersion) + 1) + "\n"
    fLines[2] = newContent
    f.close()
    f = open("./script/IACSS/rpm/libiacss.spec", "w+")
    f.writelines(fLines)
    f.close()

    os.chdir("%s/script/IACSS/rpm" % rpmDir)
    os.system("./build_rpm.sh")

    newRPMName = "libiacss-1.0.%s-0.x86_64.rpm" % str(int(subVersion) + 1)
    print newRPMName

    os.chdir("%s" % rpmDir)
    os.system("mv rpms/libiacss-* rpms/archive/.")
    os.system("cp ./script/IACSS/rpm/%s ./rpms/." % newRPMName)

# to get the dirs
rootDir = os.getcwd()
rpmDir = rootDir + "/" + RPM
libiacssDir = rootDir + "/" + LIBIACSS
kernelHeaderDir = rootDir + "/" + KERNEL_HEADER

print "please make sure that you have installed the related latest libiaiq RPM!!!!!!"
OWNER = raw_input("please input your user name:")
patches = raw_input("please input the patch lists here:")
patchesList = patches.split()
print patchesList

downloadRepositories()
applyPatches(patchesList)
makeLibiacss()
generateRPM()

