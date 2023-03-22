import javax.swing.*;
import java.awt.event.*;
public class StringOperations implements ActionListener {
JTextField tf1,tf2,tf3;
JButton b1,b2,b3,b4;
JLabel l1,l2;
StringOperations(){
JFrame f= new JFrame();
tf1=new JTextField();
tf1.setBounds(80,80,150,20);
tf2=new JTextField();
tf2.setBounds(80,130,200,20);
tf2.setEditable(false);
l1=new JLabel("Enter text");
l1.setBounds(50,50, 100,30);
l2=new JLabel("Result");
l2.setBounds(50,100,100,30);
b1=new JButton("Find Mid Character");
b1.setBounds(50,200,250,50);
b2=new JButton("Check Palindrome");
b2.setBounds(320,200,250,50);
b3=new JButton("Count Vowels");
b3.setBounds(50,300,250,50);
b4=new JButton("Find length");
b4.setBounds(320,300,250,50);
b1.addActionListener(this);
b2.addActionListener(this);
b3.addActionListener(this);
b4.addActionListener(this);
f.add(tf1);
f.add(tf2);
f.add(l1);
f.add(l2);
f.add(b1);
f.add(b2);
f.add(b3);
f.add(b4);
f.setSize(650,450);
f.setLayout(null);
f.setVisible(true);
}
public void actionPerformed(ActionEvent e) {
String s=tf1.getText();
int length;
length = s.length();
if(e.getSource()==b1) {
int mid;
mid = length/2;
if(length%2 != 0)
tf2.setText("The mid character is "+s.charAt(mid));
else
tf2.setText("The middle characters are "+s.charAt(mid-1)+" "+s.charAt(mid));
}
else if(e.getSource()==b2) {
String reverse = "";
for(int i = length-1; i>=0; i--) {
reverse = reverse + s.charAt(i);
}
if (s.equals(reverse))
tf2.setText("Entered string is a palindrome.");
else
tf2.setText("Entered string is not a palindrome.");
}
else if(e.getSource()==b3) {
int count = 0;
char ch;
for(int i = 0; i<s.length(); i ++)
{
ch = s.charAt(i);
if (ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' ||
ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U')
count ++;
}
tf2.setText("The number of vowels: "+count);
}
else if(e.getSource()==b4) {
int i=0;
while (true)
{
try
{
s.charAt(i);
i++;
}
catch(StringIndexOutOfBoundsException ex)
{
tf2.setText("The length of string is "+i);
break;
}
}
}
}
public static void main(String[] args) {
new StringOperations();
}
}
