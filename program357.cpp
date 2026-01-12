#include<iostream>
using namespace std;

int Addition(int A, int B)
{
    return A+B;
}

int main()
{
    int Ret = 0;

    Ret = Addition(10,11);

    cout<<"Addition is : "<<Ret<<"\n";

    return 0;
}