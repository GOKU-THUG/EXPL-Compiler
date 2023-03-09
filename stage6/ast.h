//AST.C
void Freeast(struct tnode* t);

/*CONSTANTS AND VARIABLE:Make4 a leaf tnode and set the value of val field*/
struct tnode* makeConstantNode(int n,char* c);

/*Make Variable Node*/
struct tnode* makeVariableNode(char* c);

/*Make Field Node*/
struct tnode* makefieldnode(char* fieldname,struct Typetable* userdeftype);

/*Make a read node*/
struct tnode* makereadnode(struct tnode* t);

/*Make a write node*/
struct tnode* makewritenode(struct tnode* t);

/*Make an dynamic memory allocation node for alloc,initialize and free*/
struct tnode* dynamicmemorynode(struct Typetable* t,int nodetype,struct tnode* left,struct tnode* right);

/*Connector Node*/
struct tnode* makeConnectorNode(char c,struct tnode* l,struct tnode* r);

/*Make Branching Node*/
struct tnode* makeBranchingNode(char* c,struct tnode* l,struct tnode* r);

/*ASSIGNMENTS AND OPERATORS:Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);

//Comparison Node
struct tnode* makeComparisonNode(char c[10],struct tnode *l,struct tnode *r);

//Logical Node:AND,OR,XOR
struct tnode* makeLogicalNode(char c[10],struct tnode* l,struct tnode* r);

//Break and Continue
struct tnode* makeBreak_ContinueNode(char* c);

//Function Node
struct tnode* makeFunctionNode(char* funcname,struct tnode* arglist,struct Gsymbol* gtemp);

void printtree(struct tnode* t);

