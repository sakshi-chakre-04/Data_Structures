import java.util.*;

class program836
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0, iCount = 0, iTemp = 0, iSum = 0, iDigit = 0;

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();// 8

        iTemp = iNo ;
        
        while(iNo != 0)
        {
            iCount++;
            iNo = iNo / 10;
        }

        iNo = iTemp ;

        while(iNo != 0)
        {
            iDigit = iNo % 10;
            iSum = iSum + ((int)Math.pow(iDigit,iCount));
            iCount--;
            iNo = iNo / 10;
        }

        if(iSum == iTemp)
        {
            System.out.println(iTemp + " is Disarium Number");
        }
        else
        {
            System.out.println(iTemp + " is not Disarium Number");
        }
    }
}
