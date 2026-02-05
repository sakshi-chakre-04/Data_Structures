import java.util.*;
import java.io.*;

class program560
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
            fobj.delete();
            System.out.println("File gets deleted");
        }
        else
        {
            System.out.println("There is no such file");
        }
        sobj.close();
    }
}