#include<stdio.h>
#include<stdlib.h>

void Display(int Arr[], int iSize)
{
    int iCnt = 0;

    for(iCnt = 0; iCnt< iSize ; iCnt++)  
    {
        printf("%d\n", Arr[iCnt]);
    }
}

int main()
{
    int iLength = 0,iCnt=0;
    int *ptr = NULL;

    printf("Enter number of elements : ");//5
    scanf("%d",&iLength);

    ptr=(int*)malloc(iLength * sizeof(int));
    if(ptr = NULL)  // major issue
    {
        printf("Unable to allocate memory .\n");
        return -1;
    }

    printf("Enter the elements : \n");//10
    for(iCnt = 0;iCnt<iLength;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    Display(ptr,iLength);

    free(ptr);

    return 0;
}

// as trying to access null[0] -> segmentation fault
