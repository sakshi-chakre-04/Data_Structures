import java.util.*;
import java.io.*;

class program558    
{
    public static void main(String args[]) throws IOException
    {
        String FileName = null;
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of File : ");
        FileName = sobj.nextLine();

        File fobj = new File(FileName);

        boolean bRet = fobj.createNewFile();

        if(bRet == true)
        {
            System.out.println("File gets created successfully");
        }
        else
        {
            System.out.println("Unable to create the file");
        }
        sobj.close();
    }
}