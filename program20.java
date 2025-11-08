// Better Approach

public class program20
{    
    public static void Display()   
    {
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
    }
    public static void main(String[] args) 
    {
       Display();      // naked call
    }
}

/*
    ✅ Reason why this works:

Yahan Display() method static hai
aur main() method bhi static hai.

Toh dono same level par hain — matlab class ke object ki zarurat nahi hai.

🧠 Static ka matlab:

static keyword ka matlab hota hai —
“ye method class se belong karta hai, kisi particular object se nahi.”

Toh hum ise directly call kar sakte hain, jaise:

Display();         // Naked call
// or
program20.Display();  // Class name ke sath bhi call kar sakte ho


Dono sahi hain ✅

📘 “Naked call” ka matlab:

“Naked call” ka simple matlab hota hai —
method ko seedha call karna,
bina kisi object ya class name ke likhe hue.

Jaise yahaan:

Display();


Ye ek “naked call” hai.

Agar likhte:

program20.Display();


Toh ye qualified call hoti.

💡 In short (Hinglish me):

Pehle wale program me error isliye aaya tha kyunki tum static ke andar non-static method call kar rahi thi.
Ab dono methods static hain, isliye class ke object ki zarurat nahi —
isiliye ye better approach hai, aur “naked call” allowed hai. 🎯
 */
