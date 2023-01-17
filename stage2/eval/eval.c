int arr[26];

struct tnode* makeConstantNode(int n)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->val=n;
    temp->varname = NULL;
    temp->nonleaf=NULL;
    temp->nodetype=0;
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
    temp->nonleaf=NULL;
    temp->nodetype=1;
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

    temp->nodetype=2;
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

    temp->nodetype=3;
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
    temp->nodetype=4;
    temp->left=l;
    temp->right=r;
    
    return temp;
}

struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    *(temp->nonleaf) = c;
    temp->nodetype=5;
    temp->left = l;
    temp->right=r;
    
    return temp;
}

void inorder(struct tnode* t)
{
    if(t->left==NULL && t->right==NULL)
    {
        if(t->nodetype==0)
            printf("%d\n",t->val);
        
        else
            printf("%c\n",*(t->varname));
    }

    if(t->left!=NULL)
        inorder(t->left);

    if(t->nodetype==2 || t->nodetype==3)
        printf("%s\n",t->nonleaf);
    
    if(t->nodetype==4 || t->nodetype==5)
        printf("%c\n",*(t->nonleaf));
    
    if(t->right!=NULL)
    inorder(t->right);
    
}

int evaluate(struct tnode* t)
{
    if(t->left==NULL && t->right==NULL)
    {
        if(t->nodetype==0)          //Constant
          return t->val;
        
        else                        //Variable
            return (*(t->varname)-'a');   
    }

    int left=evaluate(t->left);
    
    if(t->nodetype==2)                      //Read
        scanf("%d",&arr[left]);
    
    else if(t->nodetype==3)                 //Write
    {   
        if(t->left->nodetype==1)            //Variables
            printf("%d\n",arr[left]);

        else                                //Constant
            printf("%d\n",left);
    }

    else if(t->nodetype==4)         //Connector
    {int right=evaluate(t->right);}

    else                    //operator:+-*=
    {
        int right=evaluate(t->right);
        
        if(*(t->nonleaf)=='=')
            arr[left]=right;
        
        else
        {
            if(t->left->nodetype==1)    //variable
                left=arr[left];
            
            if(t->right->nodetype==1)    //variable
                right=arr[right];

            switch(*(t->nonleaf))
            {
                case '+' : return (left + right);
                            break;
                case '-' : return (left-right);
                        break;
                case '*' : return (left*right);
                        break;
                case '/' : return (left/right);
                        break;
            }
        }
    }

    return 0;
}