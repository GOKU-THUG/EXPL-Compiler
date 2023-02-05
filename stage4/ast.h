//NODETYPE
#define Constant 0
#define Variable 1
#define Read 2
#define Write 3
#define Connector 4
#define Operator 5
#define Comparison 6
#define Branch 7
#define Break 8 
#define Continue 9

//TYPE
#define Boolean 10
#define Integer 11
#define String  12

//Union val
typedef union Val
{
    int i;
    char* c;
}Val;

//Tnode
typedef struct tnode 
{ 
	union Val val;	        // value of constant.
    int type;           //DATAType:int,bool,string            	
	char* varname;	    //name of a variable for ID nodes  
    char* nonleaf;      //stores the string such as read/write/connector/operator
    int nodetype;       //0-constants,1-variables,2-read,3-write,4-connector,5-operators(+-/*=),Comparison 6,Branch 7,8-BREAK,9-CONTINUE
	struct tnode *left,*right;	//left and right branches   
    
    //pointer to GST entry for global variables and functions
    struct Gsymbol * Gentry;  
    
}tnode;



//AST.C

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

struct tnode* makeBreak_ContinueNode(char* c);

void printtree(struct tnode* t);


//CODEGEN.C

int getLabel();

int getReg();

void freeReg();

int address(char c);

void callread(FILE *fptr,int resreg_no);

void callwrite(FILE *fptr,int resreg_no);

void callwhile(FILE *fptr,struct tnode* t);

void calldo(FILE *fptr,struct tnode* t);

void callrepeat(FILE *fptr,struct tnode* t);

void callif(FILE *fptr,struct tnode* t);

void callelse(FILE *fptr,struct tnode* t);

void callifelse(FILE *fptr,struct tnode* t);

void callcomp(FILE* fptr,char c[10],int leftreg,int rightreg);

/*To evaluate an expression tree*/
int codeGen(struct tnode *t,FILE *fptr);



