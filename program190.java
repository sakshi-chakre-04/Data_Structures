/*
    iRow : 4
    iCol : 4

    #   #   #   #  
    $   #   #   #
    $   $   #   #   
    $   $   $   #    
     
    Diagonal pattern : applicaple only for matrix..
*/   

import java.util.Scanner;

class Pattern
{
    public void Display(int iRow, int iCol)
    {
        int i = 0, j = 0;
        // filter for square matrix
        if(iRow != iCol)
        {
            System.out.println("Invalid Input");
            System.out.println("Row number and column number should be same .");

            return;
        }
    

        for(i = 1 ; i <= iRow ; i++)
        {
            for(j = 1 ; j <= iCol ; j++)  
            {
                if(i>j)
                {
                    System.out.print("$\t");
                }
                else
                {
                    System.out.print("#\t");
                }
            }
            System.out.println();
        }
    }
}

class program190
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);
        int iValue1 = 0, iValue2 = 0;

        System.out.println("Enter the number of rows : ");
        iValue1 = sobj.nextInt();

        System.out.println("Enter the number of columns : ");
        iValue2 = sobj.nextInt();

        Pattern pobj = new Pattern();
        pobj.Display(iValue1, iValue2);
    }
}

// as i involved so logic apply on row