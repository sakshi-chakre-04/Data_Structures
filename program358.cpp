#include<iostream>
using namespace std;

inline int Addition(int A, int B)
{
    return A+B;
}

int main()
{
    register int Ret = 0;

    Ret = Addition(10,11);  // 10 + 11;

    cout<<"Addition is : "<<Ret<<"\n";

    return 0;
}