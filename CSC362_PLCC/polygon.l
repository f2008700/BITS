%{
#include<stdio.h>
#define MAX 1024

int start=-1;                         // starting row of figure
int end=-1;			      // ending row of figure	
int flag1=0;				//flag for chking validity
int flag2=0;				//flag for chking validity
int rowcount=0;				//total rows in input file
int arrb4[MAX];				//counts zeroes before the first '1'
int arraf[MAX];				//counts zeroes after the last '1'
int ver[MAX][2];			//stores column of first and last '1' in each row
int len=0,lf=0,rt=0;
int ones[MAX];				//stores total no. of '1's in each row
int vertex1[MAX][2];
int vertex2[MAX][2];

// To count the number of '1' in a row; length specified by the parameter 'length'.
int countones(char *lexeme,int length)
{	int i,count=0;
	for(i=0;i<length;i++)
	{	if(lexeme[i]=='1')
		count++;
	}
	return count;
}

// To count the number of '0' in a row; length specified by the parameter 'length'.
int countzero(char *lexeme,int length)
{	int i,count=0;
	for(i=0;i<length;i++)
	{	if(lexeme[i]=='0')
		count++;
	}
	return count;
}

//// To count the number of '0' in a row; within a range specified by the start->sindex and end->'endex'
int countfollowzero(char *lexeme,int sindex,int endex)
{	int i,count=0;
	for(i=sindex;i<endex;i++)
	{	if(lexeme[i]=='0')
			count++;
	}
	return count;
}

//checks if the polygon is a fully occupying quadrilateral
int chkfullquad(int *a, int *b, int strt, int ed)                
{	int z,x,m;	
	m=0;
	z = ed - strt+1;
	for (x=strt;x<=ed;x++)
	{	if((a[x]==0) && (b[x]==0)) 
		{	m++;
		}
	}
	if(m==z) 
		return 1;
	else 
		return 0;
}

int checkinputinvalid(int *arr1,int *arr01, int *arr02, int lenth, int st, int fi)
{	int w,e,r,t,y;
	y=0,e=0,r=0,t=0;
	
	//check if the starting/ending row is valid  
	if(arr1[st]+arr01[st]+arr02[st] != len) 
	{	y++;
	}
	
	if(arr1[fi]+arr01[fi]+arr02[fi] != len) 
	{	y++;
	}
	
	//checks whether the rest of rows contain not more than two 1s
	for(w=st+1;w<fi;w++)
	{	if(arr1[w]!=2 ) 
		{	return 1;
		}
	}
		
	for(w=0;w<lenth;w++)
	{	if(arr1[w]<2)						    //checks for all zeroes
		{	e++;
		}
		
		if((arr1[w]==0) && (arr1[w-1]!=0) && (arr1[w+1]!=0))         //checks for 'gaps' in the input file
		{	r=1;
		}
			
		if((arr1[w]==1) && (arr1[w-1]>1) && (arr1[w+1]>1))	    //checks for cross-points like '10001'	
		{	t=1;					    	//				    01010	
		}						   	//				    00100	
									//				    01010	
									//			            10001
	}
	
	//printf("y is %d, e is %d, r is %d, t is %d \n",y,e,r,t);
	
	if((y>0)||(e==lenth)||(r==1)||(t==1))
	{	return 1;
	}
	
	else 
		return 0;
}
%}


%%

0*0$	{	
		len=yyleng;
		arrb4[rowcount]=yyleng;
		arraf[rowcount]=-1;
		ones[rowcount]=0;
		ver[rowcount][1]=-1;
		ver[rowcount][2]=-1;
		rowcount++;
	}		


1*1$	{
		len=yyleng;
		arrb4[rowcount]=0;
		arraf[rowcount]=0;
		ones[rowcount]=yyleng;
		ver[rowcount][1]=1;		
		ver[rowcount][2]=yyleng;
		rowcount++;
	}




0*10*       {	
		len=yyleng;
		int a,b,c,d;
		
		a=0;
		while(yytext[a]!='1')
			a++;
		arrb4[rowcount]= countzero(yytext,a);
		ver[rowcount][1]=a+1;
		
		b=yyleng;
		while(yytext[b]!='1')
			b--;
		arraf[rowcount]= countfollowzero(yytext,b,yyleng);
		ver[rowcount][2]=b+1;
		
		
		ones[rowcount]=countones(yytext,yyleng);
		rowcount++;
		
	     }


0*10+10*     {	
		len=yyleng;
		int a,b,c,d;
		
		a=0;
		while(yytext[a]!='1')
			a++;
		arrb4[rowcount]= countzero(yytext,a);
		ver[rowcount][1]=a+1;
		
		b=yyleng;
		while(yytext[b]!='1')
			b--;
		arraf[rowcount]= countfollowzero(yytext,b,yyleng);
		ver[rowcount][2]=b+1;
		
		
		ones[rowcount]=countones(yytext,yyleng);
		rowcount++;
		
	     }


0*1*10*     {	
		len=yyleng;
		int a,b,c,d;
		
		a=0;
		while(yytext[a]!='1')
			a++;
		arrb4[rowcount]= countzero(yytext,a);
		ver[rowcount][1]=a+1;
		
		b=yyleng;
		while(yytext[b]!='1')
			b--;
		arraf[rowcount]= countfollowzero(yytext,b,yyleng);
		ver[rowcount][2]=b+1;
		
		ones[rowcount]=countones(yytext,yyleng);
		rowcount++;
		
	     }


\.		{
			flag1=1;
		}		
	
%%


int main()                                  
{
	yylex();
	int a,b,c,d;
	
	//calculate stating and ending rows of the polygon	
/*	if(ones[0]!=0) 
		start=0;
	if(ones[rowcount]!=0) 
		end=rowcount;
	else
*/		d=0;
		while(ones[d]==0) 
			d++;
		start=d;
		while(ones[d]!=0) 
			d++;
		end = d-1;
	
	
	//check validity
	flag2=checkinputinvalid(ones,arrb4,arraf,rowcount,start,end);
	
	if((flag1==1) || (flag2==1))
	{	printf("Not a valid input!\n");
		exit(0);
	}
		
			
	int q = chkfullquad(arrb4,arraf,start,end);
	if(q) 
	{//	printf("the vertices are at row 1-column 1 & %d ",len);
	//	printf("and row %d - column 1 & %d \n",rowcount,len);
		printf("It is a valid input having 4 sides \n");
		exit(1);
	}
	
	for(b=start;b<=end;b++)
	{	// for leading zeroes-code 
		int a2,b2,c2;
		a2 = arrb4[b-1]-arrb4[b];
		b2 = arrb4[b]-arrb4[b+1];
		c2 = a2+b2;
	
		if(c2==0 )
		{
			if((a2!=0) && (b2 !=0))
			{//	printf("1. vertice is at %d and column %d\n",b+1,ver[b][1]);
				vertex1[lf][1]=b+1;
				vertex1[lf][2]=ver[b][1];
				lf++;
			}
		}
		if(c2>0 )
		{
			if((arrb4[b]-arrb4[b-1]) != (arrb4[b+1]-arrb4[b]) )    //&& (arraf[c+1
			{//	printf("3. vertice is at %d and column %d\n",b+1,ver[b][1]);				
				vertex1[lf][1]=b+1;
				vertex1[lf][2]=ver[b][1];
				lf++;
			}
		}
			
		if(c2<0)
		{	if((arrb4[b-1]-arrb4[b]) != (arrb4[b]-arrb4[b+1]) )  
			{//	printf("2. vertice is at %d and column %d\n",b+1,ver[b][1]); 				
				vertex1[lf][1]=b+1;
				vertex1[lf][2]=ver[b][1];
				lf++;
			}
		}	
			
	}
	
	for(c=start;c<=end;c++)
	{	int a1,b1,c1;
		a1 = arraf[c-1]-arraf[c];
		b1 = arraf[c]-arraf[c+1];
		c1 = a1+b1;
		
		//printf("a1= %d and b1=%d and c1=%d \n",a1,b1,c1);		
		if(c1==0)
		{
			if((a1!=0) && (b1 !=0))
			{//	printf("1. vertice is at %d and column %d\n",c+1,ver[c][2]);						
				vertex2[rt][1]=c+1;
				vertex2[rt][2]=ver[c][2];
				rt++;
			}
		}
		if(c1>0)
		{	if((arraf[c]-arraf[c-1]) != (arraf[c+1]-arraf[c]) )    
			{//	printf("2. vertice is at %d and column %d\n",c+1,ver[c][2]);
				vertex2[rt][1]=c+1;
				vertex2[rt][2]=ver[c][2];
				rt++;
			}
		}
		
		if(c1<0)
		{	if((arraf[c-1]-arraf[c]) != (arraf[c]-arraf[c+1]) )   
			{//	printf("3. vertice is at %d and column %d\n",c+1,ver[c][2]);
				vertex2[rt][1]=c+1;
				vertex2[rt][2]=ver[c][2];
				rt++;
			}
		}
						
	}

	//Checking for scalene
	int o=0,p=0;
	while(o<lf-2)
	{	if((vertex1[o][2]<vertex1[o+1][2])&&(vertex1[o+1][2]>=vertex1[o+2][2])) 
		{	printf("it is a scalene poly and so is invalid\n");// %d row and %d vertex\n",vertex1[o+1][1],vertex1[o+1][2]);	
			exit(1);				
		}
		
		if((vertex1[o][2]==vertex1[o+1][2])&&(vertex1[o+1][2]>vertex1[o+2][2])) 
		{	printf("it is a scalene poly and so is invalid\n");// %d row and %d vertex\n",vertex1[o+1][1],vertex1[o+1][2]);	
			exit(1);				
		}
		o++;		
	}
	
	while(p<rt-2)
	{	if((vertex2[p][2]>vertex2[p+1][2])&&(vertex2[p+1][2]<=vertex2[p+2][2])) 
		{	printf("it is a scalene poly and so is invalid\n");// %d row and %d column\n",vertex2[p+1][1],vertex2[p+2][2]);	
			exit(1);				
		}
	
		if((vertex2[p][2]==vertex2[p+1][2])&&(vertex2[p+1][2]<vertex2[p+2][2])) 
		{	printf("it is a scalene poly and so is invalid\n"); // %d row and %d column\n",vertex2[p+1][1],vertex2[p+2][2]);	
			exit(1);				
		}
		p++;		
	}

	//till here for scalene.

	// Displaying the number of sides
	int dc=0;
	if((ones[start]==1)||(ones[end]==1))
	{	if((ones[start]==1)&&(ones[end]==1))
		{	dc=2;
		}
		else 
			dc=1;
	}
		
	printf("It is a valid input having %d sides \n",lf+rt-dc);
	return 1;
}

