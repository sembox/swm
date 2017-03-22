//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_app_logic.h
// desc:  Application logic definitions
//-------------------------------------------------------------------------------
#ifndef _ML_APP_LOGIC_H_
#define _ML_APP_LOGIC_H_

typedef enum _ml_app_state_t
{
	ML_APP_STATE_UNDEF,		// undefined 
	ML_APP_STATE_WELCOME_SCREEN, // welcome screen
	ML_APP_STATE_INIT,		// application in boot/intialization stage
	ML_APP_STATE_IDLE,		// application is ready to process events from user/system - no project is opened
	ML_APP_STATE_ACTIVE_PRJ // at least one project is active

} ml_app_state_t;


typedef struct _ml_app_logic_t
{
	ml_app_state_t cur_state;	// current application state
	ml_app_state_t prev_state;  // previous application state
	ml_app_state_t next_state;  // next applicatoin state? 

} ml_app_logic_t;


void ml_al_mouse_moved(void);
void ml_al_mouse_btn(void);
void ml_al_key_press(void);
void ml_al_timer(void);
void ml_al_start(void);
void ml_al_mouse_move(void);
#endif //_ML_APP_LOGIC_H_