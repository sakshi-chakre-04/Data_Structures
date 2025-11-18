//refer sir's code
#include<stdio.h>
#include<stdlib.h>

typedef int * IPTR;// it is just used for alis 

int main()
{
    int iLength = 0, iCnt = 0;
    IPTR * iPtr = NULL;

    printf("Enter the number of elements : ");
    scanf("%d",&iLength);

    // step 1 : allocate the memory
    iPtr = (IPTR)malloc(iLength * sizeof(int));

    if(NULL == iPtr)//most rare case that memo. not present in ram
    {
        printf("Unable to allocate the memory .");
        return -1;//feedback to OS
    }

    printf("Enter the values : ");
    for(iCnt = 0; iCnt < iLength ; iCnt++)
    {
        
        scanf("%d",&iPtr[iCnt]);
    }

    // step 2 : use the memory
    // call to the function which contains the business logic
    // Fun(iPtr,iLength);

    // step 3 : free the memory
    free(iPtr);

    return 0;
}