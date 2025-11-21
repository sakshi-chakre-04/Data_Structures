/*
    input : 5
    output : a   b   c   d   e
    index  : 1   2   3   4   5
    ascii  :97  98  99  100 101
*/   

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
        // char ch = 'a';
        int i = 96;

        for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
        {
            System.out.printf("%d\t",i+iCnt);// java also has printf function 
        }
        System.out.println();
    }
}

class program171
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

// don't use ascii values in the code evee,reduces code readability