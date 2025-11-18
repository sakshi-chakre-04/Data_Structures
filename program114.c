#include<stdio.h>

void Display(int* ptr)
{
    int iCnt = 0;

    for(iCnt = 0; iCnt<4 ; iCnt++ , ptr++)  //+1 , +4 bytes
    {
        printf("%d\n",*ptr);
    }
}

int main()
{
    int Arr[] = {10,20,30,40};
    
    Display(Arr);   // Display(100)->call by address

    return 0;
}