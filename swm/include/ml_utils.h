//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_utils.h
// desc:  Useful stuff goes here
//-------------------------------------------------------------------------------
#ifndef _ML_UTILS_H_
#define _ML_UTILS_H_

uint64_t ml_get_system_time();
void ml_fomat_time(uint64_t time, char* buf, uint32_t buf_len);
void ml_sleep_ms(uint32_t ms);
void ml_start_timer(uint32_t ms, void(*cb)(void));
void ml_stop_timer(void);
#endif //_ML_UTILS_H_