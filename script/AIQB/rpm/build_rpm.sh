#/bin/sh
###########################################################
# Preparations for RPM generation.
###########################################################
rm -rf ~/rpmbuild
mkdir -p ~/rpmbuild/BUILD/
rsync -av --exclude=".*" $(pwd)/../*.aiqb ~/rpmbuild/BUILD/
###########################################################
# Generate RPM package
###########################################################
rpmbuild -ba --nodeps ./aiqb.spec
cp ~/rpmbuild/RPMS/x86_64/aiqb*.rpm ./
