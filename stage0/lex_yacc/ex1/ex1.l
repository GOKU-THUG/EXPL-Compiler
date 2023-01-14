%{
	#include<stdlib.h>
	#include "y.tab.h"
%}

%%

"+"    {yylval.c=*yytext;
        return *yytext;}
"-"    {yylval.c=*yytext;
        return *yytext;}
"*"    {yylval.c=*yytext;
        return *yytext;}
"/"    {yylval.c=*yytext;
        return *yytext;}

[a-z] { 
		yylval.c=*yytext;
        return CHAR;
	  }

%%

int yywrap(){
	return 1;
}