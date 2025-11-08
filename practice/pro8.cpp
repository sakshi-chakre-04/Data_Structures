////////////////////////////////////////////////////////////////////////////////
//
//  Required header files
//
////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : AdditionTwoNumbers
//  Description : It is used to perform the addition
//  Input : Float , Float
//  Output : Float
//  Author : Sakshi Shilisiddha Chakre
//  Date : 17 / 10 / 2025
//
////////////////////////////////////////////////////////////////////////////////

float AdditionTwoNumbers(
                            float iNo1,                 //  First Input
                            float iNo2                  //  Second Input 
                        )
{
    float iAns = 0.0f;                                  // To store the Result

    if(iNo1 < 0.0f)                                     // Updator
    {
        iNo1 = -iNo1;
    }
    if(iNo2 < 0.0f)                                     // Updator
    {
        iNo2 = -iNo2;
    }
    iAns = iNo1 + iNo2;                                 // Business Logic
    return iAns;
}   // End of AdditionTwoNumbers

////////////////////////////////////////////////////////////////////////////////
//
//  Entry point function  for the application
//
////////////////////////////////////////////////////////////////////////////////

int main()
{
    float iValue1 = 0.0f, iValue2 = 0.0f ;          // To accept the input
    float iRet = 0.0f;                              // To store the result

    cout<<"Enter the 1st number : \n";
    cin>>iValue1;

    cout<<"Enter the 2nd number : \n";
    cin>>iValue2;
 
    iRet = AdditionTwoNumbers(iValue1,iValue2);             // Method Call

    cout<<"Addition is : "<<iRet<<"\n";
   
    return 0;
}   // End of main

////////////////////////////////////////////////////////////////////////////////
//
//  Test Cases successfully handled by the application 
//  Input 1 : 10             Input 2 : 20                Output : 30
//  Input 1 : -10            Input 2 : 20                Output : 30
//  Input 1 : 10             Input 2 : -20               Output : 30
//  Input 1 : -10            Input 2 : -20               Output : 30
//  Input 1 : 0.0            Input 2 : 10                Output : 10
//
////////////////////////////////////////////////////////////////////////////////