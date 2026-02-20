//  Hello'\0'

#include<iostream>
#include<stdio.h>

using namespace std;

void strDisplay(char *str)
{
    while(*str != '\0')
    {
        cout<<*str<<"\n";
        str++;
    }
}

int main()
{
    char Arr[50] = {'\0'};
    
    printf("Enter String : \n");
    scanf("%[^'\n]s",Arr);

    printf("%s\n",Arr);

    strDisplay(Arr);

    return 0;
}