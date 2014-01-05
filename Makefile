CFLAGS = `pkg-config --cflags libfm` `Magick-config --cflags`
AM_LDFLAGS = `Magick-config --libs` -rpath /usr/lib -no-undefined -module -avoid-version

all:
	libtool --mode=compile gcc $(CFLAGS) -c pcmanfm-image-size-plugin.c
	libtool --mode=link gcc $(AM_LDFLAGS) pcmanfm-image-size-plugin.lo -o pcmanfm-image-size-plugin.la

install:
	libtool --mode=install install -c pcmanfm-image-size-plugin.la /usr/lib/libfm/modules
	libtool --finish /usr/lib/libfm/modules/
