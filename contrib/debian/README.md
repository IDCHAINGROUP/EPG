
Debian
====================
This directory contains files used to package encocoinplusd/encocoinplus-qt
for Debian-based Linux systems. If you compile encocoinplusd/encocoinplus-qt yourself, there are some useful files here.

## encocoinplus: URI support ##


encocoinplus-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install encocoinplus-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your encocoinplus-qt binary to `/usr/bin`
and the `../../share/pixmaps/encocoinplus128.png` to `/usr/share/pixmaps`

encocoinplus-qt.protocol (KDE)

