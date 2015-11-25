#include<stdio.h>

int main()
{
	FILE *ifp,*ofp1,*ofp2;
	int i;
	float cgpa,maxcgpa;
	char name[100];
	char grade[3];
	ifp=fopen("grade.dat","r");
	ofp1=fopen("cgpa.dat","w+");
	while(!feof(ifp))
	{
		fscanf(ifp,"%s %c %c %c\n",name,&grade[0],&grade[1],&grade[2]);
		cgpa=0.0;
		for(i=0;i<3;i++)
		{
			if(grade[i]=='A')
				cgpa+=10.0;
			else if(grade[i]=='B')
				cgpa+=8.0;
			else if(grade[i]=='C')
				cgpa+=6.0;
			else if(grade[i]=='D')
				cgpa+=4.0;
			else if(grade[i]=='E')
				cgpa+=2.0;
			else
				cgpa+=0.0;
		}
		cgpa=cgpa/3;
		fprintf(ofp1,"%s %f\n",name,cgpa);
		fflush(NULL);
	}
	fclose(ifp);
	rewind(ofp1);
	ofp2=fopen("maxcgpa.dat","w");

	maxcgpa=0.0;
	while(!feof(ofp1))
	{
		fscanf(ofp1,"%s %f\n",name,&cgpa);
		if(cgpa>maxcgpa)
			maxcgpa=cgpa;
	}
	fprintf(ofp2,"%f\n",maxcgpa);
	fcloseall();
	rename("cgpa.dat","cgpaFinal.dat");
//	remove("cgpaFinal.dat");
	return 0;
}
