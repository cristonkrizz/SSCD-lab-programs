%{
#include<stdio.h>
#include"y.tab.h"
%}
%%
[\t] {;}
[\+|\-|\*|=|\<|\>] {printf("operator is %s\n",yytext); return OP;}
[0-9]+ {yylval=atoi(yytext);printf("number is %d\n",yylval); return DIGIT;}
int|char|bool|float|void|for|do|while|if|else|return|void|double {printf("keyword is %s\n",yytext); return KEY;}
[a-zA-Z][a-zA-Z0-9]* {printf("identifier is %s\n",yytext); return ID;}
. {;}
%%

