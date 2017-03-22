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
	ML_EVT_TYPE_START,		//start screen request
    ML_EVT_TYPE_KEY,		//key pressed/released
	ML_EVT_TYPE_MOUSE_BTN,  //mouse buttin pressed/released
	ML_EVT_TYPE_MOUSE_MOVE, //mouse move event
	ML_EVT_TYPE_TIMER,		//timer tick
} ml_evt_type_t;


// event struture
typedef struct _ml_event_t
{
	slink_entry_t slink;    // linked list pointers
    ml_evt_type_t type;     // event type
    bool_t disc;            // is event discardable
	bool_t is_valid;		// is event valid
    uint32_t data[4];             // event specific data
} ml_event_t;

typedef struct _ml_event_list_t
{
	ml_event_t *netx;
} ml_event_list_t;


//dispatch events to the event queues
bool_t ml_em_dispatch_events(ml_event_t *evt_list);
// hanlde events
bool_t ml_em_handle_events(ml_event_t *evt_list);
// get events
ml_event_t* ml_em_get_event();
// process notifications
bool_t ml_em_proces_notify(void *ml_app);


#endif //_ML_EVENTS_H_