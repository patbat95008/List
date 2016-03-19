/* By Joseph Rogers and Patrick Russell
 *   jqrogers@ucsc.ed  ||  pcrussel@ucsc.edu
 *
 * NAME: store.c
 *
 * PURPOSE: To read data from a file
 *          and organize customers'
 *          data using the List.c ADT.
 *
 * USAGE: store          [ENTER]
 *        {FileNames...} [ENTER]
 */

#include "myinclude.h"
#include "list.h"

int main()
{
  printf("Enter an input file: ");
  /* Read input files*/
  char file[256];
  long data;
  long numCust;/* Number of Customers*/
  long numPurc;/* Number of Purchases*/
  FILE* input;

  scanf("%s", file);
 
  input = fopen(file, "rt");
  /*Find the number of customers*/
  fscanf(input, "%ld", &numCust);
  printf("Customers: %ld\n", numCust);
  /*Find the number of purchases*/
  fscanf(input, "%ld", &numPurc);
  printf("Purchases: %ld\n", numPurc);
  
  /* Make a new array of lists based on*/
  /* the number of customers*/
  ListHndl cust[numCust];
  int i = 0;

  /*loop through the array, making new lists*/
  while(i < numCust){
    cust[i] = newList();
	i++;
  }
  
  long index;
  
  /* Loop through the file, inserting the data*/
  /* into the appropriate list*/
  while(fscanf(input, "%ld", &index) != -1){
    fscanf(input, "%ld", &data);
	insertAtFront(cust[index], data);
  }
  
  FILE* output;
  i = 0;
  /* Print the data on customers*/
  while(i < numCust){
    printf("%d    ", i);
	moveFirst(cust[i]);
	while(!offEnd(cust[i])){
	  printf("%ld    ", getCurrent(cust[i]));
	  moveNext(cust[i]);
	}
	printf("\n");
	i++;
  }
  
  /*close the input*/
  fclose(input);
  
  /*free the lists*/


  return(0);
}