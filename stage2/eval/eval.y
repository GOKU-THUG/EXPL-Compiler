%{
	#include <stdlib.h>
	#include <stdio.h>
    #include<string.h>
    #include "eval.h"
    #include "eval.c"

    extern FILE* yyin;

	int yylex(void);
    int yyerror();
%}

%union{
	struct tnode *no;	
}
%type <no>  Program Slist Stmt InputStmt OutputStmt AsgStmt E
%token BEG END READ WRITE ID NUM PLUS MINUS MUL DIV EQUAL
%left PLUS MINUS
%left MUL DIV
%right EQUAL

%%

Program : BEG Slist END {
                          $$=$<no>2;
                          int val=evaluate($<no>2);
                          exit(1);
                       }
          | BEG END {exit(1);}; 

Slist : Slist Stmt {$$=makeConnectorNode('.',$<no>1,$<no>2);}
      | Stmt       {$$=$<no>1;};
        
Stmt : InputStmt  {$$=$<no>1;}
       | OutputStmt {$$=$<no>1;}
       | AsgStmt   {$$=$<no>1;};
        

InputStmt : READ '(' ID ')'  {$$=makereadnode($<no>3);};

OutputStmt : WRITE '(' E ')' {$$=makewritenode($<no>3);};

AsgStmt :ID EQUAL E {$$ = makeOperatorNode('=',$<no>1,$<no>3);};


E : E PLUS E		{$$ = makeOperatorNode('+',$<no>1,$<no>3);}
	 | E MINUS E  	{$$ = makeOperatorNode('-',$<no>1,$<no>3);}
	 | E MUL E	{$$ = makeOperatorNode('*',$<no>1,$<no>3);}
	 | E DIV E	{$$ = makeOperatorNode('/',$<no>1,$<no>3);}
	 | '(' E ')'		{$$ = $<no>2;}
	 | NUM			{$$ = $<no>1;}
     |ID            {$$=$<no>1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 0;
}


int main(void) 
{
    yyin=fopen("eval.txt","r");
	yyparse();
	
	return 0;
}