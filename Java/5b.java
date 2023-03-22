import java.io.*;

public class IO {

	public static void main(String[] args) throws IOException,FileNotFoundException {
		// TODO Auto-generated method stub
		char c;
		int i;
		FileInputStream fin = new FileInputStream("Test1.txt");
		FileOutputStream fout = new FileOutputStream("Test1.txt");
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("Enter characters, 'q' to quit.");
		do{
		c = (char) br.read();
		if(c != 'q') fout.write(c);
		} while(c != 'q');
		System.out.println("Contents of the file are");
		do{
		i = fin.read();
		if(i != -1) System.out.print((char) i);
		} while(i != -1);
		fin.close();
		fout.close();
	}

}



//don't forget to create Test1.txt in the same directory where your java file exists
