/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BEG = 258,                     /* BEG  */
    END = 259,                     /* END  */
    READ = 260,                    /* READ  */
    WRITE = 261,                   /* WRITE  */
    ID = 262,                      /* ID  */
    NUM = 263,                     /* NUM  */
    PLUS = 264,                    /* PLUS  */
    MINUS = 265,                   /* MINUS  */
    MUL = 266,                     /* MUL  */
    DIV = 267,                     /* DIV  */
    EQUAL = 268,                   /* EQUAL  */
    IF = 269,                      /* IF  */
    Then = 270,                    /* Then  */
    Else = 271,                    /* Else  */
    ENDIF = 272,                   /* ENDIF  */
    WHILE = 273,                   /* WHILE  */
    DO = 274,                      /* DO  */
    ENDWHILE = 275,                /* ENDWHILE  */
    REPEAT = 276,                  /* REPEAT  */
    UNTIL = 277,                   /* UNTIL  */
    BREAK = 278,                   /* BREAK  */
    CONTINUE = 279,                /* CONTINUE  */
    DECL = 280,                    /* DECL  */
    ENDDECL = 281,                 /* ENDDECL  */
    INT = 282,                     /* INT  */
    STR = 283,                     /* STR  */
    VOID = 284,                    /* VOID  */
    STRING = 285,                  /* STRING  */
    MOD = 286,                     /* MOD  */
    RET = 287,                     /* RET  */
    MAIN = 288,                    /* MAIN  */
    AND = 289,                     /* AND  */
    OR = 290,                      /* OR  */
    NOT = 291,                     /* NOT  */
    XOR = 292,                     /* XOR  */
    TYPE = 293,                    /* TYPE  */
    ENDTYPE = 294,                 /* ENDTYPE  */
    INITIALIZE = 295,              /* INITIALIZE  */
    ALLOC = 296,                   /* ALLOC  */
    FREE = 297,                    /* FREE  */
    NULLPTR = 298,                 /* NULLPTR  */
    COMP = 299                     /* COMP  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define BEG 258
#define END 259
#define READ 260
#define WRITE 261
#define ID 262
#define NUM 263
#define PLUS 264
#define MINUS 265
#define MUL 266
#define DIV 267
#define EQUAL 268
#define IF 269
#define Then 270
#define Else 271
#define ENDIF 272
#define WHILE 273
#define DO 274
#define ENDWHILE 275
#define REPEAT 276
#define UNTIL 277
#define BREAK 278
#define CONTINUE 279
#define DECL 280
#define ENDDECL 281
#define INT 282
#define STR 283
#define VOID 284
#define STRING 285
#define MOD 286
#define RET 287
#define MAIN 288
#define AND 289
#define OR 290
#define NOT 291
#define XOR 292
#define TYPE 293
#define ENDTYPE 294
#define INITIALIZE 295
#define ALLOC 296
#define FREE 297
#define NULLPTR 298
#define COMP 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 32 "parse.y"

	struct tnode *no;
	struct Gsymbol* symbol;
	struct Parameter* param;
	struct Fieldlist* field;
	char* c;
	int i;

#line 164 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
