Summary: Lib IA CSS 
Name: libiacss 
Version: 1.0.73
Release: 0
License: Intel
Group: Development/Tools
Prefix: /usr
%description
IPU4 firmware binaries.
%prep
%build
%install
mkdir -p $RPM_BUILD_ROOT/usr/lib/
mkdir -p $RPM_BUILD_ROOT/usr/include/libiacss/
cp -R $RPM_BUILD_DIR/lib64/* $RPM_BUILD_ROOT/usr/lib/
cp -R $RPM_BUILD_DIR/include/* $RPM_BUILD_ROOT/usr/include/libiacss/
%files
/usr/
