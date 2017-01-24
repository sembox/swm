//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_item.h
// desc:  Item data strcutures and api definitions
//-------------------------------------------------------------------------------
#ifndef _ML_ITEM_H_
#define _ML_ITEM_H_

#include "ml_globals.h"
//---------------------------------------------------------
// Item defintions
//---------------------------------------------------------

typedef enum _item_type_t
{
    ML_SW_MODULE,
    ML_SW_INTERFACE,
    
} item_type_t;


typedef struct _ml_item_t
{
    int32_t id;
    geometry_t geometry; 

} ml_item_t;


#endif _ML_ITEM_H_