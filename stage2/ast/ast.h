typedef struct tnode { 
	int val;	// value of a number for NUM nodes.
	//int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
    char* nonleaf; //stores the string such as read/write/connector/operator
    int nodetype;//0-constants,1-variables,2-read,3-write,4-connector,5-operators(+-/*=)
	//int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
}tnode;

	
/*CONSTANTS AND VARIABLE:Make a leaf tnode and set the value of val field*/
struct tnode* makeConstantNode(int n);

struct tnode* makeVariableNode(char c);

/*Make a read node*/
struct tnode* makereadnode(struct tnode* t);

/*Make a write node*/
struct tnode* makewritenode(struct tnode* t);
	
/*Connector Node*/
struct tnode* makeConnectorNode(char c,struct tnode* l,struct tnode* r);

/*ASSIGNMENTS AND OPERATORS:Make a tnode with opertor, left and right branches set*/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
	
int getReg();

void freeReg();

void callwrite(FILE *fptr,int resreg_no);

void callread(FILE *fptr,int resreg_no);

void inorder(struct tnode* t);

int address(char c);

/*To evaluate an expression tree*/
int codeGen(struct tnode *t,FILE *fptr);


