import java.util.Scanner;

class ArrayX
{
    public void Display(int Brr[])
    {
        int i = 0;
        for(i = 0; i < Brr.length ; i++)
        {
            System.out.println(Brr[i]);
        }
    }
}

public class program99
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int iSize = 0;

        System.out.println("Enter the size of array : ");
        iSize = sobj.nextInt();

        int Arr[] = new int[iSize];

        System.out.println("Enter the elements : ");
        
        Arr[0] = sobj.nextInt();
        Arr[1] = sobj.nextInt();
        Arr[2] = sobj.nextInt();
        Arr[3] = sobj.nextInt();
        Arr[4] = sobj.nextInt();

        ArrayX aobj = new ArrayX();
        aobj.Display(Arr);

        //  Important
        aobj = null;
        Arr = null;
        sobj = null;

        System.gc();
    }    
}
