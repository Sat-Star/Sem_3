public class ThreadOne extends Thread
{
public void run ()
{
try
{
for (int i=0;i<4;i++)
{
Thread.sleep(1000);
System.out.println ("Good Morning");
}
}
catch (InterruptedException e)
{
System.out.println ("Thread Interrupted");
}
}
}



public class ThreadTwo extends Thread {
	public void run()
	{
		try {
			for(int i=0;i<4;i++)
			{
				Thread.sleep(2000);
				System.out.println("HEllo");
			}
		}
			catch (InterruptedException e)
			{
				System.out.println("Thread interrupted");
			}
		}
	}



public class ThreadThree extends Thread
{
public void run ()
{
try
{
for (int i=0;i<4;i++)
{
Thread.sleep(3000);
System.out.println ("Welcome");
}
}
catch (InterruptedException e)
{
System.out.println ("Thread Interrupted");
}
}
}




public class ProgramMultiThread {

	public static void main(String[] args) {
		ThreadOne t1 = new ThreadOne();
		ThreadTwo t2 = new ThreadTwo();
		ThreadThree t3 = new ThreadThree();
		
		t1.start();
		t2.start();
		t3.start();
		
		try
		{
			t1.join();
			t2.join();
			t3.join();
		}
		catch(InterruptedException e)
		{
			System.out.println("Thread interrupted");
		}
		System.out.println("Main thread exits");
	}

}
