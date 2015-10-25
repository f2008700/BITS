import java.net.*;
import java.io.*;
import java.sql.*;

public class finished {
	public static void main(String args[]) throws Exception
	{	int c;
		System.out.println("===Content===");
		System.setProperty("http.proxyHost","10.1.1.25");
      	System.setProperty("http.proxyPort","8090");
      	
		URL hp=new URL("http://w3schools.com");
		URLConnection hpCon=hp.openConnection();
		
		int len = hpCon.getContentLength();
		if(len!=0)
		{	System.out.println("===Content===");
			InputStream input=hpCon.getInputStream();
			//Create object for the file
			OutputStream f0 = new FileOutputStream("file1.txt");
			while(((c=input.read())!=-1))
			{	f0.write((char) c);
			}
			input.close();
			f0.close();
		}
		else
		{	System.out.println("No content available.");
		}
		// Main.java
		String ss="file1.txt";
		File file = new File(ss);						// create a file handle to read the contents of the file..
		if (!file.exists()) 
		{	System.out.println(ss + " does not exist.");
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
			String s2 = "http://w3schools.com";	
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
					{	s2="http://w3schools.com";
						s2=s2.concat(s1);
						s1=s2;
					//	System.out.println(s1);
					}
					else if(!(s1.startsWith("http://")))
					{	s2="http://w3schools.com/";
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
		// Get all rows code starts here
		
		
		System.out.println("Getting All Rows from a table!");
		Connection con=null;
		String url="jdbc:mysql://localhost:3306/";
		String db="crawler";
		String driver="com.mysql.jdbc.Driver";
		String user="vikas";
		String pass="vikas";
		try{
			Class.forName(driver).newInstance();
			con = DriverManager.getConnection(url+db, user, pass);
			try{
				Statement st = con.createStatement();
				ResultSet res = st.executeQuery("SELECT * FROM  link");
				System.out.println("Link Number: " + "\t" + "Link: ");
				while (res.next()) 
				{	i = res.getInt("id");
					String s = res.getString("hyperlink");
					try
					{	System.out.println("===Content===");
						System.out.println(s);
						URL hp1=new URL(""+s+"");
						URLConnection hp1Con=hp1.openConnection();
						len = hp1Con.getContentLength();
						if(len!=0)
						{	System.out.println("===Content===");
							InputStream input=hp1Con.getInputStream();
							//Create object for the file
							OutputStream f0 = new FileOutputStream(""+i+".txt");
							while(((c=input.read())!=-1))
							{	f0.write((char) c);
							}
							input.close();
							f0.close();
						}
						else
						{	System.out.println("No content available.");
						}
					}catch(FileNotFoundException e)
					{	System.out.println("The problem is this"+e);
						
					}
					
				//	System.out.println(i + "\t\t" + s);
				}
				con.close();
			}
			catch (SQLException s){
				System.out.println("SQL code does not execute.");
			}		
		}
		catch (Exception e){
			e.printStackTrace();
		}
	}	
}