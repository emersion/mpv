#ifndef MPLAYER_OPTIONS_H
#define MPLAYER_OPTIONS_H

#include <stdbool.h>
#include <stdint.h>
#include "core/m_option.h"

typedef struct mp_vo_opts {
    char **video_driver_list;

    int screenwidth;
    int screenheight;
    int ontop;
    bool fs;
    int screen_id;
    int fsscreen_id;
    int stop_screensaver;
    char *winname;
    char** fstype_list;
    int native_keyrepeat;

    float panscan;
    float panscanrange;

    struct m_geometry geometry;
    struct m_geometry autofit;
    struct m_geometry autofit_larger;

    int fsmode;
    int keepaspect;
    int border;

    int colorkey;

    int nomouse_input;
    int enable_mouse_movements;
    int cursor_autohide_delay;

    int64_t WinID;

    float force_monitor_aspect;
    float monitor_pixel_aspect;
    int force_window_position;

    int native_fs;
} mp_vo_opts;

typedef struct MPOpts {
    char **reset_options;

    char **audio_driver_list;
    int fixed_vo;
    char *mixer_device;
    char *mixer_channel;
    int softvol;
    float mixer_init_volume;
    int mixer_init_mute;
    int volstep;
    float softvol_max;
    int gapless_audio;
    int ao_buffersize;

    mp_vo_opts vo;

    char *wintitle;
    int force_rgba_osd;

    // ranges -100 - 100, 1000 if the vo default should be used
    int gamma_gamma;
    int gamma_brightness;
    int gamma_contrast;
    int gamma_saturation;
    int gamma_hue;

    int fullscreen;
    int requested_colorspace;
    int requested_input_range;
    int requested_output_range;

    char *audio_decoders;
    char *video_decoders;

    int osd_level;
    int osd_duration;
    int osd_fractions;
    int untimed;
    char *stream_capture;
    char *stream_dump;
    int loop_times;
    int ordered_chapters;
    int chapter_merge_threshold;
    int quiet;
    int load_config;
    int use_filedir_conf;
    int stream_cache_size;
    float stream_cache_min_percent;
    float stream_cache_seek_min_percent;
    int stream_cache_pause;
    int chapterrange[2];
    int edition_id;
    int correct_pts;
    int user_correct_pts;
    int user_pts_assoc_mode;
    int initial_audio_sync;
    int hr_seek;
    float hr_seek_demuxer_offset;
    float audio_delay;
    float default_max_pts_correction;
    int ignore_start;
    int autosync;
    int softsleep;
    int frame_dropping;
    int term_osd;
    char *term_osd_esc;
    char *playing_msg;
    char *status_msg;
    char *osd_status_msg;
    char *heartbeat_cmd;
    float heartbeat_interval;
    int player_idle_mode;
    int slave_mode;
    int consolecontrols;
    int doubleclick_time;
    int list_properties;
    struct m_rel_time play_start;
    struct m_rel_time play_end;
    struct m_rel_time play_length;
    int play_frames;
    double step_sec;
    int64_t seek_to_byte;
    int position_resume;
    int position_save_on_quit;
    int pause;
    int keep_open;
    int audio_id;
    int video_id;
    int sub_id;
    char **audio_lang;
    char **sub_lang;
    int audio_display;
    int sub_visibility;
    int sub_pos;
    float sub_delay;
    float sub_fps;
    int forced_subs_only;
    char *quvi_format;

    // subreader.c
    int suboverlap_enabled;
    char *sub_cp;
    int sub_no_text_pp;

    char *audio_stream;
    int audio_stream_cache;
    char *sub_stream;
    char *demuxer_name;
    char *audio_demuxer_name;
    char *sub_demuxer_name;
    int extension_parsing;
    int mkv_subtitle_preroll;

    struct image_writer_opts *screenshot_image_opts;
    char *screenshot_template;

    double force_fps;

    struct mp_chmap audio_output_channels;
    int audio_output_format;
    int force_srate;
    int dtshd;
    float playback_speed;
    struct m_obj_settings *vf_settings;
    float movie_aspect;
    int flip;
    int field_dominance;
    int divx_quality;
    char **sub_name;
    char **sub_paths;
    int sub_auto;
    int sub_match_fuzziness;
    int osd_bar_visible;
    float osd_bar_align_x;
    float osd_bar_align_y;
    float osd_bar_w;
    float osd_bar_h;
    float osd_scale;
    struct osd_style_opts *osd_style;
    struct osd_style_opts *sub_text_style;
    float sub_scale;
    float sub_gauss;
    int sub_gray;
    int ass_enabled;
    float ass_line_spacing;
    int ass_use_margins;
    int ass_vsfilter_aspect_compat;
    int use_embedded_fonts;
    char **ass_force_style_list;
    char *ass_styles_file;
    int ass_style_override;
    int ass_hinting;

    int hwdec_api;
    char *hwdec_codecs;

    struct lavc_param {
        int debug;
        int fast;
        char *skip_loop_filter_str;
        char *skip_idct_str;
        char *skip_frame_str;
        int threads;
        int bitexact;
        char *avopt;
    } lavc_param;

    struct ad_lavc_param {
        float ac3drc;
        int downmix;
        char *avopt;
    } ad_lavc_param;

    struct lavfdopts {
        int probesize;
        int probescore;
        float analyzeduration;
        int allow_mimetype;
        char *format;
        char *cryptokey;
        char *avopt;
    } lavfdopts;

    struct input_conf {
        char *config_file;
        int key_fifo_size;
        int ar_delay;
        int ar_rate;
        char *js_dev;
        char *in_file;
        int use_joystick;
        int use_lirc;
        int use_lircc;
#ifdef CONFIG_COCOA
        int use_ar;
        int use_media_keys;
#endif
        int default_bindings;
        int test;
    } input;

    struct encode_output_conf {
        char *file;
        char *format;
        char **fopts;
        float fps;
        float maxfps;
        char *vcodec;
        char **vopts;
        char *acodec;
        char **aopts;
        int harddup;
        float voffset;
        float aoffset;
        int copyts;
        int rawts;
        int autofps;
        int neverdrop;
        int video_first;
        int audio_first;
    } encode_output;
} MPOpts;

extern const m_option_t mp_opts[];
extern const struct MPOpts mp_default_opts;

#endif
