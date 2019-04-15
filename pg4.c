#include<stdio.h>
#include<string.h>
int z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];
void check();
void main()
{
printf(" GRAMMER is E->E=T|T\nT->T*F|F\nF->(E)\nF->id\n");
printf("enter input string\n");
scanf("%s",a);
c=strlen(a);
strcpy(act,"SHIFT->");
printf("stack \t input \t action");
printf("\n----------------------------\n");
for(i=0;j<c;i++,j++)
{
if(a[j]=='i'&&a[j+1]=='d')
{
stk[i]=a[j];
stk[i+1]=a[j+1];
stk[i+2]='\0';
a[j]=' ';
a[j+1]=' ';
printf("\n$%s\t%s$\t%sid",stk,a,act);
check();
}
else{
stk[i]=a[j];
stk[i+1]='\0';
a[j]=' ';
printf("\n$%s\t%s$\t%sSYMBOLS",stk,a,act);
check();
}
}
if((strcmp(stk,"E")==0))
printf("\n-----------------------------------\nSUCCESS\n");
else
printf("\n-----------------------------------\nERROR\n");
}
void check()
{
strcpy(ac,"REDUCE");
for(z=0;z<c;z++)
if(stk[z]=='i'&& stk[z+1]=='d')
{
stk[z]='F';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
j++;
}
for(z=0;z<c;z++)
{
if(stk[z]=='T'&& stk[z+1]=='*'&& stk[z+2]=='F')
{
stk[z]='T';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
}
else if(stk[z]=='F')
{
stk[z]='T';
printf("\n$%s\t%s$\t%s",stk,a,ac);
}
}
for(z=0;z<c;z++)
{
if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T' && stk[z+3]=='*')
break;
if(stk[z]=='E' && stk[z+1]=='+' && stk[z+2]=='T' && a[j+1]=='*')
break;
else if(stk[z]=='E'&& stk[z+1]=='+'&&stk[z+2]=='T')
{
stk[z]='E';
stk[z+1]='\0';
printf("\n$%s\t%s$\t%s",stk,a,ac);
return;
}
}
for(z=0;z<c;z++)
{
if(stk[z]=='T')
if(a[j+1]=='*')
break;
else if(stk[z+1]=='*')
break;
else
{
stk[z]='E';
printf("\n$%s\t%s$\t%s",stk,a,ac);
}
}
}















































