#!/bin/bash

################ Configure options define #####################
REBUILD=0
MAKE_DEPENDENCE=0
MAKE_OPTION=

function check_result() {
    local res=$1
    local func=$2

    if [ $res -eq 0 ] ; then
        echo "###############" "  $func  OK  " "#############"
    else
        echo "###############" "  $func  FAIL  " "#############"
        exit 1
    fi
}

function check_fail() {
    local res=$1
    local func=$2

    if [ $res -ne 0 ] ; then
        echo "###############" "  $func  FAIL  " "#############"
        exit 1
    fi
}

function aiqb_files_copy() {
    echo "###############" "  $FUNCNAME  " "#############"
    cp -frv $AIQB_DIR/*.aiqb $AIQB_INSTALL_DIR/

    check_result $? $FUNCNAME
}

function aiqb_rpm_install() {
    echo "###############" "  $FUNCNAME  " "#############"

    local specFile=$RPM_DIR/build/aiqb.spec

    rm -rf ~/rpmbuild
    mkdir -p ~/rpmbuild/BUILD/

    /usr/bin/rsync -av --exclude=".*" $AIQB_INSTALL_DIR/*.aiqb ~/rpmbuild/BUILD/

    /usr/bin/rpmbuild -ba --nodeps $specFile
    cp ~/rpmbuild/RPMS/x86_64/aiqb*.rpm $RPMS_INSTALL_DIR

    check_result $? $FUNCNAME
}

function aiq_files_copy() {
    echo "###############" "  $FUNCNAME  " "#############"

    cd $AIQ_DIR/

    autoreconf -i
    ./configure --prefix $AIQ_INSTALL_DIR
    make install 
    #remove useless header files and libraries
    rm -v $AIQ_INSTALL_DIR/include/ia_imaging/ia_isp_1_*
    rm -v $AIQ_INSTALL_DIR/include/ia_imaging/ia_isp_2_*
    rm -v $AIQ_INSTALL_DIR/include/ia_imaging/pvl_* 

    check_result $? $FUNCNAME
}

AIQ_RPM=libiaaiq-v2.0_010.000-000.x86_64.rpm

function aiq_generate_rpm_version() {
    #update the libiaaiq.spec with new version
    local specFile=$RPM_DIR/build/libiaaiq.spec

    #libmfldadvci: IA AIQ library release v2.0_012.000
    oldVersion=$(grep Version $specFile | cut -d "_" -f 2 | tr -d " ")
    oldRelease=$(grep Release $specFile | cut -d ":" -f 2 | tr -d " ")

    pushd $AIQ_DIR
        newRelease=$oldRelease
        #
        #FIXME: handle this case: more than 1 patch
        #
        newVersion=$(git log -1 | grep libmf | grep _ | cut -d "_" -f 2)
        if [ "$newVersion" == "" ];then
            echo "There is no version update in this libiaaiq Release!!"
            newVersion=$oldVersion
            newRelease=`expr $oldRelease + 1`
        elif [ "$newVersion" == "$oldVersion" ];then
            echo "Version is the same as old one $oldVersion"
            newRelease=`expr $oldRelease + 1`
        fi
    popd

    newVersion=`echo "$newVersion" | sed 's/ /_/g'`   
    newRelease=`printf %03d $newRelease`

    echo "New Version Information:"
    echo "Version: v2.0_$oldVersion-->v2.0_$newVersion"
    echo "Release: $oldRelease-->$newRelease"

    #FIXME: be care to update to v3.0?
    sed -i "s/Version: v2.0_$oldVersion/Version: v2.0_$newVersion/" $specFile
    sed -i "s/Release: $oldRelease/Release: $newRelease/" $specFile
}

function aiq_rpm_install() {
    echo "###############" "  $FUNCNAME  " "#############"

    local specFile=$RPM_DIR/build/libiaaiq.spec
    aiq_generate_rpm_version
    
    rm -rf ~/rpmbuild
    mkdir -p ~/rpmbuild/BUILD/
    /usr/bin/rsync -av --exclude=".*" $AIQ_INSTALL_DIR/* ~/rpmbuild/BUILD/

    /usr/bin/rpmbuild -ba --nodeps $specFile
    cp ~/rpmbuild/RPMS/x86_64/libiaaiq*.rpm $RPMS_INSTALL_DIR

    check_result $? $FUNCNAME
}

function iacss_configure() {
    echo "###############" "  $FUNCNAME  " "#############"

    export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:$AIQ_INSTALL_DIR/lib/pkgconfig
    if [ $REBUILD -eq 1 -o ! -f configure ] ; then
        rm -fr config/  config.h.in autom4te.cache/ aclocal.m4 m4 *-libtool
        autoreconf --install
        ./configure ${CONFIGURE_FLAGS} --with-kernel-sources=$KERNEL_HEADER_DIR --with-B0=yes --with-aiq=yes --prefix=$IACSS_INSTALL_DIR
    fi
    check_result $? $FUNCNAME
}

function iacss_build() {
    echo "###############" "  $FUNCNAME  " "#############"

    if [ $REBUILD -eq 1 ] ; then
        make clean
    fi

    make $MAKE_OPTION
    check_fail $? $FUNCNAME

    make install
    check_fail $? $FUNCNAME

}

function iacss_generate_rpm_version() {
    #update the libiacss.spec with new version
    local specFile=$RPM_DIR/build/libiacss.spec
    oldVersion=$(grep "Version: 1.0" $specFile | cut -d "." -f 3)
    newVersion=`expr $oldVersion + 1`
    sed -i "s/1.0.$oldVersion/1.0.$newVersion/" $specFile
    newRpm=libiacss-1.0.$newVersion-0.x86_64.rpm
    echo "$newRpm"
}

function iacss_rpm_install() {
    echo "###############" "  $FUNCNAME  " "#############"

    rm -rf ~/rpmbuild
    mkdir -p ~/rpmbuild/BUILD/
    /usr/bin/rsync -av --exclude=".*" $OUTPUT_DIR/libiacss/* ~/rpmbuild/BUILD/

    iacss_generate_rpm_version

    /usr/bin/rpmbuild -ba --nodeps $RPM_DIR/build/libiacss.spec
    cp -fv ~/rpmbuild/RPMS/x86_64/libiacss*.rpm $RPMS_INSTALL_DIR

    check_result $? $FUNCNAME
}

function libcamhal_configure() {
    echo "###############" "  $FUNCNAME  " "#############"
    # Add the dependencies to the path of package config
    export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:$AIQ_INSTALL_DIR/lib/pkgconfig:$IACSS_INSTALL_DIR/lib/pkgconfig
    if [ $REBUILD -eq 1 -o ! -f configure ] ; then
        rm -fr config.h.in autom4te.cache/ aclocal.m4 *-libtool config.guess compile config.sub configure depcomp install-sh ltmain.sh m4
        autoreconf --install
        CFLAGS="-O2" CXXFLAGS="-O2" ./configure ${CONFIGURE_FLAGS}
    fi

    check_result $? $FUNCNAME
}

function libcamhal_build() {
    echo "###############" "  $FUNCNAME  " "#############"

    if [ $REBUILD -eq 1 ] ; then
        make clean
    fi

    make $MAKE_OPTION
    check_fail $? $FUNCNAME

    check_dir $LIBCAMHAL_INSTALL_DIR/include
    cp -frv include/* $LIBCAMHAL_INSTALL_DIR/include

    check_dir $LIBCAMHAL_INSTALL_DIR/lib
    cp -frv .libs/*.so* $LIBCAMHAL_INSTALL_DIR/lib
    cp -frv .libs/*.a $LIBCAMHAL_INSTALL_DIR/lib

    check_dir $LIBCAMHAL_INSTALL_DIR/etc/camera
    cp -frv config/*.xml $LIBCAMHAL_INSTALL_DIR/etc/camera

    check_result $? $FUNCNAME
}

function libcamhal_rpm_install() {
    echo "###############" "  $FUNCNAME  " "#############"

    goto $LIBCAMHAL_DIR
    rm -f rpm/libcamhal*.rpm
    make rpm
    check_fail $? $FUNCNAME

    cp -fv rpm/libcamhal*.rpm $RPMS_INSTALL_DIR

    check_result $? $FUNCNAME
}

function libcamhal_build_test() {
    echo "###############" "  $FUNCNAME  " "#############"

    goto $LIBCAMHAL_DIR
    cd test

    if [ $REBUILD -eq 1 ] ; then
        make clean
    fi

    make $MAKE_OPTION
    check_fail $? $FUNCNAME
    cd -
    cp -frv test $TEST_INSTALL_DIR/libcamhal-test

    check_result $? $FUNCNAME
}

function icamerasrc_configure() {
    echo "###############" "  $FUNCNAME  " "#############"

    if [ $REBUILD -eq 1 -o ! -f configure ] ; then
        rm -fr config.h.in autom4te.cache/ aclocal.m4 *-libtool config.guess compile config.sub configure depcomp install-sh ltmain.sh m4
        autoreconf --install
        CPPFLAGS="-I$LIBCAMHAL_INSTALL_DIR/include/ -I$LIBCAMHAL_INSTALL_DIR/include/api -I$LIBCAMHAL_INSTALL_DIR/include/utils " LDFLAGS="-L$LIBCAMHAL_INSTALL_DIR/lib/" CFLAGS="-O2" CXXFLAGS="-O2" ./configure ${CONFIGURE_FLAGS} --prefix=$ICAMERASRC_INSTALL_DIR
    fi

    check_result $? $FUNCNAME
}

function icamerasrc_build() {
    echo "###############" "  $FUNCNAME  " "#############"

    if [ $REBUILD -eq 1 ] ; then
        make clean
    fi

    make $MAKE_OPTION
    check_result $? $FUNCNAME
}

function icamerasrc_rpm_install() {
    echo "###############" "  $FUNCNAME  " "#############"

    goto $ICAMERASRC_DIR
    rm -f rpm/icamerasrc*.rpm
    make rpm
    check_fail $? $FUNCNAME
    cp -fv rpm/icamerasrc*.rpm $RPMS_INSTALL_DIR

    check_result $? $FUNCNAME
}

function icamerasrc_build_test() {
    echo "###############" "  $FUNCNAME  " "#############"

    goto $ICAMERASRC_DIR
    cd test
    if [ $REBUILD -eq 1 ] ; then
        make clean
    fi
    make $MAKE_OPTION
    check_fail $? $FUNCNAME

    cd utils
    make $MAKE_OPTION

    goto $ICAMERASRC_DIR
    cp -frv test $TEST_INSTALL_DIR/icamera-test
    check_result $? $FUNCNAME
}

inodes=()
function get_build_inodes() {
    for((i=0;i<${#BUILD_DIRS[@]};i++));do
        #echo "$i: ${BUILD_DIRS[$i]}"
        inodes[$i]=`ls -di ${BUILD_DIRS[$i]} | awk '{print $1}'`
    done
}

function find_build_inode() {
    local lookup_dir=$1
    local parent=$1
    local lookup_inode=`ls -di $lookup_dir | awk '{print $1}' `

    build_root_inode=${inodes[0]}

    while [ $build_root_inode != $lookup_inode ] ; do
        for((i=1;i<${#inodes[@]};i++));do
            if [ $lookup_inode = ${inodes[$i]} ] ; then
                return $i
            fi
        done

        parent=`dirname $parent`
        lookup_inode=`ls -di $parent | awk '{print $1}' `
    done

    if [ $build_root_inode = $lookup_inode ] ; then
       return 0
    else
        # Not found #
        return 10000
    fi
}

function mm() {
    local build_root_inode
    REBUILD=0
    MAKE_DEPENDENCE=0
    MAKE_OPTION=

    check_output_dir
    get_build_inodes

    find_build_inode $PWD
    build_index=$?

    if [ $build_index -eq 10000 ] ; then
        echo $PWD is not build directory
        return 
    fi

    while [ -n "$1" ] ; do
        case $1 in
          -B) REBUILD=1 ;;
          -D) MAKE_DEPENDENCE=1;;
          -j) MAKE_OPTION="-j";;
        esac
        shift 1
    done

    rm -f $BUILD_LOG
    if [ $MAKE_DEPENDENCE -eq 1 ] ; then
        REBUILD=1
        for((i=1;i<$build_index;i++));do
            ${build_steps[$i]} 2>&1 | tee $BUILD_LOG
        done
    fi

    ${build_steps[$build_index]} 2>&1 | tee -a $BUILD_LOG

    handle_log
}

function mmm() {
    check_output_dir

    goto ${BUILD_DIRS[0]}

    REBUILD=1
    MAKE_OPTION="-j"
    rm -f $BUILD_LOG
    ${build_steps[0]} 2>&1 | tee -a $BUILD_LOG

    handle_log
}

function handle_log() {
    grep "FAIL" $BUILD_LOG
    ret=$?
    cp -fr $BUILD_LOG `dirname $BUILD_LOG`/build-`date +%m%H%M`.log
    mv $BUILD_LOG `dirname $BUILD_LOG`/build-latest.log

    if [ $ret -eq 0 ]; then
        return 1
    fi
}

function mm_helper() {
    echo "  mm [-B|-D|-j]: build command"
    echo "     -B: rebuild this project, include reconfigure/build/install"
    echo "     -D: rebuild this project & its dependence"
    echo "     -j: make option, use multi-jobs to do make"
}

function mmm_helper() {
    echo "  mmm : build all projects, you can run this at anywhere under repo"
}

aiqb_build_steps () {
    pushd ${AIQB_DIR}

    aiqb_files_copy
    aiqb_rpm_install

    popd
}

aiq_build_steps () {
    pushd ${AIQ_DIR}
    aiq_files_copy
    aiq_rpm_install
    popd
}

iacss_build_steps() {
    pushd ${LIBIACSS_DIR}
    iacss_configure
    iacss_build
    iacss_rpm_install
    popd
}

libcamhal_build_steps() {
    pushd ${LIBCAMHAL_DIR}
    libcamhal_configure
    libcamhal_build
    libcamhal_rpm_install
    libcamhal_build_test
    popd
}

icamerasrc_build_steps() {
    cd ${ICAMERASRC_DIR}
    icamerasrc_configure
    icamerasrc_build
    icamerasrc_rpm_install
    icamerasrc_build_test
    popd
}

all_build_steps() {
    cd ${ROOT_DIR}
    aiqb_build_steps
    aiq_build_steps
    iacss_build_steps
    libcamhal_build_steps
    icamerasrc_build_steps
}

build_steps=(all_build_steps aiq_build_steps iacss_build_steps libcamhal_build_steps icamerasrc_build_steps)
BUILD_DIRS=($ROOT_DIR $AIQ_DIR $LIBIACSS_DIR $LIBCAMHAL_DIR $ICAMERASRC_DIR)
