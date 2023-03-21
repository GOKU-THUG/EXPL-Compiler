//CLASS TABLE
struct Classtable {
 char *name;                           //name of the class
 struct Fieldlist *datamemberlist;        //pointer to DATAMEMBERLIST
 struct Memberfunclist *memberfunclist;      //pointer to MEMBERFUNCTIONSLIST
 struct Classtable *parentptr;         //pointer to the parent's class table(INHERITANCE)
 int class_index;                      //position of the class in the virtual function table
 int fieldcount;                       //count of DATAMEMBERS
 int methodcount;                    //count of MEMBERFUNCTIONS
 struct Classtable *next;              //pointer to next class table entry
};

struct Classtable* CInstall(char *name,char *parent_class_name);
struct Classtable* CLookup(char *name);
///////////////////////////////////////////////////////////////////////////////
//Memberfield list is used to store the information regarding the type, name, fieldindex and type of class of all the member fields of that class.
/*This is defined in typetable.h
struct Fieldlist{
 char* name;   //name of the field
 int fieldindex;   //position of the field
 char* nametype;           //for validation and assigning the variable of same type inside the type:for struct(userdef type)
 struct Typetable *type;  //pointer to typetable
 struct Classtable *ctype; //pointer to the class containing the field
 struct Fieldlist *next;  //pointer to next fieldlist entry
};
*/
void DInstall(struct Classtable *cptr, char* typename, char *name);
struct Fieldlist* DLookup(struct Classtable* ctype,char* name);
///////////////////////////////////////////////////////////////////////////////
//Memberfunc list is used to store the information regarding the type, name of the function, argument list, it's flabel and it's position.

struct Memberfunclist {
  char *name;                      //name of the member function in the class
 struct Typetable *type;          //pointer to typetable
 struct Parameter* paramlist;   //pointer to the head of the formal parameter list
 int funcposition;                //position of the function in the class table
  int flabel;                      //A label for identifying the starting address of the function's code in the memory
 struct Memberfunclist *next;     //pointer to next Memberfunclist entry
};

void MInstall (struct Classtable *cptr, char *name, struct Typetable *type, struct Parameter* paramlist);
struct Memberfunclist* MLookup(struct Classtable* ctype,char* name);
/////////////////////////////////////////////////
//////////////////////////////////////////////////
typedef struct Parameter{
    struct Typetable* type;
    char* name;
    struct Parameter* next;
}Parameter;

void AppendParamlist(struct Parameter* Head,struct Parameter* newnode);
struct Parameter* CreateParamlist(char* type,char* name);
///////////////////////////////////////////////////////
void printclasstable(struct Classtable* Cptr);
