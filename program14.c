#include<stdio.h>
#include<stdbool.h>

bool CheckEvenOdd(int iNo)
{
    int iRem = 0;

    iRem = iNo % 2;

    if(iRem == 0)
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
    int iValue = 0;
    bool bRet = false ;

    printf("Enter the number :\n");
    scanf("%d",&iValue);

    bRet = CheckEvenOdd(iValue);       // call by value

    if(bRet == true)
    {
        printf("%d is Even number.\n",iValue);
    }
    else 
    {
        printf("%d is Odd number.\n",iValue);
    }

    return 0;
}
/*
 in this code the problem is the selection is written 2 times in func and main both
 e.g. of printer ...always going to func to check
*/