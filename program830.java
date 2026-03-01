import java.util.*;

class program829
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();

        int iDigit = 0, iTemp = 0, iRev = 0;
        
        iTemp = iNo;

        // Harshad number: sum of digits should divide the original number
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iRev = iRev * 10 + iDigit;
            iNo = iNo / 10;
        }
        
        if(iTemp == iRev)
        {
            System.out.println(iTemp + " is a palindrome number");
        }
        else
        {
            System.out.println(iTemp + " is not a palindrome number");
        }
        
    }
}
