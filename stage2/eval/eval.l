%{
	#include <stdlib.h>
	#include "y.tab.h"
    #include "eval.h"
    int number;
%}

%%

"begin" {return BEG;}

"end"  {return END;}

"read" {return READ;}

"write" {return WRITE;}

"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"=" {return EQUAL;}

[a-z] {	
		yylval.no=makeVariableNode(*yytext);
		return ID;
	  }

[0-9]+	{number = atoi(yytext); yylval.no = makeConstantNode(number); return NUM;}

[()]	{return *yytext;}
[;] {}
[\n] {}
[ \t] {}

%%

int yywrap(void)
{
    return 1;
}