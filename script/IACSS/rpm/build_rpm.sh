#/bin/sh
###########################################################
# Preparations for RPM generation.
###########################################################
rm -rf ~/rpmbuild
mkdir -p ~/rpmbuild/BUILD/
rsync -av --exclude=".*" $(pwd)/../libiacss/* ~/rpmbuild/BUILD/
###########################################################
# Generate RPM package
###########################################################
rpmbuild -ba --nodeps ./libiacss.spec
cp ~/rpmbuild/RPMS/x86_64/libiacss*.rpm ./
