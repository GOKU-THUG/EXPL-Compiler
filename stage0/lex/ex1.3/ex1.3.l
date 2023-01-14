/*AUXILIARY DECLARATION*/

%{
	#include <stdlib.h>
	#include <stdio.h>
    #include<ctype.h>
    int words=0;

%}

/*REGULAR DEFINITION*/

low [a-z]
upper [A-Z]

%%

A(.){2}([ ]|\n) {   
                    for(int i=0;i<3;i++)
                    {
                        printf("%c",toupper(yytext[i]));
                    }
                    printf("\n");
                    words++;
                }
    

%%

int yywrap()
{
    return 1;
}
 
/*AUXILIARY FUNCTION*/
int main()
{
    yyin=fopen("ex1.3.txt","r");
	yylex();

    printf("Words:%d\n",words);

	return 1;
}