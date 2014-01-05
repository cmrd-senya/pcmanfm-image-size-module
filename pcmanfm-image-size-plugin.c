/*
 *      pcmanfm-image-size-plugin.c
 *
 *      This file is module for PCManFM.
 *      It can be used with LibFM and PCManFM version 1.2.0 or newer.
 *
 *      Copyright 2014 Alexander Varnin (fenixk19) <fenixk19@mail.ru>
 *
 *      This program is free software; you can redistribute it and/or modify
 *      it under the terms of the GNU General Public License as published by
 *      the Free Software Foundation; either version 2 of the License, or
 *      (at your option) any later version.
 *
 *      This program is distributed in the hope that it will be useful,
 *      but WITHOUT ANY WARRANTY; without even the implied warranty of
 *      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *      GNU General Public License for more details.
 *
 *      You should have received a copy of the GNU General Public License
 *      along with this program; if not, write to the Free Software
 *      Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *      MA 02110-1301, USA.
 */

#include <string.h>
#include <libfm/fm.h>
#include <magick/api.h>
#include <pcmanfm-modules.h>

FM_DEFINE_MODULE(tab_page_status, image_size)

ExceptionInfo exception;
Image *image = 0;
ImageInfo *image_info = 0;

static char * image_size_sel_message(FmFileInfoList *files, gint n_files) {
        const int str_size = 64;
	char * buffer;
	if(n_files>1)
		return 0;
	FmFileInfo* fi = fm_file_info_list_peek_head(files);
	buffer = g_malloc(str_size);
	buffer[0]=0;
	if(fm_file_info_is_image(fi)) {
                char * path_str = fm_path_to_str(fm_file_info_get_path(fi));
		strncpy(image_info->filename, path_str, MaxTextExtent);
		g_free(path_str);
		image = PingImage(image_info, &exception);	
		if(image!=0)
			snprintf(buffer, str_size, "(%dx%d)", image->columns,image->rows);
//		else
//			snprintf(buffer, str_size, "%s:%s",exception.reason,exception.description);
	}
	return buffer;
}

static gboolean image_size_init(void) {
	MagickCoreGenesis(0,MagickFalse);
	GetExceptionInfo(&exception);
	image_info=CloneImageInfo((ImageInfo *) NULL);
	return TRUE;
}

static void image_size_finalize(void) {
	DestroyImageInfo(image_info);
	DestroyExceptionInfo(&exception);
	MagickCoreTerminus();
}

FmTabPageStatusInit fm_module_init_tab_page_status = {
	.sel_message = image_size_sel_message,
	.init = image_size_init,
	.finalize = image_size_finalize,
};

