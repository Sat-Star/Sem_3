/*Write a Java program that prints all real solutions to the quadratic equation ax2 + bx + c = 0.
Read in a, b, c and use the quadratic formula. 
If the discriminate b2-4ac is negative, display a
message stating that there are no real solutions*/



//create class named QuadraticEquation
import java.util.Scanner;
public class QuadraticEquation {

	int a, b, c;
	double root1, root2, d;
	Scanner s = new Scanner(System.in);
	
	void input()
	{
	System.out.println("Quadratic equation is in the form : ax^2 + bx + c");
	System.out.print("Enter a:");
	a = s.nextInt();
	System.out.print("Enter b:");
	b = s.nextInt();
	System.out.print("Enter c:");
	c = s.nextInt();
	}
	
	void discriminant() {
	d= (b*b)-(4*a*c);
	}
	
	void calculateRoots() {
		
	if(d>0)
	{
	System.out.println("Roots are real and unequal");
	root1 = ( - b + Math.sqrt(d))/(2*a);
	root2 = (-b - Math.sqrt(d))/(2*a);
	System.out.println("First root is:"+root1);
	System.out.println("Second root is:"+root2);
	}
	
	else if(d == 0)
	{
	System.out.println("Roots are real and equal");
	root1 = (-b+Math.sqrt(d))/(2*a);
	System.out.println("Root:"+root1);
	}
	
	else
	{
	System.out.println("No real solutions. Roots are imaginary");
	}
	}

}


//create new main class with the name TestQE

public class TestQE {

	public static void main(String[] args) {
		QuadraticEquation qe = new QuadraticEquation();
		qe.input();
		qe.discriminant();
		qe.calculateRoots();
	}

}
