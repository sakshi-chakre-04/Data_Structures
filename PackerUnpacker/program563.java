import java.util.*;
import java.io.*;

class program563
{
    public static void main(String args[]) throws IOException
    {
        boolean bRet = false;
        String FileName = null;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of File : ");
        FileName = sobj.nextLine();

        FileReader frobj = new FileReader(FileName);

        frobj.close();
        sobj.close();
    }
}