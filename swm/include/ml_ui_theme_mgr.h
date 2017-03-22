//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_ui_theme_mgr.h
// desc:  Ui theme manger - settings for colors, fonts etc
//-------------------------------------------------------------------------------

#ifndef _ML_UI_THEME_MGR_H_
#define _ML_UI_THEME_MGR_H_

typedef enum _color_id
{
	UI_COLOR_TEXT,
	UI_COLOR_CURSOR,
	// ...
} color_id_t;

typedef enum _font_id
{
	UI_FONT_MENU,
	UI_FONT_TIP,
	UI_FONT_BUTTON
}font_id;

typedef struct _ml_ui_theme_t
{
	uint32_t id;
} ml_ui_theme_t;

bool_t ml_ui_tm_init(void);
ml_ui_theme_t *ml_ui_tm_get_theme();

//get colors
uint32_t ml_ui_tm_get_color(color_id_t);
//get font 
uint32_t ml_ui_tm_get_font(font_id);
//get ..

#endif //_ML_UI_THEME_MGR_H_