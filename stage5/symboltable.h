//SYMBOL TABLE ENTRY
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
#define Function 13
#define Logical 14

//TYPE
#define Boolean 10
#define Integer 11
#define String  12
//////////////////////////////////////////////////
typedef struct Gsymbol{
char* name;                                             // name of the variable
int type;                                               // type of the variable
int size;                                               // size of the type of the variable
//FOR ARRAYS
int row;                                          
int col;                                        
int binding;                                          // stores the static memory address allocated to the variable
struct Parameter* paramlist;      
int flabel;                    //stores the label corresponding to the function;
struct Gsymbol *next;
}Gsymbol;

struct Gsymbol* GLookup(char* name);                    // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void GInstall(char *name, int type, int size,int row,int col,struct Parameter* paramlist);           // Creates a symbol table entry.
void addgtype(int type);                             //Adds the datatype
void printgst();
//////////////////////////////////////////////////
typedef struct Parameter{
    int type;
    char* name;
    struct Parameter* next;
}Parameter;

void AppendParamlist(struct Parameter* Head,struct Parameter* newnode);
struct Parameter* CreateParamlist(int type,char* name);
//////////////////////////////////////////////////
typedef struct Lsymbol{ 
char *name;                 //name of the variable   
int type;                   //type of the variable:(Integer / String)  
int binding;                //local binding of the variable  
struct Lsymbol *next;       //points to the next Local Symbol Table entry
}Lsymbol;

void LInstall(char *name,int type,struct Parameter* param);
struct Lsymbol* LLookup(char *name);
void LClear(char* name);
void addltype(int type);                             //Adds the datatype to the local variables
void addlbinding();                                  //Adds the binding to the local variables
void printlst();
//////////////////////////////////////////////////
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
    struct tnode* next;         //Next for linked list of tnodes;
    //pointer to GST entry for global variables and functions
    struct Gsymbol* Gentry;  

    //Pointer to LST entry for local variables and parameters
    struct Lsymbol* Lentry;  
}tnode;
/////////////////////////////////////////////////
//Function
int validate(int returntype,char* name,struct Parameter* param);
int funccallargsvalidate(struct Gsymbol* gtemp,struct tnode* args);
//////////////////////////////////////////////////
void printsymboltable();                            //To print the symbol table;
//////////////////////////////////////////////////
int getfunclabel();                                 //to get the function label
/////////////////////////////////////////////////