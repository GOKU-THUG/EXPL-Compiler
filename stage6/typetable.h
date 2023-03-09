//TYPE TABLE

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
#define Alloc 15
#define Initialize 16
#define Free 17
#define Field 18

//TYPE
//"int","str","bool","void","NULL"
//////////////////////////////////////////////////
typedef struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer 
}Typetable;

void TypeTableCreate();                                                     //Function to initialise the type table entries with primitive types (int,str) and special entries_(boolean,null,void).
struct Typetable* TLookup(char *name);                                      //Search through the type table and return pointer to type table entry of type 'name'. Returns NULL if entry is not found.
struct Typetable* TInstall(char *name,int size, struct Fieldlist *fields);  //Creates a type table entry for the (user defined) type of 'name' with given 'fields' and returns the pointer to the type table entry. The field list must specify the field index, type and name of each field. TInstall returns NULL upon failure. This routine is invoked when the compiler encounters a type definition in the source program.
////////////////////////////////////////////////
//Fields of a user defined datatype
typedef struct Fieldlist{
  char *name;              //name of the field
  int fieldindex;          //the position of the field in the field list
  char* nametype;           //for validation and assigning the variable of same type inside the type
  struct Typetable *type;  //pointer to type table entry of the field's type
  struct Fieldlist *next;  //pointer to the next field
}Fieldlist;

struct Fieldlist* FLookup(struct Typetable *type, char *name);                     //Searches for a field of given 'name' in the 'fieldlist' of the given user-defined type and returns a pointer to the field entry. Returns NULL if the type does not have a field of the name.
struct Fieldlist* Fcreate(char* varname,char* typename);
void Fappend(struct Fieldlist* head,struct Fieldlist* field);
int GetSize(struct Typetable * type);                                              //gets the already stored size
//////////////////////////////////////////////
void printtypetable();
