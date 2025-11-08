/*
    START
        accept a number and store it in a variable
        divide the number by 2
        if remainder is 0                    
            display as even
        else
            display as odd
    STOP
*/

#include<stdio.h>

void CheckEvenOdd(int iNo)
{
    int iAns = 0 ;

    iAns = iNo % 2;

    if(iNo == 0)
    {
        printf("Neither even nor odd .");
    }
    else if(iAns == 0)
    {
        printf("%d is Even .",iNo);
    }
    else
    {
        printf("%d is Odd .",iNo);
    }
}

int main()
{
    int iValue = 0;

    printf("Enter a number : ");
    scanf("%d",&iValue);

    CheckEvenOdd(iValue);

    return 0;
}