//-------------------------------------------------------------------------------
// Copyright (c) 2017 MCI, Minsk, Belarus
//
// file:  ml_llist.h
// desc:  Linked list definitions
//-------------------------------------------------------------------------------
#ifndef _ML_LLIST_H_
#define _ML_LLIST_H_


// brief List head and tail
typedef struct
{
    void* tail;     // tail pointer
    void* head;     // head pointer
} link_head_tail_t;


// doubly linked List
typedef struct _dlink_entry_t
{
    void* prev;     // prevoius pointer (tail pointer)
    void* next;     // next pointer (head pointer)
} dlink_entry_t;


// singly linked List
typedef struct
{
    void* next;     ///< next pointer
} slink_entry_t;


//-----------------------------------------------------------------------------
//  Macros definitions:
//-----------------------------------------------------------------------------
#define DL_IS_EMPTY(DL)				   (((DL)->head) == ((DL)->tail))	
#define DL_FIRST_ENTRY(DL)             ((DL)->head)
#define DL_LAST_ENTRY(DL)              ((DL)->tail)
#define DL_IS_NULL(DL, entry)          ((void*)(DL) == (void*)(entry))
#define DL_GET_PREV(entry)             ((dlink_entry_t *)entry->prev)
#define DL_GET_NEXT(entry)             ((dlink_entry_t *)entry->next)
#define DL_HT_PTR(X)                   ((link_head_tail_t *)(X))
#define DL_ET_PTR(X)                   ((dlink_entry_t *)(X))
#define DL_HT_CLEAR(X)                 {(X).prev = NULL; (X).next = NULL;}
#define SL_IS_EMPTY(SL)				   (((void*)(SL)->head) == ((void*)(SL)))	
#define SL_FIRST_ENTRY(SL)             ((SL)->head)
#define SL_LAST_ENTRY(SL)              ((SL)->tail)
#define SL_IS_NULL(SL, entry)          ((void*)(SL) == (void*)(entry))
#define SL_GET_NEXT(entry)             ((slink_entry_t *)entry->next)
#define SL_HT_PTR(X)                   ((link_head_tail_t *)(X))
#define SL_ET_PTR(X)                   ((slink_entry_t *)(X))
#define SL_HT_CLEAR(X)                 { (X).next = NULL; }

// list iteration macros
#define DL_FOR_EACH(entry, DL) for (entry = DL_FIRST_ENTRY(DL); !DL_IS_NULL(DL, entry); entry = DL_GET_NEXT(entry))
#define DL_FOR_EACH_BACKWARD(entry, DL) for (entry = DL_LAST_ENTRY(DL); !DL_IS_NULL(DL, entry); entry = DL_GET_PREV(entry))
#define DL_FOR_EACH_FROM(entry, DL) for (; !DL_IS_NULL(DL, entry); entry = DL_GET_NEXT(entry))
#define DL_FOR_EACH_BACKWARD_FROM(entry, DL) for (; !DL_IS_NULL(DL, entry); entry = DL_GET_PREV(entry))
#define SL_FOR_EACH(entry, SL) for (entry = SL_FIRST_ENTRY(SL); !SL_IS_NULL(SL, entry); entry = SL_GET_NEXT(entry))
#define SL_FOR_EACH_FROM(entry, SL) for (; !SL_IS_NULL(SL, entry); entry = SL_GET_NEXT(entry))


// Doubly linked list API
void dl_init(link_head_tail_t* list);
void dl_insert(dlink_entry_t* entry, dlink_entry_t* pPrev, dlink_entry_t* pNext);
void dl_add_next(dlink_entry_t* entry, dlink_entry_t* pLocation);
void dl_add_prev(dlink_entry_t* entry, dlink_entry_t* pLocation);
void dl_add_head(link_head_tail_t* list, dlink_entry_t* entry);
void dl_add_tail(link_head_tail_t* list, dlink_entry_t* entry);
void dl_remove(dlink_entry_t* entry);
void *dl_pop_head(link_head_tail_t* list);
void *dl_pop_tail(link_head_tail_t* list);


// Single linked list API
void sl_init(link_head_tail_t* list);
void sl_insert(slink_entry_t* entry, slink_entry_t* pPrev);
void sl_add_next(slink_entry_t* entry, slink_entry_t* pLocation);
void sl_add_tail(link_head_tail_t* list, slink_entry_t* entry);
void *sl_pop_head(link_head_tail_t* list);
void sl_remove(slink_entry_t* entry);
#endif

#if 0
// how to use


// module global info structure
typedef struct _modlue_data_t
{
	link_head_tail_t list;  // list of items
	uint8_t* data1;			// data 1
	uint8_t* data2;			// data 2
} modlue_data_t;

typedef struct _list_data_entry_t
{
	dlink_entry_t dlink;    // linked list pointers
	unit32_t d1;			// other members of link entreis
	uint32_t d2;			// other members 
} list_data_entry_t;


// module data structure
modlue_data_t module_data;

//1. init linked list before using it
dlinit(&module_data.list);

//2. add list items
list_data_entry_t *entry1 = ...create / allocate entry;
dl_add_head(&module_data.list, &entry1->dlink);
or 
dl_add_tail(&module_data.list, &entry1->dlink);
or 
dl_add_next(..), dl_add_prev(..)

//3. delete item
list_data_entry_t *entry1;
dl_remove(entry1);

//4. pop from head/tail
list_data_entry_t *entry2;
entry2 = dl_pop_head(&module_data.list);

//5. iteration
dlink_entry_t* entry;
list_data_entry_t* node;

DL_FOR_EACH(entry, &module_data.list)
{
	//from list pointer to node structure
	node = STR_PTR_FROM_MEMBER(entry, list_node_t, dlink);
	//access node fields
	node->data1 
	node->data2;
}

#endif 