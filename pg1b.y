%{
#include<stdio.h>
int flag=0;
%}
%token DIG
%union {double dval;}
%type <dval> DIG
%left '+''-'
%left '*''/'
%type <dval> E
%nonassoc UMINUS
%%

//EXP:E {printf("Result=%f\n",$1);}
//;
E:E'+'E {;} // {$$=$1+$3;}
|E'-'E {;} //  {$$=$1-$3;}
|E'*'E {;} // {$$=$1*$3;}
|E'/'E {;}// {if($3==0) 
       /* {
                printf("Division by zero not allowed \n");
                exit(0);
                }
                $$=$1/$3;
        } */
|'-'E%prec UMINUS {;} //{$$=-$2;}
|'('E')' {;} //{$$=$2;}
|DIG {;} //{$$=$1;}
;
%%

main()
{
printf("Enter an arithmetic expression \n");
yyparse();
if(flag==1)
printf("Invalid Expression\n");
else
printf("Valid Expression\n");
}
int yyerror()
{
flag=1;
return flag;
}
