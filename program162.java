// Input : 6
// Output :     1    *    2    *    3    *    
//Counter :     1    2    3    4    5    6      

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
        int iCount = 0;
    
        iCount = 1;
        for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
        {
            if((iCnt % 2) == 0)
            {
                System.out.print("*\t");
            }
            else
            {
                System.out.print(iCount+"\t");
                iCount++;
            }
        }
        System.out.println();
    }
}

class program162
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
// if take iNo/2 then not work for odd 7 doesn't have 7 at end 
// you can also generate a mathematical equation -> try yourself (in next code)