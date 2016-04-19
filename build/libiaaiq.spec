Summary: Lib IA AIQ 
Name: libiaaiq 
Version: v2.0_013.002
Release: 001
License: Intel
Group: Development/Tools
Prefix: /usr
%description
IPU4 firmware binaries.
%prep
%build
%install
mkdir -p $RPM_BUILD_ROOT/usr/lib64/
mkdir -p $RPM_BUILD_ROOT/usr/include/libiaaiq/
cp $RPM_BUILD_DIR/lib64/* $RPM_BUILD_ROOT/usr/lib64/
cp -fr $RPM_BUILD_DIR/debug/ $RPM_BUILD_ROOT/usr/lib64/
cp $RPM_BUILD_DIR/include/* $RPM_BUILD_ROOT/usr/include/libiaaiq/ -r
%files
/usr/
