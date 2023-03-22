import java.util.Scanner;
public class EmployeeSalary {

	public static void main(String[] args) {
		String name,id;
		double basic,DA,HRA,PF,IT,gross,net,deductions;
		double CCA=250,PT=100;
		
		Scanner s = new Scanner(System.in);
		System.out.println("Enter the name of Employee");
		name = s.nextLine();
		System.out.println("Enter the ID of Employee");
		id = s.nextLine();
		System.out.println("Enter the basic salary of Employee");
		basic = s.nextDouble();
		
		DA = 0.4*basic;
		HRA = 0.2*basic;
		PF = 0.1*basic;
		
		gross = basic+DA+HRA+CCA;
		IT = 0.1*gross;
		deductions = PF+PT+IT;
		net = gross - deductions;
		
		System.out.println("The Gross salary of Employee "+name+" and ID "+id+" is "+gross);
		System.out.println("The Net salary of Employee "+name+" and ID "+id+" is "+net);
		s.close();

	}
}
