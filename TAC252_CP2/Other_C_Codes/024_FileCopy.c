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
[file1] [file2]

*/
# include <stdio.h>
# include <malloc.h>

int main(int count, char **arguments)
{
	FILE *fp;
	char *buffer;
	unsigned int fileSize;

	if(count != 3)
	{
		printf("Usage: [exe] [file1] [file2]\n");
		return 1;
	}
	
	fp = fopen(arguments[1], "r");
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
	fclose(fp);

	fp = fopen(arguments[2], "w");
	if(!fp)
	{
		printf("Unable to open the file...%s", arguments[2]);
		return 4;
	}
	fwrite(buffer, fileSize, 1, fp);
	fclose(fp);
	printf("File copy is successful\n");

	return 0;

}