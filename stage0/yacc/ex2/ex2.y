 %{

    #include<stdio.h>
    int yyerror();
    int yylex();
    extern FILE* yyin;
%}

%token digit letter

%%

start : letter s    {printf("Valid Variable\n");};

s :     letter s

      | digit s

      |

      ;

%%

int yyerror()
{

    printf("\nInvalid Variable!\n");
    return 0;

}

int main()

{
    yyin=fopen("ex2.txt","r");
    yyparse();

}