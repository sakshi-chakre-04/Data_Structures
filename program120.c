#include<stdio.h>

void Display(int Arr[])
{
    int iCnt = 0;

    for(iCnt = 0; iCnt<7 ; iCnt++)  
    {
        printf("%d\n", Arr[iCnt]);
    }
}

int main()
{
    int Brr[] = {10,20,30,40,50,60,70}; // change
    
    Display(Brr);   

    return 0;
}

// here instead of moving the pointer we stay there and just point to location