// Best Approach

class Marvellous
{
    public void Display()   
    {
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
        System.out.println("Jay Ganesh...");
    }
}

public class program21
{    
    
    public static void main(String[] args) 
    {
       Marvellous mobj = new Marvellous();
       mobj.Display();   // OO call
    }
}

/*
 🧠 Step-by-Step Explanation
🩵 1. Proper Object-Oriented Programming (OOP) style

Yahan Display() ek normal (non-static) method hai
aur use class ke object (mobj) ke through call kiya gaya hai —
yeh OOP principle follow karta hai ✅

👉 Matlab — data aur behaviour (methods) class ke object ke saath jude hain.
Ye encapsulation aur reusability ke concepts ko support karta hai.

💚 2. No unnecessary use of static

Pichle code me (program20), humne static lagaya tha sirf convenience ke liye —
par agar har method ko static bana doge,
toh class ke object ka koi importance hi nahi bachega,
aur OOP ka concept khatam ho jaayega ❌

Static methods mainly utility ke liye hote hain
(jaise Math.max(), Math.sqrt() etc.),
lekin jab behavior kisi particular object se linked ho,
tab non-static method use karna best hota hai.

🩷 3. High Reusability & Extensibility

Ab Marvellous class ko tum multiple programs me reuse kar sakti ho.
Example:

Marvellous obj1 = new Marvellous();
Marvellous obj2 = new Marvellous();
obj1.Display();
obj2.Display();


Har object alag instance represent karega.
Ye scalable design hota hai — large projects me useful.

💛 4. OO Call (Object-Oriented Call)

mobj.Display(); ko hum OO Call (Object-Oriented Call) bolte hain.
Ye clear karta hai ki Display() kis object se belong karta hai.
Yani ye clean, readable aur professional code style hai 💼

🏆 Summary: Why “Best Approach”
Approach	Description	Reusability	OOP Principle	Practical Use
program19	Static → Non-static call ❌	❌	❌	Wrong
program20	Both static → Works ✅	⚠️ Limited	❌	Small demo apps
program21	Object-based ✅	✅ High	✅ True OOP	Best Practice
🗣️ In short (Hinglish me):

Ye “Best Approach” isliye hai kyunki ye OOP concept follow karta hai,
code reusable, maintainable, aur professional banata hai.
static sirf jab zarurat ho tab hi use karte hain,
warna hamesha object ke through method call karna best practice hota hai. ✅
 */
