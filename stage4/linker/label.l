%{
	#include <stdlib.h>
    #include <string.h>
    #include "linkedlist.h"
    #include "linkedlist.c"
    
    int linenumber=0;
    int parse_no=0;

    FILE* fptr;
%}

letter [a-zA-Z]
digit  [0-9]+

%%

{letter}({letter}|{digit})*\n {
                            //printf("\nok bye\n");
                            if(parse_no==0)
                                linenumber++;
                            
                            if(parse_no==1)
                            {

                              //  printf("%s\n",yytext);
                                
                                int len=strlen(yytext);
                                yytext[len-1]='\0';
                                int addr=ifpresent(yytext);    //if present in the linker table

                                if(addr!=-1)
                                    fprintf(fptr,"%d\n",addr);
                            
                                else
                                    fprintf(fptr,"%s\n",yytext);
                            }
                        }

{letter}({letter}|{digit})*:\n {
                                    //printf("\nok bye\n"); 

                                    if(parse_no==0){
                                        int address=2056 + (2*(linenumber-8));
                                        
                                        struct lnode* newnode=(lnode*)malloc(sizeof(lnode));
                                        
                                        int len=strlen(yytext);
                                        yytext[len-2]='\0';

                                        strcpy(newnode->label,yytext);
                                        newnode->addr=address;
                                        
                                        //printf("%s\n",newnode->label);
                                        
                                        insert_node(newnode);
                                        
                                    }
                               }


\n  {
        if(parse_no==1){
            fprintf(fptr,"%s",yytext);
        }

        linenumber++;}

.  {
       // printf("\nok bye\n");
        if(parse_no==1){
            fprintf(fptr,"%s",yytext);
        }
    }
%%

int main()
{
    fptr=fopen("/home/goku/compiler_lab/stage4/ast.xsm","w");
    
    yyin=fopen("/home/goku/compiler_lab/stage4/ast.o","r");
	yylex();

    return 1;
}

int yywrap(void)
{
    parse_no+=1;

    yyin=fopen("/home/goku/compiler_lab/stage4/ast.o","r");
    
    //if(parse_no==1)
        //printlist(HEAD);
        
    if(parse_no==2)
        return 1;

    return 0;
}