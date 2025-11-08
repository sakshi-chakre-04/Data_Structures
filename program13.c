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

    printf("Result is : %d .\n",bRet);

    return 0;
}

/*
 as the return val of func changed bRet added in the main()
*/
