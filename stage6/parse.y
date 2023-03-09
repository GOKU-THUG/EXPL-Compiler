%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	
	//Type Table
	#include "typetable.h"
	#include "typetable.c"

	//Symbol table
	#include "symboltable.h"
	#include "symboltable.c"
	
	//AST CREATION
	#include "ast.h"
	#include "ast.c"

	//CODEGENERATION
    #include "codegen.h"
	#include "codegen.c"
	
	extern FILE* yyin;
	extern char* yytext;
	FILE* fptr;
    int flag=0;

	int yylex(void);
	int yyerror();
	void indextypecheck(char* type);
%}

%union{
	struct tnode *no;
	struct Gsymbol* symbol;
	struct Parameter* param;
	struct Fieldlist* field;
	char* c;
	int i;
}
 
%type <no>  Program Slist Stmt InputStmt OutputStmt AsgStmt E Ifstmt Whilestmt Dowhilestmt Repeatuntil Retstmt Body ArgList FreeStmt FIELD
%type <param> ParamList Param FdefParam FdefParamList
%type <c> Type
%type <field> FieldDecl FieldDeclList
%token BEG END READ WRITE ID NUM PLUS MINUS MUL DIV EQUAL IF Then Else ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR VOID STRING MOD RET MAIN AND OR NOT XOR TYPE ENDTYPE INITIALIZE ALLOC FREE NULLPTR
%right EQUAL
%left AND OR NOT XOR
%left COMP
%left PLUS MINUS
%left MUL DIV MOD

%%
Program : TypeDefBlock GDeclBlock FDefList MainBlock            {exit(1);}
          |TypeDefBlock GDeclBlock MainBlock            {exit(1);};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
TypeDefBlock  : TYPE TypeDefList ENDTYPE    
			  |
			  ;

TypeDefList   : TypeDefList TypeDef         {printtypetable();}
			  | TypeDef                     {printtypetable();}
			  ;

TypeDef       : ID '{' FieldDeclList '}'   { 
                                                //Flags error if the number of member fields is 9 or more
                                                if(fieldindex>=9)   //only 7 members because the first index of every block is used for storing the next free block
                                                {
                                                    printf("Too Many Member Fields:\n");
                                                    exit(1);
                                                }
                                                int size=fieldindex-1;
                                                fieldindex=1;
                                                
												struct Typetable* Tptr = TInstall($<c>1,size,$<field>3); 

												struct Fieldlist* field=$<field>3;
										
												while(field!=NULL){
                                                    if(field->type==NULL)
                                                    {
                                                        if(strcmp(field->nametype,$<c>1)==0)
                                                            field->type=Tptr;                       //Assigning the type to the fields;
                                                        
                                                        else
                                                        {
                                                            printf("Invalid type:\n");
                                                            exit(1);
                                                        }
                                                    }
													field=field->next;
												}

											}
			  ;

FieldDeclList : FieldDeclList FieldDecl     {Fappend($<field>1,$<field>2);$$=$<field>1;}
			  | FieldDecl                   {$$=$<field>1;}
			  ;

FieldDecl    : Type ID  {$$=Fcreate($<c>2,$<c>1);}          //Fcreate creates a newnode of type fieldlist.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
GDeclBlock : DECL GDeclList ENDDECL                 {  
														printgst();
														fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
														fprintf(fptr,"MOV SP,%d\n",4095+used_space);
														fprintf(fptr,"MOV BP,SP\n");
														fprintf(fptr,"ADD SP,1\n");    //For return value
														fprintf(fptr,"CALL F0\n");
														fprintf(fptr,"SUB SP,1\n");     //Popping the return value
														fprintf(fptr,"INT 10\n");
													} 
			| DECL ENDDECL                          {} 
			|                                       {}
			;
GDeclList :  GDeclList GDecl|GDecl
GDecl      : Type Gidlist                           {addgtype($<c>1);};
Type : INT                                          {$$=$<c>1;}
	   | STR                                        {$$=$<c>1;}
	   | VOID										{$$=$<c>1;}
	   | ID											{$$=$<c>1;};
Gidlist    : Gidlist ',' Gid
		   |   Gid      
Gid :	   ID '[' NUM ']'                           {GInstall($<c>1,NULL,$<i>3,-1,-1,NULL);}                                 
		 | ID '[' NUM ']' '[' NUM ']'               {GInstall($<c>1,NULL,$<i>3*$<i>6,$<i>3,$<i>6,NULL);}
		 | ID                                       {GInstall($<c>1,NULL,1,-1,-1,NULL);}
		 | ID '(' ParamList ')'      				{GInstall($<c>1,NULL,-1,-1,-1,$<param>3);}
		 | ID '('')'								{GInstall($<c>1,NULL,-1,-1,-1,NULL);};
ParamList:  ParamList ',' Param     				{AppendParamlist($<param>1,$<param>3);$$=$1;}      
		   |Param                  					{$$=$<param>1;};           
Param:   Type ID 									{$$=CreateParamlist($<c>1,$<c>2);};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
Slist : Slist Stmt                                  {$$=makeConnectorNode('.',$<no>1,$<no>2);}
	  | Stmt                                        {$$=$<no>1;}
	  |                                             {}
	  ;    
Stmt : InputStmt                                    {$$=$<no>1;}
	   | OutputStmt                                 {$$=$<no>1;}
	   | AsgStmt                                    {$$=$<no>1;}
	   | Ifstmt                                     {$$=$<no>1;}
	   | Whilestmt                                  {$$=$<no>1;}
	   | Dowhilestmt                                {$$=$<no>1;}
	   | Repeatuntil                                {$$=$<no>1;}
	   | FreeStmt									{$$=$<no>1;}
	   | BREAK                                      {char c[6]="break";
													$$=makeBreak_ContinueNode(c);}
	   | CONTINUE                                   {char c[9]="continue";
													$$=makeBreak_ContinueNode(c);}; 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
Ifstmt  : IF '(' E ')' Then Slist Else Slist ENDIF {struct tnode* else_node;
													struct tnode* connector_node;
													else_node=makeBranchingNode("Else",$<no>8,NULL);
													connector_node=makeConnectorNode('.',$<no>6,else_node);
													$$=makeBranchingNode("If",$<no>3,connector_node);}
		| IF '(' E ')' Then Slist ENDIF            {$$=makeBranchingNode("If",$<no>3,$<no>6);};
Whilestmt : WHILE '(' E ')' DO Slist ENDWHILE      {$$=makeBranchingNode("While",$<no>3,$<no>6);};
Dowhilestmt: DO Slist WHILE '(' E ')'              {$$=makeBranchingNode("Do",$<no>2,$<no>5);};
Repeatuntil: REPEAT Slist UNTIL '(' E ')'          {$$=makeBranchingNode("Repeat",$<no>2,$<no>5);};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
InputStmt : READ '(' ID ')'                        {struct tnode* var=makeVariableNode($<c>3);
													$$=makereadnode(var);}
		   |READ '(' ID '[' E ']' ')'              {struct tnode* var=makeVariableNode($<c>3);
													indextypecheck($<no>5->type->name);
													var->left=$<no>5;
													$$=makereadnode(var);}
			|READ '(' ID '[' E ']' '[' E ']' ')'   {struct tnode* var=makeVariableNode($<c>3);
													indextypecheck($<no>5->type->name);
													indextypecheck($<no>8->type->name);
													var->left=$<no>5;    //Row
													var->right=$<no>8;  //Column
													$$=makereadnode(var);}
			|READ '(' FIELD ')'                     {$$=makereadnode($<no>3);}
			;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FreeStmt:  FREE '(' ID ')'                          {
                                                        struct tnode* var=makeVariableNode($<c>3);
												        $$==dynamicmemorynode(var->type,Free,var,NULL);
                                                    }
          | FREE '(' FIELD ')'	                    { $$==dynamicmemorynode($<no>3->type,Free,$<no>3,NULL);}
		  ;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////	  
OutputStmt : WRITE '(' E ')' 					   {$$=makewritenode($<no>3);};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
AsgStmt :ID EQUAL E 							   {struct tnode* var=makeVariableNode($<c>1);
													$$ = makeOperatorNode('=',var,$<no>3);}
		|ID '[' E ']' EQUAL E 					   {struct tnode* var=makeVariableNode($<c>1);
													indextypecheck($<no>3->type->name);
													var->left=$<no>3;
													$$ = makeOperatorNode('=',var,$<no>6);}
		|ID '[' E ']' '[' E ']' EQUAL E 		   {struct tnode* var=makeVariableNode($<c>1);
													indextypecheck($<no>3->type->name);
													indextypecheck($<no>6->type->name);
													var->left=$<no>3;    //Row
													var->right=$<no>6;  //Column
													$$=makeOperatorNode('=',var,$<no>9);}  
        |FIELD EQUAL E                          {$$ = makeOperatorNode('=',$<no>1,$<no>3);}
		|ID EQUAL ALLOC'(' ')'                  { 
												 struct tnode* var=makeVariableNode($<c>1);
												 struct tnode* allocnode=dynamicmemorynode(var->type,Alloc,NULL,NULL);
												 $$=makeOperatorNode('=',var,allocnode);
												}
        |FIELD EQUAL ALLOC'(' ')' 				{
													struct tnode* allocnode=dynamicmemorynode($<no>1->type,Alloc,NULL,NULL);
													$$=makeOperatorNode('=',$<no>1,allocnode);
												}	
        |ID EQUAL INITIALIZE '(' ')'            { 
												 struct tnode* var=makeVariableNode($<c>1);
												 struct tnode* initializenode=dynamicmemorynode(var->type,Initialize,NULL,NULL);
												 $$=makeOperatorNode('=',var,initializenode);
												}
        |FIELD EQUAL INITIALIZE '(' ')' 		{
													struct tnode* initializenode=dynamicmemorynode($<no>1->type,Initialize,NULL,NULL);
													$$=makeOperatorNode('=',$<no>1,initializenode);
												}	
		
        ;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FIELD     : ID '.' ID							{	
                                                    //printf("%s,%s",$<c>1,$<c>3);
													struct tnode* var=makeVariableNode($<c>1);	
													struct tnode* field=makefieldnode($<c>3,var->type);
													var->left=field;
													var->type=field->type;
													$$=var;
												}
          | FIELD '.' ID							{
														struct tnode* var=$<no>1;
														struct tnode* field=makefieldnode($<c>3,var->type);
														
														struct tnode* iterfield=var->left;

		  												while(iterfield->next!=NULL)
															iterfield=iterfield->next;
														
														iterfield->next=field;
														var->type=field->type;
														$$=var;
		  											}
          ;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////		                                                          
E : E PLUS E									   {$$ = makeOperatorNode('+',$<no>1,$<no>3);}
	 | E MINUS E  								   {$$ = makeOperatorNode('-',$<no>1,$<no>3);}
	 | E MUL E									   {$$ = makeOperatorNode('*',$<no>1,$<no>3);}
	 | E DIV E									   {$$ = makeOperatorNode('/',$<no>1,$<no>3);}
	 | E MOD E									   {$$ = makeOperatorNode('%',$<no>1,$<no>3);} 
	 | '(' E ')'								   {$$ = $<no>2;}
	 | ID '[' E ']'  							   {struct tnode* var=makeVariableNode($<c>1);
													indextypecheck($<no>3->type->name);
													var->left=$<no>3;
													$$=var;}
	 |ID '[' E ']' '[' E ']' 						{struct tnode* var=makeVariableNode($<c>1);
													indextypecheck($<no>3->type->name);
													indextypecheck($<no>6->type->name);
													var->left=$<no>3;    //Row
													var->right=$<no>6;  //Column 
													$$=var;} 
	 | NUM										   {$$= makeConstantNode($<i>1,NULL);}
	 | ID           							   {$$= makeVariableNode($<c>1);}
     | NULLPTR                                        {$$= makeConstantNode(-1,NULL);}
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
													//Type checks the return types of each argument with the formal parameters;
													int typecheck=funccallargsvalidate(gtemp,$<no>3);
													if(typecheck==-1)
													{yyerror("Yacc :invalid argument return type \n");exit(1);}
													$$ = makeFunctionNode($<c>1,$<no>3,gtemp);
												   }
	//For members of a user defined type
	|FIELD 		                                   {$$=$<no>1;};								 
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
															if(GHEAD==NULL && flag==0) //NO GDECL BLOCK
															{
																fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															fprintf(fptr,"F0:\n");
															//Function code generation
															funccode(fptr,$7->left,$7->right,$<c>1);
															//After function code generation
															LClear($<c>2);//to clear the symbol table
															Freeast($<no>7->left);//Clear the function body ast
															printf("AST CLEARED\n");
															Freeast($<no>7->right);//Clear the return expr ast
															freereg_no=-1;
														}
			|INT MAIN '(' ')' '{' Body '}'               
														{
															if(GHEAD==NULL && flag==0) //NO GDECL BLOCK and function definition
															{
																fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															fprintf(fptr,"F0:\n");
															//Function code generation
															funccode(fptr,$<no>6->left,$<no>6->right,$<c>1);
															//After function code generation
															LClear($<c>2);//to clear the symbol table
															Freeast($<no>6->left);//Clear the function body ast
															Freeast($<no>6->right);//Clear the return expr ast
															freereg_no=-1;
														};
////////////////////////////////////////////////////////////////////////////////////////////////////
//FUNCTION DEFINITION

FDefList  : FDefList FDefBlock  
		   | FDefBlock       
		   
FDefBlock : Type ID '(' FdefParamList ')' '{' LdeclBlock Body '}'  {    

                                                                        if(GHEAD==NULL && flag==0) //first function and no global declaration
                                                                        {   
                                                                            flag=1;

                                                                            fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
                                                                            fprintf(fptr,"MOV SP,%d\n",4095+used_space);
                                                                            fprintf(fptr,"MOV BP,SP\n");
                                                                            fprintf(fptr,"ADD SP,1\n");    //For return value
                                                                            fprintf(fptr,"CALL F0\n");
                                                                            fprintf(fptr,"SUB SP,1\n");     //Popping the return value
                                                                            fprintf(fptr,"INT 10\n");
                                                                        }

                                                                        int isdefined=validate($<c>1,$<c>2,$<param>4); 
																		if(isdefined!=-1)   //if function is defined
																		{
																			
																			struct Gsymbol* func=GLookup($<c>2);
																			int funclabel=func->flabel;
																			fprintf(fptr,"F%d:\n",funclabel);                                      //Function label
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,$<no>8->left,$<no>8->right,$<c>1);
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

                                                                        if(GHEAD==NULL && flag==0) //first function and no global declaration
                                                                        {   
                                                                            flag=1;
                                                                           
                                                                            fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
                                                                            fprintf(fptr,"MOV SP,%d\n",4095+used_space);
                                                                            fprintf(fptr,"MOV BP,SP\n");
                                                                            fprintf(fptr,"ADD SP,1\n");    //For return value
                                                                            fprintf(fptr,"CALL F0\n");
                                                                            fprintf(fptr,"SUB SP,1\n");     //Popping the return value
                                                                            fprintf(fptr,"INT 10\n");
                                                                        }

																		int isdefined=validate($<c>1,$<c>2,$<param>4); 
																		if(isdefined!=-1)   //if function is defined
																		{
																			struct tnode* temp=$<no>7;

																			struct Gsymbol* func=GLookup($<c>2);
																			int funclabel=func->flabel;
																			fprintf(fptr,"F%d:\n",funclabel);                                      //Function label
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,$<no>7->left,$<no>7->right,$<c>1);
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
//FUNCTION PARAMETERS

FdefParamList:  FdefParamList ',' FdefParam     				{AppendParamlist($<param>1,$<param>3);$$=$<param>1;}      
				|FdefParam                  					{$$=$<param>1;};           
FdefParam:      Type ID 									    {   
																	struct Parameter* temp=CreateParamlist($<c>1,$<c>2);
																	//Create local symbol table
																	//Linstall Adds the arguments and increments num_args
																	LInstall(NULL,NULL,temp);  
																	$$=temp;         
																};
/////////////////////////////////////////////////////////////////////////////////////////////
//LOCAL VARIABLES
	
LdeclBlock : DECL LDecList ENDDECL                          
			| DECL ENDDECL                     
LDecList : LDecList LDecl | LDecl
LDecl : Type IdList                           {addltype($<c>1);}
											 //Linstall Adds the variables and increments num_var
IdList : IdList ',' ID                        {LInstall($<c>3,NULL,NULL);}
		| ID                                  {LInstall($<c>1,NULL,NULL);};
//////////////////////////////////////////////////////////////////////////////////
//FUNCTION BODY

Body   : BEG Slist Retstmt END                 {$$=makeConnectorNode('.',$<no>2,$<no>3);
												//printtree($<no>2);
												addlbinding();
                                                printlst();
                                                
                                              };
Retstmt : RET E                                {$$=$<no>2;};
/////////////////////////////////////////////////////////////////////////////////////
%%

int yyerror(char const *s)
{
	printf("yyerror %s",s);
	return 0;
}

void indextypecheck(char* type)
{
	if(strcmp(type,"int")!=0)
	{
		printf("Invalid 2D array index\n");
		exit(1);
	}
}

int main(void) 
{
	yyin=fopen("input.txt","r");
	fptr=fopen("input.o","w");

	//Initializing the default values in the type table
	TypetableCreate();
	printtypetable();
	yyparse();
	
	return 0;
}
												
												

