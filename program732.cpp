//  Hello'\0'

#include<iostream>
#include<stdio.h>

using namespace std;

void strDisplay(char *str)
{
    if(*str != '\0')
    {
        cout<<str<<"\n";
        strDisplay(str+1);
        cout<<str<<"\n";
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