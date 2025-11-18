#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//typedef int * IPTR;// it is just used for alis 

// < O(N)
bool LinearSearch(int Arr[], int iSize, int iNo )
{
    int iCnt = 0, iCount = 0;
    for(iCnt = 0;iCnt<iSize ;iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            iCount++;
            break;
        }
    }

    if(iCount > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int iLength = 0, iCnt = 0, iValue = 0;
    bool bRet = false;

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

    printf("Enter the number to search : \n");
    scanf("%d",&iValue);

    // step 2 : use the memory
    bRet = LinearSearch(iPtr, iLength, iValue);
    
    if(bRet == true)// is else is used as otherwise ans will be as 0 or 1
    {
        printf("%d is present in data\n",iValue);
    }
    else
    {
        printf("%d is not present in data\n",iValue);
    }

    // step 3 : free the memory
    free(iPtr);

    return 0;
}