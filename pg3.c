#include<stdio.h>
#include<string.h>
char prod[3][15] ={"S->aAb|@","A->aA|@"};
char table[2][3][3]={{"aAb","","@"},
                     {"aA","@",""}};
int size[2][3]={3,0,1,2,1,0},n;
char ip[20],stack[20];

void display(int i,int j)
{
int k;
for(k=0;k<=i;k++)
printf("%c",stack[k]);
printf("        ");
for(k=j;k<n;k++)
printf("%c",ip[k]);
printf("\n");
}

void main()
{
int i,j,k,row,col,flag=0;
printf("\n Enter the grammar:\n");
for(i=0;i<3;i++)
printf("%s\n",prod[i]);
printf("\nPredictive parsing table is \n\n");
printf("\ta\tb\t$\n");
printf("________________________________\n");
for(i=0;i<2;i++)
{
if(i==0) printf("A "); else printf("\nB ");
for(j=0;j<3;j++)
{
printf("\t%s",table[i][j]);
}
}
printf("\n Enter thr input string: \n");
scanf("%s",ip);
strcat(ip,"$");
n=strlen(ip);
stack[0]='$';
stack[1]='S';
i=1;
j=0;
printf("\nStack         Input");
printf("\n_____________________________\n");
while(1)
{
if(stack[i]==ip[j])
{
i--;
j++;
if(stack[i]=='$' && ip[j] == '$')
{ printf("$     $\nSUCCESS\n");break;}
else
if(stack[i]=='$' && ip[j]!='$')
{ printf("ERROR\n"); break;}
display(i,j);
}
switch(stack[i])
{
case'S':row=0;
break;
case'A':row=1;
break;
}
switch(ip[j])
{
case'a':col=0;
break;
case'b':col=1;
break;
case'$':col=2;
break;
}
if(table[row][col][0]=='\0')
{
printf("\nERROR\n");
break;
}
else if(table[row][col][0]=='@')
{
i--;
display(i,j);
}
else
{
for(k=size[row][col]-1;k>=0;k--)
{
stack[i]=table[row][col][k];
i++;
}
i--;
display(i,j);
}
}
}
