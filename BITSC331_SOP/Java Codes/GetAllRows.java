import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.net.URL;
import java.net.URLConnection;
import java.sql.*;

public class GetAllRows{
	public static void main(String[] args) {
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
			System.out.println("dfgfgd"+url+db);
			try{
				Statement st = con.createStatement();
				ResultSet res = st.executeQuery("SELECT * FROM  link");
				System.out.println("Link Number: " + "\t" + "Link: ");
				while (res.next()) 
				{	int i = res.getInt("id");
					String s = res.getString("hyperlink");
					try
					{	int c;
						System.out.println("===Content===");
						System.setProperty("http.proxyHost","10.1.1.26");
				      	System.setProperty("http.proxyPort","8080");
				      	
						URL hp=new URL(""+s+"");
						URLConnection hpCon=hp.openConnection();
						int len = hpCon.getContentLength();
						if(len!=0)
						{	System.out.println("===Content===");
							InputStream input=hpCon.getInputStream();
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