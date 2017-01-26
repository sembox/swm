//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_mem_mgr.h
// desc:  Memory manager
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include <stdlib.h>

typedef struct _ml_mem_chank_t
{
    uint32_t size;
    uint32_t line;
    uint32_t *ptr;
} ml_mem_chank_t;


//allocate and track memory 
void *ml_memalloc(uint32_t size, uint32_t line)
{
    void* memptr = malloc(size);
    //add to the list of allocated memory chanks

    return memptr;
}


// free memory 
void ml_mem_free(void *ptr)
{
    //find and remove list item from allocated memory chanks
    //free memory
    free(ptr);
}