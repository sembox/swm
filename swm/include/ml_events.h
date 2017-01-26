//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_events.h
// desc:  Application events defintions
//-------------------------------------------------------------------------------
#ifndef _ML_EVENTS_H_
#define _ML_EVENTS_H_


// event type definitions
typedef enum _ml_evt_type_t
{
    ML_EVT_KEY_PRESSED,
    ML_EVT_KEY_RELEASED,
    ML_EVT_MOUSE_PRESED,
    ML_EVT_MOUSE_RELEASED,
    ML_EVT_MOUSE_CLICKED,
} ml_evt_type_t;


// event struture
typedef struct _ml_event_t
{
    ml_evt_type_t type;     // event type
    bool_t disc;            // is event discardable? 
    void *data;             // event specific data
} ml_event_t;

#endif //_ML_EVENT_H_