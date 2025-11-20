// Input : 5
// Output :    -5   -4   -3   -2   -1    0    1     2     3     4     5
//Counter :     1    2    3    4    5    6    7     8     9     10    11    

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
    
        for(iCnt = -iNo ; iCnt <= iNo ; iCnt++)
        {
            System.out.print(iCnt+"\t");
        }
        System.out.println();
    }
}

class program161
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

// if 2 for loops -> for i/p 5 , 10 times loop run : i.e when 1(-5 to 0) stop 2 start(1 to 5)
// conditions to check the merger of loops
// i.   the end of 1st must match the start of 2nd 
// ii. counter ++ check

/* 
   TC of program 160 and 161 of both is O(2N)
   the loop runs -4 -3 -2 -1 0 1 2 3 4 
   9 times i.e. nearby 10 (i.e. 2 times...) so the result is 2N 
*/
