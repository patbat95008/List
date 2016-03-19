/* By Patrick Russell pcrussel
 *
 * NAME: Listdr.c
 *
 * Purpose: to test List.c
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include "List.h"

int main(int argc, char **argv){
   ListHndl new = newList();   
   printf("isEmpty(new) = %d\n", isEmpty(new));
   return 1;
}
