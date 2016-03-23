#/bin/sh
###########################################################
# Preparations for RPM generation.
###########################################################
rm -rf ~/rpmbuild
mkdir -p ~/rpmbuild/BUILD/
/usr/bin/rsync -av --exclude=".*" $(pwd)/../archive/* ~/rpmbuild/BUILD/
###########################################################
# Generate RPM package
###########################################################
/usr/bin/rpmbuild -ba --nodeps ./libiaaiq.spec
cp ~/rpmbuild/RPMS/x86_64/libiaaiq*.rpm ./
