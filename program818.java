import java.util.*;

class program818
{
    public static boolean CheckStrong(int iNo)
    {
        int iFact = 1,i = 0, iTemp = 0 , iSum = 0, iDigit = 0;

        iTemp = iNo;// to store the value to compare at end

        // 145
        while(iNo != 0)
        {
            iDigit = iNo % 10;
            
            // Logic 
            for(iFact = 1 ,i = 1;i <= iDigit ;i++)
            {
                iFact = iFact * i;
            }
            iSum = iSum + iFact;
            iNo = iNo / 10;   
        }
        
        return (iSum == iTemp);
    }
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();

        boolean bRet = false ;

        bRet = CheckStrong(iNo);

        if(bRet)
        {
            System.out.println(iNo + " is a Strong Number");
        }
        else
        {
            System.out.println(iNo + " is not a Strong Number");
        }
        
        sobj.close();
    }
}
// Algorithm
// store the value for final compare , concept of digit and factorial