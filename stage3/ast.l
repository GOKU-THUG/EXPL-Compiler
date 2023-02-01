%{
	#include <stdlib.h>
    #include <string.h>
	#include "y.tab.h"
    #include "ast.h"
    int number;
%}

%%

"begin" {return BEG;}

"end"  {return END;}

"read" {return READ;}

"Read" {return READ;}

"write" {return WRITE;}

"Write" {return WRITE;}

"if" {return IF;}

"then" {return Then;}

"else" {return Else;}

"endif" {return ENDIF;}

"do"  {return DO;}

"while" {return WHILE;}

"repeat" {return REPEAT;}

"until" {return UNTIL;}

"break" {return BREAK;}

"continue" {return CONTINUE;}

"endwhile"  {return ENDWHILE;}

"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"=" {return EQUAL;}

"<" {   
        strcpy(yylval.c,yytext);
        return COMP;
    }

">" {   
        strcpy(yylval.c,yytext);
        return COMP;
    }

"<=" {
        strcpy(yylval.c,yytext);
        return COMP;
    }

">=" {
        strcpy(yylval.c,yytext);
        return COMP;
    }

"!="  {
        strcpy(yylval.c,yytext);
        return COMP;
      }

"==" {  
        strcpy(yylval.c,yytext);
        return COMP;
     }

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