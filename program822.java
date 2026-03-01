import java.util.*;

class program822
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        int x = 0 , y = 0 , i = 0, iPow = 1;

        System.out.println("Enter base : ");
        x = sobj.nextInt();

        System.out.println("Enter exponent : ");
        y = sobj.nextInt();

        // x = 5 , y = 3

        iPow = 1;
        while(y != 0)
        {
            iPow = iPow * x;
            y--;
        }

        System.out.println("Result : " + iPow);

    }
}
