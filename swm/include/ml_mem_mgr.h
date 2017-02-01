//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_mem_mgr.h
// desc:  Memory manager
//-------------------------------------------------------------------------------
typedef struct _ml_mem_chank_t
{
    uint32_t size;
    uint32_t line;
    uint32_t *ptr;
} ml_mem_chank_t;

typedef struct
{
    uint32_t count;              // list count
    link_head_tail_t head_tail;  // list pointer
} ml_mem_chanks_t;


#define MEMCPY(dst,src,size)        memcpy((void*)(dst),(void*)(src),size)
#define MEMMOVE(dst,src,size)       memmove((void*)(dst),(void*)(src),size)
#define MEMCMP(dst,src,size)        memcmp((void*)(dst),(void*)(src),size)
#define MEMSET(dst,pattern,size)    memset((void*)(dst),pattern,size)

//allocate and track memory 
void *ml_mem_alloc(uint32_t size, uint32_t line);
// free memory 
void ml_mem_free(void *ptr);
