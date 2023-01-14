/*AUXILIARY DECLARATION*/

%{
	#include <stdlib.h>
	#include <stdio.h>

	int integers=0,floating=0;

%}

/*REGULAR DEFINITION*/

number [0-9]+

%%

[.]+[0-9]+[.][0-9]+([eE][-+][0-9]+)* {return 0;}
[0-9]+[.][0-9]+([eE][-+][0-9]+)*[.]+ {return 0;}
[0-9]+[.][0-9]+([eE][-+][0-9]+)* {floating++;}
[a-zA-Z]+{number}  {return 0;}
{number}[a-zA-Z]+  {return 0;}
{number} {integers++;}



%%

int yywrap()
{
	return 1;
}
 
/*AUXILIARY FUNCTION*/
int main()
{
	yyin=fopen("ex1.2.txt","r");
	yylex();

	printf("Integers:%d\n",integers);
	printf("Floating:%d\n",floating);
	
	return 1;
}