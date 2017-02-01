//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_app.c
// desc:  SWM application
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_mem_mgr.h"

typedef struct _ml_app_t
{
	uint32_t version;
	uint32_t error;

} ml_app_t;

ml_app_t ml_app;

//-------------------------------------------------------------------------------
// Clear/set default parameters for the app
//-------------------------------------------------------------------------------
void ml_app_clear(ml_app_t *app)
{
	//reset everything for now
	MEMSET(app, 0);
}


//-------------------------------------------------------------------------------
// Fill in serialized data
//-------------------------------------------------------------------------------
bool_t ml_app_fill_from_data(ml_app_t *app, void *data)
{
	//not implemented yet
	return FALSE;
}


//-------------------------------------------------------------------------------
// Create and init main data strcutre(s)
//-------------------------------------------------------------------------------
ml_app_t *ml_app_create(void *ml_app_data)
{
	ml_app_t *app = ml_mem_alloc(sizeof(ml_app_t));
	bool_t res; 
	if (app != NULL)
	{
		if (ml_app_data != NULL)
		{
			//try to fill app data from serialized info
			res = ml_app_fill_from_data(app, ml_app_data);
			if (res == FALSE)
			{
				ML_LOG(ML_LOG_ERROR, "Failed to init app from data");
				//use defatult settings
				ml_app_clear(app);
			}
		}
		else
		{
			//use defatult settings
			ml_app_clear(app);
		}
	}
	return app;
}

//-------------------------------------------------------------------------------
// Init SWM applicatoin
//-------------------------------------------------------------------------------
bool_t ml_app_init()
{
	ml_app = ml_app_create();
	return TRUE;
}