//CODEGEN.C

int getLabel();

int getReg();

void freeReg();

int address(char c);

int get_numlocalvar();

void callread(FILE *fptr,int resreg_no);

void callwrite(FILE *fptr,int resreg_no);

int callinitialize(FILE* fptr);

int callalloc(FILE* fptr);

void callfree(FILE* fptr,int resreg_no);

int pushtempreg(FILE* fptr);

void poptempreg(int lastreg_local,FILE* fptr);

void callwhile(FILE *fptr,struct tnode* t);

void calldo(FILE *fptr,struct tnode* t);

void callrepeat(FILE *fptr,struct tnode* t);

void callif(FILE *fptr,struct tnode* t);

void callelse(FILE *fptr,struct tnode* t);

void callifelse(FILE *fptr,struct tnode* t);

void callcomp(FILE* fptr,char c[10],int leftreg,int rightreg);

//Calling return statement
void callret(FILE* fptr,struct tnode* returnexpr,char* functype);

//Codegeneration of function
void funccode(FILE *fptr, struct tnode *body, struct tnode *returnexpr,char* functype,int ismain);

//to get the heap address of the field
int getfieldaddress(struct tnode* t,FILE *fptr);

//to check if type is userdefined or not
int isuserdefined(char* typename);

/*To evaluate an expression tree*/
int codeGen(struct tnode *t,FILE *fptr);