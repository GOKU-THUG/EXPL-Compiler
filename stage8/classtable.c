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
        newnode->fieldcount=0;
        newnode->methodcount=0;
        newnode->class_index=classindex;
        classindex+=1;

        //assigns the parent class
        struct Classtable* parentptr=CLookup(parent_class_name);
        newnode->parentptr=parentptr;

        if(parentptr!=NULL)
        {
            struct Fieldlist* pdatamem=parentptr->datamemberlist;
            struct Memberfunclist* pmemfunc=parentptr->memberfunclist;

            //Copying data members  and member functions of parent class to derived class
            while(pdatamem!=NULL)
            {
                if(pdatamem->ctype!=NULL)    //if the type is of a class
                    DInstall(newnode,pdatamem->ctype->name,pdatamem->name);
                
                else    //it is not of class type
                    DInstall(newnode,pdatamem->type->name,pdatamem->name);

                pdatamem=pdatamem->next;
            }

            while(pmemfunc!=NULL)
            {
                ParentMinstall(newnode,pmemfunc);
                pmemfunc=pmemfunc->next;
            }
        }

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
    if(name==NULL)
        return NULL;

    struct Classtable* temp=CHEAD;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0)
            return temp;
        temp=temp->next;
    }

    return temp;
}
///////////////////////////////////////////////////////////////////////////////
void ParentMinstall(struct Classtable* cptr,struct Memberfunclist* pmemfunc)
{
    struct Memberfunclist* newnode=(struct Memberfunclist*)malloc(sizeof(struct Memberfunclist));
        newnode->name=(char*)malloc(strlen(pmemfunc->name)*sizeof(char));
        
       strcpy(newnode->name,pmemfunc->name);
       newnode->type=pmemfunc->type;
       newnode->paramlist=pmemfunc->paramlist;
       
       newnode->funcposition=cptr->methodcount;
       cptr->methodcount+=1;

        newnode->flabel=pmemfunc->flabel;//In codegen.c
        
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

    if(name==NULL)
        return NULL;

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
    if(type==NULL)
    {
        printf("Error:Member Function has invalid type:%s\n",name);
        exit(1);
    }
    
    struct Memberfunclist* memfunc=MLookup(cptr,name);    //As function overloading is not supported
    int flag=0;

    if(memfunc!=NULL)   //same name:can have same or different arguments;
    {
        if(memfunc->type==type)  //if the type is different then it is function overloading hence don't do anything as it will automatically be rejected.
        {
            struct Parameter* parentparamlist=memfunc->paramlist;
            struct Parameter* childparamlist=paramlist;

            while(parentparamlist!=NULL && childparamlist!=NULL)
            {
                if((strcmp(parentparamlist->name,childparamlist->name)!=0) | (parentparamlist->type!=childparamlist->type))//function overloading case
                        break;
                    
                parentparamlist=parentparamlist->next;
                childparamlist=childparamlist->next;
            }

            //function overrided
            if(parentparamlist==NULL && childparamlist==NULL)    //same number of arguments//Valid function
            {
                memfunc->flabel=getfunclabel();
                flag=1;
            }
            //else function overloading where the number of arguments in both are different
        }
    }

    if(memfunc==NULL)
    {
        flag=1;
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

    if(flag==0)
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
int isvalid(char* pclassname,char* descclassname)
{
    struct Classtable* parentclass=CLookup(pclassname);
    struct Classtable* desclass=CLookup(descclassname);

    if(parentclass==NULL | desclass==NULL)
        return -1;

    if(parentclass!=desclass)  //new can be done for the same class
    {
        struct Classtable* parent=desclass->parentptr;

        while(parent!=NULL)
        {
            if(parent==parentclass)
                return 0;

            parent=parent->parentptr;
        }

        return -1;
    }

    //parentclass==descclass case
    return 0;
}
///////////////////////////////////////////////////////////////////////////////
void initializeallvfts(FILE* fptr)
{
    struct Classtable* class=CHEAD;
    while(class!=NULL)
    {
        initializevft(fptr,class);
        class=class->next;
    }
}
///////////////////////////////////////////////////////////////////////////////
void initializevft(FILE*fptr,struct Classtable* Cptr)
{
    struct Memberfunclist* memfunc=Cptr->memberfunclist;
    int vftaddr=4096+8*(Cptr->class_index); //start address of the virtual function table of this class
    
    //printf("VFT:%d\n",vftaddr);

    int m=getReg();
    fprintf(fptr,"MOV R%d,%d\n",m,vftaddr);
    int count=0;

    while(memfunc!=NULL)
    {
        //printf("C%d\n",memfunc->flabel);
        fprintf(fptr,"MOV [R%d],C%d\n",m,memfunc->flabel);  
        fprintf(fptr,"ADD R%d,1\n",m);
        memfunc=memfunc->next;
        count+=1;
    }       

    while(count<8)
    {
        fprintf(fptr,"MOV [R%d],-1\n",m);
        fprintf(fptr,"ADD R%d,1\n",m);
        count+=1;
    }
    freeReg();
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
///////////////////////////////////////////////////////////////////////////////
