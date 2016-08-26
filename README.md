pcmanfm-image-size-module
=========================

Module for pcmanfm to render image size to status bar when file selected

### Dependencies && Building

Requires pcmanfm and libfm version 1.2.0 and above. Also depends on Imagemagick. Building process requires development files of these libraries, as well as build-essentials (C compiler, make, libtool).

On Ubuntu 16.04 you may install the build dependencies using the following command:
```
sudo apt-get install libtool-bin libmagickcore-dev libfm-dev
```

You must have `Magick-config` binary in your `$PATH` to build the module. On Ubuntu 16.04 with `libmagickcore-dev` you should run make the following way:
```
PATH="/usr/lib/x86_64-linux-gnu/ImageMagick-6.8.9/bin-Q16:$PATH" make
```

Can be built outside of pcmanfm and libfm tree and installed separately.

### Installation

According to the LXDE wiki on [LibFM Extensions](http://wiki.lxde.org/en/Extension_modules_for_LibFM#Types_of_plugins_supported_by_LibFM), modules must be installed to `$(libdir)/libfm/modules`. Supplied `Makefile` considers this to be `/usr/lib/libfm/modules`. However, it's not always true. E.g. for Ubuntu 16.04 with x86_64 architecture the path is `/usr/lib/x86_64-linux-gnu/libfm/modules`. Therefore, it's recommended to install the module by running
```
sudo cp .libs/pcmanfm-image-size-plugin.so /usr/lib/x86_64-linux-gnu/libfm/modules/
```

Adjust the command if your `$(libdir)` is different.

### TODO

Fix the build scripts.

### Contribute

PRs are welcome.
