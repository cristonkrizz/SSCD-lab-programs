%{
#include<stdio.h>
int cmt=0;
%}
%%
"/*"[^*/]*"*/" {cmt++; ECHO;}
"//".* {cmt++; ECHO;}
%%
main(int argc,char *argv[])
{
        FILE *f1,*f2;
        if(argc!=3)
        printf("Error:Enter 2 arguments\n");
        else
        {
                f1=fopen(argv[1],"r");
                if(!f1)
                {
                printf("File does not exist!\n");
                exit(0);
                }
        f2=fopen(argv[2],"w");
        yyin=f1;
        yyout=f2;
        yylex();
        printf("Number of comment lines=%d\n",cmt);
        }
}
