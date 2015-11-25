#include<stdio.h>

int main()
{
	char c,ifname[50],ofname[50], line[80];
	FILE *fin, *fout;
	printf("Enter the source and Destination file names\n");
	scanf("%s %s",ifname,ofname);

	fin=fopen(ifname,"r");
	fout=fopen(ofname,"w");
	while(!feof(fin))
	{
		fgets(line,80,fin);
		fputs(line,fout);
	}
	fclose(fin);
	fclose(fout);
	//fcloseall();
	
	return 0;
}
