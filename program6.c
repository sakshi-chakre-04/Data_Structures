#include<stdio.h>

int Add(int a, int b)//helper function
{
    int sum = 0;
    sum = a + b;        // business logic
    return sum;
}

int main()
{
    int no1 = 0, no2 = 0, ans = 0;

    printf("Enter the first number : \n");
    scanf("%d",&no1);

    printf("Enter the second number : \n");
    scanf("%d",&no2);

    ans = Add(no1,no2);     

    printf("Addition is : %d \n",ans);
    
    return 0;
}
//arg?para? , class dig on para pass