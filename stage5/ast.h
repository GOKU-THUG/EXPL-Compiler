//AST.C
void Freeast(struct tnode* t);

/*CONSTANTS AND VARIABLE:Make4 a leaf tnode and set the value of val field*/
struct tnode* makeConstantNode(int n,char* c);

/*Make Variable Node*/
struct tnode* makeVariableNode(char* c);

/*Make a read node*/
struct tnode* makereadnode(struct tnode* t);

/*Make a write node*/
struct tnode* makewritenode(struct tnode* t);
	
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


//CODEGEN.C

int getLabel();

int getReg();

void freeReg();

int address(char c);

int get_numlocalvar();

void callread(FILE *fptr,int resreg_no);

void callwrite(FILE *fptr,int resreg_no);

void callwhile(FILE *fptr,struct tnode* t);

void calldo(FILE *fptr,struct tnode* t);

void callrepeat(FILE *fptr,struct tnode* t);

void callif(FILE *fptr,struct tnode* t);

void callelse(FILE *fptr,struct tnode* t);

void callifelse(FILE *fptr,struct tnode* t);

void callcomp(FILE* fptr,char c[10],int leftreg,int rightreg);

//Calling return statement
void callret(FILE* fptr,struct tnode* returnexpr,int functype);

//Codegeneration of function
void funccode(FILE* fptr,struct tnode* body,struct tnode* returnexpr,int functype);
/*To evaluate an expression tree*/
int codeGen(struct tnode *t,FILE *fptr);

