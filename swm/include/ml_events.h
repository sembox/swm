//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_events.h
// desc:  Application events defintions
//-------------------------------------------------------------------------------
#ifndef _ML_EVENTS_H_
#define _ML_EVENTS_H_

typedef enum _ml_event_t
{
    ML_EVT_KEY_PRESSED,
    ML_EVT_KEY_RELEASED,
    ML_EVT_MOUSE_PRESED,
    ML_EVT_MOUSE_RELEASED,
    ML_EVT_MOUSE_CLICKED,
} ml_event_t;

#endif //_ML_EVENT_H_