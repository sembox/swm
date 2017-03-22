//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file: ml_macro.h
// desc: SWM maros defititions
//-------------------------------------------------------------------------------

#include <stddef.h>

// structure pointer from the member 
#define STR_PTR_FROM_MEMBER(addr,s,m) ((s *)((uint8_t *)(addr) - offsetof(s,m)))
// size of structure member
#define SIZEOF_MEMBER(s,m)  sizeof(((s *)0)->m)