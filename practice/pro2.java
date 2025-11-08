package practice;
import java.util.Scanner;

public class pro2 
{
    public static void main(String[] args) 
    {
        int i = 0, j = 0 , ans = 0;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the first number : ");
        i = sc.nextInt();

        System.out.println("Enter the first number : ");
        j = sc.nextInt();

        ans = i + j;

        System.out.println("Addition is : " + ans);
    }    
}
