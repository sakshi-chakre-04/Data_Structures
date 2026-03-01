import java.util.*;

class program833
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0, iDigit = 0, iSum = 0, iProduct = 1, iTemp = 0;

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();
        iTemp = iNo;
 
        // Spy number: sum of digits equals product of digits
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + iDigit;
            iProduct = iProduct * iDigit;
            iNo = iNo / 10;
        }

        if(iSum == iProduct)
        {
            System.out.println(iTemp + " is Spy Number");
        }
        else
        {
            System.out.println(iTemp + " is not Spy Number");
        }
    }
}
