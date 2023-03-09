//SYMBOL TABLE ENTRY
typedef struct Gsymbol
{
    char* name;                                             // name of the variable
    struct Typetable* type;                                               // type of the variable
    int size;                                               // size of the type of the variable
    //FOR ARRAYS
    int row;                                          
    int col;                                        
    int binding;                                          // stores the static memory address allocated to the variable
    struct Parameter* paramlist;      
    int flabel;                                            //stores the label corresponding to the function;
    struct Gsymbol *next;
}Gsymbol;

struct Gsymbol* GLookup(char* name);                    // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void GInstall(char *name,struct Typetable* type, int size,int row,int col,struct Parameter* paramlist);           // Creates a symbol table entry.
void addgtype(char* type);                             //Adds the datatype
void printgst();
//////////////////////////////////////////////////
typedef struct Parameter{
    struct Typetable* type;
    char* name;
    struct Parameter* next;
}Parameter;

void AppendParamlist(struct Parameter* Head,struct Parameter* newnode);
struct Parameter* CreateParamlist(char* type,char* name);
//////////////////////////////////////////////////
typedef struct Lsymbol{ 
char *name;                 //name of the variable   
struct Typetable* type;                   //type of the variable:(Integer / String)  
int binding;                //local binding of the variable  
struct Lsymbol *next;       //points to the next Local Symbol Table entry
}Lsymbol;

void LInstall(char *name,struct Typetable* type,struct Parameter* param);
struct Lsymbol* LLookup(char* name);
void LClear(char* name);
void addltype(char* type);                             //Adds the datatype to the local variables
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
    struct Typetable* type;           //DATAType:int,bool,string            	
	char* varname;	    //name of a variable for ID nodes  
    char* nonleaf;      //stores the string such as read/write/connector/operator/variable/field
    int nodetype;       //0-constants,1-variables,2-read,3-write,4-connector,5-operators(+-/*=),Comparison 6,Branch 7,8-BREAK,9-CONTINUE
	struct tnode *left,*right;	//left and right branches   
    struct tnode* next;         //Next for linked list of tnodes;
    //pointer to GST entry for global variables and functions
    struct Gsymbol* Gentry;  
    //Pointer to LST entry for local variables and parameters
    struct Lsymbol* Lentry;  
    //For storing the field data
    struct Fieldlist* field;
}tnode;
/////////////////////////////////////////////////
//Function
int validate(char* returntype,char* name,struct Parameter* param);
int funccallargsvalidate(struct Gsymbol* gtemp,struct tnode* args);
//////////////////////////////////////////////////
void printsymboltable();                            //To print the symbol table;
//////////////////////////////////////////////////
int getfunclabel();                                 //to get the function label
/////////////////////////////////////////////////