//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_llist.c
// desc:  Linked list processing functions
//-------------------------------------------------------------------------------
#include "ml_globals.h"
#include "ml_llist.h"


//-------------------------------------------------------------------------------
// Initialize dobule link list
// Linked list uses below link mechanism to make insertion and deletion simpler.
// (see Sentinel linked list)
//-------------------------------------------------------------------------------
void ld_init(link_head_tail_t* list)
{
    list->head = list;
    list->tail = list;
}


//-------------------------------------------------------------------------------
// Insert new entry to doubly linked list.
// entry      entry pointer to be inserted
// prev       Previous entry pointer
// next       Next entry pointer
//-----------------------------------------------------------------------------
void dl_insert(dlink_entry_t* entry, dlink_entry_t* prev, dlink_entry_t* next)
{
    entry->next = next;
    entry->prev = prev;
    next->prev = entry;
    prev->next = entry;
}


//-------------------------------------------------------------------------------
// Add new entry to next position of specified location
// entry      entry pointer to be added
// location   location pointer
//-------------------------------------------------------------------------------
void dl_add_next(dlink_entry_t* entry, dlink_entry_t* location)
{
    dl_insert(entry, location, location->next);
}


//-------------------------------------------------------------------------------
// Add new entry to previous position  of specified location
// entry      entry pointer to be added
// pLocation   location pointer
//-------------------------------------------------------------------------------
void ld_add_prev(dlink_entry_t* entry, dlink_entry_t* location)
{
    dl_insert(entry, location->prev, location);
}


//-------------------------------------------------------------------------------
// Add new entry to head of list
// list       list pointer
// entry      entry pointer to be added
//-------------------------------------------------------------------------------
__inline static void dl_add_head(link_head_tail_t* list, dlink_entry_t* entry)
{
    dl_add_prev(entry, list->head);
}


//-------------------------------------------------------------------------------
// Add new entry to tail of list
// list       list pointer
// entry      entry pointer to be added
//-------------------------------------------------------------------------------
void dl_add_tail(link_head_tail_t* list, dlink_entry_t* entry)
{
    dl_add_next(entry, list->tail);
}


//-------------------------------------------------------------------------------
// Remove entry from list
// entry      entry pointer to be added
//-------------------------------------------------------------------------------
void dl_remove(dlink_entry_t* entry)
{
    ((dlink_entry_t *)entry->prev)->next = entry->next;
    ((dlink_entry_t *)entry->next)->prev = entry->prev;
}


//-------------------------------------------------------------------------------
// Pop a entry from head of list
// list       list pointer
//-------------------------------------------------------------------------------
void* dl_pop_head(link_head_tail_t* list)
{
    dlink_entry_t* entry;
    entry = (dlink_entry_t *)list->head;
    ((dlink_entry_t *)entry->next)->prev = list;
    list->head = entry->next;
    return entry;
}

//-------------------------------------------------------------------------------
// Pop a entry from tail of list
//-------------------------------------------------------------------------------
void* ld_pop_tail(link_head_tail_t* list)
{
    dlink_entry_t* entry;
    entry = (dlink_entry_t *)list->tail;
    ((dlink_entry_t *)entry->prev)->next = list;
    list->tail = entry->prev;
    return entry;
}


//-------------------------------------------------------------------------------
// Initialize single link list.
// Linked list uses below link mechanism to make insertion and deletion simpler.
// (see Sentinel linked list)
//-------------------------------------------------------------------------------
void sl_init(link_head_tail_t* list)
{
    list->head = list;
    list->tail = list;
}


//-------------------------------------------------------------------------------
// Insert new entry to single linked list.
// entry      entry pointer to be inserted
// pPrev       Previous entry pointer
//-------------------------------------------------------------------------------
void sl_insert(slink_entry_t* entry, slink_entry_t* prev)
{
    entry->next = prev->next;
    prev->next = entry;
}


//-------------------------------------------------------------------------------
// Add new entry to next position of specified location
// entry      entry pointer to be added
// location   location pointer
//-------------------------------------------------------------------------------
void sl_add_next(slink_entry_t* entry, slink_entry_t* location)
{
    sl_insert(entry, location);
}


//-------------------------------------------------------------------------------
// Add new entry to tail of single link list
// list       list pointer
// entry      entry pointer to be added
//-------------------------------------------------------------------------------
void sl_add_tail(link_head_tail_t* list, slink_entry_t* entry)
{
    if (SL_IS_NULL(list, list->head))
    {
        list->head = entry;
    }
    if (!SL_IS_NULL(list, list->tail))
    {
        ((slink_entry_t *)list->tail)->next = entry;
    }
    entry->next = (void *)list;
    list->tail = entry;
}


//-------------------------------------------------------------------------------
// Pop a entry from head of single link list
// list       list pointer
//-------------------------------------------------------------------------------
void* sl_pop_head(link_head_tail_t* list)
{
    slink_entry_t* entry;
    entry = (slink_entry_t *)list->head;
    list->head = entry->next;
    return entry;
}

