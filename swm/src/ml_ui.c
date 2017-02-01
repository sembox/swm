//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_ui.c
// desc:  User interface elements
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_window.h"
#include "ml_area.h"
#include "ml_win_layout.h"


//-------------------------------------------------------------------------------
// Initialize user interface
//-------------------------------------------------------------------------------
bool_t ml_ui_init()
{
	return TRUE;
}


//-------------------------------------------------------------------------------
// Draw window content
//-------------------------------------------------------------------------------
bool_t ml_draw_win(ml_window_t *win)
{
	//get window layout
	win_layout_t* layout = win->layout;

	//layout contain window's areas (views)
	ml_area_list_t *wa_list = layout->areas;

	while (area = )
	{
		// draw area 
		ml_draw_area();

		//draw area border;
		ml_draw_area_border();
	}


	return TRUE;
}

