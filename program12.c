/*
    START
        Accept the number and store as no
        Divide the number by 2
        If the remainder is 0 
            then display as Even 
        otherwise
            display as odd 
    STOP
*/

#include<stdio.h>

void CheckEvenOdd(int iNo)
{
    int iRem = 0;

    iRem = iNo % 2;

    if(iRem == 0)   // comparison opt
    {
        printf("%d is Even .\n",iNo);
    }
    else
    {
        printf("%d is Odd .\n",iNo);
    }
}

int main()
{
    int iValue = 0;

    printf("Enter the number :\n");
    scanf("%d",&iValue);

    CheckEvenOdd(iValue);       // call by value

    return 0;
}

/*
here iRet is not taken as no value is returned 
solve basic Q. of sheet
*/














/*
Q. can you tell me (_)if my understanding is correct
*/