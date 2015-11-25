#include<stdio.h>

int main()
{

enum {A,B,C}e1;
enum {A1=1,B1=0,C1,D1,E1}e2;
enum{A2=20,B2=10,C2=100}e3;

printf("A:%d\n",A);
printf("B:%d\n",B);
printf("C:%d\n",C);

printf("A1:%d\n",A1);
printf("B1:%d\n",B1);
printf("C1:%d\n",C1);

printf("D1:%d\n",D1);
printf("E1:%d\n",E1);


return 0;
}
