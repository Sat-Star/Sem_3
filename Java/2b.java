

public class ComplexNumbers 
{
double r;
double i;
ComplexNumbers ()
{
r = 0;
i = 0;
}
ComplexNumbers (double var )
{
r = var;
i = 0;
}
ComplexNumbers (double var1,double var2)
{
r = var1;
i = var2;
}
ComplexNumbers (ComplexNumbers obj)
{
r = obj.r;
i = obj.i;
}
void add (ComplexNumbers obj1,ComplexNumbers obj2)
{
r = obj1.r+obj2.r;
i = obj1.i+obj2.i;
System.out.println ("Sum = "+r+"+"+i+"i");
}
void sub (ComplexNumbers obj1,ComplexNumbers obj2)
{
r = obj1.r-obj2.r;
i = obj1.i-obj2.i;
System.out.println ("Difference = "+r+"-"+i+"i");
}
}


//main class
class CNRun
{
public static void main (String args[])
{
ComplexNumbers c1 = new ComplexNumbers ();
ComplexNumbers c2 = new ComplexNumbers (10);
ComplexNumbers c3 = new ComplexNumbers (20,30);
ComplexNumbers c4 = new ComplexNumbers (c1);
c1.add (c1,c2);
c2.sub (c3,c4);
}
}
