import java.util.*;
import java.io.*;

class program565
{
    public static void main(String args[]) throws IOException
    {
        boolean bRet = false;
        String FileName = null;
        FileReader frobj = null;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of File : ");
        FileName = sobj.nextLine();

        File fobj = new File(FileName);

        if(fobj.exists())
        {
            frobj = new FileReader(FileName);

            int iRet = 0;
            
            iRet = frobj.read();
            if(iRet != -1)
            {
                System.out.println((char)iRet);
            }
            
            iRet = frobj.read();
            if(iRet != -1)
            {
                System.out.println((char)iRet);
            }
            
            iRet = frobj.read();
            if(iRet != -1)
            {
                System.out.println((char)iRet);
            }
        }
        else
        {
            System.out.println("There is no such file :( ");
        }

        if(frobj != null)
        {
            frobj.close();
        }

        sobj.close();
    }
}