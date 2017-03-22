//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_mem_mgr.c
// desc:  Memory manager
//-------------------------------------------------------------------------------

#include "ml_globals.h"
#include "ml_llist.h"
#include "ml_mem_mgr.h"
#include <stdlib.h>


// ML memort manager
ml_mem_mgr_t mem_mgr;

//-------------------------------------------------------------------------------
// initialize memory manager
//-------------------------------------------------------------------------------
void ml_memmgr_init()
{
	ML_LOG(ML_LOG_INFO, "Initializing memory manager..");
	// init linked list
	dl_init(&mem_mgr.alloc_list);
	// show allocated memory chunks
	mem_mgr_list_mem_chanks();
}


//-------------------------------------------------------------------------------
// shut down memory manager - must be called last 
//-------------------------------------------------------------------------------
void ml_mem_mgr_exit()
{
	ML_LOG(ML_LOG_INFO, "Shutting down memory manager..");
	if (!SL_IS_EMPTY(&mem_mgr.alloc_list))
	{
		ML_LOG(ML_LOG_ERR, "Memory leak detected..");
		mem_mgr_list_mem_chanks();
	}
}


//-------------------------------------------------------------------------------
// allocate and track memory 
//-------------------------------------------------------------------------------
void *ml_mem_alloc(uint32_t size, uint32_t line)
{
    void* mem_ptr = malloc(size);
	ml_mem_chank_t *entry;
	//ML_LOG(ML_LOG_INFO, "Alloc memory 0x%X size x %d, line %d", mem_ptr, size, line);
    //add to the list of allocated memory chanks
    if (mem_ptr != NULL)
    {
		entry = malloc(sizeof(ml_mem_chank_t));
        if (entry != NULL)
        {
            entry->mem_ptr = mem_ptr;
            entry->line = line;
            entry->size = size; 
			dl_add_tail(&mem_mgr.alloc_list, &entry->dlink);
        }
        else
        {
            //fail to allocate memory for the entry
			ML_LOG(ML_LOG_ERR, "Failed to allocate intern. memory, size: %d", sizeof(ml_mem_chank_t));
            //free allocated memory 
            free(mem_ptr);
            mem_ptr = NULL;
        }
    }
	else
	{
		ML_LOG(ML_LOG_ERR, "Failed to allocate memory, size: %d at %d", size, line);
	}
    return mem_ptr;
}


//-------------------------------------------------------------------------------
// free memory 
//-------------------------------------------------------------------------------
void ml_mem_free(void *ptr)
{
    dlink_entry_t *entry;
	ml_mem_chank_t *mem_chk;
	//ML_LOG(ML_LOG_INFO, "Free memory 0x%X", ptr);
    //find and remove list item from allocated memory chanks
	DL_FOR_EACH(entry, &mem_mgr.alloc_list)
    {
        // compare memory 
		mem_chk = STR_PTR_FROM_MEMBER(entry, ml_mem_chank_t, dlink);
		if (mem_chk->mem_ptr == ptr)
		{
			// found allocated memory chunk - delete from list
			dl_remove(entry);
			//free memory
			free(ptr);
			//free chunk structure
			free(mem_chk);
			break;
		}
    }
}


//-------------------------------------------------------------------------------
// mem mgr list mem hcunks
//-------------------------------------------------------------------------------
void mem_mgr_list_mem_chanks()
{
	dlink_entry_t *entry;
	ml_mem_chank_t *mem_chk;
	ML_LOG(ML_LOG_INFO, "Allocated memory chunks:");
	//find and remove list item from allocated memory chanks
	DL_FOR_EACH(entry, &mem_mgr.alloc_list)
	{
		mem_chk = STR_PTR_FROM_MEMBER(entry, ml_mem_chank_t, dlink);
		//print chunk info
		ML_LOG(ML_LOG_INFO, "Mem chunk: 0x%X, size: %d, line: %d", mem_chk->mem_ptr, mem_chk->size, mem_chk->line);
	}
}
