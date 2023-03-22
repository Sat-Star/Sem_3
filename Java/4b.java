//new class
import java.util.Scanner;
abstract class Solid
{
double r;
double h;
abstract void SArea ();
abstract void Vol ();
void input ()
{
Scanner sc = new Scanner (System.in);
System.out.println ("Enter the Radius");
r = sc.nextDouble ();
System.out.println ("Enter the Height");
h = sc.nextDouble ();
}
}


class Cylinder extends Solid 
{
void SArea ()
{
double sarea = (2*3.14*r*h) + (2*3.14*r*r);
System.out.println ("Surface Area of Cylinder = "+sarea);
}
void Vol()
{
double vol = 3.14*r*r*h;
System.out.println ("Volume of Cylinder = "+vol+"\n");
}
}



class Cone extends Solid 
{
void SArea ()
{
double sarea = 3.14*r*(r+Math.sqrt(r*r+h*h));
System.out.println ("Surface Area of Cone = "+sarea);
}
void Vol ()
{
double vol = (3.14*r*r*h) / 3;
System.out.println ("Volume of Cone = "+vol+"\n");
}
}



class Sphere extends Solid 
{
void SArea ()
{
double sarea = 4*3.14*r*r;
System.out.println ("Surface Area of Sphere = "+sarea);
}
void Vol ()
{
double vol = (4/3)*3.14*r*r*r;
System.out.println ("Volume of Sphere = "+vol+"\n");
}
}



class SRun 
{
public static void main (String args[])
{
Solid s;
Cylinder cy = new Cylinder ();
s = cy;
s.input ();
s.SArea ();
s.Vol ();
Cone co = new Cone ();
s = co;
s.input ();
s.SArea ();
s.Vol ();
Sphere sp = new Sphere ();
s = sp;
s.input ();
s.SArea ();
s.Vol ();
}
}
