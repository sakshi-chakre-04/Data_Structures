#include<stdio.h> 

void CountDigits(char str[])
{
    int iCountSmall = 0;
    int iCountCapital = 0;

    while(*str != '\0')
    {
        if((*str >='A')&&(*str <='Z') )
        {
            iCountCapital++;
        }
        else if((*str >='a')&&(*str <='z'))
        {
            iCountSmall++;
        }
        str++;
    }
    printf("Capital count : %d\n",iCountCapital);
    printf("Small count : %d\n",iCountSmall);
}

int main()
{
    char Arr[50] = {'\0'};

    printf("Enter your name : \n");
    scanf("%[^'\n']s",Arr);

    CountAll(Arr);

    return 0;
}

// Q. ask in interview to either make it case sensitive or not ?