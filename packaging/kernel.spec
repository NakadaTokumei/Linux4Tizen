# Ignore double dash in version for rpmbuild
%define _wrong_version_format_terminate_build 0

%define buildarch x86_64
%define target_board normal
%define variant %{buildarch}-%{target_board}

Name: tizen-linux-kernel
Summary: The Linux Kernel for Raspberry Pi4
Version: 6.12.0
Release: 0
License: GPL-2.0
ExclusiveArch: %{arm} aarch64 x86_64
Group: System/Kernel
Vendor: The Linux Community
URL: https://www.kernel.org
Source0:   linux-kernel-%{version}.tar.xz
BuildRoot: %{_tmppath}/%{name}-%{PACKAGE_VERSION}-root

%define fullVersion %{version}-%{variant}

BuildRequires: bc
BuildRequires: module-init-tools
BuildRequires: bison
BuildRequires: flex
BuildRequires: pkgconfig(openssl3)
BuildRequires: libunwind-devel
BuildRequires: libdw-devel
BuildRequires: libelf-devel
BuildRequires: elfutils
BuildRequires: xz-devel
BuildRequires: binutils-devel
BuildRequires: python3
BuildRequires: rsync

%description
The Linux Kernel, the operating system core itself

# kernel
%package -n %{variant}-linux-kernel
License: GPL-2.0
Summary: Tizen kernel for %{target_board}
Group: System/Kernel
Provides: %{variant}-kernel-uname-r = %{fullVersion}
Provides: linux-kernel = %{version}-%{release}

%description -n %{variant}-linux-kernel
This package contains the Linux kernel for Tizen (arch %{buildarch}, target board %{target_board})

%prep
%setup -q

%build
make x86_64_defconfig
make bzImage -j4

%install
mkdir %{buildroot}/boot
install -m 644 arch/x86/boot/bzImage %{buildroot}/boot/bzImage

%files -n %{variant}-linux-kernel
/boot/bzImage
