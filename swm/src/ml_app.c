//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_app.c
// desc:  SWM application
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_utils.h"
#include "ml_mem_mgr.h"
#include "ml_events.h"
#include "ml_event_mgr.h"
#include "ml_llist.h"
#include "ml_app.h"
#include "ml_view.h"
#include "ml_gl.h"
#include "ml_controller.h"


ml_app_t *ml_app;

//-------------------------------------------------------------------------------
// Clear/set default parameters for the app
//-------------------------------------------------------------------------------
void ml_app_clear(ml_app_t *app)
{
	//reset everything for now
	MEMSET(app, 0, sizeof(ml_app_t));
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
int ml_app_start()
{
	void *ml_app_data = NULL;
	
	// init app
	ml_app_init();

	ml_app_t *app = ml_mem_alloc(sizeof(ml_app_t), __LINE__);
	bool_t res; 
	if (app != NULL)
	{
		if (ml_app_data != NULL)
		{
			//try to fill app data from serialized info
			res = ml_app_fill_from_data(app, ml_app_data);
			if (res == FALSE)
			{
				ML_LOG(ML_LOG_ERR, "Failed to init app from data");
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

	app_entry(app);

	ml_app_exit(app);
	return 0;
}


//-------------------------------------------------------------------------------
// Init SWM applicatoin
//-------------------------------------------------------------------------------
bool_t ml_app_init()
{
	void *ptr1 = NULL;
	void *ptr2 = NULL;
	void *ptr3 = NULL;
	// clear app_data
	ml_app_data_t app_data = {0};
	// init logger
	ml_logger_init();
	// init memory manager
	ml_memmgr_init();
	// init event manager;
	ml_em_init();
	//ml_app = ml_app_create(&app_data);
	return TRUE;
}

void ml_app_welcome_screen()
{
	ml_event_t *evt;
	evt = ml_em_get_free_evt();
	evt->is_valid = TRUE;
	evt->type = ML_EVT_TYPE_START;
	ml_em_add_event(evt);
}

void ml_app_main()
{
	ml_event_t *evt = NULL;

	// show logo
	ml_app_welcome_screen();
	while (!ml_ctl_exit(ml_app))
	{
		//get event
		evt = ml_em_get_event();

		if (evt == NULL) 
		{
			//nothing to do
			ml_sleep_ms(5);
		}
		else
		{
			//dispatch events to the event queues
			//ml_em_dispatch_events(evt);
		
			// hanlde events
			ml_em_handle_events(evt);
		}
		// process notifications
		ml_em_proces_notify(ml_app);

		// draw changes
		ml_view_draw(ml_app);
	}

	ML_LOG(ML_LOG_INFO, "Terminate Open GL subsystem");
	//terminate ogl subsystem
	ml_gl_terminate();
}


//-------------------------------------------------------------------------------
// application entry point
//-------------------------------------------------------------------------------
void app_entry(ml_app_t *ml_app)
{
	//create ogl window
	ml_create_gl_win();

	// application main loop
	ml_app_main();
}


//-------------------------------------------------------------------------------
// application shut down
//-------------------------------------------------------------------------------
void ml_app_exit(ml_app_t *ml_app)
{
	// put here all code to clear resources
	// shutdown event manager
	ml_em_exit();
	
	ml_mem_free(ml_app);
	// memory manager should be called last
	ml_mem_mgr_exit();
}