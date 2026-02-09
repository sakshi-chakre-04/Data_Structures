import java.util.Scanner;

class program633
{
    public static void main(String A[])
    {
        int iNo = 0, iMask = 0x1, iResult = 0, iPos = 0;

        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter number : ");
        iNo = sobj.nextInt();

        System.out.println("Enter position : ");
        iPos = sobj.nextInt();

        iMask = iMask << (iPos - 1);
        
        iResult = iNo & iMask;

        if(iResult == iMask)
        {
            System.out.println(iPos+"th Bit is ON");
        }
        else
        {
            System.out.println(iPos+"th Bit is OFF");
        }
    }
}
/*
The code (for reference)
int iNo = 0, iMask = 0x1, iResult = 0, iPos = 0;


iNo → the number you enter
iPos → which bit you want to check
iMask → used to isolate that bit
iResult → result after AND operation

Example input

Let’s assume the user enters:

Enter number : 10
Enter position : 2

Step 1: Convert number to binary
iNo = 10
Binary of 10 = 0000 1010
                ↑ ↑
Position:       4 2


Bit positions are counted from right to left, starting at 1:

Position:  4 3 2 1
Bits:      1 0 1 0

Step 2: Initial mask value
iMask = 0x1;


0x1 in binary is:

0000 0001

Step 3: Shift the mask
iMask = iMask << (iPos - 1);


Since iPos = 2:

iMask = 0000 0001 << 1
       = 0000 0010


So the mask now targets bit position 2.

Step 4: AND operation
iResult = iNo & iMask;


Binary operation:

iNo     = 0000 1010
iMask   = 0000 0010
-------------------
Result  = 0000 0010

Step 5: Compare result
if(iResult == iMask)


Here:

iResult = 2
iMask   = 2


They are equal ✅
So the bit is ON.

Output
2th Bit is ON

 */