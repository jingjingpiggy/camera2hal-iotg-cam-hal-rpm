Summary: Lib IA CSS 
Name: libiacss 
Version: 1.0.21
Release: 0
License: Intel
Group: Development/Tools
Prefix: /usr
%description
IPU4 firmware binaries.
%prep
%build
%install
mkdir -p $RPM_BUILD_ROOT/usr/lib64/
mkdir -p $RPM_BUILD_ROOT/usr/include/libiacss/
cp -R $RPM_BUILD_DIR/lib/* $RPM_BUILD_ROOT/usr/lib64/
cp -R $RPM_BUILD_DIR/include/* $RPM_BUILD_ROOT/usr/include/libiacss/
%files
/usr/
