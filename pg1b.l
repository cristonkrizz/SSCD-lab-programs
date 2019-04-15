%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
%}
%%
[0-9]*\.?[0-9]* {yylval.dval=atof(yytext);return DIG;}
[\t]    {;}
[\n]    {return 0;}
.       {return yytext[0];}
%%
