Summary: Lib IA AIQ 
Name: libiaaiq 
Version: v2.0_015.003
Release: 000
License: Intel
Group: Development/Tools
Prefix: /usr
%description
IPU4 firmware binaries.
%prep
%build
%install
mkdir -p $RPM_BUILD_ROOT/usr/lib/
mkdir -p $RPM_BUILD_ROOT/usr/include/libiaaiq/
cp $RPM_BUILD_DIR/lib/* $RPM_BUILD_ROOT/usr/lib/ -r
cp $RPM_BUILD_DIR/include/ia_imaging/* $RPM_BUILD_ROOT/usr/include/libiaaiq/ -r
%files
/usr/
