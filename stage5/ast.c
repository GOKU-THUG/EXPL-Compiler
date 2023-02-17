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
    temp->next=NULL;

	return temp;
}
//////////////////////////////////////////
struct tnode* makeFunctionNode(char* funcname,struct tnode* arglist,struct Gsymbol* gtemp)
{
		struct tnode *temp;
		temp = (struct tnode *)malloc(sizeof(struct tnode));

		temp->nonleaf = (char*)malloc(strlen(funcname) * sizeof(char));
		
		strcpy(temp->nonleaf,funcname);
		temp->type = gtemp->type; // Setting the return type of the function
		temp->nodetype=Function;
		temp->left=arglist;
		temp->right=NULL;
		temp->next=NULL;
        temp->Gentry=gtemp;
        
		return temp;
}
//////////////////////////////////////////
struct tnode *makeVariableNode(char *c)
{
	struct Gsymbol *gvariable;
	struct Lsymbol *lvariable;
	struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

	gvariable=GLookup(c);
	temp->Gentry = gvariable;

	lvariable = LLookup(c);
	temp->Lentry=lvariable;
	
	if (gvariable!=NULL | lvariable != NULL)
	{
		temp->varname = (char *)malloc(strlen(c) * sizeof(char));
		strcpy(temp->varname,c);

		temp->nonleaf = NULL;
		temp->nodetype = Variable;
		temp->left = NULL;
		temp->right = NULL;
		temp->next=NULL;

        if(lvariable!=NULL)
		    temp->type = lvariable->type; // Setting the variable type

        else
		    temp->type = gvariable->type; // Setting the variable type

		return temp;
	}

	free(temp);
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
    temp->type=-1;
	temp->left = t; // setting the id as the left child
	temp->right = NULL;
    temp->next=NULL;

	return temp;
}

struct tnode *makewritenode(struct tnode *t)
{
	struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

	temp->nonleaf = (char *)malloc(6 * sizeof(char));
	strcpy(temp->nonleaf, "write");

	temp->nodetype = Write;
    temp->type=-1;
	temp->left = t; // setting the id as the left child
	temp->right = NULL;
    temp->next=NULL;
	return temp;
}

struct tnode *makeConnectorNode(char c, struct tnode *l, struct tnode *r)
{
	struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

	temp->nonleaf = malloc(sizeof(char));
	*(temp->nonleaf) = c;

	temp->nodetype = Connector;
    temp->type=-1;
	temp->left = l;
	temp->right = r;
    temp->next=NULL;
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
    temp->next=NULL;

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
	temp->next=NULL;

	return temp;
}

//AND,OR,XOR,NOT
struct tnode* makeLogicalNode(char c[10],struct tnode* l,struct tnode* r)
{
    if(l!=NULL && l->type!=Boolean)
    {
        printf("Left Expression does not return boolean:Type:%d\n",l->type);
        exit(1);
    }

    if(r!=NULL && r->type!=Boolean)
    {
        printf("Right Expression does not return boolean:Type:%d\n",r->type);
        exit(1);
    }

    struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

	temp->nonleaf = malloc(strlen(c) * sizeof(char));
	strcpy(temp->nonleaf, c);

	temp->type = Boolean;
	temp->nodetype = Logical;
	temp->left = l;
	temp->right = r;
	temp->next=NULL;

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
    temp->type=-1;
	temp->left = l;
	temp->right = r;
	temp->next=NULL;

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

    temp->type=-1;
	temp->left = NULL;
	temp->right = NULL;
	temp->next=NULL;

	return temp;
}

// Print tree
void printtree(struct tnode *t)
{
	if(t!=NULL)
	{
	    printtree(t->left);

        if (t->nodetype == Constant)
		{
			if (t->type == Integer)
				printf("%d\n", (t->val).i);

			if (t->type == String)
				printf("%s\n", (t->val).c);
		}

        if(t->nodetype==Variable)
            printf("%s\n",t->varname);

        if(t->nodetype==Function)
            printf("%s\n",t->nonleaf);

		if (t->nodetype == Read) // read
			printf("Read\n");
		
		else if (t->nodetype == Write)
			printf("Write\n");

		else if (t->nodetype == Connector)
			printf(".\n");
	
        else if (t->nodetype  == Logical)
			printf("%s\n", t->nonleaf);
        
		else if (t->nodetype == Operator)
			printf("%c\n", *(t->nonleaf));

		else if (t->nodetype == Comparison)
			printf("%s\n", t->nonleaf);

		else if (t->nodetype == Branch)
			printf("%s\n", t->nonleaf);

		printtree(t->right);
	}
}

//AST CLEAR:POST ORDER CLEARANCE
void Freeast(struct tnode* t)
{
    if(t!=NULL)
    {
        Freeast(t->left);
        Freeast(t->right);
        free(t);
    }
}