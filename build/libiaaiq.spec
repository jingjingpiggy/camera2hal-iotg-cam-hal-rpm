Summary: Lib IA AIQ 
Name: libiaaiq 
Version: v2.0_014.002
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
cp $RPM_BUILD_DIR/lib64/* $RPM_BUILD_ROOT/usr/lib/
cp -fr $RPM_BUILD_DIR/debug/ $RPM_BUILD_ROOT/usr/lib/
cp $RPM_BUILD_DIR/include/* $RPM_BUILD_ROOT/usr/include/libiaaiq/ -r
%files
/usr/
