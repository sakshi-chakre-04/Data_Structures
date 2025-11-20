// Input : 6
// Output :     0    1    2    3    4    5     6
//Counter :     1    2    3    4    5    6     7

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
    
        for(iCnt = 0 ; iCnt <= iNo ; iCnt++)
        {
            System.out.print(iCnt+"\t");
        }
        System.out.println();
    }
}

class program159
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);
        int iValue = 0;

        System.out.println("Enter the frequency : ");
        iValue = sobj.nextInt();

        Pattern pobj = new Pattern();
        pobj.Display(iValue);
    }
}


// i.   start with negative
// ii.  displacement -> increment
// iii. hardcoded value of -1