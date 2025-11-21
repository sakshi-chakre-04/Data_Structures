/*
    input : 8
    output : z   y   x   w   v   u   t   s
    index  : 1   2   3   4   5   6   7   8
*/   

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
        char ch = 'z';

        for(iCnt = iNo ; iCnt >= 1 ; iCnt--,ch--)
        { 
            System.out.printf("%c\t",ch);
        }
        System.out.println();
    }
}

class program178
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

