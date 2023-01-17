int freereg_no=-1;

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

int getReg()
{
    freereg_no++;

    if(freereg_no==20)
    {    printf("Register full\n");
        return -1;
    }

    else
        return freereg_no;
} 

void freeReg()
{
    if(freereg_no>=0)
        freereg_no--;

    else
        printf("All registers already freed\n");

}

void callwrite(FILE *fptr,int resreg_no)
{
    int reg=getReg();
    
    fprintf(fptr,"MOV SP, 4122\n");         //AS first 26 locations are reserved for static variables
    fprintf(fptr,"MOV R%d,\"Write\"\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"MOV R%d, -2\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",resreg_no);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    
    freeReg();
    
    fprintf(fptr,"CALL 0\n");

    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
}

void callread(FILE *fptr,int resreg_no)
{
    int reg=getReg();
    
    fprintf(fptr,"MOV SP, 4122\n");   //AS first 26 locations are reserved for static variables
    fprintf(fptr,"MOV R%d,\"Read\"\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"MOV R%d,-1\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",resreg_no);
    fprintf(fptr,"PUSH R%d\n",reg);
    fprintf(fptr,"PUSH R%d\n",reg);
    
    freeReg();
    
    fprintf(fptr,"CALL 0\n");

    fprintf(fptr,"POP R0\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
    fprintf(fptr,"POP R1\n");
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

int address(char c)
{
    return 4096+(c-'a');
}

int codeGen(struct tnode* t,FILE* fptr)
{
    if(t->left==NULL && t->right==NULL)
    {
        if(t->nodetype==0)          //CONSTANT
        {
          int p=getReg();
          fprintf(fptr,"MOV R%d,%d\n",p,t->val);
          return p;
        }

        else                        //Variable
        {
            int p=getReg();
            int addr=address(*(t->varname));

            fprintf(fptr,"MOV R%d,%d\n",p,addr); //Moving the address to a register
            return p;
        }
    }

    int left=codeGen(t->left,fptr);
    
    if(t->nodetype==2)          //read
        callread(fptr,left);
    
    else if(t->nodetype==3)          //write
    {   
        if(t->left->nodetype==1)   //Variables
            fprintf(fptr,"MOV R%d,[R%d]\n",left,left);

        callwrite(fptr,left);
    }

    else if(t->nodetype==4)         //Connector
    {    int right=codeGen(t->right,fptr);}

    else                    //operator:+-*=
    {
        int right=codeGen(t->right,fptr);
        
        if(*(t->nonleaf)=='=')
            fprintf(fptr,"MOV [R%d],R%d\n",left,right);
        
        
        else
        {
            if(t->left->nodetype==1)    //variable
                fprintf(fptr,"MOV R%d,[R%d]\n",left,left);
            
            if(t->right->nodetype==1)    //variable
                fprintf(fptr,"MOV R%d,[R%d]\n",right,right);

            switch(*(t->nonleaf))
            {
                case '+' : fprintf(fptr,"ADD R%d,R%d\n",left,right);
                        break;
                case '-' : fprintf(fptr,"SUB R%d,R%d\n",left,right);
                        break;
                case '*' : fprintf(fptr,"MUL R%d,R%d\n",left,right);
                        break;
                case '/' : fprintf(fptr,"DIV R%d,R%d\n",left,right);
                        break;
            }
        }
    }

    freeReg();
    return left;
}

