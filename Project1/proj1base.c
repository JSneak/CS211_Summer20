/*  proj1Base.c

Written May 19th, 2020 by Sean Kim for CS 211, Summer 2020

*/

#include <stdio.h>
#include <stdlib.h>

void copyArray(int *fromArray, int *toArray, int size) {
  for(int i = 0; i < size; i++) {
    toArray[i] = fromArray[i];
  }
}

void myFavoriteSort(int *arr, int size) {
  for (int i = 0; i < size; i++) /* Loop for ascending order */ {
    for (int j = 0; j < size; j++) /* Loop for comparing values */ {
      if (arr[j] > arr[i]) /* Value comparison */ {
        int tmp = arr[i]; /* Store last value for comparison */
        arr[i] = arr[j]; /* Replace value */
        arr[j] = tmp; /* Store last value */
      }  
    }
  }
}

int countMatches(int *arr, int *sorted, int size) {
  /* Total matches */
  int count = 0;
  for(int i = 0; i < size; i++) {
    if(*(arr+i) == *(sorted+i)) {
      count++;
    }
  }
  return count;
}

int findInList(int *arr, int *sorted, int size, int target, int *nfound, int *index) {

  for(int i = 0; i < size; i++) {
    if(*(sorted+i) > target) /* Check to see if the sorted is greater than target */ {
      break;
    }
    if( *(sorted+i) == target ) /* Check if target integer is in sorted */ {
      *nfound += 1;
      if( *(sorted+i) == *(arr+i) ) /* Check if target integer is in correct position */ {
        *index = i;
      }
    }
  }

  if(nfound == 0) /* If not in the list at all */
    return -1;

  if(*index == -1) /* Check if target integer is in correct position */ {
    return 0;
  }else /* If not in the correct position */ {
    return 1;
  }

}

int main (int argc, char** argv)
{
  int val;
  /* Declare a pointer variable to point to allocated heap space */
  int *numArray;
  /* Set the size of the array to 100 */
  int sizeOfArray = 100;
  /* Variable to store the number of values stored */
  int inUse = 0;
  /* Malloc the appropriate number of bytes for the array */
  numArray = (int*)malloc(sizeof(int)*sizeOfArray);

  /* prompt the user for input */
  printf ("Enter in a list of numbers to be stored in a dynamic array.\n");
  printf ("End the list with the terminal value of -999\n");

  /* loop until the user enters -999 */
  scanf ("%d", &val);
  while (val != -999) {
    /* store the value into an array, growing array if needed. */
    if(inUse == sizeOfArray) /* Need to allocate more memory */ {
      /* Creates a temporary pointer to point to allocated heap space of numArray */
      int *temp = numArray;
      /* Double the size of the array */
      sizeOfArray  *= 2;
      /* Malloc more memory */
      numArray = (int*)malloc(sizeof(int) * sizeOfArray);
      for(int i = 0; i < inUse; i++) {
        numArray[i] = temp[i];
      }
      /* Free allocated memory */
      free(temp);
      
    } 
    /* Has enough allocated memory */ 
    /* Set val to position inUse+1 for numArray */
    numArray[inUse] = val;
    /* Increase value of inUse by one */
    inUse++;
    /* get next value */
    scanf("%d", &val);
  }
  /* Array to be copied into */
  int *copiedIntoArray;
  /* Malloc memory for the size of inUse */
  copiedIntoArray = (int *)malloc(sizeof(int)*inUse);
  /* Call function to make a copy of the array of values. */
  copyArray(numArray, copiedIntoArray, inUse);
  /* Call function to sort one of the arrays. */
  myFavoriteSort(numArray, inUse);
  for(int x = 0; x < inUse; x++) {
    printf("Pos: %d, Value at Pos: %d \n", x, numArray[x]);
  }
  /* Call function to count matches, and report results. */
  countMatches(copiedIntoArray, numArray, inUse);
  /* loop until the user enters -999 */
  printf ("Enter in a list of numbers to use for searching.  \n");
  printf ("End the list with a terminal value of -999\n");
  scanf ("%d", &val);
  while (val != -999)
  {
    /* Create nfound and index */
    int nfound = 0;
    int index = -1;
    /* call function to perform target search operation */
    findInList(copiedIntoArray, numArray, inUse, val, &nfound, &index);
    /* print out info about the target search results  */
    printf("Target Value: %d, Copies in list: %d, Position in sorted list: %d\n", val, nfound, index);
    /* get next value */
    scanf("%d", &val);
  }

  printf ("Good bye\n");
  return 0;
} 
