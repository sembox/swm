//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_event_mgr.h
// desc:  Logger
//-------------------------------------------------------------------------------
#ifndef _ML_EVENT_MGR_H_
#define _ML_EVENT_MGR_H

#define DEF_EVET_POOL_SIZE 10

typedef struct _ml_evt_mgr_t
{
	link_head_tail_t free_evts;   // free events pool
	link_head_tail_t event_queue; // event queue to process
} ml_evt_mgr_t;

bool_t ml_em_init(void);
void ml_em_exit(void);
ml_event_t *ml_em_create_event(void);
ml_event_t* ml_em_get_free_evt(void);
void ml_em_add_event(ml_event_t *evt);
void ml_em_free_event(ml_event_t *evt);

#endif //_ML_EVENT_MGR_H