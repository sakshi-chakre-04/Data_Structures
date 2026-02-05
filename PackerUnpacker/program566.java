import java.util.*;
import java.io.*;

class program566
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

            char Buffer[] = new char[50];

            frobj.read(Buffer,0,13);

            System.out.println("Data from file : "+(String)Buffer); //ERROR
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