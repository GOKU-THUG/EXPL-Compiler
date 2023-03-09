struct lnode* HEAD=NULL;

void insert_node(struct lnode* newnode)
{
    if(HEAD==NULL)
        HEAD=newnode;
    
    else
    {
        struct lnode* temp=HEAD;

        while(temp->next!=NULL){
            temp=temp->next;
        }

        temp->next=newnode;
    }

    newnode->next=NULL;
}

int ifpresent(char label[10])
{
    struct lnode* temp=HEAD;

    while(temp!=NULL)
    {
        if(strcmp(temp->label,label)==0)
            return temp->addr;

        temp=temp->next;
    }

    return -1;
}

void printlist(struct lnode* temp)
{
    while(temp!=NULL)
    {
        printf("%s:%d\n",temp->label,temp->addr);
        temp=temp->next;
    }
}