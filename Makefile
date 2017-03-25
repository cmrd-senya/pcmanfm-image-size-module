CFLAGS = `pkg-config --cflags libfm` `Magick-config --cflags`
AM_LDFLAGS = `Magick-config --libs` -rpath /usr/lib -no-undefined -module -avoid-version
modulepath=$(shell locate libfm/modules | head -n1 | tr -d "\n")

all:
	libtool --mode=compile gcc $(CFLAGS) -c pcmanfm-image-size-plugin.c
	libtool --mode=link gcc $(AM_LDFLAGS) pcmanfm-image-size-plugin.lo -o pcmanfm-image-size-plugin.la

install:
	libtool --mode=install install -c pcmanfm-image-size-plugin.la $(modulepath)
	libtool --finish $(modulepath)
