import java.util.*;

class program828
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();

        int iDigit = 0, iTemp = 0, iSum = 0;
        
        iTemp = iNo;

        // Harshad number: sum of digits should divide the original number
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iNo = iNo / 10;
        }
        
        if(iTemp % iSum == 0)
        {
            System.out.println(iTemp + " is a Harshad number");
        }
        else
        {
            System.out.println(iTemp + " is not a Harshad number");
        }
        
    }
}
