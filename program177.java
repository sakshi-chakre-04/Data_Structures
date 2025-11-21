/*
    input : 8
    output : 1   A   3   B   5   C   7   D
    index  : 1   2   3   4   5   6   7   8
*/   

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
        char ch = 'A';

        for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
        { 
            if((iCnt%2)==0)
            {
                System.out.printf("%c\t",ch++);
            }
            else
            {
                System.out.print(iCnt+"\t");
            }
        }
        System.out.println();
    }
}

class program177
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

