int freereg_no = -1;
int freelabel = -1;
int break_label = -1;
int continue_label = -1;

int getLabel()
{
    freelabel++;

    return freelabel;
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

    fprintf(fptr, "CALL 0\n");

    fprintf(fptr, "POP R0\n");
    fprintf(fptr, "POP R1\n");
    fprintf(fptr, "POP R1\n");
    fprintf(fptr, "POP R1\n");
    fprintf(fptr, "POP R1\n");
}

void callread(FILE *fptr, int resreg_no)
{
    int reg = getReg();

    fprintf(fptr, "MOV R%d,\"Read\"\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "MOV R%d,-1\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", resreg_no);
    fprintf(fptr, "PUSH R%d\n", reg);
    fprintf(fptr, "PUSH R%d\n", reg);

    freeReg();

    fprintf(fptr, "CALL 0\n");

    fprintf(fptr, "POP R0\n");
    fprintf(fptr, "POP R1\n");
    fprintf(fptr, "POP R1\n");
    fprintf(fptr, "POP R1\n");
    fprintf(fptr, "POP R1\n");
}

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
        break_label = label2;    // For break statements
        continue_label = label1; // For continue statements

        int right = codeGen(t->right, fptr);

        break_label = -1;
        continue_label = -1;

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
        break_label = label2;    // For break statements
        continue_label = label1; // For continue statements

        int left = codeGen(t->left, fptr);

        break_label = -1;
        continue_label = -1;

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
        break_label = label2;    // For break statements
        continue_label = label1; // For continue statements

        int left = codeGen(t->left, fptr);

        break_label = -1;
        continue_label = -1;

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

int codeGen(struct tnode *t, FILE *fptr)
{
    if (t == NULL)
        return -1;

    int left = codeGen(t->left, fptr);

    if (t->nodetype == Constant) // CONSTANT
    {
        int p = getReg();

        if (t->type == Integer)
            fprintf(fptr, "MOV R%d,%d\n", p, (t->val).i);

        if (t->type == String)
            fprintf(fptr, "MOV R%d,%s\n", p, (t->val).c);

        return p;
    }

    else if (t->nodetype == Break && break_label != -1) // Only to consider breaks inside loops
    {
        fprintf(fptr, "JMP L%d\n", break_label);
        return -1;
    }

    else if (t->nodetype == Continue && continue_label != -1) // Only to consider continue inside loops
    {
        fprintf(fptr, "JMP L%d\n", continue_label);
        return -1;
    }

    else if (t->nodetype == Variable) // Variable
    {
        int right = codeGen(t->right, fptr);

        // Gets the starting address
        int addr = t->Gentry->binding;

        if (t->left != NULL && t->right != NULL)
        {
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

            if (t->left->nodetype == Variable)
            {
                // gets the offset address in case of a[b[1ori]];
                fprintf(fptr, "MOV R%d,[R%d]\n", left, left);
            }

            // addr=addr+offsetvalue;
            fprintf(fptr, "ADD R%d,%d\n", left, addr);
            return left;
        }

        else
        {
            int p = getReg();

            fprintf(fptr, "MOV R%d,%d\n", p, addr); // Moving the address to a register
            return p;
        }
    }

    else if (t->nodetype == Branch)
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

    else if (t->nodetype == Read) // read
    {
        callread(fptr, left);
        freeReg();
        return -1;
    }

    else if (t->nodetype == Write) // write
    {
        if (t->left->nodetype == Variable) // Variables
            fprintf(fptr, "MOV R%d,[R%d]\n", left, left);

        callwrite(fptr, left);

        freeReg();
        return -1;
    }

    else if (t->nodetype == Comparison)
    {
        int right = codeGen(t->right, fptr);

        if (t->left->nodetype == 1) // Variables
            fprintf(fptr, "MOV R%d,[R%d]\n", left, left);

        if (t->right->nodetype == 1) // Variables
            fprintf(fptr, "MOV R%d,[R%d]\n", right, right);

        callcomp(fptr, t->nonleaf, left, right);
    }

    else if (t->nodetype == Connector) // Connector
    {
        int right = codeGen(t->right, fptr);

        if (left != -1)
            freeReg();

        if (right != -1)
            freeReg();

        return -1;
    }

    else // Operator:+-*=
    {
        int right = codeGen(t->right, fptr);

        if (*(t->nonleaf) == '=')
        {
            if(t->right->nodetype == Variable)
                fprintf(fptr, "MOV R%d,[R%d]\n", right, right);

            fprintf(fptr, "MOV [R%d],R%d\n", left, right);

            freeReg(); // free left
            freeReg(); // free right

            return -1;
        }

        else
        {
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
    }

    freeReg();
    return left;
}
