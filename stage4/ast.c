struct tnode *makeConstantNode(int n, char *c)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));

    if (c != NULL) // In case of integer constant
    {
        (temp->val).c = (char *)malloc(strlen(c) * sizeof(char));
        (temp->val).c = c;

        temp->type = String;
    }

    else // In case of String constants
    {
        (temp->val).i = n;
        temp->type = Integer;
    }

    temp->varname = NULL;
    temp->nonleaf = NULL;
    temp->nodetype = Constant;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct tnode *makeVariableNode(char *c)
{
    struct Gsymbol *variable;

    variable = Lookup(c);

    if (variable != NULL)
    {
        struct tnode *temp;
        temp = (struct tnode *)malloc(sizeof(struct tnode));

        temp->varname = (char *)malloc(strlen(c) * sizeof(char));
        strcpy(temp->varname, c);

        temp->nonleaf = NULL;
        temp->nodetype = Variable;
        temp->left = NULL;
        temp->right = NULL;

        temp->Gentry = variable;

        temp->type = variable->type; // Setting the variable type

        return temp;
    }

    printf("Variable undeclared:%s\n", c);
    exit(1);
}

struct tnode *makereadnode(struct tnode *t)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));

    temp->nonleaf = (char *)malloc(5 * sizeof(char));
    strcpy(temp->nonleaf, "read");

    temp->nodetype = Read;
    temp->left = t; // setting the id as the left child
    temp->right = NULL;

    return temp;
}

struct tnode *makewritenode(struct tnode *t)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));

    temp->nonleaf = (char *)malloc(6 * sizeof(char));
    strcpy(temp->nonleaf, "write");

    temp->nodetype = Write;
    temp->left = t; // setting the id as the left child
    temp->right = NULL;

    return temp;
}

struct tnode *makeConnectorNode(char c, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    *(temp->nonleaf) = c;

    temp->nodetype = Connector;
    temp->left = l;
    temp->right = r;

    return temp;
}

//=,+,-,*,/
struct tnode *makeOperatorNode(char c, struct tnode *l, struct tnode *r)
{
    if (c == '=' && (l->type != r->type | l->nodetype!=Variable))
    {
        printf("Operator Type mismatch:%c\n", c);
        exit(1);
    }

    if (c != '=' && (l->type != Integer | r->type != Integer))
    {
        printf("Operator Type mismatch:%c\n", c);
        exit(1);
    }

    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    *(temp->nonleaf) = c;

    temp->type = Integer;
    temp->nodetype = Operator;
    temp->left = l;
    temp->right = r;

    return temp;
}

//<,>,<=,>=,==
struct tnode *makeComparisonNode(char c[10], struct tnode *l, struct tnode *r)
{
    if (l->type != r->type)
    {
        printf("Comparison Type Mismatch:%d and %d\n", l->type, r->type);
        exit(1);
    }

    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(strlen(c) * sizeof(char));
    strcpy(temp->nonleaf, c);

    temp->type = Boolean;
    temp->nodetype = Comparison;
    temp->left = l;
    temp->right = r;

    return temp;
}

// if,while,else
struct tnode *makeBranchingNode(char *c, struct tnode *l, struct tnode *r)
{
    if (r != NULL && r->type != Boolean && ((strcmp(c, "Do") == 0) || (strcmp(c, "Repeat") == 0)))
    {
        printf("%s", r->nonleaf);
        printf("Branch Type mismatch:Branching\n");
        exit(1);
    }

    else if (l != NULL && l->type != Boolean && strcmp(c, "Else") != 0 && (strcmp(c, "Do") != 0) && (strcmp(c, "Repeat") != 0))
    {
        printf("%s", l->nonleaf);
        printf("Branch Type mismatch:Branching\n");
        exit(1);
    }

    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(sizeof(char));
    strcpy(temp->nonleaf, c);

    // temp->type=Boolean;
    temp->nodetype = Branch;
    temp->left = l;
    temp->right = r;

    return temp;
}

struct tnode *makeBreak_ContinueNode(char *c)
{
    struct tnode *temp;
    temp = (struct tnode *)malloc(sizeof(struct tnode));

    temp->nonleaf = malloc(strlen(c) * sizeof(char));
    strcpy(temp->nonleaf, c);

    if (strcmp("break", c) == 0)
        temp->nodetype = Break;

    else if (strcmp("continue", c) == 0)
        temp->nodetype = Continue;

    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Print tree
void printtree(struct tnode *t)
{
    if (t->left == NULL && t->right == NULL)
    {
        if (t->nodetype == Constant)
        {
            if (t->type == Integer)
                printf("%d\n", (t->val).i);

            if (t->type == String)
                printf("%s\n", (t->val).c);
        }

    }

    else
    {
        if(t->left!=NULL)
            printtree(t->left);

        if (t->nodetype == Read) // read
        {
            printf("Read\n");
        }

        else if (t->nodetype == Write)
        {
            printf("Write\n");
        }

        else if (t->nodetype == Connector)
        {
            printf(".\n");
        }

        else if (t->nodetype == Operator)
            printf("%c\n", *(t->nonleaf));

        else if (t->nodetype == Comparison)
            printf("%s\n", t->nonleaf);

        else if (t->nodetype == Branch)
            printf("%s\n", t->nonleaf);

        if(t->nodetype==Variable)
            printf("Variable:%c\n",*(t->varname));

        if (t->right != NULL)
            printtree(t->right);
    }
}
