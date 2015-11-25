#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MONTHS 12


void copy1(char A[][15], char B[][15]);
char ** copy2(char A[][15]);
void copy3(char A[][15], char ***B);

int main()
{
	char X[MONTHS][15];
	char Y[MONTHS][15];
	int i,j;
	char **Z;
	char **ret;
	strcpy(X[0],"January");strcpy(X[1],"February");strcpy(X[2],"March");
	strcpy(X[3],"April");strcpy(X[4],"May"); strcpy(X[5],"June");
	strcpy(X[6],"July");strcpy(X[7],"August");strcpy(X[8],"September");
	strcpy(X[9],"October");strcpy(X[10],"November");strcpy(X[11],"December");

	copy1(X,Y);
	ret=copy2(X);
	copy3(X,&Z);
	printf("Output of copy1 --> Array Y\n");
	for(i=0;i<MONTHS;i++)
			printf("%s\n",Y[i]);
	printf("\n\n\n");

	printf("Output of copy2 --> ret\n");
	for(i=0;i<MONTHS;i++)
			printf("%s\n",ret[i]);
	printf("\n\n\n");

	printf("Output of copy3 --> Z\n");
	for(i=0;i<MONTHS;i++)
			printf("%s\n",Z[i]);
	printf("\n\n\n");

	return 0;
}

void copy1(char A[][15], char B[][15])
{
	int i;
	for(i=0;i<MONTHS;i++)
		strcpy(B[i],A[i]);
}

char ** copy2(char A[][15])
{
	int i;
	char **B;

	B=(char **)malloc(MONTHS*sizeof(char *));
	for(i=0;i<MONTHS;i++)
		B[i]=(char *)malloc((strlen(A[i])+1)*sizeof(char));
	for(i=0;i<MONTHS;i++)
		strcpy(B[i],A[i]);
	return B;
}

void copy3(char A[][15], char ***B)
{
	int i,j;
	*B=(char **)malloc(MONTHS*sizeof(char *));
	for(i=0;i<MONTHS;i++)
		(*B)[i]=(char *)malloc((strlen(A[i])+1)*sizeof(char));
	for(i=0;i<MONTHS;i++)
		strcpy((*B)[i],A[i]);
}

