/**
 ** DynamicArrays.c  - private implementations - student file
 **
 ** Implementation of a (constant growth) Dynamic Array data type             
 **   Modify struc Data in DynamicArrays.h for payload according application  
 **   To change growth policy modify PushToDArray as needed                   
 **                                                                           
 ** Written by: Greg Semeraro,Ph.D.                                           
 ** Modified: Dr. Juan C. Cockburn (jcck@ieee.org)                            
 ** Revised: 02/01/2014 JCCK     
 **          10/02/2015 R Repka 
 **          03/03/2017 R Repka
 **          07/21/2017 R.Repka - added class errors include file
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ClassErrors.h"
#include "DynamicArrays.h"

typedef double MatElement;

/***************************************************************************
 CreateDArray -- Allocates memory and initializes DArray state             
        void CreateDArray(DArray *DArrayHead, unsigned int InitialSize)
 Where:
    DArray *DArrayHead       - Pointer to a storage block which holds the
                               data structure entry 
    unsigned int InitialSize - The initial data block size, could be 0
    returns: void            - nothing is returned.
    errors:                  - This routine will print an error message to 
                               stderror and exit with an error code
 **************************************************************************/
void CreateDArray(DArray *DArrayHead, unsigned int InitialSize) {
   /************************************************************************
   Pseudo code: 
   Initialize array with 0 entries used 
   Initialize capacity (you decide, could be zero)
   Based on capacity allocate memory storage, if necessary 
      If initial capacity is zero, no allocation needed 
      else Allocate storage space for payload according to struc Data
   if memory not allocated print error to stderr and exit with a code 
  ************************************************************************/
	/* Set initial Capacity to InitialSize */
	DArrayHead->Capacity = InitialSize; 
	
	/* Set initial entries used to 0 */
	DArrayHead->EntriesUsed = 0;

	/* Allocate heap memory for Data */
	/* If initial capacity is zero, no allocation needed */	
	if (0 == DArrayHead->Capacity) {
		DArrayHead->Payload = NULL;
	}
	else {
		DArrayHead->Payload = 
		( Data* ) malloc(DArrayHead-> Capacity * sizeof(Data));
		/* Verify that the memory was actually allocated */
		if (NULL == DArrayHead->Payload) {
			/* print error to stderr and exit with a code*/
			fprintf(stderr, "CreateDArray(): malloc() failed!\n");
			fflush(stderr);
		}	
	}
} /* CreateDArray() */


/***************************************************************************
  PushToDArray -- Adds data at the end of the dynamic array and updates its 
                  state in the array header.  If full, reallocates memory 
                  space according to growth policy                          
        unsigned int PushToDArray(DArray *DArrayHead, Data *PayloadPtr)     
Where:
    DArray *DArrayHead      - Pointer to a storage block which holds the
                              data structure entry 
    Data * PayloadPtr       - 
    returns: unsigned int   - The index of the last element inserted
    errors:                 - This routine will print an error message to 
                              stderror and exit with an error code 
 **************************************************************************/
unsigned int PushToDArray(DArray *DArrayHead, Data *PayloadPtr)
{
   /************************************************************************
    Pseudo code: 
    Check if the array needs to be made larger 
    If yes, increase the size of the dynamic array 
    Re-allocate storage for the array elements using larger size 
    if memory not re-allocated print error to stderr and exit 
    Increment the number of elements used in Darray header 
    Return the array index of last element inserted 
   ************************************************************************/
 	/* Check if the array needs to be made larger*/
	if (DArrayHead->EntriesUsed == DArrayHead->Capacity) {
		/* Increase the size of the dynamic array */
		DArrayHead ->Capacity += GROWTH_AMOUNT;
		/* Re-allocated storage for larger array elements*/
		DArrayHead->Payload = realloc(DArrayHead->Payload,
		DArrayHead->Capacity * sizeof(Data));
		/* Verify that the memory was actually allocated */
		if (NULL == DArrayHead->Payload) {
                        /* print error to stderr and exit with a code*/
                       fprintf(stderr, "OushToDArray(): realloc() failed!\n");
                       fflush(stderr);
		}
	}
	/* Copy the new data to the array at the insertion index value */
	memcpy(&(DArrayHead->Payload[DArrayHead->EntriesUsed]),
		PayloadPtr, sizeof(Data));

	/* Increment the number of elements used in the array */
	DArrayHead->EntriesUsed++;

	/* Return the array index of last element inserted */
	return (DArrayHead->EntriesUsed - 1);
} /* PushToDArray() */


/*************************************************************************
 DestroyDArray -- Returns the memory back to the heap and updates the   
                  state in the array header      
        void DestroyDArray(DArray *DArrayHead)
  Where:
    DArray *DArrayHead  - Pointer to a storage block which holds the
                          data structure entry 
    returns: void       - nothing is returned.
    errors:             - No errors are reported
*************************************************************************/
void DestroyDArray(DArray *DArrayHead)
{
   /**********************************************************************
    Pseudo code: 
    Set the number of entries used to zero in Darray header 
    Set the capacity to zero in Darray header
    De-allocate the storage for the array elements 
 *************************************************************************/
	/* Set the number of entries used to 0 in Darray header */
	DArrayHead->EntriesUsed = 0;

	/* Set the capacity to 0 in Darray header */ 
	DArrayHead->Capacity = 0;

	/* De-allocate the storage for the array elements*/
	free(DArrayHead->Payload);
	DArrayHead->Payload = NULL; /* ground it */

} /* DestroyDArray() */
