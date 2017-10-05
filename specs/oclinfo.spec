Summary:        Command-line tool to display information about available OpenCL platforms and devices
Name:           oclinfo
Version:        0.0.1
Release:        0
# License is a compulsory field so you have to put something there.
License:        MIT
Source:         %{name}-%{version}.tar.gz
BuildRoot:      %{_tmppath}/%{name}-%{version}-build
BuildRequires:  cmake
BuildRequires:  gcc
BuildRequires:  opencl-headers
BuildRequires:  ocl-icd-devel
Group:          System Environment/Base
Vendor:         galarius

%description
Command-line tool to display information about available OpenCL platforms and devices.

%prep
%setup -n %{name}

%build
mkdir build && cd build
cmake ..
make 

%install
make install DESTDIR=%{buildroot}

%post
# the post section is where you can run commands after the rpm is installed.

%clean
rm -rf %{buildroot}

# list files owned by the package here
%files
# %defattr(-,root,root)

%changelog
* Thu Oct 05 2017 galarius
- 0.0 r1 First release