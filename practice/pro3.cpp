#include<iostream>
using namespace std;

int Addition(int a, int b)
{
    int ans = 0;
    ans = a + b;
    return ans;
}

int main()
{
    int i = 0, j = 0 , ret = 0;

    cout<<"Enter the 1st number : \n";
    cin>>i;

    cout<<"Enter the 2nd number : \n";
    cin>>j;
 
    ret = Addition(i,j);

    cout<<"Addition is : "<<ret<<"\n";
   
    return 0;
}