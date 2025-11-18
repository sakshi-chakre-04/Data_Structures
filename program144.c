#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//typedef int * IPTR;// it is just used for alis 

int Maximum(int Arr[], int iSize)
{
    int iCnt = 0, iMax = 0; // unable to handle negative values

    for(iCnt = 0; iCnt<iSize ; iCnt++)
    {
        if(Arr[iCnt] > iMax)
        {
            iMax = Arr[iCnt];
        }
    }
    return iMax;
}

int main()
{
    int iLength = 0, iCnt = 0, iRet = 0;

    int * iPtr = NULL;

    printf("Enter the number of elements : ");
    scanf("%d",&iLength);

    // step 1 : allocate the memory
    iPtr = (int *)malloc(iLength * sizeof(int));

    if(NULL == iPtr)//most rare case that memo. not present in ram
    {
        printf("Unable to allocate the memory .");
        return -1;//feedback to OS
    }

    printf("Enter the values : \n");
    for(iCnt = 0; iCnt < iLength ; iCnt++)
    {
        scanf("%d",&iPtr[iCnt]);
    }


    // step 2 : use the memory
    iRet = Maximum(iPtr, iLength);

    printf("Maximum number is :%d\n",iRet);

    // step 3 : free the memory
    free(iPtr);

    return 0;
}