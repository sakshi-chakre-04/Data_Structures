// refer sir's code 
#include<stdio.h>
#include<stdlib.h>

// float Average(int Arr[], int iSize)
// {
//     int iCnt = 0, iSum = 0, fAvg = 0.0f;

//     for(iCnt = 0; iCnt< iSize ; iCnt++)  
//     {
//         iSum += Arr[iCnt];
//         fAvg = iSum / iSize;
//     }
//     return fAvg;
// }

float Average(int Arr[], int iSize)
{
    int iCnt = 0, iSum = 0;

    for(iCnt = 0; iCnt< iSize ; iCnt++)  
    {
        iSum += Arr[iCnt];
    }
    return ((float)iSum/(float)iSize);    // Issue resolved
}

int main()
{
    int iLength = 0,iCnt=0;
    float fRet = 0;
    int *ptr = NULL;

    printf("Enter number of elements : ");//5
    scanf("%d",&iLength);

    ptr=(int*)malloc(iLength * sizeof(int));
    if(NULL == ptr)  
    {
        printf("Unable to allocate memory .\n");
        return -1;
    }

    printf("Enter the elements : \n");//10
    for(iCnt = 0;iCnt<iLength;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    fRet = Average(ptr,iLength);
    printf("Average is : %d\n",fRet);

    free(ptr);

    return 0;
}

// issue resolved with typecasting