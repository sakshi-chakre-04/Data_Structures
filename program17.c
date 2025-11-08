#include<stdio.h>
#include<stdbool.h>

bool CheckEvenOdd(int iNo)
{
    return ((iNo % 2) == 0);    // not a good prog. prac. but allowed
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