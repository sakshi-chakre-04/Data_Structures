class ArrayX
{
    public void Display(int Brr[])
    {
        int i = 0;
        for(i = 0; i < Brr.length ; i++)
        {
            System.out.println(Brr[i]);
        }
    }
}

public class program94
{
    public static void main(String[] args) 
    {
        int Arr[] = {10,20,30,40};

        ArrayX aobj = new ArrayX();
        
        aobj.Display(Arr);
    }    
}
