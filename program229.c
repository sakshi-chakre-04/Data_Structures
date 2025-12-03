#include<stdio.h> 

// a e i o u

int CountCapital(char str[])
{
    int iCount = 0;

    while(*str != '\0')
    {
        if((*str >='A')&&(*str <='Z') )
        {
            iCount++;
        }
        str++;
    }
    return iCount;
}

int main()
{
    char Arr[50] = {'\0'};
    int iRet = 0;
    char cValue = '\0';

    printf("Enter your name : \n");
    scanf("%[^'\n']s",Arr);

    iRet = CountCapital(Arr);

    printf("Count of occurances are : %d\n",iRet);

    return 0;
}

// Q. ask in interview to either make it case sensitive or not ?