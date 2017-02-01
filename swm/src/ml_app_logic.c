//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_app_logic.c
// desc:  SWM application logic. Application state machine, logic, and everything 
//        else.. 
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_app_logic.h"


ml_app_logic_t app_logic;

//-------------------------------------------------------------------------------
// Init app logic
//-------------------------------------------------------------------------------
bool_t ml_app_logic_init()
{
	// initialize all application modules in right order

	// uinitialization stage
	app_logic.cur_state = ML_APP_STATE_INIT;
}


ml_app_state_t ml_app_logic_state()
{
	return app_logic.cur_state;
}
