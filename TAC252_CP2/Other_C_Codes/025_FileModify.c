/*
This program is to copy one file into another file.

This program uses command line arguments.
To run the exe created by compiling this program,
the usage should be...

"[exe name] [file1] [file2]"

while using vc++ IDE, the command arguments are set 
from the project options.
From menu, select the following...

project -> [project] properties -> configuration properties

you should see "Debugging".  click on that
you should see "Command Arguments".  type next to it...
[file1] [size]
*/

# include <stdio.h>
# include <stdlib.h>

int main(int count, char **arguments)
{
	FILE *fp;
	char *buffer;
	unsigned int fileSize;
	int loop;

	if(count != 3)
	{
		printf("Usage: [exe] [file1] [size]\n");
		return 1;
	}
	
	fp = fopen(arguments[1], "rw");
	if(!fp)
	{
		printf("Unable to open the file...%s", arguments[1]);
		return 2;
	}
	fseek(fp, 0, SEEK_END);
	fileSize = ftell(fp);
	
	buffer = (char*) malloc(fileSize);
	if(!buffer)
	{
		printf("Unable to allocate memory");
		return 3;
	}
	
	fread(buffer, fileSize, 1, fp);

	count = atoi(arguments[2]);
	for(loop = 0; loop < count/2; loop++)
	{
		char c;
		c = buffer[loop];
		buffer[loop] = buffer[count - loop - 1];
		buffer[count - loop - 1] = c;
	}
	
	fseek(fp, 0, SEEK_END);
	fwrite(buffer, fileSize, 1, fp);
	fclose(fp);
	printf("File Modification is successful\n");

	return 0;

}
