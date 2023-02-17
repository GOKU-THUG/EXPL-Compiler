%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	
	#include "symboltable.h"
	#include "symboltable.c"
	
	#include "ast.h"
	#include "ast.c"

	#include "codegen.c"
	

	extern FILE* yyin;
	extern char* yytext;
	FILE* fptr;

	int yylex(void);
	int yyerror();
	void indextypecheck(int type);
%}

%union{
	struct tnode *no;
	struct Gsymbol* symbol;
	struct Parameter* param;
	char* c;
	int i;
}
 
%type<i> Type 
%type <no>  Program Slist Stmt InputStmt OutputStmt AsgStmt E Ifstmt Whilestmt Dowhilestmt Repeatuntil Retstmt Body ArgList
%type <param> ParamList Param FdefParam FdefParamList
%token BEG END READ WRITE ID NUM PLUS MINUS MUL DIV EQUAL IF Then Else ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR STRING MOD RET MAIN AND OR NOT XOR
%right EQUAL
%left AND OR NOT XOR
%left COMP
%left PLUS MINUS
%left MUL DIV MOD

%%
Program : GDeclBlock FDefList MainBlock            {exit(1);}
		| GDeclBlock MainBlock                      {exit(1);}
		| MainBlock                                 {exit(1);}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
GDeclBlock : DECL GDeclList ENDDECL                 {  
														//printgst();
														fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
														fprintf(fptr,"MOV SP,%d\n",4095+used_space);
														fprintf(fptr,"MOV BP,SP\n");
														fprintf(fptr,"ADD SP,1\n");    //For return value
														fprintf(fptr,"CALL F0\n");
														fprintf(fptr,"SUB SP,1\n");     //Popping the return value
														fprintf(fptr,"INT 10\n");
													} 
			| DECL ENDDECL                          {  
														fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
														fprintf(fptr,"MOV SP,%d\n",4095+used_space);
														fprintf(fptr,"MOV BP,SP\n");
														fprintf(fptr,"ADD SP,1\n");    //For return value
														fprintf(fptr,"CALL F0\n");
														fprintf(fptr,"SUB SP,1\n");     //Popping the return value
														fprintf(fptr,"INT 10\n");
													} 
GDeclList :  GDeclList GDecl|GDecl
GDecl      : Type Gidlist                           {addgtype($<i>1);};
Type : INT                                          {$$=Integer;}
	   | STR                                        {$$=String;};
Gidlist    : Gidlist ',' Gid
		   |   Gid      
Gid :	   ID '[' NUM ']'                           {GInstall($<c>1,-1,$<i>3,-1,-1,NULL);}                                 
		 | ID '[' NUM ']' '[' NUM ']'               {GInstall($<c>1,-1,$<i>3*$<i>6,$<i>3,$<i>6,NULL);}
		 | ID                                       {GInstall($<c>1,-1,1,-1,-1,NULL);}
		 | ID '(' ParamList ')'      				{GInstall($<c>1,-1,-1,-1,-1,$<param>3);}
		 | ID '('')'								{GInstall($<c>1,-1,-1,-1,-1,NULL);};
ParamList:  ParamList ',' Param     				{AppendParamlist($<param>1,$<param>3);$$=$1;}      
		   |Param                  					{$$=$<param>1;};           
Param:   Type ID 									{$$=CreateParamlist($<i>1,$<c>2);};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
Slist : Slist Stmt                                  {$$=makeConnectorNode('.',$<no>1,$<no>2);}
	  | Stmt                                        {$$=$<no>1;};    
Stmt : InputStmt                                    {$$=$<no>1;}
	   | OutputStmt                                 {$$=$<no>1;}
	   | AsgStmt                                    {$$=$<no>1;}
	   | Ifstmt                                     {$$=$<no>1;}
	   | Whilestmt                                  {$$=$<no>1;}
	   | Dowhilestmt                                {$$=$<no>1;}
	   | Repeatuntil                                {$$=$<no>1;}
	   | BREAK                                      {char c[6]="break";
													$$=makeBreak_ContinueNode(c);}
	   | CONTINUE                                   {char c[9]="continue";
													$$=makeBreak_ContinueNode(c);}; 
///////////////////////////////////////////////////////////////////////////////////////////////////////////  
Ifstmt  : IF '(' E ')' Then Slist Else Slist ENDIF {struct tnode* else_node;
													struct tnode* connector_node;
													else_node=makeBranchingNode("Else",$<no>8,NULL);
													connector_node=makeConnectorNode('.',$<no>6,else_node);
													$$=makeBranchingNode("If",$<no>3,connector_node);}
		| IF '(' E ')' Then Slist ENDIF            {$$=makeBranchingNode("If",$<no>3,$<no>6);};
Whilestmt : WHILE '(' E ')' DO Slist ENDWHILE      {$$=makeBranchingNode("While",$<no>3,$<no>6);};
Dowhilestmt: DO Slist WHILE '(' E ')'              {$$=makeBranchingNode("Do",$<no>2,$<no>5);};
Repeatuntil: REPEAT Slist UNTIL '(' E ')'          {$$=makeBranchingNode("Repeat",$<no>2,$<no>5);};
InputStmt : READ '(' ID ')'                        {struct tnode* var=makeVariableNode($<c>3);
													$$=makereadnode(var);}
		   |READ '(' ID '[' E ']' ')'              {struct tnode* var=makeVariableNode($<c>3);
													indextypecheck($<no>5->type);
													var->left=$<no>5;
													$$=makereadnode(var);}
			|READ '(' ID '[' E ']' '[' E ']' ')'   {struct tnode* var=makeVariableNode($<c>3);
													indextypecheck($<no>5->type);
													indextypecheck($<no>8->type);
													var->left=$<no>5;    //Row
													var->right=$<no>8;  //Column
													$$=makereadnode(var);};
OutputStmt : WRITE '(' E ')' 					   {$$=makewritenode($<no>3);};
AsgStmt :ID EQUAL E 							   {struct tnode* var=makeVariableNode($<c>1);
													$$ = makeOperatorNode('=',var,$<no>3);}
		|ID '[' E ']' EQUAL E 					   {struct tnode* var=makeVariableNode($<c>1);
													indextypecheck($<no>3->type);
													var->left=$<no>3;
													$$ = makeOperatorNode('=',var,$<no>6);}
		|ID '[' E ']' '[' E ']' EQUAL E 		   {struct tnode* var=makeVariableNode($<c>1);
													indextypecheck($<no>3->type);
													indextypecheck($<no>6->type);
													var->left=$<no>3;    //Row
													var->right=$<no>6;  //Column
													$$=makeOperatorNode('=',var,$<no>9);};                                                           
E : E PLUS E									   {$$ = makeOperatorNode('+',$<no>1,$<no>3);}
	 | E MINUS E  								   {$$ = makeOperatorNode('-',$<no>1,$<no>3);}
	 | E MUL E									   {$$ = makeOperatorNode('*',$<no>1,$<no>3);}
	 | E DIV E									   {$$ = makeOperatorNode('/',$<no>1,$<no>3);}
	 | E MOD E									   {$$ = makeOperatorNode('%',$<no>1,$<no>3);} 
	 | '(' E ')'								   {$$ = $<no>2;}
	 | ID '[' E ']'  							   {struct tnode* var=makeVariableNode($<c>1);
													indextypecheck($<no>3->type);
													var->left=$<no>3;
													$$=var;}
	 |ID '[' E ']' '[' E ']' 						{struct tnode* var=makeVariableNode($<c>1);
													indextypecheck($<no>3->type);
													indextypecheck($<no>6->type);
													var->left=$<no>3;    //Row
													var->right=$<no>6;  //Column 
													$$=var;} 
	 | NUM										   {$$= makeConstantNode($<i>1,NULL);}
	 | ID           							   {$$= makeVariableNode($<c>1);}     
	 | STRING       							   {$$= makeConstantNode(-1,$<c>1);}        
	 | E COMP E 								   {$$= makeComparisonNode($<c>2,$<no>1,$<no>3);}
	 | E AND E                                     {$$= makeLogicalNode($<c>2,$<no>1,$<no>3);}
	 | E OR E                                      {$$= makeLogicalNode($<c>2,$<no>1,$<no>3);}
	 | E XOR E                                     {$$= makeLogicalNode($<c>2,$<no>1,$<no>3);}
	 | NOT E                                       {$$= makeLogicalNode($<c>1,$<no>2,NULL);}

	 //For Function Call
	 |ID '('')'                                    {struct Gsymbol* gtemp = GLookup($<c>1);
													if(gtemp == NULL){yyerror("Yacc : Undefined function");exit(1);}}
	 |ID '(' ArgList ')'                           {
													struct Gsymbol* gtemp= GLookup($<c>1);
													if(gtemp == NULL){yyerror("Yacc : Undefined function\n");exit(1);}
													//Type checks the return types;
													int typecheck=funccallargsvalidate(gtemp,$<no>3);
													if(typecheck==-1)
													{yyerror("Yacc :invalid argument return type \n");exit(1);}
													$$ = makeFunctionNode($<c>1,$<no>3,gtemp);
						                           };
ArgList : ArgList ',' E                            {
													struct tnode* temp=$<no>1;
													if(temp==NULL)
														printf("Arg NULL error");
													else
													{
														while(temp->next!=NULL)
															temp=temp->next;
														
														temp->next=$<no>3;
													}
													$$=$<no>1;   
												   }
		  | E                                      {$$=$<no>1;};                                   //Arglist contains the value of the argument
////////////////////////////////////////////////////////////////////////////////////////////////////
//MAIN FUNCTION:
MainBlock : INT MAIN '(' ')' '{' LdeclBlock Body '}'
														{
															if(GHEAD==NULL) //NO GDECL BLOCK
															{
																fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															//printlst();
															fprintf(fptr,"F0:\n");
															//Function code generation
															funccode(fptr,$7->left,$7->right,Integer);
															//After function code generation
															LClear($<c>2);//to clear the symbol table
															Freeast($<no>7->left);//Clear the function body ast
															printf("AST CLEARED\n");
															Freeast($<no>7->right);//Clear the return expr ast
															freereg_no=-1;
														}
			|INT MAIN '(' ')' '{' Body '}'               
														{
															if(GHEAD==NULL) //NO GDECL BLOCK
															{
																fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															//printlst();
															fprintf(fptr,"F0:\n");
															//Function code generation
															funccode(fptr,$<no>6->left,$<no>6->right,Integer);
															//After function code generation
															LClear($<c>2);//to clear the symbol table
															Freeast($<no>6->left);//Clear the function body ast
															Freeast($<no>6->right);//Clear the return expr ast
															freereg_no=-1;
														};
////////////////////////////////////////////////////////////////////////////////////////////////////
//Function Definition
FDefList  : FDefList FDefBlock
		   | FDefBlock;
FDefBlock : Type ID '(' FdefParamList ')' '{' LdeclBlock Body '}'  {    int isdefined=validate($<i>1,$<c>2,$<param>4); 
																		if(isdefined!=-1)   //if function is defined
																		{
																			//printlst();
																			
																			struct Gsymbol* func=GLookup($<c>2);
																			int funclabel=func->flabel;
																			fprintf(fptr,"F%d:\n",funclabel);                                      //Function label
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,$<no>8->left,$<no>8->right,$<i>1);
																			////////////////////////////////////////////
																			//After function code generation
																			LClear($<c>2);//to clear the symbol table
																			Freeast($<no>8->left);//Clear the function body ast
																			Freeast($<no>8->right);//Clear the return expr ast
																			freereg_no=-1;
																			////////////////////////////////////////////
																		}
																		else
																		{
																			LClear($<c>2);//to clear the symbol table and resets the localargs and localvar
																			Freeast($<no>8->left);//Clear the function body ast
																			Freeast($<no>8->right);//Clear the return expr ast
																			freereg_no=-1;
																			printf("Function arguments invalid:\n");
																			exit(1);
																		}
																	}
		   |Type ID '(' FdefParamList ')' '{' Body '}'              {
																		int isdefined=validate($<i>1,$<c>2,$<param>4); 
																		if(isdefined!=-1)   //if function is defined
																		{
																			//printlst();
																			
																			struct Gsymbol* func=GLookup($<c>2);
																			int funclabel=func->flabel;
																			fprintf(fptr,"F%d:\n",funclabel);                                      //Function label
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,$<no>7->left,$<no>7->right,$<i>1);
																			////////////////////////////////////////////
																			//After function code generation
																			LClear($<c>2);//to clear the symbol table
																			Freeast($<no>7->left);//Clear the function body ast
																			Freeast($<no>7->right);//Clear the return expr ast
																			freereg_no=-1;
																			////////////////////////////////////////////
																		}
																		else
																		{
																			LClear($<c>2);//to clear the symbol table and resets the localargs and localvar
																			Freeast($<no>7->left);//Clear the function body ast
																			Freeast($<no>7->right);//Clear the return expr ast
																			freereg_no=-1;
																			printf("Function arguments invalid:\n");
																			exit(1);
																		}
																	};
/////////////////////////////////////////////////////////////////////////////////////////////
FdefParamList:  FdefParamList ',' FdefParam     				{AppendParamlist($<param>1,$<param>3);$$=$<param>1;}      
				|FdefParam                  					{$$=$<param>1;};           
FdefParam:      Type ID 									    {   
																	struct Parameter* temp=CreateParamlist($<i>1,$<c>2);
																	//Create local symbol table
																	//Linstall Adds the arguments and increments num_args
																	LInstall(NULL,-1,temp);  
																	$$=temp;         
																};
/////////////////////////////////////////////////////////////////////////////////////////////
LdeclBlock : DECL LDecList ENDDECL                         //Now both local arguments and local variables have been added to the local symbol table              
			| DECL ENDDECL                     
LDecList : LDecList LDecl | LDecl
LDecl : Type IdList                           {addltype($<i>1);}
											 //Linstall Adds the variables and increments num_var
IdList : IdList ',' ID                        {LInstall($<c>3,-1,NULL);}
		| ID                                  {LInstall($<c>1,-1,NULL);};
//////////////////////////////////////////////////////////////////////////////////
Body   : BEG Slist Retstmt END                 {$$=makeConnectorNode('.',$<no>2,$<no>3);
												//printtree($<no>2);
												addlbinding();
											 	//printlst();
											  };
Retstmt : RET E                                {$$=$<no>2;};
/////////////////////////////////////////////////////////////////////////////////////
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
	fptr=fopen("ast.o","w");

	yyparse();
	
	return 0;
}
												
												

