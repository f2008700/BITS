import java.net.*;
import java.io.*;

class UCDemo
{	public static void main(String args[]) throws Exception
	{	int c;
		System.out.println("===Content===");
		System.setProperty("http.proxyHost","10.1.1.26");
      	System.setProperty("http.proxyPort","8080");
      	
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
	}
}