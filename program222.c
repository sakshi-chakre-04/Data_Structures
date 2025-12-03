#include<stdio.h> 

// a e i o u

int Count(char str[])
{
    int iCount = 0;

    while(*str != '\0')
    {
        if((*str == 'A') || (*str =='a') || (*str =='E') || (*str =='e') || (*str =='I')|| (*str =='i')|| (*str =='O')|| (*str =='o') || (*str =='U')|| (*str =='u'))
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

    printf("Enter your name : \n");
    scanf("%[^'\n']s",Arr);

    iRet = Count(Arr);

    printf("Count of vowels is : %d\n",iRet);

    return 0;
}
