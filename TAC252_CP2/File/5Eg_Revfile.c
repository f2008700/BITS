#include<stdio.h>

int main()
{
	char c;
	FILE *ifp, *ofp;
	ifp=fopen("f1","r");
	ofp=fopen("f1Rev","w");

	fseek(ifp,-2,SEEK_END);
	while(ftell(ifp)!=0)
	{
		c=fgetc(ifp);
		fputc(c,ofp);
		fseek(ifp,-2,SEEK_CUR);
	}
	c=fgetc(ifp);
	fputc(c,ofp);
	return 0;
}
