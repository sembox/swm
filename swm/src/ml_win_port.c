#include "ml_globals.h"
#include <Windows.h>


void (*timer_cb)(void) = NULL;
UINT_PTR timerid;

VOID CALLBACK win_timer_proc(
	HWND hwnd,        // handle to window for timer messages 
	UINT message,     // WM_TIMER message 
	UINT idTimer,     // timer identifier 
	DWORD dwTime)     // current system time 
{
	timer_cb();
}

void ml_win_start_timer(uint32_t to_ms, void(*cb)(void))
{
	timer_cb = cb;
	timerid = SetTimer(NULL, 0, to_ms, &win_timer_proc);
}


void ml_win_stop_timer(uint32_t to_ms, void(*cb)(void))
{
	KillTimer(NULL, timerid);
}
