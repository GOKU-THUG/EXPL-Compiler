%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    extern FILE* yyin;
    char temp[10];
    int yylex();
    int yyerror();
%}

%union
{
    char op;
    char* c;
};

%token CHAR


%left '+' '-'
%left '*' '/'

%%

start:expr {printf("%s\n",$<c>1);
            exit(0);};

expr:expr '+' expr {strcpy($<c>$,strcat(strcpy(temp,"+"),strcat($<c>1,$<c>3)));}
    |expr '-' expr {strcpy($<c>$,strcat(strcpy(temp,"-"),strcat($<c>1,$<c>3)));}
    |expr '*' expr {strcpy($<c>$,strcat(strcpy(temp,"*"),strcat($<c>1,$<c>3)));}
    |expr '/' expr {strcpy($<c>$,strcat(strcpy(temp,"/"),strcat($<c>1,$<c>3)));}
    |CHAR  { strcpy($<c>$,$<c>1);}
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
    yyin=fopen("ex3.txt","r");
    yyparse();
    return 1;
}