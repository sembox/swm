//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_mem_mgr.h
// desc:  Memory manager
//-------------------------------------------------------------------------------
#include <string.h>
#include "ml_llist.h"
// memory chank definition
typedef struct _ml_mem_chank_t
{
	dlink_entry_t dlink;    // single linked list
	void *mem_ptr;          // memory pointer
	uint32_t size;          // allocated size
	uint32_t line;          // line number
} ml_mem_chank_t;

typedef struct
{
    uint32_t count;              // list count
    //link_head_tail_t head_tail;  // list pointer
} ml_mem_chanks_t;

typedef struct _ml_mem_mgr_t
{
	link_head_tail_t alloc_list;
	// other info will go here
} ml_mem_mgr_t;

#define MEMCPY(dst,src,size)        memcpy((void*)(dst),(void*)(src),size)
#define MEMMOVE(dst,src,size)       memmove((void*)(dst),(void*)(src),size)
#define MEMCMP(dst,src,size)        memcmp((void*)(dst),(void*)(src),size)
#define MEMSET(dst,pattern,size)    memset((void*)(dst),pattern,size)


// init memory manager
void ml_memmgr_init(void);
//allocate and track memory 
void *ml_mem_alloc(uint32_t size, uint32_t line);
// free memory 
void ml_mem_free(void *ptr);
// shutdown memory manager
void ml_mem_mgr_exit(void);
// show allocated memory chunks
void mem_mgr_list_mem_chanks(void);