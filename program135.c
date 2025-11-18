#include<stdio.h>
#include<stdlib.h>

//typedef int * IPTR;// it is just used for alis 

int FrequencyCalculate(int Arr[], int size)
{
    int iCnt = 0, iCount = 0;
    for(iCnt = 0;iCnt<size ;iCnt++)
    {
        if(Arr[iCnt]==11)
        {
            iCount++;
        }
    }
    return iCount;
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
    iRet = FrequencyCalculate(iPtr, iLength);
    printf("Frequency of 11 is : %d \n ",iRet);

    // step 3 : free the memory
    free(iPtr);

    return 0;
}