// *    *   *   *   *   

#include<stdio.h>

void Display()
{
    int iCnt = 0;

    for(iCnt = 1; iCnt <= 5; iCnt++)
    {
        printf("*\t");//if loop body same always hen static loop
    }

    printf("\n");
}

int main()
{
    Display();

    return 0;
}