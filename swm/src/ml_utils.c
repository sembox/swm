//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_utils.c
// desc:  Useful stuff goes here
//-------------------------------------------------------------------------------
#include"ml_globals.h"
#include <time.h>


//-------------------------------------------------------------------------------
// retrieve system time in milliseconods
//-------------------------------------------------------------------------------
uint64_t ml_get_system_time()
{
	uint64_t time = (uint64_t)time();
	//get current system time
	return time;
}


//-------------------------------------------------------------------------------
// format time
//-------------------------------------------------------------------------------
void ml_fomat_time(uint64_t time, char* buf, uint32_t buf_len)
{
	time_t t = (time_t)time;
	strftime(buf, buf_len, "%Y-%m-%d %H:%M:%S", localtime(&t));
}