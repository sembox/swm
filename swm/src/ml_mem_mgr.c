//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_mem_mgr.c
// desc:  Memory manager
//-------------------------------------------------------------------------------

#include "ml_globals.h"
#include "ml_llist.h"
#include <stdlib.h>


typedef struct _mem_chank_node_t
{
    slink_entry_t slink;    // single linked list
    void *mem_ptr;          // memory pointer
    uint32_t size;          // allocated size
    uint32_t line;          // line number
} mem_chank_node_t;

// list of allocated memory chanks
link_head_tail_t mem_chanks;


void ml_memmgr_init()
{
	ML_LOG(ML_LOG_INFO, "Initializing memory manager...");
    sl_init(&mem_chanks);
}

//allocate and track memory 
void *ml_memalloc(uint32_t size, uint32_t line)
{
    void* mem_ptr = malloc(size);
    mem_chank_node_t *entry; 
    //add to the list of allocated memory chanks
    if (mem_ptr != NULL)
    {
        entry = malloc(sizeof(mem_chank_node_t));
        if (entry != NULL)
        {
            entry->mem_ptr = mem_ptr;
            entry->line = line;
            entry->size = size; 
            sl_add_tail(&mem_chanks, entry);
        }
        else
        {
            //fail to allocate memory for the entry
			ML_LOG(ML_LOG_ERROR, "Failed to allocate intern. memory, size: %d", sizeof(mem_chank_node_t));
            //free allocated memory 
            free(mem_ptr);
            mem_ptr = NULL;
        }
    }
	else
	{
		ML_LOG(ML_LOG_ERROR, "Failed to allocate memory, size: %d at %d", size, line);
	}
    return mem_ptr;
}


// free memory 
void ml_mem_free(void *ptr)
{
    slink_entry_t* entry;

    //find and remove list item from allocated memory chanks
    SL_FOR_EACH(entry, &mem_chanks)
    {
        // compare memory 
    }
    //free memory
    free(ptr);
}