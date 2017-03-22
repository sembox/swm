//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_app_logic.c
// desc:  SWM application logic. Application state machine, logic, and everything 
//        else.. 
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_app_logic.h"
#include "ml_logger.h"

ml_app_logic_t app_logic;

//-------------------------------------------------------------------------------
// Init app logic
//-------------------------------------------------------------------------------
bool_t ml_app_logic_init()
{
	// initialize all application modules in right order

	// uinitialization stage
	app_logic.cur_state = ML_APP_STATE_INIT;
	return TRUE;
}


ml_app_state_t ml_app_logic_state()
{
	return app_logic.cur_state;
}


//-------------------------------------------------------------------------------
// user moved a mouse
//-------------------------------------------------------------------------------
void ml_al_mouse_moved()
{

}


//-------------------------------------------------------------------------------
// user pressed/released mouse button
//-------------------------------------------------------------------------------
void ml_al_mouse_btn()
{

}


//-------------------------------------------------------------------------------
// user pressed/released a key
//-------------------------------------------------------------------------------
void ml_al_key_press()
{

}


//-------------------------------------------------------------------------------
// user pressed/released a key
//-------------------------------------------------------------------------------
void ml_al_timer()
{

}


//-------------------------------------------------------------------------------
// welcome screen
//-------------------------------------------------------------------------------
void ml_al_start()
{
	//start show logo
	ML_LOG(ML_LOG_INFO, "Showing app welcome screen..");
	app_logic.cur_state = ML_APP_STATE_WELCOME_SCREEN;
}


//-------------------------------------------------------------------------------
// welcome screen
//-------------------------------------------------------------------------------
void ml_al_mouse_move()
{

}