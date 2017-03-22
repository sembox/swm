//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_controller.c
// desc:  Processing user input and distribute commands to other components
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_llist.h"
#include "ml_mem_mgr.h"
#include "ml_gl.h"
#include "ml_app.h"
#include "ml_events.h"
#include "ml_controller.h"

ml_evt_queue_t ml_evt_queue;


void ml_ctl_init()
{
    // init event queue
    sl_init(&ml_evt_queue.head_tail);
    
}

// add user event to the queue and process it if possilbe
bool_t ml_ctl_add_evt(ml_event_t *evt)
{
    //allocate memory for the event item
    ml_evt_entry_t *evt_ent = (ml_evt_entry_t *)ml_mem_alloc(sizeof(ml_evt_entry_t), __LINE__);    
    
    //store pointer to the event
    evt_ent->evt = evt;

    //add to queue tail
    sl_add_tail(&ml_evt_queue.head_tail, &evt_ent->slink);
    return TRUE;
}


// process events in the event queue
bool_t ml_ctl_process_evt(ml_event_t *evt)
{

    return TRUE;
}


// dump event queue
void ml_ctl_dump_evt_queu()
{

}

bool_t ml_ctl_exit(ml_app_t* ml_app)
{
	return ml_gl_shold_close();
}





