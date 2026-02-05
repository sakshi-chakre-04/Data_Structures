import java.util.*;//Scanner
import java.io.*;//File

class program557
{
    public static void main(String args[]) throws IOException
    {
        File fobj = new File("Demo.txt");

        boolean bRet = fobj.createNewFile();

        if(bRet == true)
        {
            System.out.println("File gets created successfully");
        }
        else
        {
            System.out.println("Unable to create the file");
        }
    }
}