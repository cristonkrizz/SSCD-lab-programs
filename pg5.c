#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

char tset[3][3][3]={{"*","C","D"},
                     {"+","B","0"},
                     {"=","1","A"}
                     };
int main()
{
int row,col;
printf("input statement is: A=B+C*D\n");
printf("intermediate code in three address form is:\nT1=C*D\nT2=B+T1\nA=T2\n");
printf("triples are:\n");
printf("\t op\targ1\targ2\n");
for(row=0;row<4;row++)
{
if(row==0)printf("0\t*\tC\tD\n");
if(row==1)printf("1\t+\tB\t0\n");
if(row==2)printf("2\t=\t1\tA\n");
}
printf("machine code generated is:\n");
for(row=0;row<3;row++)
{
col=2;
if(tset[row][0][0]=='*')
{

printf("\nLD R0,%s",tset[row][1]);
printf("\nLD R1,%s",tset[row][2]);
printf("\nMUL R0,R0,%s",tset[row][1]);
}
else
{
if(tset[row][0][0]=='+')
{
        printf("\nLD R2,%s",tset[row][1]);
        printf("\nADD R2,R0,R2");
}
else{
printf("\nST %s,R2",tset[row][2]);
}
}
}
printf("\n");
return 0;
}


