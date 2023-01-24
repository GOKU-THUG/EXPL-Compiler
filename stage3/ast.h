//NODETYPE
#define Constant 0
#define Variable 1
#define Read 2
#define Write 3
#define Connector 4
#define Operator 5
#define Comparison 6
#define Branch 7

//TYPE
#define Boolean 0
#define Integer 1

typedef struct tnode 
{ 
	int val;	        // value of a number for NUM nodes.
    int type;           //DATAType:int,bool             	
	char* varname;	    //name of a variable for ID nodes  
    char* nonleaf;      //stores the string such as read/write/connector/operator
    int nodetype;       //0-constants,1-variables,2-read,3-write,4-connector,5-operators(+-/*=)
    
	struct tnode *left,*right;	//left and right branches   
}tnode;


//AST.C

/*CONSTANTS AND VARIABLE:Make4 a leaf tnode and set the value of val field*/
struct tnode* makeConstantNode(int n);

/*Make Variable Node*/
struct tnode* makeVariableNode(char c);

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

void printtree(struct tnode* t);


//CODEGEN.C

int getLabel();

int getReg();

void freeReg();

int address(char c);

void callread(FILE *fptr,int resreg_no);

void callwrite(FILE *fptr,int resreg_no);

void callwhile(FILE *fptr,struct tnode* t);

void callif(FILE *fptr,struct tnode* t);

void callelse(FILE *fptr,struct tnode* t);

void callifelse(FILE *fptr,struct tnode* t);

void callcomp(FILE* fptr,char c[10],int leftreg,int rightreg);

/*To evaluate an expression tree*/
int codeGen(struct tnode *t,FILE *fptr);


