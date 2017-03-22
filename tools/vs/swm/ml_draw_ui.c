#include "ml_globals.h"
#include "ml_geom.h"
#include "ml_area.h"
#include "ml_window.h"
#include "ml_win_layout.h"
#include "ml_draw_ui.h"

//-------------------------------------------------------------------------------
// Draw window content
//-------------------------------------------------------------------------------
bool_t ml_draw_win(ml_window_t *win)
{
	//get window layout
	win_layout_t* layout = win->layout;

	//layout contain window's areas (views)
	ml_area_list_t *wa_list = layout->areas;

	//for each area in the window 
	while (1)
	{
		// draw area 
		ml_draw_area(NULL);

		//draw area border;
		ml_draw_area_border();
	}

	return TRUE;
}

void ml_draw_area(ml_area_t *area)
{

}


void ml_draw_area_border(void)
{
	
}

void ml_draw_view(void)
{

}