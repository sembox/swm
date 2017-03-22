//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_win_port.h
// desc:  windows porting code
//-------------------------------------------------------------------------------
#ifndef _ML_WIN_PORT_H_
#define _ML_WIN_PORT_H_


void ml_win_start_timer(uint32_t to_ms, void(*cb)(void));
void ml_win_stop_timer(void);
#endif //_ML_WIN_PORT_H_
