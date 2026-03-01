import java.util.*;

class program837
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0, iCount = 0, iTemp = 0, iCube = 0, iDeno = 0;

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();

        iTemp = iNo;
        
        while(iNo != 0)
        {
            iCount++;
            iNo = iNo / 10;
        }

        iNo = iTemp;
        iCube = iNo * iNo * iNo;
        iDeno = (int)Math.pow(10, iCount);

        if(iCube % iDeno == iTemp)
        {
            System.out.println(iTemp + " is Trimorphic Number");
        }
        else
        {
            System.out.println(iTemp + " is not Trimorphic Number");
        }
    }
}
