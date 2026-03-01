import java.util.*;

class program831
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();

        int iDigit = 0, iSquare = 0, iSum = 0;
        
        iSquare = iNo * iNo;

        // Neon number: sum of digits of square equals original number
        while(iSquare != 0)
        {
            iDigit = iSquare % 10;
            iSum = iSum + iDigit;
            iSquare = iSquare / 10;
        }
        
        if(iSum == iNo)
        {
            System.out.println(iNo + " is a neon number");
        }
        else
        {
            System.out.println(iNo + " is not a neon number");
        }
        
    }
}
