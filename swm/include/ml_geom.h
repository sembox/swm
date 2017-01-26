//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_geom.h
// desc:  Geometyry-related defitinios
//-------------------------------------------------------------------------------
#ifndef _ML_GEOM_H_
#define _ML_GEOM_H_


// point type
typedef struct _point_t
{
    float x;
    float y;
} point_t;


// dimension type
typedef struct _dims_t
{
    float widht;
    float height;
} dims_t;


// rectangle type
typedef struct _rect_t
{
    point_t pos;
    dims_t  dims;
} rect_t;

#endif