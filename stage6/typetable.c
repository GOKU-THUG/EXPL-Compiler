struct Typetable* THEAD = NULL;
int fieldindex=1;

///////////////////////////////////////////////////////////////////////////
void TypetableCreate(){    
    THEAD=TInstall("int",1,NULL);
    THEAD->next=TInstall("str",1,NULL);
    THEAD->next->next=TInstall("bool",1,NULL);
    THEAD->next->next->next=TInstall("void",0,NULL); 
    THEAD->next->next->next->next=TInstall("NULL",0,NULL); 

}
///////////////////////////////////////////////////////////////////////////
struct Typetable* TInstall(char* name,int size,struct Fieldlist *fields){

    struct Typetable* ispresent=TLookup(name);

    if(ispresent==NULL){
        struct Typetable* newnode=(struct Typetable*)malloc(sizeof(struct Typetable));
        newnode->name=(char*)malloc(strlen(name)*sizeof(char));
        
        strcpy(newnode->name,name);
        newnode->size=size;
        newnode->fields=fields;

        if (THEAD == NULL)
            THEAD = newnode;
        
        else
        {
            struct Typetable *temp = THEAD;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = newnode;
        }
        
        newnode->next=NULL;
        return newnode;
    }
    
    else
    {
        printf("Error:Type already defined:%s\n",name);
        exit(1);
    }
}
///////////////////////////////////////////////////////////////////////////
struct Typetable* TLookup(char *name){
    
    struct Typetable* temp=THEAD;
    while(temp!=NULL){
        if(strcmp(temp->name,name)==0)
            return temp;
        temp=temp->next;
    }

    return temp;
}
///////////////////////////////////////////////////////////////////////////
int GetSize(struct Typetable* type){
    return type->size;
}
///////////////////////////////////////////////////////////////////////////
struct Fieldlist* FLookup(struct Typetable *type, char *name){
    struct Fieldlist* temp=type->fields;

    while(temp!=NULL){
        if(strcmp(temp->name,name)==0)
            return temp;
        
        temp=temp->next;
    }
    return temp;
}
//////////////////////////////////////////////////////////////////////////
struct Fieldlist* Fcreate(char* varname,char* typename)
{
    struct Fieldlist* field=(struct Fieldlist*)malloc(sizeof(struct Fieldlist));
    field->name=(char*)malloc(strlen(varname)*sizeof(char));
    field->nametype=(char*)malloc(strlen(typename)*sizeof(char));

    strcpy(field->name,varname);
    strcpy(field->nametype,typename);
    field->type=TLookup(typename);
    field->fieldindex=fieldindex;
    field->next=NULL;

    fieldindex+=1;
    return field;
}
////////////////////////////////////////////////////////////////////////////
void Fappend(struct Fieldlist* head,struct Fieldlist* field)
{
    if(head==NULL)
    {
        printf("Field Head Empty\n");
        exit(1);
    }
    while(head->next!=NULL)
    {
        if(strcmp(head->name,field->name)==0)       //Same field declared twice
        {
            printf("Same field declared twice:\n");
            exit(1);
        }

        head=head->next;
    }

    if(strcmp(head->name,field->name)==0)       //Same field declared twice
    {
        printf("Same field declared twice:\n");
        exit(1);
    }
    head->next=field;
    field->next=NULL;
}
////////////////////////////////////////////////////////////////////////////
void printtypetable()
{
    struct Typetable* temp=THEAD;
    struct Fieldlist* fields;

    printf("Type Table:\n");

    while(temp!=NULL)
    {
        printf("TYPE:%s,TYPE SIZE:%d\n",temp->name,temp->size);
        
        fields=temp->fields;

        while(fields!=NULL)
        {
            printf("FIELD:%s , FIELDINDEX:%d , FIELDTYPE:%s\n",fields->name,fields->fieldindex,fields->type->name);
            fields=fields->next;
        }

        temp=temp->next;
    }

    printf("\n");
}