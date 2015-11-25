#include<stdio.h>

int main()
{
	char c,ifname[50],ofname[50];
	FILE *fin, *fout;
	printf("Enter the source and Destination file names\n");
	scanf("%s %s",ifname,ofname);

	fin=fopen(ifname,"r");
	fout=fopen(ofname,"w");
	//while((c=fgetc(fin))!=EOF)
	while((c=getc(fin))!=EOF)
	{
		fputc(c,fout);
	}
	fclose(fin);
	fclose(fout);
	//fcloseall();
	
	return 0;
}
