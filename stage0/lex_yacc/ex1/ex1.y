%{
    #include<stdio.h>
    #include<stdlib.h>
    extern FILE* yyin;
    int yylex();
    int yyerror();
%}

%union
{
    char c;
};

%token CHAR
%type <c> CHAR 

%left '+' '-'
%left '*' '/'

%%

start:expr {printf("\n");
            exit(0);};

expr:expr '+' expr {printf("%c",$<c>2);}
    |expr '-' expr {printf("%c",$<c>2);}
    |expr '*' expr {printf("%c",$<c>2);}
    |expr '/' expr {printf("%c",$<c>2);}
    |CHAR  { $<c>$=$<c>1;
            printf("%c",$<c>1);}
    ;

%%

int yyerror(char const* msg)
{
    printf("Error %s",msg);
    exit(0);
}

int main()
{
    yyin=fopen("ex1.txt","r");
    yyparse();
    return 1;
}