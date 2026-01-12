#include<iostream>
using namespace std;

class Arithematic
{
    public:
        int No1;
        int No2;

        Arithematic(int A, int B)//don't use default value parameters in case to implement template 
        {
            No1 = A;
            No2 = B;
        }

        int Addition()
        {
            int Ans;// not made char. outisde becoz may not be neccessarily used by all func.
            Ans = No1 + No2;
            return Ans;
        }
};

int main()
{
    // Arithematic obj(); Not allowed

    Arithematic obj(11,10);

    cout<<"Addition is : "<<obj.Addition()<<"\n";

    return 0;
}