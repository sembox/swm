//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_controller.c
// desc:  Processing user input and distribute commands to other components
//-------------------------------------------------------------------------------
#ifndef _ML_CONTROLLER_H_
#define _ML_CONTROLLER_H_

typedef struct
{
	uint32_t count;              // list count
	link_head_tail_t head_tail;  // list pointer
} ml_evt_queue_t;


typedef struct
{
	slink_entry_t slink;         // single linked list
	ml_event_t *evt;             // event data
} ml_evt_entry_t;



void ml_ctl_init();
bool_t ml_ctl_add_evt(ml_event_t *evt);
bool_t ml_ctl_process_evt(ml_event_t *evt);
void ml_ctl_dump_evt_queu(void);
bool_t ml_ctl_exit(ml_app_t* ml_app);

#endif // _ML_CONTOLLER_H_




