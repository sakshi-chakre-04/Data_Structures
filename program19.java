public class program19 
{   // private is allowed but blocks reusability 
    public void Display()   // not good practice but if less time
    {
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
    }
    public static void main(String[] args) 
    {
       //Display();       // ERROR 
    }
}

/*
        ⚠️ Error ka reason:

Display() ek non-static method hai.
Lekin tum use directly static method (main) ke andar call kar rahi ho.

👉 main() method static hota hai — iska matlab hai ki wo class ke object ke bina chal sakta hai.
Lekin Display() static nahi hai, matlab wo class ke object ke through hi call ho sakta hai.

🧠 Simple Explanation:

Static methods → class ke naam se directly call hote hain (without object).

Non-static methods → pehle class ka object banana padta hai, fir us object se call karte hain.

🚫 Isliye Error aata hai:
Display();  // ❌ compiler bolega: non-static method cannot be referenced from a static context

✅ Sahi Tarika:
public static void main(String[] args) 
{
    program19 obj = new program19();  // object create karo
    obj.Display();                     // ab method call karo
}

🗣️ In short (Hinglish me):

“Static method ke andar directly non-static method nahi call kar sakte,
kyunki non-static methods class ke object se jude hote hain,
aur static methods bina object ke chal jaate hain.
Toh compiler confuse ho jaata hai — kis object ka Display() call karu?”
 */