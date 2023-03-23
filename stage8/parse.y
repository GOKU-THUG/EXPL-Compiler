%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	
	//Type Table
	#include "typetable.h"
	#include "typetable.c"

	//Class Table
	#include "classtable.h"
	#include "classtable.c"

	//Symbol table
	#include "symboltable.h"
	#include "symboltable.c"
	
	
	//AST CREATION
	#include "ast.h"
	#include "ast.c"

	struct Classtable* Cptr=NULL;       //Pointer to class in class table
	//CODEGENERATION
	#include "codegen.h"
	#include "codegen.c"
	
	extern FILE* yyin;
	extern char* yytext;
	FILE* fptr;
	extern int yylineno;
	int flag=0;
    int isfuncdefined=0;

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
 
%type <no>  Program Slistblock Slist Stmt InputStmt OutputStmt AsgStmt E Ifstmt Whilestmt Dowhilestmt Repeatuntil Retstmt Body ArglistBlock ArgList FreeStmt FIELD FieldFunction
%type <param> ParamList Param FdefParam FdefParamList FdefParamListBlock
%type <c> Type
%type <field> FieldDecl FieldDeclList
%token BEG END READ WRITE ID NUM PLUS MINUS MUL DIV EQUAL IF Then Else ENDIF WHILE DO ENDWHILE REPEAT UNTIL BREAK CONTINUE DECL ENDDECL INT STR VOID STRING MOD RET MAIN AND OR NOT XOR TYPE ENDTYPE INITIALIZE ALLOC FREE NULLPTR CLASS ENDCLASS Extends NEW DELETE SELF
%right EQUAL
%left AND OR NOT XOR
%left COMP
%left PLUS MINUS
%left MUL DIV MOD

%%
Program : TypeDefBlock ClassDefBlock GDeclBlock FDefList MainBlock    {if(isfuncdefined!=0)
                                                                        printf("FUNCTION NOT DEFINED\n");
                                                                        exit(1);
                                                                      }
		  |TypeDefBlock ClassDefBlock GDeclBlock MainBlock            {
                                                                        if(isfuncdefined!=0)
                                                                            printf("FUNCTION NOT DEFINED\n");
                                                                        exit(1);
                                                                       };
////////////////////////////////////////////////////////////////////////////////////////////////////////////
TypeDefBlock  : TYPE TypeDefList ENDTYPE    
			  |
			  ;

TypeDefList   : TypeDefList TypeDef         {printtypetable();}
			  | TypeDef                     {printtypetable();}
			  ;

TypeDef       : ID '{' FieldDeclList '}'   { 
												//Flags error if the number of member fields is 9 or more
												if(fieldindex>9)   //only 8 members because the first index of every block is used for storing the next free block
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

FieldDeclList : FieldDeclList FieldDecl  ';'   {Fappend($<field>1,$<field>2);$$=$<field>1;}
			  | FieldDecl  ';'                 {$$=$<field>1;}
			  ;

FieldDecl    : Type ID  {$$=Fcreate($<c>2,$<c>1);}          //Fcreate creates a newnode of type fieldlist.
////////////////////////////////////////////////////////////////////////////////////////////////////////////
ClassDefBlock   : CLASS ClassDefList ENDCLASS 
				|
				;
ClassDefList    : ClassDefList Classdef             
				| Classdef                          
				;

Classdef        : Cname '{'DECL Fieldlists MethodDecl ENDDECL MethodDefns '}'       {
																						//Allocates space for the vft and initializes the vft with the flabels of the member functions

																						used_space+=8;
																						
																						printf("Classtable:\n");
																						printclasstable(Cptr);
																						Cptr=NULL;
																					}
				;

Cname           : ID            {Cptr = CInstall($<c>1,NULL);}
				| ID Extends ID {Cptr = CInstall($<c>1,$<c>3);} //Installs the data members and member functions of parent
				;

Fieldlists      : Fieldlists Fld        
				|
				;

Fld             :  Type ID  ';' {
								if(Cptr==NULL){printf("CPTR NULL in fieldlist\n");exit(1);}
								   
								if(Cptr->fieldcount==8)
								{
									printf("Only 8 data members possible at max\n");
									exit(1);
								}
								DInstall(Cptr,$<c>1,$<c>2);
							} //Installing the data member to the class table
				;

MethodDecl      : MethodDecl MDecl 
				| MDecl                 
				;

MDecl           : Type ID '(' ParamList ')' ';'{
                                                 isfuncdefined+=1;//for checking if all functions declared is defined or not
												if(Cptr==NULL){printf("CPTR NULL in MDecl\n");exit(1);}
								   
												if(Cptr->methodcount==8)
												{
													printf("Only 8 member functions possible at max\n");
													exit(1);
												}
												MInstall(Cptr,$<c>2,TLookup($<c>1),$<param>4);
												
											}
											//Installing the method to class table:Validation is done in classtable
				|Type ID '('')' ';' {
												isfuncdefined+=1;
												if(Cptr==NULL){printf("CPTR NULL in MDecl\n");exit(1);}
								   
												if(Cptr->methodcount==8)
												{
													printf("Only 8 member functions possible at max\n");
													exit(1);
												}
												MInstall(Cptr,$<c>2,TLookup($<c>1),NULL);
								}
											//Installing the method to class table:Validation is done in classtable
				;

MethodDefns     : MethodDefns FDefBlock
				| FDefBlock
				;
////////////////////////////////////////////////////////////////////////////////////////////////////////////
GDeclBlock : DECL GDeclList ENDDECL                 {  
														printgst();
														if(flag==0)
														{
															flag=1;
															fprintf(fptr,"MOV SP,%d\n",4095+used_space);
															fprintf(fptr,"MOV BP,SP\n");
															fprintf(fptr,"ADD SP,1\n");    //For return value
															fprintf(fptr,"CALL F0\n");
															fprintf(fptr,"SUB SP,1\n");     //Popping the return value
															fprintf(fptr,"INT 10\n");
														}
													} 
			| DECL ENDDECL                          {} 
			|                                       {}
			;
GDeclList :  GDeclList GDecl ';'
			 |GDecl ';'
GDecl      : Type Gidlist                           {addgtype($<c>1);};

Type : INT                                          {$$=$<c>1;}
	   | STR                                        {$$=$<c>1;}
	   | VOID										{$$=$<c>1;}
	   | ID											{$$=$<c>1;};    //FOR USER DEFINED TYPES(struct and classes)
Gidlist    : Gidlist ',' Gid
		   |   Gid      
Gid :	   ID '[' NUM ']'                           {GInstall($<c>1,NULL,$<i>3,-1,-1,NULL);}                                 
		 | ID '[' NUM ']' '[' NUM ']'               {GInstall($<c>1,NULL,$<i>3*$<i>6,$<i>3,$<i>6,NULL);}
		 | ID                                       {GInstall($<c>1,NULL,1,-1,-1,NULL);}
		 | ID '(' ParamList ')'      				{isfuncdefined+=1;GInstall($<c>1,NULL,-1,-1,-1,$<param>3);}
		 | ID '('')'								{isfuncdefined+=1;GInstall($<c>1,NULL,-1,-1,-1,NULL);};
ParamList:  ParamList ',' Param     				{AppendParamlist($<param>1,$<param>3);$$=$1;}      
		   |Param                  					{$$=$<param>1;};           
Param:   Type ID 									{$$=CreateParamlist($<c>1,$<c>2);};
////////////////////////////////////////////////////////////////////////////////////////////////////////////
Slistblock:Slist                                      {$$=$<no>1;}  
		   |                                          {$$=NULL;}
		   ;
Slist : Slist Stmt                                 {$$=makeConnectorNode('.',$<no>1,$<no>2);}
	  | Stmt                                        {$$=$<no>1;}
		;    
Stmt : InputStmt';'                                {$$=$<no>1;}
	   | OutputStmt';'                                 {$$=$<no>1;}
	   | AsgStmt';'                                 {$$=$<no>1;}
	   | Ifstmt';'                                 {$$=$<no>1;}
	   | Whilestmt                                 {$$=$<no>1;}
	   | Dowhilestmt                                {$$=$<no>1;}
	   | Repeatuntil';'                              {$$=$<no>1;}
	   | FreeStmt';'									{$$=$<no>1;}
	   | BREAK';'                                     {char c[6]="break";
													$$=makeBreak_ContinueNode(c);}
	   | CONTINUE';'                                  {char c[9]="continue";
													$$=makeBreak_ContinueNode(c);}
	   | DELETE '(' FIELD ')'';'                       {$$==dynamicmemorynode($<no>3->type,Delete,$<no>3,NULL);}
	   ;                                 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////// 
Ifstmt  : IF '(' E ')' Then Slistblock Else Slistblock ENDIF {struct tnode* else_node;
													struct tnode* connector_node;
													else_node=makeBranchingNode("Else",$<no>8,NULL);
													connector_node=makeConnectorNode('.',$<no>6,else_node);
													$$=makeBranchingNode("If",$<no>3,connector_node);}
		| IF '(' E ')' Then Slistblock ENDIF            {$$=makeBranchingNode("If",$<no>3,$<no>6);};
Whilestmt : WHILE '(' E ')' DO Slistblock ENDWHILE';'      {$$=makeBranchingNode("While",$<no>3,$<no>6);};
Dowhilestmt: DO Slistblock WHILE '(' E ')'';'              {$$=makeBranchingNode("Do",$<no>2,$<no>5);};
Repeatuntil: REPEAT Slistblock UNTIL '(' E ')'          {$$=makeBranchingNode("Repeat",$<no>2,$<no>5);};
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
AsgStmt :ID EQUAL E 							   {
													struct tnode* var=makeVariableNode($<c>1);
													//if ID and E are classes then makeoperator node typechecks and also checks if E is a valid descendent of ID
													$$ = makeOperatorNode('=',var,$<no>3);  
												   }
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
		|FIELD EQUAL E                          {
													//FIELD CAN ONLY BE A CLASS:SELF.ID
													//operator node checks if is descendant class or not.
													$$ = makeOperatorNode('=',$<no>1,$<no>3);}
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
		| ID EQUAL NEW '(' ID ')'               {
													//checks if valid(descendent and parent class or not) and exits if error else does nothing
													//descendent class validation
													struct tnode* var=makeVariableNode($<c>1);
													if(var->Lentry!=NULL) //it will surely be a userdefined datatype     
													{
														printf("Cannot assign new to non-object:Lentry\n");
														exit(1);
													}
												   
													if(var->Gentry->ctype==NULL)
													{
														printf("Cannot assign new to non-object:Gentry\n");
														exit(1);
													}

													int valid=isvalid(var->Gentry->ctype->name,$<c>5);  

													if(valid==-1)
													{   
														printf("Desc class and parent class mismatch:\n");
														exit(1);
													} 

													struct Classtable* descclass=CLookup($<c>5);
													struct tnode* var1=makeVariableNode($<c>1);
													struct tnode* constnode=makeConstantNode(4096+8*(descclass->class_index),NULL);
													struct tnode* newnode=dynamicmemorynode(var1->type,New,var1,constnode);
													$$=makeOperatorNode('=',var,newnode);
												}
		| FIELD EQUAL NEW '(' ID ')'            {
													//FIELD CAN ONLY be a class or userdeftype.
													struct tnode* var=$<no>1;
													struct tnode *var1=makeVariableNode(var->varname);
													var1->type=var->type;	//since var's type is changed to field type.
													///////////////////////////////////////////////////////////////
													struct tnode* iterfield=var->left;
						
													while(iterfield->next!=NULL)
														iterfield=iterfield->next;
													
													if(iterfield->field->ctype==NULL)
													{
														printf("Cannot assign new to non-object field:field equal new(id)\n");
														exit(1);
													}
													int valid=isvalid(iterfield->field->ctype->name,$<c>5);  

													if(valid==-1)
													{   
														printf("Desc class and parent class mismatch:field equal new(id)\n");
														exit(1);
													} 
													///////////////////////////////////////////////////////////////
													struct tnode* temp=var1;
													iterfield=var->left;
													
													temp->left=(struct tnode *)malloc(sizeof(struct tnode));
													temp->left->type=iterfield->type;
													temp->left->nodetype=iterfield->nodetype;
													temp->left->field=iterfield->field;
													temp->left->left=NULL;
													temp->left->right=NULL;
													temp->left->next=NULL;
													
													temp=temp->left;
													iterfield=iterfield->next;

													while(iterfield!=NULL)
													{
														temp->next=(struct tnode *)malloc(sizeof(struct tnode));
														temp->next->type=iterfield->type;
														temp->next->nodetype=iterfield->nodetype;
														temp->next->field=iterfield->field;
														temp->next->left=NULL;
														temp->next->right=NULL;
														temp->next->next=NULL;
														
														temp=temp->next;
														iterfield=iterfield->next;
													}
													//////////////////////////////////////////////////////////////////////
													//After above step indicates that the type is null.Hence by default ctype will not be null.
													//NOTE:Inside dynamic memory node we check if field is a class or not.
													struct Classtable* descclass=CLookup($<c>5);
													struct tnode* constnode=makeConstantNode(4096+8*(descclass->class_index),NULL);
													struct tnode* newnode=dynamicmemorynode(var->type,New,var1,constnode);   
													//the beow code is put after dynamic memory node because it will detect if it is a class or not
													$$=makeOperatorNode('=',var,newnode);
												}
		;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
FIELD     :  SELF '.' ID                            { 
														 //Below code is incase there is no parameters and local declarations inside the function of the class
														 if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
															LInstall("self",NULL,NULL,Cptr);
														
														if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
															LInstall("vft",NULL,NULL,Cptr);
														
														struct tnode* var=makeVariableNode("self");
														struct tnode* field;
														if(Cptr==NULL)
														{
															printf("CPTR IS NULL\n");
															exit(1);
														}
														field=makefieldnode($<c>3,NULL,Cptr);   //field can be of class or userdefined type:Hence 3 arguments are given to makefieldnode
														var->left=field;
														var->type=field->type;
														$$=var;
													}//check is the data member is defined

			|ID '.' ID							    {   //First ID always has a type,can never be a class
														//First ID cannot be a class because the second id cannot be a data member
														//printf("%s,%s",$<c>1,$<c>3);
														struct tnode* var=makeVariableNode($<c>1);	
														struct tnode* field;
														if(var->Gentry!=NULL && var->Lentry==NULL && var->Gentry->ctype!=NULL)
														{
															printf("Data members can only be accessed through member functions:%s\n",$<c>3);
															exit(1);
														}
														field=makefieldnode($<c>3,var->type,NULL);
														var->left=field;
														var->type=field->type;
														$$=var;
													}
		  | FIELD '.' ID							{
														struct tnode* var=$<no>1;
														//If field is a class then var->type will be null else it won't be null
														struct tnode* field;
														
														if(var->type==NULL)      //Classes cannot access data members directly
														{
																printf("Cannot access member function from non-object\n in field");
																exit(1);
														}
														struct tnode* iterfield=var->left;

		  												while(iterfield->next!=NULL)
															iterfield=iterfield->next;
														
														field=makefieldnode($<c>3,iterfield->field->type,iterfield->field->ctype);

														iterfield->next=field;
														var->type=field->type;
														$$=var;
		  											}
		  ;
//Member functions
FieldFunction   : SELF '.' ID '(' ArglistBlock ')'           {   
															//Below code is incase there is no parameters and local declarations inside the function of the class
															if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
																LInstall("self",NULL,NULL,Cptr);
															
															if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
																LInstall("vft",NULL,NULL,Cptr);

															struct Memberfunclist* member=MLookup(Cptr,$<c>3);
															if(member==NULL)
																{yyerror("Yacc : Undefined Member function for self");exit(1);}
															
															struct tnode* temp=$<no>5;

															int typecheck=funccallargsvalidate(NULL,temp,member);
															if(typecheck==-1)
															{yyerror("Yacc :invalid argument return type for member function of class\n");exit(1);}
														   
															//Arguments(makefunctionnode):funcname,arglist(left child),gsymboltable(outside class functions),memberfunclist pointer(inside class functions),rightnode(for self/id/field)
															struct tnode* var=makeVariableNode("self");     //It is present in the local symbol table
															struct tnode* vft=makeVariableNode("vft");      //vft from local symbol table
															var->next=vft;
															$$ = makeFunctionNode($<c>3,$<no>5,NULL,member,var);
														}
				| ID '.' ID '(' ArglistBlock ')'             {   //The class variable is always declared in the global symbol table.
															//This will not occurinside a class.Eg:a.b(c):WIthin functions outside class
															struct tnode* temp=$<no>5;
															struct tnode* var=makeVariableNode($<c>1);
															if(var->Lentry!=NULL)     
															{
																printf("Cannot access member function from non-object\n");
																exit(1);
															}
															
															if(var->Gentry->ctype==NULL)
															{
																printf("Cannot access member function from non-object\n");
																exit(1);
															}

															//gets the class and checks if such a member function exists
															struct Memberfunclist* member=MLookup(var->Gentry->ctype,$<c>3);
															if(member==NULL)
																{yyerror("Yacc : Undefined Member function for object");exit(1);}

															//Type checks the return types of each argument with the formal parameters;
															//funccallargsvalidate(arguments):gtemp(to get the actual parameters(functions not member functions),temp(call parameters),member(to get the actual parameters for member functions))
															int typecheck=funccallargsvalidate(NULL,temp,member);
															if(typecheck==-1)
															{yyerror("Yacc :invalid argument return type for member function of class\n");exit(1);}

															//Arguments(makefunctionnode):funcname,arglist(left child),gsymboltable(outside class functions),classtable(inside class functions),rightnode(for self/id/field)
															struct tnode* constnode=makeConstantNode((var->Gentry->binding)+1,NULL);//stores the vft pointer address
															var->next=constnode;
															$$ = makeFunctionNode($<c>3,$<no>5,NULL,member,var);
														}
				| FIELD '.' ID '(' ArglistBlock ')'        {
															//can only be self.id where id is a class
															struct tnode* var=$<no>1;	//HERE VAR IS A FIELD NODE
															struct tnode* temp=$<no>5;
															
															if(var->type!=NULL)      //Not a class
															{
																printf("Cannot access member function from non-object\n");
																exit(1);
															}
															struct tnode* iterfield=var->left;

		  													while(iterfield->next!=NULL)
																iterfield=iterfield->next;

															//gets the class and checks if such a member function exists
															struct Memberfunclist* member=MLookup(iterfield->field->ctype,$<c>3);
															if(member==NULL)
																{yyerror("Yacc : Undefined Member function for field");exit(1);}

															//Type checks the return types of each argument with the formal parameters;
															//funccallargsvalidate(arguments):gtemp(to get the actual parameters(functions not member functions),temp(call parameters),member(to get the actual parameters for member functions))
															int typecheck=funccallargsvalidate(NULL,temp,member);
															if(typecheck==-1)
															{yyerror("Yacc :invalid argument return type for member function of class\n");exit(1);}
															

														   // struct tnode* =makeVariableNode("vft");      //vft from local symbol table
															// var->next=vft;
															//Arguments(makefunctionnode):funcname,arglist(left child),gsymboltable(outside class functions),classtable(inside class functions),rightchild(for self/id/field)
															$$ = makeFunctionNode($<c>3,$<no>5,NULL,member,var);
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
	 |ID '(' ArglistBlock ')'                       {
													struct Gsymbol* gtemp= GLookup($<c>1);
													if(gtemp == NULL){yyerror("Yacc : Undefined function\n");exit(1);}
													//Type checks the return types of each argument with the formal parameters;
													int typecheck=funccallargsvalidate(gtemp,$<no>3,NULL);
													if(typecheck==-1)
													{yyerror("Yacc :invalid argument return type \n");exit(1);}
													$$ = makeFunctionNode($<c>1,$<no>3,gtemp,NULL,NULL);
												   }
	//For members of a user defined type
	|FIELD 		                                   {$$=$<no>1;}						 
	|FieldFunction                                 {$$=$<no>1;};

ArglistBlock: ArgList                               {$$=$<no>1;}
			  |                                     {$$=NULL;};

ArgList : ArgList','E                            {
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
															if(flag==0) //NO CLASS AND GDECL BLOCK AND OUTSIDE FUNCTION DEF
															{
																flag=1;
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															fprintf(fptr,"F0:\n");
															//INITIALIZING THE VIRTUAL FUNCTION TABLES OF ALL FUNCTIONS
															if(CHEAD!=NULL)
															{
																printf("USED SPACE:%d\n",used_space);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																//INITIALIZING THE VIRTUAL FUNCTION TABLES OF ALL FUNCTIONS
																initializeallvfts(fptr);    
															}
															///////////////////////////////////////////////////////////
															//Function code generation
															funccode(fptr,$7->left,$7->right,$<c>1,1);
															//After function code generation
															struct tnode* temp=$<no>7;
															LClear($<c>2);//to clear the symbol table
															
															Freeast($<no>7->left);//Clear the function body ast
															printf("AST CLEARED\n");
															Freeast($<no>7->right);//Clear the return expr ast
															freereg_no=-1;
														}
			|INT MAIN '(' ')' '{' Body '}'               
														{
															if(flag==0) //NO GDECL BLOCK and function definition
															{
																flag=1;
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");    //initiliazes initial value of BP
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															fprintf(fptr,"F0:\n");
															 if(CHEAD!=NULL)
															{
																printf("USED SPACE:%d\n",used_space);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");

																//INITIALIZING THE VIRTUAL FUNCTION TABLES OF ALL FUNCTIONS
																initializeallvfts(fptr);   
															}
															 
															//Function code generation
															funccode(fptr,$<no>6->left,$<no>6->right,$<c>1,1);
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
		   
FDefBlock : Type ID '(' FdefParamListBlock ')' '{' LdeclBlock Body '}'  {    
                                                                        isfuncdefined-=1;//to check if the function declared is defined or not
																		if(flag==0) //first function and no global declaration
																		{   
																			flag=1;
																			
																				
																			fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																			fprintf(fptr,"MOV BP,SP\n");
																			fprintf(fptr,"ADD SP,1\n");    //For return value
																			fprintf(fptr,"CALL F0\n");
																			fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																			fprintf(fptr,"INT 10\n");
																		}

																		int isdefined=validate($<c>1,$<c>2,$<param>4,Cptr); 
																		if(isdefined!=-1)   //if function is defined(either inside class or outside)
																		{
																			int funclabel;

																			if(Cptr==NULL)      //outside class function
																			{ 
																				struct Gsymbol* func=GLookup($<c>2);
																				funclabel=func->flabel;
																			}
																			
																			else                //inside class function
																			{ 
																				struct Memberfunclist* func=MLookup(Cptr,$<c>2);
																				funclabel=func->flabel;
																			}
																				
																		   
																			if(Cptr==NULL)
																				fprintf(fptr,"F%d:\n",funclabel);                                      //Function label 
																			
																			else
																				fprintf(fptr,"C%d:\n",funclabel);                                      //Member Function label
																			

																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,$<no>8->left,$<no>8->right,$<c>1,-1);
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
																			printf("Function arguments invalid:\n");
																			LClear($<c>2);//to clear the symbol table and resets the localargs and localvar
																			Freeast($<no>8->left);//Clear the function body ast
																			Freeast($<no>8->right);//Clear the return expr ast
																			freereg_no=-1;
																			exit(1);
																		}
																	}
		   |Type ID '(' FdefParamListBlock ')' '{' Body '}'              {
                                                                            isfuncdefined-=1;
																		if(flag==0) //first function and no global declaration
																		{   
																			flag=1;
																		   
																			fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																			fprintf(fptr,"MOV BP,SP\n");
																			fprintf(fptr,"ADD SP,1\n");    //For return value
																			fprintf(fptr,"CALL F0\n");
																			fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																			fprintf(fptr,"INT 10\n");
																		}

																		
																		int isdefined=validate($<c>1,$<c>2,$<param>4,Cptr); 
																		if(isdefined!=-1)   //if function is defined(either inside class or outside)
																		{
																			struct tnode* temp=$<no>7;

																			int funclabel;

																			if(Cptr==NULL)      //outside class function
																			{ 
																				struct Gsymbol* func=GLookup($<c>2);
																				funclabel=func->flabel;
																			}
																			
																			else                //inside class function
																			{ 
																				struct Memberfunclist* func=MLookup(Cptr,$<c>2);
																				funclabel=func->flabel;
																			}

																			if(Cptr==NULL)
																				fprintf(fptr,"F%d:\n",funclabel);                                      //Function label 
																			
																			else
																				fprintf(fptr,"C%d:\n",funclabel);                                      //Member Function label
																			
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,$<no>7->left,$<no>7->right,$<c>1,-1);
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
																			printf("Function arguments invalid:\n");
																			LClear($<c>2);//to clear the symbol table and resets the localargs and localvar
																			Freeast($<no>7->left);//Clear the function body ast
																			Freeast($<no>7->right);//Clear the return expr ast
																			freereg_no=-1;
																			exit(1);
																		}
																	};
/////////////////////////////////////////////////////////////////////////////////////////////
//FUNCTION PARAMETERS
FdefParamListBlock:FdefParamList            {$$=$<param>1;}
				  |                         {$$=NULL;}

FdefParamList:  FdefParamList ',' FdefParam     				{AppendParamlist($<param>1,$<param>3);$$=$<param>1;}      
				|FdefParam                  					{$$=$<param>1;};           
FdefParam:      Type ID 									    {   
																	if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
																		LInstall("self",NULL,NULL,Cptr);

																	if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
																		LInstall("vft",NULL,NULL,Cptr);
																	
																	struct Parameter* temp=CreateParamlist($<c>1,$<c>2);
																	//Create local symbol table
																	//Linstall Adds the arguments and increments num_args
																	LInstall(NULL,NULL,temp,NULL);  
																	$$=temp;         
																};
/////////////////////////////////////////////////////////////////////////////////////////////
//LOCAL VARIABLES
	
LdeclBlock : DECL LDecList ENDDECL                          
			| DECL ENDDECL                     
LDecList : LDecList LDecl ';'
		   | LDecl ';'
LDecl : Type IdList                           {addltype($<c>1);}//Assigns the type to the local variables
											 //Linstall Adds the variables and increments num_var
IdList : IdList ',' ID                        {LInstall($<c>3,NULL,NULL,NULL);}
		| ID                                  {
												if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
													LInstall("self",NULL,NULL,Cptr);
											   
												if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
													LInstall("vft",NULL,NULL,Cptr);

												LInstall($<c>1,NULL,NULL,NULL);
											  };
//////////////////////////////////////////////////////////////////////////////////
//FUNCTION BODY

Body   : BEG Slistblock Retstmt END                 {
												if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
													LInstall("self",NULL,NULL,Cptr);
											   
												if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
													LInstall("vft",NULL,NULL,Cptr);

												$$=makeConnectorNode('.',$<no>2,$<no>3);
												//printtree($<no>2);
												addlbinding();
												printlst();                                        
											  };
Retstmt : RET E ';'                             {$$=$<no>2;};
/////////////////////////////////////////////////////////////////////////////////////
%%

int yyerror(char const *s)
{
	printf("yyerror %s at line number : %d char : %s\n",s, yylineno, yytext);
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

	fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);

	//Initializing the default values in the type table
	TypetableCreate();
	printtypetable();
	yyparse();
	
	return 0;
}
												
												

