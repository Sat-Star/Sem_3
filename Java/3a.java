import java.util.Scanner;
public class Sort 
{
  
void sortAscend (int a[], int n)
{
for(int i=0;i<n-1;i++)
 for(int j=0;j<n-1;j++)
 if(a[j] > a[j+1])
 {
 int temp = a[j];
 a[j] = a[j+1];
 a[j+1] = temp;
 }
}
  
void sortDescend (int a[], int n)
{
for(int i=0;i<n-1;i++)
 for(int j=0;j<n-1;j++)
 if(a[j] < a[j+1])
 {
 int temp = a[j];
 a[j] = a[j+1];
 a[j+1] = temp;
 }
}
  
void printArray (int a[], int n)
{
for (int i=0;i<n;i++)
System.out.println (a[i]+" ");
}
}


//main class
class SortRun
{
public static void main (String args[])
{
int n;
Scanner sc = new Scanner (System.in);
Sort s = new Sort ();
System.out.println ("Enter the no. of Elements");
n = sc.nextInt();
int array[] = new int [5];
System.out.println ("Enter "+n+" Integers");
for (int i=0;i<n;i++)
{
try
{
array[i] = sc.nextInt();
}
catch (ArrayIndexOutOfBoundsException e)
{
System.out.println ("Index out of Bounds "+e);
System.exit(0);
}
}
System.out.println ("Entered Elements are");
s.printArray(array, n);
System.out.println ("Ascending Order:");
s.sortAscend(array, n);
s.printArray(array, n);
System.out.println ("Descending Order:");
s.sortDescend(array, n);
s.printArray(array, n);
}
}
