// Input : 6
// Output : 1  *   3   *   5

import java.util.Scanner;

class Pattern
{
    public void Display(int iNo)
    {
        int iCnt = 0;
    
        for(iCnt = 1 ; iCnt <= iNo ; iCnt++)
        {
            if((iCnt % 2) == 0)
            {
                System.out.print("*\t");
            }
            else
            {
                System.out.print(iCnt+"\t");
            }
        }
        System.out.println();
    }
}

class program154
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

// combination + condition code
// the logic of icnt + 2 doesn't work for odd , as display 1 extra star
