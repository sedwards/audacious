/*  Audacious - Cross platform multimedia player
 *  Copyright (C) 2005-2007  Audacious development team
 *
 *  Based on BMP:
 *  Copyright (C) 2003-2004  BMP development team
 *
 *  Based on XMMS:
 *  Copyright (C) 1998-2003  XMMS development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; under version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef INPUT_H
#define INPUT_H

#include "plugin.h"

typedef struct _InputPluginData InputPluginData;

struct _InputPluginData {
    GList *input_list;
    InputPlayback *current_input_playback;
    gboolean playing;
    gboolean paused;
    gboolean stop;
    gboolean buffering;
    GMutex *playback_mutex;
};

GList *get_input_list(void);
InputPlayback *get_current_input_playback(void);
void set_current_input_playback(InputPlayback * ip);
void set_current_input_data(void * data);
InputVisType input_get_vis_type();
void free_vis_data(void);
InputPlugin *input_check_file(const gchar * filename, gboolean show_warning);
TitleInput *input_get_song_tuple(const gchar * filename);
void input_play(gchar * filename);
void input_stop(void);
void input_pause(void);
gint input_get_time(void);
void input_set_eq(gint on, gfloat preamp, gfloat * bands);
void input_seek(gint time);
void input_get_song_info(const gchar * filename, gchar ** title,
                         gint * length);
guchar *input_get_vis(gint time);
void input_update_vis_plugin(gint time);
gchar *input_get_info_text(void);
void input_about(gint index);
void input_configure(gint index);
void input_add_vis(gint time, guchar * s, InputVisType type);
void input_add_vis_pcm(gint time, AFormat fmt, gint nch, gint length,
                       gpointer ptr);
InputVisType input_get_vis_type();
void input_update_vis(gint time);

void input_set_info_text(const gchar * text);
void input_set_status_buffering(gboolean status);

GList *input_scan_dir(const gchar * dir);
void input_get_volume(gint * l, gint * r);
void input_set_volume(gint l, gint r);
void input_file_info_box(const gchar * filename);

void input_file_not_playable(const gchar * filename);
gboolean input_is_disabled(const gchar * filename);
gboolean input_is_enabled(const gchar * filename);
gchar *input_stringify_disabled_list(void);

extern InputPluginData ip_data;
extern gchar *input_info_text;


#endif
