%{
	#include <stdlib.h>
    #include <string.h>
	#include "y.tab.h"

    int number;
%}

letter [_a-zA-Z]
digit  [0-9]
%%

"begin" {return BEG;}

"decl" {return DECL;}

"enddecl" {return ENDDECL;}

"int"  {yylval.c=strdup(yytext);
        return INT;}

"str" {return STR;}

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

"return"  {return RET;}

"main"     {yylval.c=strdup(yytext);
            return MAIN;}

"AND"     {yylval.c=strdup(yytext);
            return AND;}
"and"     {yylval.c=strdup(yytext);
            return AND;}
"OR"     {yylval.c=strdup(yytext);
            return OR;}
"or"     {yylval.c=strdup(yytext);
            return OR;}
"NOT"     {yylval.c=strdup(yytext);
            return NOT;}
"not"     {yylval.c=strdup(yytext);
            return NOT;}
"XOR"     {yylval.c=strdup(yytext);
            return XOR;}
"xor"     {yylval.c=strdup(yytext);
            return XOR;}

"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
"=" {return EQUAL;}
"%" {return MOD;}

"<" {   
        yylval.c = strdup(yytext);
        return COMP;
    }

">" {   
        yylval.c = strdup(yytext);
        return COMP;
    }

"<="|"≤" {
        yylval.c = strdup("<=");
        return COMP;
    }

">=" {
        yylval.c = strdup(yytext);
        return COMP;
    }

"!="  {
        yylval.c = strdup(yytext);
        return COMP;
      }

"==" {  
        yylval.c = strdup(yytext);
        return COMP;
     }

{letter}({letter}|{digit})*     {	
		                            yylval.c = strdup(yytext);
                                    return ID;
                                }

["].*["] {
                yylval.c = strdup(yytext);
                return STRING;
        }

[0-9]+	{number = atoi(yytext); yylval.i = number; return NUM;}

[()\[\],{}]	{return *yytext;}
[;]  {}
[\n] {}
[ \t] {}

%%

int yywrap(void)
{
    return 1;
}