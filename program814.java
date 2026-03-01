import java.util.*;

class program814
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iNo = 0;

        System.out.println("Enter Number : ");
        iNo = sobj.nextInt();

        while(iNo != 0)
        {
            int iDigit = iNo % 10;
            System.out.println(iDigit);
            iNo = iNo / 10;   
        }
    }
}