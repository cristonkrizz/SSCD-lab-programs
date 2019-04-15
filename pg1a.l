%{
#include<stdio.h>
int opn=0,pop=0,id=0,pid=0,op=0,br=0,flag=0,err=0;
%}
%%
[a-zA-Z0-9]+ {id++;if(opn==1)pid++;printf("\n ID:");ECHO;}
[\+\*\-\/] {op++;if(opn==1)pop++;printf("\n OPERATOR:");ECHO;}
[(] {br++;opn=1;}
[)] {if(pid!=op+1)flag=1;br--;if(br==0){pop=0;pid=0;opn=0;}}
[ ] {;}
. {printf("\n invalid symbol:");ECHO;err=1;}
\n {return;}
%%
void main()
{
        printf("enter the expression:\n");
        yylex();
        printf("\n Number of identifiers: %d\n",id);
        printf("\n Number of operators: %d\n",op);
        if(id==op+1 && br==0 && flag==0 && err==0)
        printf("\n VALID EXPRESSION\n");
        else
        printf(" INVALID EXPRESSION\n");
}

