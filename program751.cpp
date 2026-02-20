#include<iostream>
using namespace std;

class ArrayX
{
    public:
        int *Arr;
        int iSize;

        ArrayX(int no)
        {
            cout<<"Inside constructor\n";
            iSize = no;
            Arr = new int[iSize];
        }

        ~ArrayX()
        {
            cout<<"Inside destructor\n";
            delete [] Arr;
        }

        void Accept()
        {
            int iCnt = 0;

            cout<<"Enter the elements : \n";

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cin>>Arr[iCnt];
            }
        }

        void Display()
        {
            int iCnt = 0;

            cout<<"Elements of the array are : \n";

            for(iCnt = 0; iCnt < iSize; iCnt++)
            {
                cout<<Arr[iCnt]<<"\t";
            }
            cout<<"\n";
        }

        bool LinearSearch(int iNo)
        {
            bool bFlag = false;
            int i = 0;

            for(i = 0; i<iSize ; i++)
            {
                if(Arr[i] == iNo)
                {
                    bFlag = true;
                    break;
                }
            }
            return bFlag;
        }

        bool BidirectionalSearch(int iNo)
        {
            bool bFlag = false;
            int iStart = 0;
            int iEnd = iSize-1;

            for(iStart = 0 , iEnd = iSize-1 ; iStart <= iEnd ;iStart++,iEnd--)
            {
                if((Arr[iStart] == iNo) || (Arr[iEnd] == iNo) )
                {
                    bFlag = true;
                    break;
                }
            }
            return bFlag;
        }
};

int main()
{   
    int iValue = 0;
    bool bRet = false;

    cout<<"Enter the number of elements : \n";
    cin>>iValue;

    ArrayX aobj(iValue);

    aobj.Accept();

    aobj.Display();

    if(aobj.LinearSearch(21))
    {
        cout<<"Element is present.\n";
    }
    else
    {
        cout<<"Element not found.\n";
    }

    if(aobj.BidirectionalSearch(21))
    {
        cout<<"Element is present.\n";
    }
    else
    {
        cout<<"Element not found.\n";
    }

    return 0;
}

/*

    Arr     |   100 |   --> 11 | 21 | 51 | 101
    iSize   |   4   |


*/

//WC TC : O(n/2)

