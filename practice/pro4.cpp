#include<iostream>
using namespace std;

int AdditionTwoNumbers(int iNo1, int iNo2)
{
    int iAns = 0;
    iAns = iNo1 + iNo2;
    return iAns;
}

int main()
{
    int iValue1 = 0, iValue2 = 0 , iRet = 0;

    cout<<"Enter the 1st number : \n";
    cin>>iValue1;

    cout<<"Enter the 2nd number : \n";
    cin>>iValue2;
 
    iRet = AdditionTwoNumbers(iValue1,iValue2);

    cout<<"Addition is : "<<iRet<<"\n";
   
    return 0;
}