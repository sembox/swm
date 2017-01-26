//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_window.h
// desc:  Window data strcutures and api definitions
//-------------------------------------------------------------------------------
#ifndef _ML_WINDOW_H_
#define _ML_WINDOW_H_

#include "ml_globals.h"

//---------------------------------------------------------
// Window defintions
//---------------------------------------------------------
typedef struct _ml_window_t
{
    uint32_t id;    // window id
    dims_t dim;     // window dimensions
} ml_window_t;




#endif //_ML_WINDOW_H_