/* By Patrick Russell   and Joseph Rogers
 *    pcrussel@ucsc.edu || jqrogers@ucsc.edu
 *
 * NAME: List.c
 * 
 * PURPOSE: Serves as a list Advanced Data Type
 *          for programs
 */

#include "myinclude.h"
#include <assert.h>

/* define the structs for NodePtr and ListHndl*/
typedef struct NodeStruct * NodePtr;
typedef struct ListStruct * ListHndl;

/* define the node and list structures*/
typedef struct NodeStruct {
  long data;
  struct NodeStruct* next;
  struct NodeStruct* prev;
} NodeStruct;


typedef struct ListStruct {
  NodePtr first;
  NodePtr last;
  NodePtr current;
} ListStruct;


/*** Constructor-Destructors ***/


/* Allocate memory to make a new list*/
ListHndl newList ()
{
  ListHndl tempList;
  tempList = malloc ( sizeof(ListStruct) );

  /*set the memory for the first and last nodes*/
  tempList->first = malloc ( sizeof(NodeStruct) );
  
  tempList->last = malloc ( sizeof(NodeStruct) );
  
  /*tempList->first->data = 7;*/
  tempList->first->prev = NULL;
  tempList->first->next = tempList->last;
  
  /*tempList->last->data = 3;*/
  tempList->last->prev = tempList->first;
  tempList->last->next = NULL;
  
  /*set the current element to the last*/
  tempList->current = tempList->last;
  
  return (tempList);
}


/* Free the list from memory*/
void freeList (ListHndl *List)
{
  assert ((*List) != NULL); 
  (*List) = NULL;
}


/*** Access fucntions ***/


/* Returns 1 if the list is empty*/
int isEmpty(ListHndl L){
  if(L->first == NULL){
    return 1;
  }
  return 0;
}


/* 
 * Returns 1 if the current 
 * pointer is off the end.
 */
int offEnd(ListHndl L){
  if(L->current == NULL){
    return 1;
  }
  return 0;
}


/*
 * Returns 1 if the current
 * pointer is at the first
 * node in the list.
 */
int atFirst(ListHndl L){
  if(!offEnd(L)){
    if(L->current == L->first){
      return 1;
    }
  }
  return 0;
}

/*
 * Returns 1 if the current
 * pointer is at the end
 * of the list.
 */
int atLast(ListHndl L){
  if(!offEnd(L)){
    if(L->current == L->last){
      return 1;
    }
  }
  return 0;
}


/* 
 * Gets the first element
 * in the list.
 */
long getFirst(ListHndl L)
{
  if(!isEmpty(L)){
    return(L->first->data);
  }
  return(-1);
}

/* 
 * Gets the last element
 * in the list.
 */
long getLast(ListHndl L)
{
  if(!isEmpty(L)){
    return(L->last->data);
  }
  return(-1);
}

/*
 * Gets the current element 
 * in the list.
 */
long getCurrent(ListHndl L)
{
  if(!isEmpty(L)){
    return(L->current->data);
  }
  return(-1);
}


/*** Manipulation procedures ***/


/* makes the list empty*/
void makeEmpty(ListHndl L){
  L->first = NULL;
  L->last = NULL;
  L->current = NULL;
  assert(isEmpty(L));
  assert(offEnd(L));
}

/* Makes the first element to the current one*/
/* Pre: !isEmpty(); Post: !offEnd()*/
void moveFirst(ListHndl L){
  if(!isEmpty(L)){
    L->current = L->first;
  }
  assert(!offEnd(L));
}

/* Makes the last element to the current one*/
/* Pre: !isEmpty(); Post: !offEnd()*/
void moveLast(ListHndl L){
  if(!isEmpty(L)){
    L->current = L->last;
  }
  assert(!offEnd(L));
}


/* Move the current marker one element eariler*/
/* Pre: !offEnd(); Post: offEnd() only if*/
/* atFirst() was true*/
void movePrev(ListHndl L){
  if(!offEnd(L)){
    if(atFirst(L)){
	  L->current = L->current->prev;
	  assert(offEnd(L));
	} else {
	  L->current = L->current->prev;
	}
  } 
}

/* Move the current marker one element later*/
/* Pre: !offEnd(); Post: offEnd() only if*/
/* atFirst() was true*/
void moveNext(ListHndl L){
  if(!offEnd(L)){
    if(atLast(L)){
	  L->current = L->current->next;
	  assert(offEnd(L));
	} else {
	  L->current = L->current->next;
	}
  } 
}


/* Inserts a new element before the first*/
/* Post: !isEmpty(); doesn't change current element*/
void insertAtFront(ListHndl L, long data){
  NodePtr hold = L->first;
  
  L->first = malloc ( sizeof(NodeStruct) );
  
  hold->prev = L->first;
  
  L->first->data = data;
  L->first->prev = NULL;
  L->first->next = hold;
  assert(!isEmpty(L));
}

/* Inserts a new element after the Last*/
/* Post: !isEmpty(); doesn't change current element*/
void insertAtBack(ListHndl L, long data){
  NodePtr hold = L->last;
  
  L->last = malloc ( sizeof(NodeStruct) );
  
  hold->next = L->last;
  
  L->last->data = data;
  L->last->prev = hold;
  L->last->next = NULL;
  assert(!isEmpty(L));
}

/* Inserts a new element before the current*/
/* Post: !isEmpty(); doesn't change current element*/
void insertBeforeCurrent(ListHndl L, long data){
  if(!offEnd(L)){
    NodePtr hold = L->current->prev;
	
	L->current->prev = malloc ( sizeof(NodeStruct) );
  
    hold->next = L->current->prev;
	
	L->current->prev->data = data;
    L->current->prev->prev = hold;
    L->current->prev->next = L->current;
    assert(!isEmpty(L));
  }
}

/* Delete the first element*/
/* Pre: !isEmpty()*/
void deleteFirst(ListHndl L){
  if(!isEmpty(L)){
    L->first->next->prev = NULL;
	L->first = L->first->next;
  }
}

/* Delete the last element*/
/* Pre: !isEmpty()*/
void deleteLast(ListHndl L){
  if(!isEmpty(L)){
    L->last->prev->next = NULL;
	L->last = L->last->prev;
  }
}

/* Delete the current element*/
/* Pre: !isEmpty()*/
void deleteCurrent(ListHndl L){
  if(!isEmpty(L)){
    if(!offEnd(L)){
          /* check to see if current points at*/
          /* the front or rear of the list*/
	  if(atFirst(L)){
	    deleteFirst(L);
	  } else if(atLast(L)){
	    deleteLast(L);
	  } else {
          /* if not, set the next and prev pointers*/
          /* of the nodes connected to current*/
        L->current->prev->next = L->current->next;
	    L->current->next->prev = L->current->prev;
      }
          /*free the current node*/
	  L->current = NULL;
          /*assert that current is not off the*/
          /*end of the list*/
	  assert(offEnd(L));
	}
  }
}


/*** Other operations ***/


/* 
 * Print the list with the current element
 * marked, useful for debugging.
 */
void printList(FILE* out, ListHndl L){
  /* remember where the current node was*/
  NodePtr hold = L->current;
  /* set the current to the first in the list*/
  L->current = L->first;
  out = fopen("tracedList.txt", "a");
  /* loop through the list, printing the data*/
  while(!offEnd(L)){
	if(L->current == hold){
	  fprintf(out, "%d*\n", getCurrent(L));
	} else {
	  fprintf(out, "%d\n", getCurrent(L));
	}
	moveNext(L);
  }
  /* set the current back to where it*/
  /* was at the start*/
  L->current = hold;
  fclose(out);
}