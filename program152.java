// Input : 5
// Output : * * * * *

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
    
        for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
        {
            System.out.print("*\t");// use \t as onlt tab space changes from platform to platform
        }
        System.out.println();
    }
}

class program152
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

// Q. does it follow oop paradigms -> partial
// encapsulation , public -> yes but no characteristics
// Q. can you optimize this code ? -> no (as loop is needed)

