#include<stdio.h> 

// a e i o u

int CountOccurance(char str[], char ch)
{
    int iCount = 0;

    while(*str != '\0')
    {
        if((*str == ch))
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

    printf("Enter the character you want to find : \n");
    scanf("%c",cValue);     // ISSUE

    iRet = CountOccurance(Arr,cValue);

    printf("Count of occurances are : %d\n",iRet);

    return 0;
}

// Q. ask in interview to either make it case sensitive or not ?