/*AUXILIARY DECLARATION*/

%{
	#include <stdlib.h>
	#include <stdio.h>
    int comments=0;

%}

/*REGULAR DEFINITION*/



%%



"//"(.)* {  
            printf("%s",yytext);
            comments++;}


"/*"(.|\n|[ ])*"*/" {    printf("%s",yytext);
                        comments++;}

[a-zA-Z]+  {return 0;}


%%

int yywrap()
{
    return 1;
}
 
/*AUXILIARY FUNCTION*/
int main()
{
    yyin=fopen("ex1.4.txt","r");
	yylex();

    printf("Comments:%d\n",comments);

	return 1;
}