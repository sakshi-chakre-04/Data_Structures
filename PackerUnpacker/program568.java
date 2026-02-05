import java.util.Scanner;
import java.io.*;

public class Program568
{
    public static void main(String[] args) throws Exception
    {
        boolean bRet = false;
        String FileName = null;
        FileReader frobj = null;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of file");
        FileName = sobj.nextLine();

        File fobj = new File(FileName);

        if(fobj.exists())
        {
           System.out.println("File Name :"+fobj.getName());
           System.out.println("File Path :"+fobj.getAbsolutePath());   
           System.out.println("File Size :"+fobj.length()); 
        }
        else
        {
            System.out.println("There is  no such file...");
        }
        
        sobj.close();
    }
}