%{
	#include <stdlib.h>
	#include <stdio.h>
    #include<string.h>
    
    #include "symboltable.h"
    #include "ast.h"

    #include "ast.c"
    #include "codegen.c"
    #include "symboltable.c"

    extern FILE* yyin;
    extern char* yytext;

	int yylex(void);
    int yyerror();
    void indextypecheck(int type);
%}

%union{
	struct tnode *no;
    struct Gsymbol* symbol;
    char* c;
    int i;
}
 
%type<i> Type
%type<symbol> VarList
%type <no>  Program Slist Stmt InputStmt OutputStmt AsgStmt E Ifstmt Whilestmt Dowhilestmt Repeatuntil
%token BEG END READ WRITE ID NUM PLUS MINUS MUL DIV EQUAL IF Then Else ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR STRING MOD
%right EQUAL
%left COMP
%left PLUS MINUS
%left MUL DIV MOD

%%

Program : BEG Slist END {
                          $$=$<no>2;

                        //printtree($<no>2);
                        printsymboltable();

                        FILE *fptr=fopen("ast.o","w");
				        fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
                        
                        //MOVES SP TO THE LAST USED SPACE
                        fprintf(fptr,"MOV SP,%d\n",4096+used_space);

                        int resreg_no= codeGen($<no>2,fptr);
                        //printf("Reg%d\n",resreg_no);
                        fprintf(fptr,"INT 10");
                        exit(1);
                       }
          | Declarations BEG Slist END   {
                                            $$=$<no>3;
                                            
                                            printsymboltable();
                                            //printtree($<no>2);
                                            

                                            FILE *fptr=fopen("ast.o","w");
                                            fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
                                            
                                            //MOVES SP TO THE LAST USED SPACE
                                            fprintf(fptr,"MOV SP,%d\n",4096+used_space);

                                            int resreg_no= codeGen($<no>3,fptr);
                                            //printf("Reg%d\n",resreg_no);
                                            fprintf(fptr,"INT 10");
                                            exit(1);
                                        }
          | Declarations BEG END {exit(1);}
          | BEG END {exit(1);}; 

Declarations : DECL DeclList ENDDECL | DECL ENDDECL

DeclList : DeclList Decl|Decl

Decl : Type VarList {addtype($<i>1);};

Type : INT    {$$=Integer;}
       | STR  {$$=String;};

VarList :  VarList ',' ID '[' NUM ']'   { Install($<c>3,-1,$<i>5,-1,-1);}
         | VarList ',' ID '[' NUM ']' '[' NUM ']'   { Install($<c>3,-1,$<i>5*$<i>8,$<i>5,$<i>8);}
         | VarList ',' ID               {Install($<c>3,-1,1,-1,-1);} 
         | ID '[' NUM ']'               { Install($<c>1,-1,$<i>3,-1,-1);}                                 
         | ID '[' NUM ']' '[' NUM ']'    { Install($<c>1,-1,$<i>3*$<i>6,$<i>3,$<i>6);}
         | ID                           {Install($<c>1,-1,1,-1,-1);};

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
                    };
        
    
Ifstmt  : IF '(' E ')' Then Slist Else Slist ENDIF {
                                                        struct tnode* else_node;
                                                        struct tnode* connector_node;
                                                        
                                                        else_node=makeBranchingNode("Else",$<no>8,NULL);
                                                        connector_node=makeConnectorNode('.',$<no>6,else_node);
                                                        $$=makeBranchingNode("If",$<no>3,connector_node);              
                                                   }
        | IF '(' E ')' Then Slist ENDIF       {$$=makeBranchingNode("If",$<no>3,$<no>6);}
        ;

Whilestmt : WHILE '(' E ')' DO Slist ENDWHILE    { 
                                                    $$=makeBranchingNode("While",$<no>3,$<no>6);};

Dowhilestmt: DO Slist WHILE '(' E ')'           {$$=makeBranchingNode("Do",$<no>2,$<no>5);};

Repeatuntil: REPEAT Slist UNTIL '(' E ')'       {$$=makeBranchingNode("Repeat",$<no>2,$<no>5);};

InputStmt : READ '(' ID ')'  {
                                struct tnode* var=makeVariableNode($<c>3);
                                $$=makereadnode(var);}

           |READ '(' ID '[' E ']' ')'
                            {
                                struct tnode* var=makeVariableNode($<c>3);
                                indextypecheck($<no>5->type);
                                var->left=$<no>5;
                           
                                $$=makereadnode(var);
                            }

            |READ '(' ID '[' E ']' '[' E ']' ')'
                            {
                                struct tnode* var=makeVariableNode($<c>3);
                                indextypecheck($<no>5->type);
                                indextypecheck($<no>8->type);
                                var->left=$<no>5;    //Row
                                var->right=$<no>8;  //Column
                                
                                $$=makereadnode(var);
                            };

OutputStmt : WRITE '(' E ')' {$$=makewritenode($<no>3);};

AsgStmt :ID EQUAL E {   
                        struct tnode* var=makeVariableNode($<c>1);
                        $$ = makeOperatorNode('=',var,$<no>3);
                    }

        |ID '[' E ']' EQUAL E 
                               {
                                    struct tnode* var=makeVariableNode($<c>1);
                                    indextypecheck($<no>3->type);
                                    var->left=$<no>3;
                                    $$ = makeOperatorNode('=',var,$<no>6);
                               }

        |ID '[' E ']' '[' E ']' EQUAL E 
                                        { 
                                            struct tnode* var=makeVariableNode($<c>1);
                                            indextypecheck($<no>3->type);
                                            indextypecheck($<no>6->type);
                                            var->left=$<no>3;    //Row
                                            var->right=$<no>6;  //Column
                                            $$=makeOperatorNode('=',var,$<no>9);
                                        };               
                                                
E : E PLUS E		{$$ = makeOperatorNode('+',$<no>1,$<no>3);}

	 | E MINUS E  	{$$ = makeOperatorNode('-',$<no>1,$<no>3);}

	 | E MUL E	{$$ = makeOperatorNode('*',$<no>1,$<no>3);}

	 | E DIV E	{$$ = makeOperatorNode('/',$<no>1,$<no>3);}

	 | E MOD E	{$$ = makeOperatorNode('%',$<no>1,$<no>3);}
	 
     | '(' E ')'		{$$ = $<no>2;}


    | ID '[' E ']'  
                    { 
                        struct tnode* var=makeVariableNode($<c>1);
                        indextypecheck($<no>3->type);
                        var->left=$<no>3;
                        $$=var;
                    }

     |ID '[' E ']' '[' E ']' 
                                { 
                                   struct tnode* var=makeVariableNode($<c>1);
                                   indextypecheck($<no>3->type);
                                   indextypecheck($<no>6->type);
                                   var->left=$<no>3;    //Row
                                   var->right=$<no>6;  //Column
                                    
                                   $$=var;
                                } 
	 | NUM			{$$ = makeConstantNode($<i>1,NULL);}
     | ID           {$$=makeVariableNode($<c>1);}     

     | STRING       {$$= makeConstantNode(-1,$<c>1);}

	 | E COMP E {$$ = makeComparisonNode($<c>2,$<no>1,$<no>3);}
     ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 0;
}

void indextypecheck(int type)
{
    if(type!=Integer)
    {
        printf("Invalid 2D array index\n");
        exit(1);
    }
}

int main(void) 
{
    yyin=fopen("ast.txt","r");
	yyparse();
	
	return 0;
}
                                                
                                                

