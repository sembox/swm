//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_window.h
// desc:  Window data strcutures and api definitions
//--------_-----------------------------------------------------------------------
#ifndef _ML_APP_H_
#define _ML_APP_H_

typedef struct _ml_app_t
{
	uint32_t version;
	uint32_t error;

} ml_app_t;

typedef struct _ml_app_data_t
{
	uint32_t id;
} ml_app_data_t;


int ml_app_start(void);
bool_t ml_app_init(void);
void app_entry(ml_app_t *ml_app);
void ml_app_exit(ml_app_t *ml_app);
#endif //_ML_APP_H_