Summary: AIQB file 
Name: aiqb
Version: 1.0.0
Release: 0
License: Intel
Group: Development/Tools
Prefix: /etc
%description
IPU4 firmware binaries.
%prep
%build
%install
mkdir -p $RPM_BUILD_ROOT/etc/camera/
cp $RPM_BUILD_DIR/* $RPM_BUILD_ROOT/etc/camera/
%files
/etc/
