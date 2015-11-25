#include<stdio.h>

int main()
{
	char c,ifname[50],ofname[50];
	int a;
	float f;
	char str[50];
	FILE *fin, *fout;
	printf("Enter the source and Destination file names\n");
	scanf("%s %s",ifname,ofname);

	fin=fopen(ifname,"r");
	fout=fopen(ofname,"w");
	while(!feof(fin))
	{
		fscanf(fin,"%d %f %s\n",&a,&f,str);
		fprintf(fout,"%d %f %s\n",a,f,str);
	}
	fclose(fin);
	fclose(fout);
	
	return 0;
}
