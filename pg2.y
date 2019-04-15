//crstnmac8
%{
#include<stdio.h>
#include<stdlib.h>
%}
%token A B
%%
input:s'\n' {printf("String is recognized successfully\n");exit(0);}
s: A s1 B|B s1 B
s1:{;} | A s1 B
%%

main()
{
printf("Enter a string\n");
yyparse();
}

int yyerror()
{
printf("Error \n");
exit(0);
}

