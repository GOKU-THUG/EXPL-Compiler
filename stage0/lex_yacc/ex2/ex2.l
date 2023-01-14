%{
	#include<stdlib.h>
    #include<string.h>
	#include "y.tab.h"
%}

%%

"+"    {yylval.op=*yytext;
        return *yytext;}
"-"    {yylval.op=*yytext;
        return *yytext;}
"*"    {yylval.op=*yytext;
        return *yytext;}
"/"    {yylval.op=*yytext;
        return *yytext;}
[()]   {
        return *yytext;
        }

[a-zA-Z]+ { yylval.c=strdup(yytext);
        return CHAR;
	  }

%%

int yywrap(){
	return 1;
}