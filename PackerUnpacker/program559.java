import java.util.*;
import java.io.*;

class program559
{
    public static void main(String args[]) throws IOException
    {
        boolean bRet = false;
        String FileName = null;
        File fobj = null;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of File : ");
        FileName = sobj.nextLine();

        fobj = new File(FileName);

        bRet = fobj.exists();

        if(bRet == true)
        {
            System.out.println("File is already present");
        }
        else
        {
            bRet = fobj.createNewFile();

            if(bRet == true)
            {
                System.out.println("File gets created successfully");
            }
            else
            {
                System.out.println("Unable to create the file");
            }
        }
        
        sobj.close();
    }
}