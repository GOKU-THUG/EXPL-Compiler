typedef struct lnode 
{ 
    char label[20];
    int addr;
    struct lnode* next;
}lnode;

void insertnode(struct lnode* newnode);

int ifpresent(char label[10]);

void printlist(struct lnode* temp);
