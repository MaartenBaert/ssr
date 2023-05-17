%global shortname ssr

%undefine __cmake_in_source_build

Name:           simplescreenrecorder
Version:        0.4.5
Release:        1%{?dist}
Summary:        Simple Screen Recorder is a screen recorder for Linux

License:        GPLv3
URL:            https://www.maartenbaert.be/simplescreenrecorder/
Source0:        https://github.com/SergeyMy/ssr/archive/%{version}/%{name}-%{version}.tar.gz
# source Master 20230517

BuildRequires:  gcc-c++
BuildRequires:  desktop-file-utils
BuildRequires:  cmake3
BuildRequires:  ffmpeg-devel
BuildRequires:  pkgconfig(Qt5) >= 5.7.0
BuildRequires:  pkgconfig(Qt5X11Extras)
BuildRequires:  pkgconfig(alsa)
BuildRequires:  pkgconfig(libpulse)
BuildRequires:  pkgconfig(jack)
BuildRequires:  pkgconfig(x11)
BuildRequires:  pkgconfig(xfixes)
BuildRequires:  pkgconfig(xinerama)
BuildRequires:  pkgconfig(gl)
BuildRequires:  pkgconfig(glu)
BuildRequires:  pkgconfig(xi)
BuildRequires:  qt5-linguist
BuildRequires:  libappstream-glib
BuildRequires:  pkgconfig(libv4l2)

Requires:       hicolor-icon-theme
Obsoletes:      %{name}-libs < %{version}-3


%description
It is a screen recorder for Linux.
Despite the name, this program is actually quite complex.
It's 'simple' in the sense that it's easier to use than ffmpeg/avconv or VLC

%prep
%autosetup -p1 -n %{shortname}-%{version}


%build
%cmake3 \
        -DCMAKE_BUILD_TYPE=Release \
        -DWITH_QT5=TRUE \
%ifnarch %{ix86} x86_64
        -DENABLE_X86_ASM=FALSE \
%endif
%ifarch %{arm} aarch64 %{power64}
        -DWITH_GLINJECT=FALSE \
%endif
%cmake3_build


%install
%cmake3_install

rm -f %{buildroot}%{_libdir}/*.la
mkdir -p %{buildroot}%{_libdir}/%{name}/
%ifnarch %{arm} aarch64 %{power64}
    mv %{buildroot}%{_libdir}/lib%{shortname}-glinject.so %{buildroot}%{_libdir}/%{name}/lib%{shortname}-glinject.so
%endif

%check
desktop-file-validate %{buildroot}%{_datadir}/applications/%{name}.desktop
appstream-util validate-relax --nonet %{buildroot}%{_datadir}/metainfo/*.metainfo.xml

%files
%doc README.md AUTHORS.md CHANGELOG.md notes.txt todo.txt
%license COPYING
%{_bindir}/%{name}
%{_datadir}/%{name}/
%{_datadir}/applications/%{name}.desktop
%{_datadir}/icons/hicolor/*/apps/%{name}*
%{_bindir}/%{shortname}-glinject
%{_libdir}/%{name}/
%{_mandir}/man1/%{name}.1.*
%{_mandir}/man1/%{shortname}-glinject.1.*
%{_datadir}/metainfo/%{name}.metainfo.xml

%changelog
* Wed May 17 2023  Sergey V My <virtual@ufasp.ru> - 0.4.5-1
- Update to 0.4.5
- Initial spec for RL8
