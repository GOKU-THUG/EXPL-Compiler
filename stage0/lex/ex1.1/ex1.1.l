/*AUXILIARY DECLARATION*/

%{
	#include <stdlib.h>
	#include <stdio.h>

    int words=0,lines=0,characters=0;

%}

/*REGULAR DEFINITION*/

character .
space [ ]+
line  \n


%%

({space}|\t) {words++;}
{character} {characters++;}
{line} {lines++;words++;}

%%

int yywrap()
{
    return 1;
}
 
/*AUXILIARY FUNCTION*/
int main()
{
    yyin=fopen("ex1.1.txt","r");
	yylex();

    printf("Characters:%d\n",characters);
    printf("Words:%d\n",words);
    printf("Lines:%d\n",lines);

	return 1;
}