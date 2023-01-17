%{
	#include <stdlib.h>
	#include <stdio.h>
    #include<string.h>
    #include "ast.h"
    #include "ast.c"

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

                        FILE *fptr=fopen("ast.xsm","w");
				        fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
                         int resreg_no= codeGen($<no>2,fptr);
                        fprintf(fptr,"INT 10");
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
    yyin=fopen("ast.txt","r");
	yyparse();
	
	return 0;
}