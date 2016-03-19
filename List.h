/* By Patrick Russell pcrussel
 *
 * Name: List.h
 *
 * Purpose: Headerfile for List.c
 *
 */

#include<assert.h>
#include<stdio.h>
#include<stdlib.h>

/* NOTE: all Access functions and Manipulation procedures also have the
precondition that L has been initialized by newList().
*/

typedef struct ListStruct* ListHndl;


/*** Constructors-Destructors ***/


/* Makes a new list */
ListHndl newList( void );

/* Pre: L has been created with newList.*/
void freeList(ListHndl* L); 


/*** Access functions ***/


/*returns true is list if empty else returns false.*/
int isEmpty(ListHndl L); 

/*returns true if current == NULL*/
int offEnd(ListHndl L);

/*returns true if current == first and !offEnd()*/
int atFirst(ListHndl L);

/*returns true if current == last and !offEnd()*/
int atLast(ListHndl L);

/*return the first element; pre: !isEmpty()*/
long getFirst(ListHndl L);

/*return the last element; pre: !isEmpty()*/
long getLast(ListHndl L);

/*return the current element pre: !offEnd()*/
long getCurrent(ListHndl L);


/*** Manipulation procedures ***/

/* delete all elements from the list,
 * making it empty.
 *
 * Post: isEmpty(), offEnd() are both true
 */
void makeEmpty(ListHndl L);
  
/* without changing list order, make the first element
 * the current one.
 *
 * Pre: !isEmpty(); Post: !offEnd()
 */
void moveFirst(ListHndl L);

/* without changing list order, make the last element
 * the current one.
 *
 * Pre: !isEmpty(); Post: !offEnd()
 */
void moveLast(ListHndl L);

/* move the current marker one element earlier in the list
 *
 * Pre: !offEnd();
 * Post: offEnd() only if atFirst() was true;
 */
void movePrev(ListHndl L);

/* move the current marker one element later in the list.
 *
 * Pre: !offEnd();
 * Post: offEnd() only if atLast() was true;
 */
void moveNext(ListHndl L);
  
/* Inserts new element before first
 *
 * Post: !isEmpty(); doesnt change current element
 */
void insertAtFront(ListHndl L, long data);

/* Inserts new element after last one
 *
 * Post: !isEmpty(); doesn’t change current element
 */
void insertAtBack(ListHndl L, long data);

/* Inserts new element before current one
 *
 * Pre: !offEnd();
 * Post: !isEmpty(), !offEnd(), !atFirst()
 */
void insertBeforeCurrent(ListHndl L, long data);

/*delete the first element. Pre: !isEmpty()*/
void deleteFirst(ListHndl L);

/* delete the last element. Pre: !isEmpty()*/
void deleteLast(ListHndl L);

/* delete the current element.*/
/* Pre: !isEmpty(), !offEnd(); Post: offEnd()*/
void deleteCurrent(ListHndl L);


/*** Other operations ***/


/* prints out the list with the
 * current element marked, helpful for debugging */
void printList(FILE* out, ListHndl L);
