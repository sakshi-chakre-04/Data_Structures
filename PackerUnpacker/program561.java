import java.util.*;
import java.io.*;

class program561
{
    public static void main(String args[]) throws IOException
    {
        boolean bRet = false;
        String FileName = null;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of File : ");
        FileName = sobj.nextLine();

        FileWriter fwobj = new FileWriter(FileName);
        
        sobj.close();
    }
}