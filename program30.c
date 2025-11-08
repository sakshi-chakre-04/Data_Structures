// 1    2   3   4   5

#include<stdio.h>

void Display()
{
    int iCnt = 0;

    iCnt = 1;
    while(iCnt <= 5)
    {
        printf("%d\t",iCnt);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
        iCnt++;// dynamic loop
    }

    printf("\n");
}

int main()
{
    Display();

    return 0;
}

//coverting for to while
// any loop to any possible