/*
    step 1 : Understand the problem statement
    step 2 : Write the algorithm
    step 3 : Decide the programming language
    step 4 : Write the program
    step 5 : Test the program
*/

/*
    ALGORITHM
.0f
    START
        Accept first number as no1
        Accept second number as no2
        Perform addition of no1 and no2
        Display the addition on screen
    STOP
*/
#include<stdio.h>

float AdditionTwoNumbers(float fNo1, float fNo2)
{
    float fSum = 0.0f;
    fSum = fNo1 + fNo2;        
    return fSum;
}

int main()
{
    float fValue1 = 0.0f, fValue2 = 0.0f, fRet = 0.0f;

    printf("Enter the first number : \n");
    scanf("%f",&fValue1);

    printf("Enter the second number : \n");
    scanf("%f",&fValue2);

    fRet = AdditionTwoNumbers(fValue1,fValue2);     

    printf("Addition is : %f \n",fRet);
    
    return 0;
}