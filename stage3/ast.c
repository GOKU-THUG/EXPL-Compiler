struct tnode* makeConstantNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->val=n;
    temp->type=Integer;
    temp->varname = NULL;
    temp->nonleaf=NULL;
    temp->nodetype=Constant;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct tnode* makeVariableNode(char c)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->varname=malloc(sizeof(char));
    *(temp->varname)=c;

    temp->type=Integer;
    temp->nonleaf=NULL;
    temp->nodetype=Variable;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct tnode* makereadnode(struct tnode* t)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    strcpy(temp->nonleaf,"read");

    temp->type=Integer;
    temp->nodetype=Read;
    temp->left =t;          //setting the id as the left child
    temp->right=NULL;
    
    return temp;
}

struct tnode* makewritenode(struct tnode* t)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    strcpy(temp->nonleaf,"write");

    temp->type=Integer;
    temp->nodetype=Write;
    temp->left =t;          //setting the id as the left child
    temp->right=NULL;
    
    return temp;
}

struct tnode* makeConnectorNode(char c,struct tnode *l,struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    *(temp->nonleaf) = c;


    temp->nodetype=Connector;
    temp->left=l;
    temp->right=r;
    
    return temp;
}

//=,+,-,*,/
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r)
{

    if(l->type!=Integer | r->type!=Integer)
    {
        printf("Type mismatch:%c\n",c);
        exit(0);
    }

    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    *(temp->nonleaf) = c;

    temp->type=Integer;
    temp->nodetype=Operator;
    temp->left = l;
    temp->right=r;
    
    return temp;
}

//<,>,<=,>=,==
struct tnode* makeComparisonNode(char c[10],struct tnode *l,struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    strcpy(temp->nonleaf,c);

    temp->type=Boolean;
    temp->nodetype=Comparison;
    temp->left = l;
    temp->right=r;
    
    return temp;
}

//if,while,else
struct tnode* makeBranchingNode(char* c,struct tnode* l,struct tnode* r)
{
    if(l->type!=Boolean && strcmp(c,"Else")!=0)
    {
        printf("%s",l->nonleaf);

        //printf("%s",l->nonleaf);
        //printf("%s",l->nonleaf);

        printf("Type mismatch:Branching\n");
        exit(0);
    }

    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    strcpy(temp->nonleaf,c);

    temp->type=Boolean;
    temp->nodetype=Branch;
    temp->left = l;
    temp->right=r;
    
    return temp;
}

//Print tree
void printtree(struct tnode* t)
{
    if(t->left==NULL && t->right==NULL)
    {
        if(t->nodetype==0)
            printf("%d\n",t->val);

        else
            printf("%c\n",*(t->varname));
    }

    else
    {
        printtree(t->left);

        if(t->nodetype==Read)          //read
        {printf("Read\n");}

        else if(t->nodetype==Write)
        {printf("Write\n");}

        else if(t->nodetype==Connector)
        {printf(".\n");}

        else if(t->nodetype==Operator)
            printf("%c\n",*(t->nonleaf)); 
        
        else if(t->nodetype==Comparison)
            printf("%s\n",t->nonleaf); 
        
        else if(t->nodetype==Branch)
            printf("%s\n",t->nonleaf); 
        

        if(t->right!=NULL)
            printtree(t->right);   
    }
}

