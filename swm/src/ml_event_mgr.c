//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_event_mgr.c
// desc:  Logger
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_llist.h"
#include "ml_app.h"
#include "ml_events.h"
#include "ml_io.h"
#include "ml_mem_mgr.h"
#include "ml_app_logic.h"
#include "ml_event_mgr.h"

ml_evt_mgr_t ml_event_mgr;

// initialize event manager
bool_t ml_em_init()
{
	uint32_t count;
	ml_event_t *evt;
	
	// init lists
	sl_init(&ml_event_mgr.event_queue);
	sl_init(&ml_event_mgr.free_evts);

	//creat pool of available event
	for (count = 0; count < DEF_EVET_POOL_SIZE; count++)
	{
		evt = ml_em_create_event();
		if (evt != NULL)
		{
			//add to free event list
			sl_add_tail(&ml_event_mgr.free_evts, &evt->slink);
		}
	}
	return TRUE;
}

void ml_em_exit()
{
	slink_entry_t *entry;
	ml_event_t *evt;
	//all events must be processed by this timie
	if (!SL_IS_EMPTY(&ml_event_mgr.event_queue))
	{
		ML_LOG(ML_LOG_ERR, "Not all events in the queue are processed..");
	}

	//free event pool
	while (!SL_IS_EMPTY(&ml_event_mgr.free_evts))
	{
		entry = sl_pop_head(&ml_event_mgr.free_evts);
		evt = STR_PTR_FROM_MEMBER(entry, ml_event_t, slink);
		ml_mem_free(evt);
	}
}


// allocate empty event
ml_event_t *ml_em_create_event()
{
	ml_event_t *evt = ml_mem_alloc(sizeof(ml_event_t), __LINE__);
	if (evt != NULL)
	{
		evt->is_valid = FALSE;
	}
	return evt;
}


//dispatch events to the event queues
bool_t ml_em_dispatch_events(ml_event_t *evt_list)
{
	return TRUE;
}


// hanlde events
bool_t ml_em_handle_events(ml_event_t *evt)
{
	ML_LOG(ML_LOG_INFO, "Processing event[%d]..", evt->type);
	switch(evt->type)
	{
		case ML_EVT_TYPE_START:
			ml_al_start();
			break;
		case ML_EVT_TYPE_KEY:
			ml_al_mouse_btn();
			break;
		case ML_EVT_TYPE_MOUSE_BTN:
			ml_al_mouse_move();
			break;
		case ML_EVT_TYPE_MOUSE_MOVE:
			ml_al_mouse_move();
			break;
		case ML_EVT_TYPE_TIMER:
			ml_al_timer();
			break;
		default:
			ML_LOG(ML_LOG_ERR, "Unhanlded event[%d]..", evt->type);
	}
	ml_em_free_event(evt);
	return TRUE;
}

void ml_em_add_event(ml_event_t *evt)
{
	//add event to event queue
	ML_LOG(ML_LOG_INFO, "Adding event to event[%d] queue..", evt->type);
	sl_add_tail(&ml_event_mgr.event_queue, &evt->slink);
}

// get free event 
ml_event_t* ml_em_get_free_evt()
{
	ml_event_t* evt = NULL;
	slink_entry_t *entry;

	if (SL_IS_EMPTY(&ml_event_mgr.free_evts))
	{
		// no free events - try to allocate another one
		evt = ml_em_create_event();
	}
	else
	{
		entry = (slink_entry_t*) sl_pop_head(&ml_event_mgr.free_evts);
		evt = STR_PTR_FROM_MEMBER(entry, ml_event_t, slink);
	}
	return evt;
}


ml_event_t* ml_em_get_event()
{
	ml_event_t* evt = NULL;
	slink_entry_t *entry;
	if (!SL_IS_EMPTY(&ml_event_mgr.event_queue))
	{
		entry = (slink_entry_t*)sl_pop_head(&ml_event_mgr.event_queue);
		evt = STR_PTR_FROM_MEMBER(entry, ml_event_t, slink);
	}
	return evt;
}


//free event - put to poll of free events
void ml_em_free_event(ml_event_t *evt)
{
	//invalidate events
	evt->is_valid = FALSE; 
	//add to head of free events
	sl_add_tail(&ml_event_mgr.free_evts, &evt->slink);
}

// process notifications
bool_t ml_em_proces_notify(ml_app_t *ml_app)
{
	return TRUE;
}
