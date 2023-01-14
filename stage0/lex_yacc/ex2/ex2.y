%{
    #include<stdio.h>
    #include<stdlib.h>
    extern FILE* yyin;
    int yylex();
    int yyerror();
%}

%union
{
    char op;
    char* c;
};

%token CHAR
%type <c> CHAR 

%left '+' '-'
%left '*' '/'

%%

start:expr {printf("\n");
            exit(0);};

expr:expr '+' expr {printf("%c",$<op>2);}
    |expr '-' expr {printf("%c",$<op>2);}
    |expr '*' expr {printf("%c",$<op>2);}
    |expr '/' expr {printf("%c",$<op>2);}
    |CHAR  { $<c>$=$<c>1;
            printf("%s",$<c>1);}
    |'('expr')' {$<c>$=$<c>2;}
    ;

%%

int yyerror(char const* msg)
{
    printf("Error %s",msg);
    exit(0);
}

int main()
{
    yyin=fopen("ex2.txt","r");
    yyparse();
    return 1;
}