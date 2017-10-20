/******************************************************************************
 * TestDarray_hw.c - skeleton of code to test DynamicArray module
 *
 * Program to test the DynamicArrays module.  Reads in a large list of words
 * and puts them into the data structure, then prints out the first and last 
 * five elements in the data structure as well as the total number of words.
 ******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "ClassErrors.h"
#include "DynamicArrays.h"

/* Initial Size of Dynamic Array */
#define INITIAL_SIZE (1000)

/* Local function definitions */
 void ReadData(FILE *InputFile, DArray *DynamicArrayPtr);

/******************************************************************************
 This program to test the Data structure by reading the Data file provided on
 the command line into the structure, printing out the first and last N
 elements and total number of elements.  
        int main(int argc, char* argv[])
 Where:
    int argc        - The number of command line parameters
    char *argv[]    - An array of pointers to the parameters
    returns: in     - 0 for success, non-zero for error
    errors:         - Error message printed to stderr and exits with an error 
                      code 
******************************************************************************/
int main(int argc, char* argv[])
  {
  /* declare local variables */
   int ErrorCode = 0;               /* Application error code - 0 is OK */
   DArray TestDynamicArray;         /* Dynamic Array for Data */
   DArray *Arrayptr;
   Arrayptr = &TestDynamicArray;
   FILE *DataFile = NULL;           /* Pointer to Data file name (from cmd line) */
   int lcv;                         /* Loop Control Variable */
   unsigned int *NumofW;            /* Creates a pointer for number of words*/
   NumofW = &TestDynamicArray.EntriesUsed; /*Number of words in the file*/

   /* One command line argument is required: the file name     */
   if (2 == argc) /* note that argc 2 means one argument given */
     {
      /* Try to open the Data file for input (read mode)     */
      DataFile = fopen(argv[1], "r"); /* argv[1] is a string */

      /* Verify that file was opened correctly */
      if (NULL != DataFile)
        {
        /********************************************************************
         Pseudo code: 
         Initialize the dynamic array 
         Read all Data from text file 
         Close the Data file - use fclose(DataFile)
         Print the first 6 entries 
         Print the last 6 entries 
         Print total number of words read 
         De-allocate the dynamic array 
        ********************************************************************/
         /* WRITE YOUR CODE HERE */
	CreateDArray(Arrayptr, INITIAL_SIZE);
	ReadData(DataFile, Arrayptr );	
	fclose(DataFile);

	/* Print the first 6 entries */
	printf("The first six entries are:\n\n");
	for (lcv=0; lcv<6; lcv++) {
		printf("%d %s \t \n",lcv+1,TestDynamicArray.Payload[lcv].String);
		}
	printf("\n");
	/* Print the last 6 entries */
	printf("The last six entries are:\n\n");	
	for (lcv=(*NumofW-6); lcv<*NumofW; lcv++){
		printf("%d %s \t \n",lcv+1,TestDynamicArray.Payload[lcv].String);
	}
	printf("\n");	
	/* Print total Number of words read */
	printf("The total number of words in the file is: %d\n\n", *NumofW);

	/* Deallocating the DArray*/
	DestroyDArray(Arrayptr);
        } /* if() */
      else
        {
         /* Print error messages */
	fprintf(stderr,"Failed to locate the text file %s.\n", argv[1]);
	ErrorCode = 2;
	printf("\nThe Error Code is: %d\n",ErrorCode);
        } /* if...else() */
	
     } /* if() */
   else
     {
      /* Print usage information */
	fprintf(stderr,"\nPlease verify input arguments.\n\n");
	printf("This program is used to test the Data structure by reading");
	printf("\nONE Data file provided on the command line into the");
	printf("\nstructure printing out the first and last N elements and");
	printf("\ntotal number of elements. The data file must be in test");
	printf("\ndocument format.\nPlease enter:\t./TDA file_name.txt\n\n");
	ErrorCode = 1;
	printf("\nThe ErrorCode is: %d\n",ErrorCode);

     } /* if...else() */

   return ErrorCode;
  } /* main() */
  
 
/******************************************************************************
 Read the data file (assumed to be open) one word at a time placing each
 word into the data structure.  This routine will verify that the input string
 has the correct length.  Any string that is too long will generate a warning
 to stderr, not be added but processing will continue
        void ReadData(FILE *InputFile, DArray *DynamicArrayPtr)
  Where:
    FILE *InputFile         - Pointer to an open input file
    DArray *DynamicArrayPtr - Pointer to a storage block which holds the
                              data structure entry 
    returns: voi            - nothing is returned.
    errors:                 - This routine will print an error message to 
                              stderror and exit with an error code
******************************************************************************/
 void ReadData(FILE *InputFile, DArray *DynamicArrayPtr)
  {
   Data TempData;             /* temp variable to hold data   */
   int lcv = 1;               /* loop control variable        */
   int strLen;                /* The actual input string length */
   char String[MAX_STR_LEN];          /* temp variable to hold string */
   while (EOF != fscanf(InputFile, "%s", String))
     {
      /* Insert code here to make sure the input data is not too long*/
	strLen = strlen(String);
	if (strLen > MAX_STR_LEN){
 	 fprintf(stderr,"Warnning: Word exceeds maximum length of 255\n");
	}	
	else{
     	 TempData.Num = lcv++;
     	 strcpy(TempData.String, String);
      	 PushToDArray(DynamicArrayPtr, &TempData);
	}
     } /* while() */
  } /* ReadData() */
