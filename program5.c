#include<stdio.h>

int main()
{
    int i = 0, j = 0, ans = 0;

    printf("Enter the first number : \n");
    scanf("%d",&i);

    printf("Enter the second number : \n");
    scanf("%d",&j);

    ans = i + j;             // Business logic

    printf("Addition is : %d \n",ans);
    
    return 0;
}