int freereg_no = -1;
int freelabel = -1;
int funclabel = 0;

int bstack[100];
int cstack[100];

int btop = -1;
int ctop = -1;

int push(char c, int label)
{
    if (c == 'b')
    {
        btop += 1;
        bstack[btop] = label;
    }

    else if (c == 'c')
    {
        ctop += 1;
        cstack[ctop] = label;
    }
}
int pop(char c)
{
    if (c == 'b')
    {
        if (btop == -1)
            printf("BSTACK EMPTY ALREADY\n");

        btop -= 1;
    }

    else if (c == 'c')
    {
        if (ctop == -1)
            printf("CSTACK EMPTY ALREADY\n");

        ctop -= 1;
    }
}

int getLabel()
{
    freelabel += 1;

    return freelabel;
}

int getfunclabel()
{ // FOR FLABEL
    funclabel += 1;
    return funclabel;
}

int getReg()
{
    freereg_no++;

    if (freereg_no == 20)
    {
        printf("Register full\n");
        return -1;
    }

    else
        return freereg_no;
}

void freeReg()
{
    if (freereg_no >= 0)
        freereg_no--;

    else
        printf("All registers already freed\n");
}

int address(char c)
{
    return 4096 + (c - 'a');
}

/////////////////////////////////////////////////////////////
//SYSTEM CALLS
//For system calls ensure that you push the temporary registers into the stack
void callread(FILE *fptr, int resreg_no)
{
    int reg = getReg();

    fprintf(fptr, "MOV R%d,\"Read\"\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "MOV R%d,-1\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", resreg_no);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg); // Return value

    freeReg();
    freeReg();

    int lastreg=pushtempreg(fptr);
    fprintf(fptr, "CALL 0\n");
    poptempreg(lastreg,fptr);

    int return_reg = getReg();
    reg = getReg();

    fprintf(fptr, "POP R%d\n", return_reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);

    freeReg();
    freeReg();
}

void callwrite(FILE *fptr, int resreg_no)
{
    int reg = getReg();

    fprintf(fptr, "MOV R%d,\"Write\"\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "MOV R%d,-2\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", resreg_no);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);

    freeReg();
    freeReg();

    int lastreg=pushtempreg(fptr);
    fprintf(fptr, "CALL 0\n");
    poptempreg(lastreg,fptr);

    int return_reg = getReg();
    reg = getReg();

    fprintf(fptr, "POP R%d\n", return_reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);

    freeReg();
    freeReg();
}

//To initialize the heap
int callinitialize(FILE* fptr)
{   
    int reg = getReg();

    fprintf(fptr, "MOV R%d,\"Heapset\"\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg); // Return value

    freeReg();

    int lastreg=pushtempreg(fptr);
    fprintf(fptr, "CALL 0\n");
    poptempreg(lastreg,fptr);

    int return_reg = getReg();
    reg = getReg();

    fprintf(fptr, "POP R%d\n", return_reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);

    freeReg();
    
    return return_reg;              //Returns the register number of the register containing the return value
}

int callalloc(FILE* fptr)
{
    int reg=getReg();

    fprintf(fptr, "MOV R%d,\"Alloc\"\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);

    fprintf(fptr, "MOV R%d,8\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);

    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg); // Return value

    freeReg();

    int lastreg=pushtempreg(fptr);
    fprintf(fptr, "CALL 0\n");
    poptempreg(lastreg,fptr);

    int return_reg = getReg();          //Contains the starting heap address
    reg = getReg();

    fprintf(fptr, "POP R%d\n", return_reg);     //Contains the heap starting address
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);

    freeReg();

    return return_reg;              //Returns the register number of the register containing the return value
}

void callfree(FILE* fptr,int resreg_no)
{
    int reg = getReg();

    fprintf(fptr, "MOV R%d,\"Free\"\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", resreg_no); //Pushes the register containing the address
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg); // Return value

    freeReg();
    freeReg();

    int lastreg=pushtempreg(fptr);
    fprintf(fptr, "CALL 0\n");
    poptempreg(lastreg,fptr);

    int return_reg = getReg();
    reg = getReg();

    fprintf(fptr, "POP R%d\n", return_reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);
    fprintf(fptr, "POP R%d\n", reg);

    freeReg();
    freeReg();
}

int pushtempreg(FILE* fptr)
{
    int lastreg_local = freereg_no;
    for (int i = lastreg_local; i >= 0; i--) // Pushing the temporary registers
    {
        fprintf(fptr, "\tPUSH R%d\n", i);
        // frees the registers since it has been pushed
        freeReg();
    }

    return lastreg_local;
}

void poptempreg(int lastreg_local,FILE* fptr)
{
     for (int i = 0; i <= lastreg_local; i++) // Popping back the value of the temporary registers
     {
            int reg = getReg();
            fprintf(fptr,"\tPOP R%d\n", i);
     }
}
////////////////////////////////////////////////////////////
void callwhile(FILE *fptr, struct tnode *t)
{
    int label1 = getLabel();
    int label2 = getLabel();

    fprintf(fptr, "L%d:\n", label1);

    int result_reg = codeGen(t->left, fptr); // Will return the no of the register containing the boolean result

    fprintf(fptr, "JZ R%d,L%d\n", result_reg, label2);

    freeReg();

    if (t->right != NULL) // If condition is satisfied
    {
        push('b', label2); // For break statements
        push('c', label1); // For continue statements

        int right = codeGen(t->right, fptr);

        pop('b');
        pop('c');

        if (right != -1)
            freeReg();
    }
    fprintf(fptr, "JMP L%d\n", label1);
    fprintf(fptr, "L%d:\n", label2);
}

void calldo(FILE *fptr, struct tnode *t)
{
    int label1 = getLabel();
    int label2 = getLabel();

    fprintf(fptr, "L%d:\n", label1);

    if (t->left != NULL)
    {
        push('b', label2); // For break statements
        push('c', label1); // For continue statements

        int left = codeGen(t->left, fptr);

        pop('b');
        pop('c');

        if (left != -1)
            freeReg();
    }

    int result_reg = codeGen(t->right, fptr); // Will return the no of the register containing the boolean result
    freeReg();

    fprintf(fptr, "JNZ R%d,L%d\n", result_reg, label1); // If condition satisfied

    fprintf(fptr, "L%d:\n", label2);
}

void callrepeat(FILE *fptr, struct tnode *t)
{
    int label1 = getLabel();
    int label2 = getLabel();

    fprintf(fptr, "L%d:\n", label1);

    if (t->left != NULL)
    {
        push('b', label2); // For break statements
        push('c', label1); // For continue statements

        int left = codeGen(t->left, fptr);

        pop('b');
        pop('c');

        if (left != -1)
            freeReg();
    }

    int result_reg = codeGen(t->right, fptr); // Will return the no of the register containing the boolean result

    fprintf(fptr, "JZ R%d,L%d\n", result_reg, label1); // If condition satisfied

    freeReg();

    fprintf(fptr, "L%d:\n", label2);
}

void callif(FILE *fptr, struct tnode *t)
{
    int label1 = getLabel();
    int label2 = getLabel();

    fprintf(fptr, "L%d:\n", label1);

    int result_reg = codeGen(t->left, fptr); // Will return the no of the register containing the boolean result

    fprintf(fptr, "JZ R%d,L%d\n", result_reg, label2);

    freeReg();

    if (t->right != NULL) // If condition is satisfied
    {
        int right = codeGen(t->right, fptr);

        if (right != -1)
            freeReg();
    }
    fprintf(fptr, "L%d:\n", label2);
}

void callelse(FILE *fptr, struct tnode *t)
{
    if (t->left != NULL)
    {
        int left = codeGen(t->left, fptr);

        if (left != -1)
            freeReg();
    }
}

void callifelse(FILE *fptr, struct tnode *t)
{
    int label1 = getLabel();
    int label2 = getLabel();
    int label3 = getLabel();

    fprintf(fptr, "L%d:\n", label1);

    int result_reg = codeGen(t->left, fptr); // Will return the no of the register containing the boolean result

    fprintf(fptr, "JZ R%d,L%d\n", result_reg, label2);

    freeReg();

    if (t->right->left != NULL)
    {
        int right_left = codeGen(t->right->left, fptr);

        if (right_left != -1)
            freeReg();
    }

    fprintf(fptr, "JMP L%d\n", label3);

    fprintf(fptr, "L%d:\n", label2);

    callelse(fptr, t->right->right);

    fprintf(fptr, "L%d:\n", label3);

    // return -1 is done in codegen;
}

void callcomp(FILE *fptr, char c[10], int leftreg, int rightreg)
{
    if (strcmp(c, "<") == 0)
        fprintf(fptr, "LT R%d,R%d\n", leftreg, rightreg);

    if (strcmp(c, ">") == 0)
        fprintf(fptr, "GT R%d,R%d\n", leftreg, rightreg);

    if (strcmp(c, "<=") == 0)
        fprintf(fptr, "LE R%d,R%d\n", leftreg, rightreg);

    if (strcmp(c, ">=") == 0)
        fprintf(fptr, "GE R%d,R%d\n", leftreg, rightreg);

    if (strcmp(c, "==") == 0)
        fprintf(fptr, "EQ R%d,R%d\n", leftreg, rightreg);

    if (strcmp(c, "!=") == 0)
        fprintf(fptr, "NE R%d,R%d\n", leftreg, rightreg);
}

void funccode(FILE *fptr, struct tnode *body, struct tnode *returnexpr,char* functype,int ismain)
{
    // PUSH BP AND LOCAL VARIABLES
    int localvar = get_numlocalvar();
    fprintf(fptr, "PUSH BP\n");
    fprintf(fptr, "MOV BP,SP\n");

    if (localvar > 0)
        fprintf(fptr, "ADD SP,%d\n", localvar);
    ///////////////////////////////////////////
    // Codegen of body
    int reg = codeGen(body, fptr); // SList
    if (reg != -1)
        printf("Function registers not freed\n");
    ////////////////////////////////////////////
    if(ismain==-1)
        callret(fptr, returnexpr, functype); // Return Statement:POPS LOCAL VAR,FINDS RETURN VAL AND STORES IT ,POP BP,RET

    else
        fprintf(fptr,"INT 10\n");
}

void callret(FILE *fptr, struct tnode *returnexpr, char* functype)
{
    int localvar = get_numlocalvar();

    int returnreg;
    returnreg = codeGen(returnexpr, fptr);

    // Validation
    if (returnexpr->type != TLookup(functype))  //Function return type cannot be a class hence this validation is sufficient
    {
        printf("Return type does not match with function return type\n");
        exit(1);
    }

    if (returnexpr->nodetype == Variable) // Stores the value from the address in the register
        fprintf(fptr, "MOV R%d,[R%d]\n", returnreg, returnreg);
    /////////////////////////////////////////////
    if (localvar > 0)
        fprintf(fptr, "SUB SP,%d\n", localvar);

    int reg = getReg();
    fprintf(fptr, "MOV R%d,BP\n", reg);
    fprintf(fptr, "SUB R%d,2\n", reg);
    fprintf(fptr, "MOV [R%d],R%d\n", reg, returnreg);
    freeReg(); // frees the temporary register for storing BP
    freeReg(); // To free the returned register
    fprintf(fptr, "POP BP\n");
    fprintf(fptr, "RET\n");
}

int get_numlocalvar()
{
    struct Lsymbol *temp = LHEAD;
    int localvar = 0;

    while (temp != NULL)
    {
        if (temp->binding > 0) // local variable:binding is greater than 0
            localvar += 1;

        temp = temp->next;
    }

    return localvar;
}

//Acessing a.b,a.b.c types etc
int getfieldaddress(struct tnode* t,FILE *fptr)
{
    int p = getReg();
    int addr;

    if (t->Lentry != NULL) // Local Variables and Parameters
    {
        addr = t->Lentry->binding;
        fprintf(fptr, "MOV R%d,BP\n", p);
        // Local Variables
        if (addr > 0)
        {
            // printf("\n\n\n\n");
            fprintf(fptr, "ADD R%d,%d\n", p, addr);
        }
        // Parameters
        else if (addr < 0)
        {
            fprintf(fptr, "SUB R%d,%d\n", p, -addr);
        }
    }

    else if (t->Gentry != NULL) // Global Variables
    {
        addr = t->Gentry->binding;
        fprintf(fptr, "MOV R%d,%d\n", p, addr); // Moving the address to a register
    }

    //To get the starting heap address if the userdefined datatype
    fprintf(fptr, "MOV R%d,[R%d]\n",p,p);

    struct tnode* fields=t->left;
    int userdefined;

   while(fields!=NULL)
   {
        fprintf(fptr,"ADD R%d,%d\n",p,fields->field->fieldindex);

        //userdefined=isuserdefined(fields->type->name);
        //If field->next is not null then surely that field is a pointer.
        if(fields->next!=NULL)
            fprintf(fptr, "MOV R%d,[R%d]\n",p,p);
   
        fields=fields->next;
   }

    return p;
}

// Expression code generate
int codeGen(struct tnode *t, FILE *fptr)
{
    if (t == NULL)
        return -1;

    if (t->nodetype == Constant) // CONSTANT
    {
        int p = getReg();

        if (t->type == TLookup("int"))
            fprintf(fptr, "MOV R%d,%d\n", p, (t->val).i);

        if (t->type == TLookup("str"))
            fprintf(fptr, "MOV R%d,%s\n", p, (t->val).c);

        //NULL POINTER
        if (t->type == TLookup("NULL"))
            fprintf(fptr, "MOV R%d,%d\n",p,0);

        return p;
    }

    if (t->nodetype == Function)
    {
        //Pushing temporary registers
        int lastreg_local=pushtempreg(fptr);
        int count_args = 0;
        struct tnode *args=NULL;

        if(t->right!=NULL)  //For pushing the object address and the virtual function table as arguments to the stack
        {
            args=t->right;
            while(args!=NULL)
            {
                int reg_no = codeGen(args, fptr);

                //whether it is a variable node(for self.func) or constant node(vft pointer obj for id.function)
                fprintf(fptr, "MOV R%d,[R%d]\n", reg_no, reg_no);

                fprintf(fptr, "\tPUSH R%d\n", reg_no);

                freeReg(); // Frees the register
                count_args += 1;
                args = args->next;
            }
            
        }

        // Pushing the actual arguments(ie:the parameters)
        args= t->left;
        while (args != NULL)
        {
            int reg_no = codeGen(args, fptr);

            if (args->nodetype == Variable) // If the argument is a variable
                fprintf(fptr, "MOV R%d,[R%d]\n", reg_no, reg_no);

            fprintf(fptr, "\tPUSH R%d\n", reg_no);

            freeReg(); // Frees the register
            count_args += 1;
            args = args->next;
        }
        ///////////////////////////////
        fprintf(fptr, "\tADD SP,1\n");                    // For storing the return value
        
        //FUNCTIONS NOT MEMBER FUNCTIONS
        if(t->right==NULL)
            fprintf(fptr, "\tCALL F%d\n", t->Gentry->flabel); // For calling the function
        
        else 
        {
           if(t->right->next==NULL)        //INCASE OF FIELD.FUNCTION:SINCE POLYMORPHISM IS NOT POSSIBLE AND HENCE VIRTUAL FUNCTION TABLE DOES NOT COME INTO PLAY
                 fprintf(fptr, "\tCALL C%d\n", t->member->flabel); // For calling the member function
            
            else
            {
                int offset;

                offset=t->member->funcposition;

                int vptraddrreg=codeGen(t->right->next,fptr);   //for both self.function and id.function
               
                //gets the base address of the vft of the decendant class;
                fprintf(fptr,"MOV R%d,[R%d]\n",vptraddrreg,vptraddrreg);

                //adds the offset to the base address
                fprintf(fptr,"ADD R%d,%d\n",vptraddrreg,offset);

                //gets the label address from the vft
                fprintf(fptr,"MOV R%d,[R%d]\n",vptraddrreg,vptraddrreg);

                fprintf(fptr,"\tCALL R%d\n",vptraddrreg);

                freeReg();
            }
            
        }
        ////////////////////////////////
        // To get the return value
        int returnreg = lastreg_local + 1;
        fprintf(fptr, "\tPOP R%d\n", returnreg);

        //////////////////////////////////
        if (count_args > 0)
            fprintf(fptr, "\tSUB SP,%d\n", count_args);

        //Popping the temporary registers
        poptempreg(lastreg_local,fptr);

        //extra register for storing the return value
        freereg_no+=1;  

        return returnreg;
    }

    if (t->nodetype == Break && btop != -1) // Only to consider breaks inside loops
    {
        fprintf(fptr, "JMP L%d\n", bstack[btop]);
        return -1;
    }

    if (t->nodetype == Continue && ctop != -1) // Only to consider continue inside loops
    {
        fprintf(fptr, "JMP L%d\n", cstack[ctop]);
        return -1;
    }

    if (t->nodetype == Branch)
    {
        if (strcmp(t->nonleaf, "While") == 0)
        {
            callwhile(fptr, t);
            return -1;
        }

        if (strcmp(t->nonleaf, "Do") == 0)
        {
            calldo(fptr, t);
            return -1;
        }

        if (strcmp(t->nonleaf, "Repeat") == 0)
        {
            callrepeat(fptr, t);
            return -1;
        }

        if (strcmp(t->nonleaf, "If") == 0)
        {
            if (t->right != NULL && t->right->nodetype == Connector && t->right->right != NULL && t->right->right->nodetype == Branch && strcmp(t->right->right->nonleaf, "Else") == 0)
            {
                callifelse(fptr, t);
                return -1;
            }
            callif(fptr, t);
            return -1;
        }
    }

    if(t->nodetype == Initialize)
    {
        int p=callinitialize(fptr);         //Returns the return value
        return p;
    }      

    if(t->nodetype == Alloc)
    {
        int p=callalloc(fptr);              //Returns the return value
        return p;
    }

    if(t->nodetype == New)
    {
        int p=callalloc(fptr);              //Returns the return value

        //POINTING VIRTUAL FUNCTION TABLE TO THE VFT OF THE DESCENDANT CLASS in case of ID=NEW(ID)
        if(t->left!=NULL && t->right!=NULL)  //for ID EQUAL NEW CASE//NOT FOR FIELD EQUAL NEW CASE
        {
            int left=codeGen(t->left,fptr); //Variable node
            int right=codeGen(t->right,fptr);   //Constant node

            if(left==-1)
            {
                printf("LEFT RETURNED -1 IN NEW:Codegen");
                exit(1);
            }

            if(right==-1)
            {
                printf("RIGHT RETURNED -1 IN NEW:Codegen");
                exit(1);
            }

            fprintf(fptr,"ADD R%d,1\n",left);           //to get the vft pointer
            fprintf(fptr,"MOV [R%d],R%d\n",left,right);    //stores the vft starting address of the descendent pointer to the vft pointer of the parent class

            freeReg();
            freeReg();
        }
        return p;
    }

    if(t->nodetype == Free)
    {
        int left = codeGen(t->left, fptr);

        //NOTE:Since we need the address the pointer stores and not the address where the pointer is stored!!!
        fprintf(fptr,"MOV R%d,[R%d]\n",left,left);
        
        callfree(fptr, left);
        return -1;
    }

    if(t->nodetype == Delete)
    {
        int left = codeGen(t->left, fptr);

        //NOTE:Since we need the address the pointer stores and not the address where the pointer is stored!!!
        fprintf(fptr,"MOV R%d,[R%d]\n",left,left);
        
        callfree(fptr, left);
        return -1;
    }

    if(t->nodetype == Variable && t->left!=NULL && t->left->nodetype == Field)
        return getfieldaddress(t,fptr);
    
     if (t->nodetype == Operator && *(t->nonleaf) == '=')
        {
            int right = codeGen(t->right, fptr);
            int left=codeGen(t->left,fptr);
            int temp=getReg();

            if (t->right->nodetype == Variable) //in case of ID=ID
                fprintf(fptr, "MOV R%d,[R%d]\n",temp, right);

            else    //in case of ID=NEW(ID)
                fprintf(fptr,"MOV R%d,R%d\n",temp,right);

            fprintf(fptr, "MOV [R%d],R%d\n", left,temp);

            //for storing the virtual function table in case of class(which is not a field)=class(can never be a field beacause field is iether data member which is not pooossible from outside function or field is a member function and member function does not return a class):
            if(t->left->nodetype==Variable && t->left->type==NULL && t->left->left==NULL && t->right->nodetype==Variable && t->right->type==NULL && t->right->left==NULL)
            {
                fprintf(fptr,"ADD R%d,1\n",left);           //to get the vft pointer of left node
                fprintf(fptr,"ADD R%d,1\n",right);          //to get the vft pointer of desc class
                
                fprintf(fptr,"MOV [R%d],[R%d]\n",left,right);    //stores the vft starting address of the descendent pointer to the vft pointer of the parent class
            }
            
            freeReg(); //frees temp
            freeReg(); // free right
            freeReg(); // free left
            return -1;
        }
    ////////////////////////////////////////////////////////////////////
    //LEFT ASSOCIATIVE NODES START BELOW
    ///////////////////////////////////////////////////////////////////
    // Nodes which calculate left first:ie:left associative
    int left = codeGen(t->left, fptr);

    if (t->nodetype == Operator && *(t->nonleaf) != '=') // Operator:+-*=
    {
        int right = codeGen(t->right, fptr);
        
            if (t->left->nodetype == Variable) // variable
                fprintf(fptr, "MOV R%d,[R%d]\n", left, left);

            if (t->right->nodetype == Variable) // variable
                fprintf(fptr, "MOV R%d,[R%d]\n", right, right);

            switch (*(t->nonleaf))
            {
            case '+':
                fprintf(fptr, "ADD R%d,R%d\n", left, right);
                break;
            case '-':
                fprintf(fptr, "SUB R%d,R%d\n", left, right);
                break;
            case '*':
                fprintf(fptr, "MUL R%d,R%d\n", left, right);
                break;
            case '/':
                fprintf(fptr, "DIV R%d,R%d\n", left, right);
                break;
            case '%':
                fprintf(fptr, "MOD R%d,R%d\n", left, right);
                break;
            }

    }

    if (t->nodetype == Variable) // Variable:array or normal variable:does not contain fields
    {
        int right = codeGen(t->right, fptr);
        // Gets the starting address
        int addr;

        if (t->left != NULL && t->right != NULL)
        {
            addr = t->Gentry->binding;

            int rowsize = t->Gentry->row;
            int colsize = t->Gentry->col;

            // int rowidx = evaluate(t->left);
            // int colidx = evaluate(t->right);

            // Rowidx
            // if(t->left->nodetype==Constant | t->left->nodetype==Operator)
            // fprintf("ADD R%d,%d\n",left,addr);

            if (t->left->nodetype == Variable)
            {
                // gets the offset address in case of a[b[1ori]];
                fprintf(fptr, "MOV R%d,[R%d]\n", left, left);
            }

            // Colidx
            // if(t->right->nodetype==Constant | t->right->nodetype==Operator)
            // Dont do anything

            if (t->right->nodetype == Variable)
            {
                // gets the offset address in case of a[b[1ori]];
                fprintf(fptr, "MOV R%d,[R%d]\n", right, right);
            }

            fprintf(fptr, "MUL R%d,%d\n", left, colsize);
            fprintf(fptr, "ADD R%d,R%d\n", left, right);
            fprintf(fptr, "ADD R%d,%d\n", left, addr);

            freeReg();
            return left;
            // addr = addr + (rowidx * colsize) + colidx;
        }

        else if (t->left != NULL)
        {
            // if (t->left->nodetype == Constant | t->left->nodetype == Operator)
            // Don't do anything
            addr = t->Gentry->binding;

            // gets the offset address in case of a[b[1ori]];
            if (t->left->nodetype == Variable)
                fprintf(fptr, "MOV R%d,[R%d]\n", left, left);
    
            // addr=addr+offsetvalue;
            fprintf(fptr, "ADD R%d,%d\n", left, addr);
            return left;
        }

        else
        {
            int p = getReg();

            if (t->Lentry != NULL) // Local Variables and Parameters
            {
                addr = t->Lentry->binding;
                fprintf(fptr, "MOV R%d,BP\n", p);
                // Local Variables
                if (addr > 0)
                {
                    // printf("\n\n\n\n");
                    fprintf(fptr, "ADD R%d,%d\n", p, addr);
                }
                // Parameters
                else if (addr < 0)
                {
                    fprintf(fptr, "SUB R%d,%d\n", p, -addr);
                }
            }

            else if (t->Gentry != NULL) // Global Variables
            {
                addr = t->Gentry->binding;
                fprintf(fptr, "MOV R%d,%d\n", p, addr); // Moving the address to a register
            }

            return p;
        }
    }

    if (t->nodetype == Read) // read
    {
        callread(fptr, left);
        return -1;
    }

    if (t->nodetype == Write) // write
    {
        if (t->left->nodetype == Variable) // Variables
            fprintf(fptr, "MOV R%d,[R%d]\n", left, left);
        
        callwrite(fptr, left);
        return -1;
    }


    if (t->nodetype == Comparison)
    {
        int right = codeGen(t->right, fptr);

        if (t->left->nodetype == Variable) // Variables
            fprintf(fptr, "MOV R%d,[R%d]\n", left, left);

        if (t->right->nodetype == Variable) // Variables
            fprintf(fptr, "MOV R%d,[R%d]\n", right, right);

        callcomp(fptr, t->nonleaf, left, right);
    }

    if(t->nodetype ==Logical)
    {
        if(strcmp(t->nonleaf,"not")==0 | strcmp(t->nonleaf,"NOT")==0)
        {
            int label1=getLabel();
			int label2=getLabel();

            fprintf(fptr,"JZ R%d,L%d\n",left,label1);
            fprintf(fptr,"MOV R%d,0\n",left);
			fprintf(fptr,"JMP L%d\n",label2);
            fprintf(fptr,"L%d:\n",label1);
            fprintf(fptr,"MOV R%d,1\n",left);
			fprintf(fptr,"L%d:\n",label2);
			return left;
		}

        else
        {
            int right = codeGen(t->right, fptr);

            if(strcmp(t->nonleaf,"and")==0 | strcmp(t->nonleaf,"AND")==0)
                fprintf(fptr,"MUL R%d,R%d\n",left,right);
            
            if(strcmp(t->nonleaf,"or")==0 | strcmp(t->nonleaf,"OR")==0)
            {
                fprintf(fptr,"ADD R%d,R%d\n",left,right);

                //for verifying if it is equal to 2
                fprintf(fptr,"MOV R%d,R%d\n",right,left);
                int reg=getReg();
                fprintf(fptr,"MOV R%d,2\n",reg);
                fprintf(fptr, "EQ R%d,R%d\n",right,reg);
                freeReg();
                int label=getLabel();
                fprintf(fptr,"JZ R%d,L%d\n",right,label);
                fprintf(fptr,"MOV R%d,1\n",left);
                fprintf(fptr,"L%d:\n",label);
            }
        }
    }

    if (t->nodetype == Connector) // Connector
    {
        int right = codeGen(t->right, fptr);

        if (left != -1)
            freeReg();

        if (right != -1)
            freeReg();

        return -1;
    }
    
    freeReg();
    return left;
}
