%{
	#include <stdlib.h>
	#include <stdio.h>
    #include<string.h>
    #include "ast.h"
    #include "ast.c"
    #include "codegen.c"

    extern FILE* yyin;

	int yylex(void);
    int yyerror();
%}

%union{
	struct tnode *no;
    char* c;
}

%type <no>  Program Slist Stmt InputStmt OutputStmt AsgStmt E Ifstmt Whilestmt Dowhilestmt Repeatuntil
%token BEG END READ WRITE ID NUM PLUS MINUS MUL DIV EQUAL IF Then Else ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE
%left COMP
%left PLUS MINUS
%left MUL DIV
%right EQUAL

%%

Program : BEG Slist END {
                          $$=$<no>2;

                        //printtree($<no>2);

                        FILE *fptr=fopen("ast.o","w");
				        fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
                        
                        int resreg_no= codeGen($<no>2,fptr);
                        //printf("Reg%d\n",resreg_no);
                        fprintf(fptr,"INT 10");
                        exit(1);
                       }
          | BEG END {exit(1);}; 

Slist : Slist Stmt {$$=makeConnectorNode('.',$<no>1,$<no>2);}
      | Stmt       {$$=$<no>1;};
        
Stmt : InputStmt  {$$=$<no>1;}
       | OutputStmt {$$=$<no>1;}
       | AsgStmt   {$$=$<no>1;}
       | Ifstmt   {$$=$<no>1;}
       | Whilestmt   {$$=$<no>1;}
       | Dowhilestmt {$$=$<no>1;}
       | Repeatuntil {$$=$<no>1;}
       | BREAK      {
                        char c[6]="break";
                        $$=makeBreak_ContinueNode(c);
                    }

       | CONTINUE   {
                        char c[9]="continue";
                        $$=makeBreak_ContinueNode(c);
                    }
        
    
Ifstmt  : IF '(' E ')' Then Slist Else Slist ENDIF {
                                                        struct tnode* else_node;
                                                        struct tnode* connector_node;
                                                        
                                                        else_node=makeBranchingNode("Else",$<no>8,NULL);
                                                        connector_node=makeConnectorNode('.',$<no>6,else_node);
                                                        $$=makeBranchingNode("If",$<no>3,connector_node);              
                                                   }
        | IF '(' E ')' Then Slist ENDIF       {$$=makeBranchingNode("If",$<no>3,$<no>6);}
        ;

Whilestmt : WHILE '(' E ')' DO Slist ENDWHILE    {$$=makeBranchingNode("While",$<no>3,$<no>6);};

Dowhilestmt: DO Slist WHILE '(' E ')'           {$$=makeBranchingNode("Do",$<no>2,$<no>5);};

Repeatuntil: REPEAT Slist UNTIL '(' E ')'       {$$=makeBranchingNode("Repeat",$<no>2,$<no>5);};

InputStmt : READ '(' ID ')'  {$$=makereadnode($<no>3);};

OutputStmt : WRITE '(' E ')' {$$=makewritenode($<no>3);};

AsgStmt :ID EQUAL E {$$ = makeOperatorNode('=',$<no>1,$<no>3);};


E : E PLUS E		{$$ = makeOperatorNode('+',$<no>1,$<no>3);}
	 | E MINUS E  	{$$ = makeOperatorNode('-',$<no>1,$<no>3);}
	 | E MUL E	{$$ = makeOperatorNode('*',$<no>1,$<no>3);}
	 | E DIV E	{$$ = makeOperatorNode('/',$<no>1,$<no>3);}
	 | '(' E ')'		{$$ = $<no>2;}
	 | NUM			{$$ = $<no>1;}
     | ID            {$$=$<no>1;}
	 | E COMP E {  $$ = makeComparisonNode($<c>2,$<no>1,$<no>3);}
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