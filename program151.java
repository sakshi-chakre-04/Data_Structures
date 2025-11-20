class Pattern
{
    public void Display()
    {
        System.out.println("Inside Display");
        // logic of pattern printing
    }
}

class program151
{
    public static void main(String[] args) 
    {
        Pattern pobj = new Pattern();
        pobj.Display();
    }
}

// if make the func. i.e static then call by class name
// as start , end , displacement known -> for loop , can use while also