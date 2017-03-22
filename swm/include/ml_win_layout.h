//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_win_layout.h
// desc:  Window layout manager, nows how to create areas and layout them within 
//        window
//-------------------------------------------------------------------------------
#ifndef _ML_WIN_LAYOUT_H_
#define _ML_WIN_LAYOUT_H_

#include "ml_globals.h"
#include "ml_window.h"
#include "ml_geom.h"
#include "ml_area.h"
#include "ml_llist.h"

typedef struct _ml_area_list_t
{
	link_head_tail_t head_tail;
	ml_area_t *areas;
} ml_area_list_t;

//-------------------------------------------------------------------------------
// Layout definitions
//-------------------------------------------------------------------------------
typedef struct _win_layout_t
{
    struct _ml_window_t *win;   // pointer to the parent window (need to know where to add views)
	ml_area_list_t *areas;   // pointer to the list of areas in current layout
} win_layout_t;



//-------------------------------------------------------------------------------
// Layout API
//-------------------------------------------------------------------------------
ml_area_t* ml_layout_get_area_at(point_t *point);   // get pointer to the area at location point
bool_t ml_layout_split_area(ml_area_t *area);       // split area into two reagions
bool_t ml_layout_delete_area(ml_area_t *area);      // delete area from layout
bool_t ml_layout_default_layout();                  // set default layout for current window
bool_t ml_layout_add_area(ml_area_t *area);         // just add new aread to the layout 
bool_t ml_layout_rearrange();                       // rearrange areas according to crurrent window dimensions

#endif