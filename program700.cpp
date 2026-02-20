// Input : 5
// Output : 1   2   3   4   5   
#include<iostream>
using namespace std;

int CountDigits(int iNo)
{
    int iCount = 0;

    while(iNo != 0)
    {
        iCount++;
        iNo = iNo / 10;
    }
    return iCount;
}

int main()
{
    int iValue = 0 ,iRet = 0;

    cout<<"Enter number : \n";
    cin>>iValue;

    iRet = CountDigits(iValue);

    cout<<"Number of digits are : "<<iRet<<"\n";
    
    return 0;
}