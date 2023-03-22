struct tnode *makeConstantNode(int n, char *c)
{
	struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

	if (c != NULL) // In case of integer constant
	{
		(temp->val).c = (char *)malloc(strlen(c) * sizeof(char));
		(temp->val).c = c;

		temp->type = TLookup("str");
	}

	else if(n!=-1) // In case of String constants
	{
		(temp->val).i = n;
		temp->type =  TLookup("int");
	}

    else    //NULL POINTER
        temp->type =  TLookup("NULL");
    
	temp->varname = NULL;
	temp->nonleaf = NULL;
	temp->nodetype = Constant;
	temp->left = NULL;
	temp->right = NULL;
    temp->next=NULL;

	return temp;
}
//////////////////////////////////////////
struct tnode* makeFunctionNode(char* funcname,struct tnode* arglist,struct Gsymbol* gtemp,struct Memberfunclist* member,struct tnode* right)
{
		struct tnode *temp;
		temp = (struct tnode *)malloc(sizeof(struct tnode));

		temp->nonleaf = (char*)malloc(strlen(funcname) * sizeof(char));
		
		strcpy(temp->nonleaf,funcname);
        
        if(gtemp!=NULL)
		    temp->type = gtemp->type; // Setting the return type of the function
        
        if(member!=NULL)        //Member function can never have a class as a return type
            temp->type= member->type;
    

		temp->nodetype=Function;
		temp->left=arglist;
		temp->right=right;
		temp->next=NULL;
        temp->Gentry=gtemp;
        temp->member=member;

		return temp;
}
//////////////////////////////////////////
struct tnode* makefieldnode(char* fieldname,struct Typetable* userdeftype,struct Classtable* ctype)
{
    struct Fieldlist* field=NULL;
    
    if(userdeftype!=NULL)                                         
        field=FLookup(userdeftype,fieldname);             //Checks if the field is of a userdefined type

    else if(ctype!=NULL)
        field=DLookup(ctype,fieldname);                  //Checks if such a data member exists in that class

    if(field==NULL)
    {
        printf("Field does not exist");
        exit(1);
    }

    struct tnode *temp=(struct tnode *)malloc(sizeof(struct tnode));

    temp->type=field->type;     //If field is a class then type will be null;
    temp->nodetype = Field;
    //This field stores the field data
    temp->field=field;
    temp->next=NULL;
    temp->left=NULL;
    temp->right=NULL;
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

	    temp->nonleaf = (char *)malloc(9 * sizeof(char));
		strcpy(temp->nonleaf,"variable");
		
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
    temp->type=NULL;
	temp->left = t; // setting the id as the left child
	temp->right = NULL;
    temp->next=NULL;

	return temp;
}

//Initialize,alloc and free
struct tnode* dynamicmemorynode(struct Typetable* t,int nodetype,struct tnode* left,struct tnode* right)
{
    if(nodetype==Initialize && t==NULL)//It is a class
    {
        printf("Invalid initialization for non pointer type:\n");
        exit(1);
    }

    if(nodetype==Initialize && strcmp(t->name,"int")!=0)
    {
        printf("Invalid initialization for non pointer type:\n");
        exit(1);
    }
    
    if((nodetype==New) | (nodetype==Delete))
    {
        if(t!=NULL)
        {
            printf("New/Delete is invalid for non-class type:");
            exit(1);
        }

        //else t== null indicates new /delete is valid
    }
  
    if((nodetype==Alloc) | (nodetype==Free))
    {
        if(t==NULL)//idicates class
        {
            printf("Alloc/Free is invalid for class type");
            exit(1);
        }

        //t!=NULL
        else if(strcmp(t->name,"int")==0 | strcmp(t->name,"bool")==0 | strcmp(t->name,"str")==0 | strcmp(t->name,"void")==0)
        {
            printf("Invalid Free or alloc function:%d for non pointer type:\n",nodetype);
            exit(1);
        }
    }

    struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

    temp->nodetype = nodetype;
    temp->type=t;               //ie:user defined datatype on the left side of ID/FIELD=alloc()
	temp->left = left;         // setting the id/field as the left child
	temp->right = right;
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
    temp->type=NULL;
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
    temp->type=NULL;
	temp->left = l;
	temp->right = r;
    temp->next=NULL;
	return temp;
}

//=,+,-,*,/
struct tnode *makeOperatorNode(char c, struct tnode *l, struct tnode *r)
{
    struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

    if(c=='=')
    {
        if(l->nodetype!=Variable)
        {
            free(temp);
            printf("Left hand side not variable for =:\n");
		    exit(1);
        }

        else if(l->type==NULL)  //Class
        {
            if(r->type!=NULL)   //NON-CLASS
            {
                printf("Operator Type mismatch for class in =:\n");
		        exit(1);
            }

            //Hence Now we found that right is a class
            if(r->nodetype==Variable) //for a=b and a=b,c case.Not for a=New() case we check is it is desc class
            {
                //NOW l->type and r->type is a class we can confirm after the above 2 if conditions
                //since l->nodetype ==variable l will have a varname;
                //r can now be either a class variable or a field;a.b(b is a class belonging to variable a) or c(variable of type class)
                char* descname=NULL;

                if(r->left!=NULL)   //Field of a class ID=E(E=ID.FIELD) where field is a class
                {
                    struct tnode* iterfield=r->left;
                    
                    while(iterfield->next!=NULL)
                        iterfield=iterfield->next;   

                    descname=iterfield->field->ctype->name;
                }

                else        //ID=E(WHERE E =ID AND E IS OF TYPE CLASS)
                    descname=r->Gentry->ctype->name;

                int valid=isvalid(l->Gentry->ctype->name,descname);  

                if(valid==-1)
                {
                    printf("Desc class and parent class mismatch:\n");
                    exit(1);
                } 
            }
        }

        else if(r->type==TLookup("NULL") && (strcmp(l->type->name,"int")==0 | strcmp(l->type->name,"bool")==0 | strcmp(l->type->name,"str")==0|strcmp(l->type->name,"void")==0|strcmp(l->type->name,"NULL")==0))
        {
            free(temp);
            printf("Operator Type mismatch for NULL:\n");
		    exit(1);
        }

        else if(r->type!=TLookup("NULL") && (l->type!=r->type))
        {
            free(temp);
            printf("Operator Type mismatch:%c\n", c);
		    exit(1);
        }
        
        temp->type = TLookup("void");
    }
    
	else if (c != '=')
	{
        if((l->type != TLookup("int") | r->type != TLookup("int")))
		{
            free(temp);
            printf("Operator Type mismatch:%c\n", c);
		    exit(1);
        }

        temp->type = TLookup("int");
    }

	
	temp->nonleaf = malloc(sizeof(char));
	*(temp->nonleaf) = c;
	
    temp->nodetype = Operator;
	temp->left = l;
	temp->right = r;
    temp->next=NULL;

	return temp;
}

//<,>,<=,>=,==,!=
struct tnode *makeComparisonNode(char c[10], struct tnode *l, struct tnode *r)
{
    if(strcmp(c,"==")==0 | strcmp(c,"!=")==0)
    {
        if(l->type==NULL && l->type!=r->type)   //Incase of classes
        {
            printf("Comparison Type(%s) Mismatch for class:NULL and %s\n",c,r->type->name);
		    exit(1);
        }

        else if(r->type==TLookup("NULL") && (strcmp(l->type->name,"int")==0 | strcmp(l->type->name,"bool")==0 | strcmp(l->type->name,"str")==0|strcmp(l->type->name,"void")==0|strcmp(l->type->name,"NULL")==0))
        {
            printf("Comparison Type(%s) Mismatch for NULL:%s and %s\n",c,l->type->name, r->type->name);
		    exit(1);
        }

        else if(r->type!=TLookup("NULL") && l->type != r->type)
        {
            printf("Comparison Type(%s) Mismatch:%s and %s\n",c,l->type->name, r->type->name);
		    exit(1);
        }

        struct tnode *temp;
        temp = (struct tnode *)malloc(sizeof(struct tnode));

        temp->nonleaf = malloc(strlen(c) * sizeof(char));
        strcpy(temp->nonleaf, c);

        temp->type = TLookup("bool");
        temp->nodetype = Comparison;
        temp->left = l;
        temp->right = r;
        temp->next=NULL;

        return temp;
    }

	if (l->type != r->type)
	{
		printf("Comparison Type Mismatch:%s and %s\n", l->type->name, r->type->name);
		exit(1);
	}

	struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

	temp->nonleaf = malloc(strlen(c) * sizeof(char));
	strcpy(temp->nonleaf, c);

	temp->type = TLookup("bool");
	temp->nodetype = Comparison;
	temp->left = l;
	temp->right = r;
	temp->next=NULL;

	return temp;
}

//AND,OR,XOR,NOT
struct tnode* makeLogicalNode(char c[10],struct tnode* l,struct tnode* r)
{
    if(l!=NULL && l->type!=TLookup("bool"))
    {
        printf("Left Expression does not return boolean:Type:%s\n",l->type->name);
        exit(1);
    }

    if(r!=NULL && r->type!=TLookup("bool"))
    {
        printf("Right Expression does not return boolean:Type:%s\n",r->type->name);
        exit(1);
    }

    struct tnode *temp;
	temp = (struct tnode *)malloc(sizeof(struct tnode));

	temp->nonleaf = malloc(strlen(c) * sizeof(char));
	strcpy(temp->nonleaf, c);

	temp->type = TLookup("bool");
	temp->nodetype = Logical;
	temp->left = l;
	temp->right = r;
	temp->next=NULL;

	return temp;
    
}
// if,while,else
struct tnode *makeBranchingNode(char *c, struct tnode *l, struct tnode *r)
{
	if (r != NULL && r->type != TLookup("bool") && ((strcmp(c, "Do") == 0) || (strcmp(c, "Repeat") == 0)))
	{
		printf("%s", r->nonleaf);
		printf("Branch Type mismatch:Branching\n");
		exit(1);
	}

	else if (l != NULL && l->type != TLookup("bool") && strcmp(c, "Else") != 0 && (strcmp(c, "Do") != 0) && (strcmp(c, "Repeat") != 0))
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
    temp->type=NULL;
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

    temp->type=NULL;
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
			if (t->type == TLookup("int"))
				printf("%d\n", (t->val).i);

			if (t->type == TLookup("str"))
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

        else if(t->nodetype == Initialize)
            printf("Initialize\n");

        else if(t->nodetype == Alloc)
            printf("ALLOC\n");

        else if(t->nodetype == Free)
            printf("Free\n");
            
		printtree(t->right);
	}
}

//AST CLEAR:POST ORDER CLEARANCE
void Freeast(struct tnode* t)
{
    if(t!=NULL)
    {
        //printf("%d\n",t->nodetype);
        Freeast(t->left);
        Freeast(t->right);
        Freeast(t->next);
        free(t);
    }
}