struct Gsymbol* GHEAD = NULL;
struct Lsymbol* LHEAD=NULL;

int used_space = 0;
int num_args=0; //For getting the offset for the binding in case of arguments
int num_var=0;  //For getting the offset for the binding for local variables inside functions.
///////////////////////////////////////////////
struct Gsymbol *GLookup(char *name) // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
{
    struct Gsymbol *temp = GHEAD;
    while (temp != NULL){
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void GInstall(char *name,struct Typetable* type, int size,int rowsize,int colsize,struct Parameter* paramlist) // Creates a symbol table entry.
{
    struct Gsymbol *ispresent = GLookup(name);

    if (ispresent == NULL)
    {
        struct Gsymbol *newnode = (Gsymbol *)malloc(sizeof(Gsymbol));

        newnode->name = (char *)malloc(strlen(name) * sizeof(char));
        strcpy(newnode->name,name);
        newnode->type = type;               //Data type
        newnode->ctype= NULL;               //Class type
        newnode->size = size;
        newnode->paramlist=paramlist;
        
        if(paramlist!=NULL)
            newnode->flabel=getfunclabel();

        //For 2d arrays
        if(rowsize!=-1)
            newnode->row=rowsize;
        
        if(colsize!=-1)
            newnode->col=colsize;

        if(paramlist==NULL)
            newnode->binding = (4096+used_space);
            
        // To track the last used space so as to push registers in case of system calls
        if(paramlist==NULL)
            {used_space = used_space + size;}

        if (GHEAD == NULL)
            GHEAD = newnode;
        
        else
        {
            struct Gsymbol *temp = GHEAD;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
        
        newnode->next = NULL;
    }

    else
    {
        printf("Error:Global Variable or Function already declared:%s\n", name);
        exit(0);
    }
}
void addgtype(char* type)
{
    struct Gsymbol *temp = GHEAD;

    while (temp != NULL)
    {
        if (temp->type == NULL && temp->ctype==NULL)
        {
            //To check in the typetable
            temp->type = TLookup(type);
            temp->ctype = CLookup(type);

            //Invalid type validation
            if(temp->type==NULL && temp->ctype==NULL)
            {
                printf("Invalid type for Global Variable:%s\n",temp->name);
                exit(1);
            }

            //Incase classes 2 words are alloted one for storing the heap address and one for storing the vft address
            if(temp->ctype!=NULL)   //for classes
            {
                struct Gsymbol* symbolahead=temp->next;

                while(symbolahead!=NULL)
                {
                    symbolahead->binding+=1;
                    symbolahead=symbolahead->next;
                }

                used_space+=1;
            }
        }
        temp = temp->next;
    }
}

void printgst()
{
    struct Gsymbol* temp=GHEAD;
    printf("Global Symbol Table:\n");
    while(temp!=NULL)
    {
        if(temp->size==-1)
             printf("FunctionName:%s,Type:%s,Flabel:%d\n",temp->name,temp->type->name,temp->flabel);
        else
        {
            if(temp->type!=NULL)
                printf("VariableName:%s,Type:%s,Binding:%d\n",temp->name,temp->type->name,temp->binding);
            if(temp->ctype!=NULL)
                printf("VariableName:%s,CType:%s,Binding:%d\n",temp->name,temp->ctype->name,temp->binding);
        }
        temp=temp->next;
    }
    printf("\n");
}
///////////////////////////////////////////////
struct Lsymbol *LLookup(char *name) // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
{
    struct Lsymbol *temp = LHEAD;
    while (temp != NULL){
        if (strcmp(temp->name, name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void LInstall(char* name,struct Typetable* type,struct Parameter* param,struct Classtable* Cptr)
{
    char* checkname;

    if(name==NULL)      //incase of parameters
    {
        checkname=(char *)malloc(strlen(param->name) * sizeof(char)); 
        strcpy(checkname,param->name);
    }
    else            //incase of local variables
    {
        checkname=(char *)malloc(strlen(name) * sizeof(char));
        strcpy(checkname,name);
    }

    struct Lsymbol *ispresent = LLookup(checkname);

    free(checkname);

    if (ispresent == NULL)
    {
        struct Lsymbol *newnode = (struct Lsymbol*)malloc(sizeof(struct Lsymbol));

        if(name!=NULL)          //In case of local variables
        {
            newnode->name = (char *)malloc(strlen(name) * sizeof(char));
            strcpy(newnode->name,name);
            newnode->type = type;
            
            if(Cptr==NULL)
                num_var+=1;

            else                    //Incase of self
                num_args+=1;
        }
        
        else if(param!=NULL)
        {
            newnode->name = (char *)malloc(strlen(param->name) * sizeof(char));            
            strcpy(newnode->name,param->name);
            newnode->type = param->type;
            num_args+=1;
        }

        if (LHEAD == NULL) 
            LHEAD = newnode;
        
        else
        {
            struct Lsymbol* temp=LHEAD;
            while(temp->next!=NULL)
                temp=temp->next;
            
            temp->next = newnode;
        }

        newnode->next = NULL;
    }

    else
    {
        printf("Error:Local Variable/Argument/Self already declared:%s\n", name);
        exit(0);
    }
}
void LClear(char* name)
{
    struct Lsymbol* nextnode;
    struct Lsymbol* currentnode=LHEAD;

    while(currentnode!=NULL)
    {
        nextnode=currentnode->next;
        free(currentnode);
        currentnode=nextnode;
    }

    LHEAD=NULL;
    num_args=0;
    num_var=0;
    printf("Local Symbol table of Function %s freed\n\n",name);
}


//Adds binding to the local variables and parameters
void addlbinding()
{
    struct Lsymbol* temp=LHEAD;
    int countargs=(-2)-(num_args);
    int countvar=1;

    //local list order:arg1,2,3..,local1,local2,loca3....
    while(temp!=NULL)
    {
        if(countargs<=-3)              //For local args
        {
            temp->binding=countargs;
            countargs+=1;
        }


        else if(countvar<=num_var)      //For local variable
        {
            temp->binding=countvar;
            countvar+=1;
        }
        temp=temp->next;
    }
}
void addltype(char* type)
{
    struct Lsymbol *temp = LHEAD;

    while (temp != NULL)
    {
        //For local variables as for arguments the type has already been assigned
        if (temp->type == NULL) 
        {              
            temp->type =  TLookup(type);
        
            //Invalid type validation
            if(temp->type==NULL)
            {
                printf("Invalid type for Local Variable:%s\n",temp->name);
                exit(1);
            }
        }
        temp = temp->next;
    }
}

void printlst()
{
    struct Lsymbol* temp=LHEAD;
    printf("Local Symbol Table:\n");
    while(temp!=NULL)
    {
        if(temp->type!=NULL)
            printf("Name:%s,Type:%s,Binding:%d\n",temp->name,temp->type->name,temp->binding);
        
        else
            printf("Name:%s,Type:NULL,Binding:%d\n",temp->name,temp->binding);
            
        temp=temp->next;
    }
    printf("\n");
}
///////////////////////////////////////////////
//CHECKS IF A FUNCTION IS DEFINED
int validate(char* returntype,char* name,struct Parameter* param,struct Classtable* Cptr)
{
    struct Gsymbol* func=NULL;
    struct Memberfunclist* memberfunc=NULL;

    //Checks if the function is defined in the global symbol table
    if(Cptr==NULL)
    {
        
        func=GLookup(name);
    
        if(func!=NULL)
        {
            if(func->type==TLookup(returntype) && strcmp(name,func->name)==0)
            {
            struct Parameter* actualparam=func->paramlist;

            while(actualparam!=NULL && param!=NULL){
                //printf("%s:%s",actualparam->name,param->name);
                if((strcmp(actualparam->name,param->name)!=0) | (actualparam->type!=param->type))
                {
                    printf("Declared param not same as Defined param\n");
                    return -1;
                }
                actualparam=actualparam->next;
                param=param->next;
            }  
            if(actualparam==NULL && param==NULL)
                return 0;

            printf("Mismatch in the number of arguments declared and those defined.\n");
            return -1; 
            }
        }

        printf("Function not declared\n");
        return -1;
    }                 
    
     //Checks if the function is defined within the class
    else
    {
        memberfunc=MLookup(Cptr,name); 
        
        if(memberfunc!=NULL)
        {
            if(memberfunc->type==TLookup(returntype) && strcmp(name,memberfunc->name)==0)
            {
            struct Parameter* actualparam=memberfunc->paramlist;

            while(actualparam!=NULL && param!=NULL){
                //printf("%s:%s",actualparam->name,param->name);
                if((strcmp(actualparam->name,param->name)!=0) | (actualparam->type!=param->type))
                {
                    printf("Declared param not same as Defined param in member function\n");
                    return -1;
                }
                actualparam=actualparam->next;
                param=param->next;
            }  
            if(actualparam==NULL && param==NULL)
                return 0;

            printf("Mismatch in the number of arguments declared and those defined in member function.\n");
            return -1; 
            }
        }

        printf("Member Function not declared\n");
        return -1;
    }       
    
   
}

//Type check with the function return type
int funccallargsvalidate(struct Gsymbol* gtemp,struct tnode* args,struct Memberfunclist* member)
{
    struct Parameter* gargs;
    
    if(gtemp!=NULL)
        gargs=gtemp->paramlist;

    if(member!=NULL)
        gargs=member->paramlist;
        
    while(args!=NULL && gargs!=NULL)
    {
        if(args->type!=gargs->type)
        {
            printf("ARGUMENT TYPE MISMATCH in FUNCTION DECLARATION AND DEFINITION.\n");
            return -1;
        }
        args=args->next;
        gargs=gargs->next;
    }

    if(args!=NULL | gargs!=NULL)
    {
        printf("MISMATCH IN NUMBER OF ARGUMENTS IN FUNCTION DECLARATION AND DEFINITION.\n");
        return -1;
    }
    return 0;
}
///////////////////////////////////////////////
void printsymboltable()
{
    struct Gsymbol *temp = GHEAD;

    while (temp != NULL)
    {
        char type[10];

        if(temp->type==TLookup("bool"))
            strcpy(type,"Boolean");
        
        if(temp->type==TLookup("int"))
            strcpy(type,"Integer");
        
        if(temp->type==TLookup("Str"))
            strcpy(type,"String");
        
        if(temp->type==TLookup("void"))
            strcpy(type,"Void");
        
        printf("%s %s %d\n", temp->name,type,temp->size);
        temp = temp->next;
    }
    printf("\n");
}
///////////////////////////////////////////////
void AppendParamlist(struct Parameter* Head,struct Parameter* newnode)
{
    struct Parameter* temp=Head;

    if(temp==NULL)
        printf("Parameter NULL");

    while(temp->next!=NULL){
        temp=temp->next;
    }

    temp->next=newnode;
    newnode->next=NULL;
}

struct Parameter* CreateParamlist(char* type,char* name)
{
    struct Parameter* newnode=(struct Parameter*)malloc(sizeof(Parameter));
    newnode->type=TLookup(type);

    //Invalid type validation
    if(newnode->type==NULL)
    {
        printf("Invalid type for:%s\n",newnode->name);
        exit(1);
    }

    newnode->name=(char*)malloc(strlen(name)*sizeof(char));
    strcpy(newnode->name,name);

    newnode->next=NULL;
    return newnode;

}
/////////////////////////////////////////////