#include<iostream>
using namespace std;

float AdditionTwoNumbers(float iNo1, float iNo2)
{
    float iAns = 0;
    iAns = iNo1 + iNo2;
    return iAns;
}

int main()
{
    float iValue1 = 0.0f, iValue2 = 0.0f , iRet = 0.0f;

    cout<<"Enter the 1st number : \n";
    cin>>iValue1;

    cout<<"Enter the 2nd number : \n";
    cin>>iValue2;
 
    iRet = AdditionTwoNumbers(iValue1,iValue2);

    cout<<"Addition is : "<<iRet<<"\n";
   
    return 0;
}