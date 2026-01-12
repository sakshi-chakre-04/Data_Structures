#include<iostream>
using namespace std;

/*
class Demo
{
    constructor(A, B)       // Parametrised
    {
        this.No1 = A;
        this.No2 = B;

        console.log("Inside constructor");
    }
}
*/

class Demo
{
    public:
        int No1, No2;

        Demo(int A, int B)
        {
            cout<<"Inside constructor\n";
            
            this->No1 = A;
            this->No2 = B;
        }
};

int main()
{
    Demo *obj = new Demo(10,11);

    return 0;
}