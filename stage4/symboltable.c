struct Gsymbol *HEAD = NULL;
int used_space = 0;

struct Gsymbol *Lookup(char *name) // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
{
    struct Gsymbol *temp = HEAD;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

void Install(char *name, int type, int size,int rowsize,int colsize) // Creates a symbol table entry.
{
    struct Gsymbol *ispresent = Lookup(name);

    if (ispresent == NULL)
    {
        struct Gsymbol *newnode = (Gsymbol *)malloc(sizeof(Gsymbol));

        newnode->name = (char *)malloc(strlen(name) * sizeof(char));
        strcpy(newnode->name, name);
        newnode->type = type;
        newnode->size = size;
        
        //For 2d arrays
        if(rowsize!=-1)
            newnode->row=rowsize;
        
        if(colsize!=-1)
            newnode->col=colsize;

        // To track the last used space so as to push registers in case of system calls
        used_space = used_space + size;

        if (HEAD == NULL)
        {
            HEAD = newnode;
            newnode->binding = 4096;
        }

        else
        {
            struct Gsymbol *temp = HEAD;
            int lastsize, start_addr;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }

            lastsize = temp->size;
            start_addr = temp->binding;

            temp->next = newnode;

            newnode->binding = (lastsize + start_addr);
        }

        newnode->next = NULL;
    }

    else
    {
        printf("Error:Variable already declared:%s\n", name);
        exit(0);
    }
}

void printsymboltable()
{
    struct Gsymbol *temp = HEAD;

    while (temp != NULL)
    {
        char type[10];

        if(temp->type==Boolean)
            strcpy(type,"Boolean");
        
        if(temp->type==Integer)
            strcpy(type,"Integer");
        
        if(temp->type==String)
            strcpy(type,"String");

        printf("%s %s %d\n", temp->name,type,temp->size);
        temp = temp->next;
    }
    printf("\n");
}

void addtype(int type)
{
    struct Gsymbol *temp = HEAD;

    while (temp != NULL)
    {
        if (temp->type == -1)
            temp->type = type;

        temp = temp->next;
    }
}