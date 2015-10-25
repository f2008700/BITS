import java.io.*;
import java.sql.*;

public class Main 
{	public static void main(String[] args) 
	{	File file = new File(args[0]);							// create a file handle to read the contents of the file..
		if (!file.exists()) 
		{	System.out.println(args[0] + " does not exist.");
			return;
		}
		if (!(file.isFile() && file.canRead())) 
		{	System.out.println(file.getName() + " cannot be read from.");
			return;									
		}														// till here it just tries to open the file.				
		int i,al=0,id=0;										// to run the for loop. 
		int g=0;												// count the number of hyperlinks
		char pat[]={'<','a',' ','h','r','e','f','=','"'};		// to match the pattern with the <a href="
		
		try 
		{	FileInputStream fis = new FileInputStream(file);
			char current;										// to store each character from the file
			String s2 = "http://w3school.com";	
			while (fis.available() > 0) 
			{	current = (char) fis.read();					// start reading characters from the file
				for(i=0;((pat[i]==current) && (i<8));i++)		
				{	current = (char) fis.read();				// checking for the presence of <a href
				}
				if(i==8)
				{	g++;										// increment the counter -- the number of hyperlinks on that page
					String s1 = "";								// this string forms the hyperlink
					while((current = (char) fis.read())!='"')	// 
					{	s1=s1.concat(Character.toString(current)); 	// string formation - and it does not add prefix if the hyperlink is proper
					}												
					if(s1.startsWith("/"))							// Process the string to attach proper hyperlink to be stored in db	
					{	s2="http://w3school.com";
						s2=s2.concat(s1);
						s1=s2;
					//	System.out.println(s1);
					}
					else if(!(s1.startsWith("http://")))
					{	s2="http://w3school.com/";
						s2=s2.concat(s1);
						s1=s2;
					//	System.out.println(s1);
					}												// Processing ends here - properly
					// Connecting to the database..
					//System.out.println(s1);			
					System.out.println("Inserting values in Mysql database table!");
					Connection con = null;
					String url = "jdbc:mysql://localhost:3306/";
					String db = "crawler";
					String driver = "com.mysql.jdbc.Driver";
					try{
						Class.forName(driver);
						con = DriverManager.getConnection(url+db,"vikas","vikas");
						try{
							Statement st = con.createStatement();
							al = st.executeUpdate("INSERT link VALUES("+id+",'"+s1+"')");
							id++;
							System.out.println("1 row affected");
						}
						catch (SQLException s){
							System.out.println("SQL statement is not executed!");
						}
					}
					catch (Exception e){
						e.printStackTrace();
					}			
				}	
			}
		} catch (IOException e) 
		{	e.printStackTrace();
		}
		System.out.println(g);
	}
}