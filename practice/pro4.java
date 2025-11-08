package practice;

import java.util.Scanner;

public class pro4 {
    public static int Addition(int a, int b)
    {
        int sum = 0;
        sum = a + b;
        return sum;
    }
    public static void main(String[] args) 
    {
        int i = 0, j = 0 , ans = 0;
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the first number : ");
        i = sc.nextInt();

        System.out.println("Enter the first number : ");
        j = sc.nextInt();

        ans = Addition(i,j);

        System.out.println("Addition is : " + ans);
    }
}
