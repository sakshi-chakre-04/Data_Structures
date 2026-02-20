// Input : 5
// Output : 1   2   3   4   5   
#include<iostream>
using namespace std;

int CountDigits(int iNo)
{
    static int iCount = 0;

    if(iNo != 0)
    {
        iCount++;
        CountDigits(iNo/10);
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