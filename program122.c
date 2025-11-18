#include<stdio.h>

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
    int Brr[] = {10,20,30,40}; // change
    
    Display(Brr,4);   // Display(100,4)->call by address,call by value

    return 0;
}

// here instead of moving the pointer we stay there and just point to location