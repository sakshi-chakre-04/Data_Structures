#include<iostream>
#include<stdio.h>

using namespace std;

int strlenX(char *str)
{
    int iCount = 0;

    while(*str != '\0')
    {
        iCount++;
        str++;
    }
    return iCount;
}

int main()
{
    char Arr[50] = {'\0'};
    int iRet = 0;
    
    printf("Enter String : \n");
    scanf("%[^'\n]s",Arr);

    printf("%s\n",Arr);

    iRet = strlenX(Arr);

    printf("String length is : %d\n",iRet);

    return 0;
}