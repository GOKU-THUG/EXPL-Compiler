struct Classtable* CHEAD = NULL;
int classindex=0;      //keeps track of the number of classes

///////////////////////////////////////////////////////////////////////////////
struct Classtable* CInstall(char *name,char *parent_class_name)
{

    struct Classtable* ispresent=CLookup(name);

    if(ispresent==NULL){

        struct Classtable* newnode=(struct Classtable*)malloc(sizeof(struct Classtable));
        newnode->name=(char*)malloc(strlen(name)*sizeof(char));
        
        strcpy(newnode->name,name);
        newnode->datamemberlist=NULL;
        newnode->memberfunclist=NULL;
        newnode->parentptr=NULL;
        newnode->fieldcount=0;
        newnode->methodcount=0;
        newnode->class_index=classindex;
        classindex+=1;

        if (CHEAD == NULL)
            CHEAD = newnode;
        
        else
        {
            struct Classtable *temp = CHEAD;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
        
        newnode->next=NULL;
        return newnode;
    }
    
    else
    {
        printf("Error:Class already defined:%s\n",name);
        exit(1);
    }
}

struct Classtable* CLookup(char *name)
{
    struct Classtable* temp=CHEAD;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0)
            return temp;
        temp=temp->next;
    }

    return temp;
}
///////////////////////////////////////////////////////////////////////////////
void DInstall(struct Classtable *cptr, char* typename, char *name)
{
    struct Fieldlist* ispresent=DLookup(cptr,name);

    if(ispresent==NULL)
    {
        struct Fieldlist* newnode=(struct Fieldlist*)malloc(sizeof(struct Fieldlist));
        newnode->name=(char*)malloc(strlen(name)*sizeof(char));
        
        strcpy(newnode->name,name);
        newnode->fieldindex=(cptr->fieldcount);
        cptr->fieldcount+=1;

        struct Typetable* type=TLookup(typename); 
        struct Classtable* class=CLookup(typename);

        //Data member can be a class or int/str/userdefined type
        newnode->type=type;
        newnode->ctype=class;

        if(newnode->type==NULL && newnode->ctype==NULL)
        {
            printf("Error:Invalid datatype of data member:%s\n",name);
            exit(1);
        }

        struct Fieldlist* temp=cptr->datamemberlist;
        
        if(temp==NULL)
            cptr->datamemberlist=newnode;
        
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;
            
            temp->next=newnode;
        } 
        newnode->nametype=NULL;
        newnode->next=NULL;
    }

    else
    {
        printf("Error:Data Member already defined:%s\n",name);
        exit(1);
    }
}

struct Fieldlist* DLookup(struct Classtable* ctype,char* name)
{
    if(ctype==NULL)
    {
        printf("Cannot access DATA MEMBER from non-object:DLOOKUP\n");
        exit(1);
    }

    struct Fieldlist* temp=ctype->datamemberlist;

    while(temp!=NULL){
        if(strcmp(temp->name,name)==0)
            return temp;
        
        temp=temp->next;
    }
    return temp;
}
///////////////////////////////////////////////////////////////////////////////
void MInstall (struct Classtable *cptr, char *name, struct Typetable *type, struct Parameter* paramlist)
{
    struct Memberfunclist* ispresent=MLookup(cptr,name);

    if(type==NULL)
    {
        printf("Error:Member Function has invalid type:%s\n",name);
        exit(1);
    }

    if(ispresent==NULL)
    {
        struct Memberfunclist* newnode=(struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
        newnode->name=(char*)malloc(strlen(name)*sizeof(char));
        
       strcpy(newnode->name,name);
       newnode->type=type;
       newnode->paramlist=paramlist;
       
       newnode->funcposition=cptr->methodcount;
       cptr->methodcount+=1;

        newnode->flabel=getfunclabel();//In codegen.c
        
        struct Memberfunclist* temp=cptr->memberfunclist;
        
        if(temp==NULL)
            cptr->memberfunclist=newnode;
        
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;
            
            temp->next=newnode;
        }

        newnode->next=NULL;

    }

    else
    {
        printf("Error:Member Function already defined:%s\n",name);
        exit(1);
    }
}

struct Memberfunclist* MLookup(struct Classtable* ctype,char* name)
{
        if(ctype==NULL)
        {
            printf("Cannot access member function from non-object:MLOOKUP\n");
            exit(1);
        
        }
        struct Memberfunclist* temp=ctype->memberfunclist;

        while(temp!=NULL){
            if(strcmp(temp->name,name)==0)
                return temp;
            
            temp=temp->next;
        }

        return temp;
}

///////////////////////////////////////////////////////////////////////////////
void printclasstable(struct Classtable* Cptr)
{
    struct Fieldlist* datamem=Cptr->datamemberlist;
    struct Memberfunclist *memberfun=Cptr->memberfunclist;

    printf("Class:%s\n",Cptr->name);
    
    if(Cptr->parentptr!=NULL)
        printf("Parent Class:%s\n",Cptr->parentptr->name);
    
    printf("\nData Members:\n");
    while(datamem!=NULL)
    {
        printf("Datamem:%s,Fieldindex:%d",datamem->name,datamem->fieldindex);
        
        if(datamem->type!=NULL)
            printf(",Type:%s",datamem->type->name);

        if(datamem->ctype!=NULL)
            printf(",CType:%s",datamem->ctype->name);

        printf("\n");

        datamem=datamem->next;
    }

    printf("\nMember Functions:\n");

    while(memberfun!=NULL)
    {
        printf("Memfun:%s,FuncPosition:%d,Flabel:%d",memberfun->name,memberfun->funcposition,memberfun->flabel);
        
        if(memberfun->type!=NULL)
            printf(",Type:%s",memberfun->type->name);

        if(memberfun->paramlist!=NULL)
        {
            printf("\nParameters:\n");
            struct Parameter* temp=memberfun->paramlist;
            while(temp!=NULL)
            {
                printf("Name:%s",temp->name);
                printf(",Type:%s",temp->type->name);
                printf("\n");
                temp=temp->next;
            }
        }
          

        printf("\n");

        memberfun=memberfun->next;
    }
}