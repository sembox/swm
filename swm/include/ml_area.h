//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_area.h
// desc:  Area data strcutures and api definitions
//-------------------------------------------------------------------------------

#ifndef _ML_AREA_H_
#define _ML_AREA_H_

#include "ml_types.h"
//---------------------------------------------------------
// Area defintion
//---------------------------------------------------------
typedef struct ml_area_t
{
    uint32_t id;
    float x;
    float y;
    float width;
    float height;
} ml_area_t;

#endif //_ML_AREA_H_