/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parse.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	
	//Type Table
	#include "typetable.h"
	#include "typetable.c"

	//Class Table
	#include "classtable.h"
	#include "classtable.c"

	//Symbol table
	#include "symboltable.h"
	#include "symboltable.c"
	
	
	//AST CREATION
	#include "ast.h"
	#include "ast.c"

	struct Classtable* Cptr=NULL;       //Pointer to class in class table
	//CODEGENERATION
	#include "codegen.h"
	#include "codegen.c"
	
	extern FILE* yyin;
	extern char* yytext;
	FILE* fptr;
	extern int yylineno;
	int flag=0;

	int yylex(void);
	int yyerror();
	void indextypecheck(char* type);

#line 109 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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
    CLASS = 299,                   /* CLASS  */
    ENDCLASS = 300,                /* ENDCLASS  */
    Extends = 301,                 /* Extends  */
    NEW = 302,                     /* NEW  */
    DELETE = 303,                  /* DELETE  */
    SELF = 304,                    /* SELF  */
    COMP = 305                     /* COMP  */
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
#define CLASS 299
#define ENDCLASS 300
#define Extends 301
#define NEW 302
#define DELETE 303
#define SELF 304
#define COMP 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 39 "parse.y"

	struct tnode *no;
	struct Gsymbol* symbol;
	struct Parameter* param;
	struct Fieldlist* field;
	char* c;
	int i;

#line 271 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BEG = 3,                        /* BEG  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_READ = 5,                       /* READ  */
  YYSYMBOL_WRITE = 6,                      /* WRITE  */
  YYSYMBOL_ID = 7,                         /* ID  */
  YYSYMBOL_NUM = 8,                        /* NUM  */
  YYSYMBOL_PLUS = 9,                       /* PLUS  */
  YYSYMBOL_MINUS = 10,                     /* MINUS  */
  YYSYMBOL_MUL = 11,                       /* MUL  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_EQUAL = 13,                     /* EQUAL  */
  YYSYMBOL_IF = 14,                        /* IF  */
  YYSYMBOL_Then = 15,                      /* Then  */
  YYSYMBOL_Else = 16,                      /* Else  */
  YYSYMBOL_ENDIF = 17,                     /* ENDIF  */
  YYSYMBOL_WHILE = 18,                     /* WHILE  */
  YYSYMBOL_DO = 19,                        /* DO  */
  YYSYMBOL_ENDWHILE = 20,                  /* ENDWHILE  */
  YYSYMBOL_REPEAT = 21,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 22,                     /* UNTIL  */
  YYSYMBOL_BREAK = 23,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 24,                  /* CONTINUE  */
  YYSYMBOL_DECL = 25,                      /* DECL  */
  YYSYMBOL_ENDDECL = 26,                   /* ENDDECL  */
  YYSYMBOL_INT = 27,                       /* INT  */
  YYSYMBOL_STR = 28,                       /* STR  */
  YYSYMBOL_VOID = 29,                      /* VOID  */
  YYSYMBOL_STRING = 30,                    /* STRING  */
  YYSYMBOL_MOD = 31,                       /* MOD  */
  YYSYMBOL_RET = 32,                       /* RET  */
  YYSYMBOL_MAIN = 33,                      /* MAIN  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_OR = 35,                        /* OR  */
  YYSYMBOL_NOT = 36,                       /* NOT  */
  YYSYMBOL_XOR = 37,                       /* XOR  */
  YYSYMBOL_TYPE = 38,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 39,                   /* ENDTYPE  */
  YYSYMBOL_INITIALIZE = 40,                /* INITIALIZE  */
  YYSYMBOL_ALLOC = 41,                     /* ALLOC  */
  YYSYMBOL_FREE = 42,                      /* FREE  */
  YYSYMBOL_NULLPTR = 43,                   /* NULLPTR  */
  YYSYMBOL_CLASS = 44,                     /* CLASS  */
  YYSYMBOL_ENDCLASS = 45,                  /* ENDCLASS  */
  YYSYMBOL_Extends = 46,                   /* Extends  */
  YYSYMBOL_NEW = 47,                       /* NEW  */
  YYSYMBOL_DELETE = 48,                    /* DELETE  */
  YYSYMBOL_SELF = 49,                      /* SELF  */
  YYSYMBOL_COMP = 50,                      /* COMP  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* ';'  */
  YYSYMBOL_54_ = 54,                       /* '('  */
  YYSYMBOL_55_ = 55,                       /* ')'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '['  */
  YYSYMBOL_58_ = 58,                       /* ']'  */
  YYSYMBOL_59_ = 59,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 60,                  /* $accept  */
  YYSYMBOL_Program = 61,                   /* Program  */
  YYSYMBOL_TypeDefBlock = 62,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 63,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 64,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 65,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 66,                 /* FieldDecl  */
  YYSYMBOL_ClassDefBlock = 67,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 68,              /* ClassDefList  */
  YYSYMBOL_Classdef = 69,                  /* Classdef  */
  YYSYMBOL_Cname = 70,                     /* Cname  */
  YYSYMBOL_Fieldlists = 71,                /* Fieldlists  */
  YYSYMBOL_Fld = 72,                       /* Fld  */
  YYSYMBOL_MethodDecl = 73,                /* MethodDecl  */
  YYSYMBOL_MDecl = 74,                     /* MDecl  */
  YYSYMBOL_MethodDefns = 75,               /* MethodDefns  */
  YYSYMBOL_GDeclBlock = 76,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 77,                 /* GDeclList  */
  YYSYMBOL_GDecl = 78,                     /* GDecl  */
  YYSYMBOL_Type = 79,                      /* Type  */
  YYSYMBOL_Gidlist = 80,                   /* Gidlist  */
  YYSYMBOL_Gid = 81,                       /* Gid  */
  YYSYMBOL_ParamList = 82,                 /* ParamList  */
  YYSYMBOL_Param = 83,                     /* Param  */
  YYSYMBOL_Slistblock = 84,                /* Slistblock  */
  YYSYMBOL_Slist = 85,                     /* Slist  */
  YYSYMBOL_Stmt = 86,                      /* Stmt  */
  YYSYMBOL_Ifstmt = 87,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 88,                 /* Whilestmt  */
  YYSYMBOL_Dowhilestmt = 89,               /* Dowhilestmt  */
  YYSYMBOL_Repeatuntil = 90,               /* Repeatuntil  */
  YYSYMBOL_InputStmt = 91,                 /* InputStmt  */
  YYSYMBOL_FreeStmt = 92,                  /* FreeStmt  */
  YYSYMBOL_OutputStmt = 93,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 94,                   /* AsgStmt  */
  YYSYMBOL_FIELD = 95,                     /* FIELD  */
  YYSYMBOL_FieldFunction = 96,             /* FieldFunction  */
  YYSYMBOL_E = 97,                         /* E  */
  YYSYMBOL_ArglistBlock = 98,              /* ArglistBlock  */
  YYSYMBOL_ArgList = 99,                   /* ArgList  */
  YYSYMBOL_MainBlock = 100,                /* MainBlock  */
  YYSYMBOL_FDefList = 101,                 /* FDefList  */
  YYSYMBOL_FDefBlock = 102,                /* FDefBlock  */
  YYSYMBOL_FdefParamListBlock = 103,       /* FdefParamListBlock  */
  YYSYMBOL_FdefParamList = 104,            /* FdefParamList  */
  YYSYMBOL_FdefParam = 105,                /* FdefParam  */
  YYSYMBOL_LdeclBlock = 106,               /* LdeclBlock  */
  YYSYMBOL_LDecList = 107,                 /* LDecList  */
  YYSYMBOL_LDecl = 108,                    /* LDecl  */
  YYSYMBOL_IdList = 109,                   /* IdList  */
  YYSYMBOL_Body = 110,                     /* Body  */
  YYSYMBOL_Retstmt = 111                   /* Retstmt  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   492

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  60
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  52
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  321

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      54,    55,     2,     2,    56,     2,    59,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    53,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    57,     2,    58,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,     2,    52,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    61,    63,    64,    67,    68,    71,   103,
     104,   107,   109,   110,   112,   113,   116,   127,   128,   131,
     132,   135,   147,   148,   151,   163,   177,   178,   181,   194,
     195,   197,   198,   199,   201,   202,   203,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   216,   217,
     219,   220,   222,   223,   224,   225,   226,   227,   228,   229,
     230,   232,   234,   237,   242,   243,   244,   245,   247,   249,
     253,   259,   262,   266,   269,   271,   276,   280,   286,   290,
     295,   299,   304,   308,   338,   400,   421,   436,   459,   483,
     515,   549,   550,   551,   552,   553,   554,   555,   559,   565,
     566,   567,   568,   569,   570,   571,   572,   573,   576,   586,
     587,   589,   590,   592,   606,   609,   643,   677,   678,   680,
     742,   807,   808,   810,   811,   812,   828,   829,   830,   831,
     832,   834,   835,   847,   859
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "BEG", "END", "READ",
  "WRITE", "ID", "NUM", "PLUS", "MINUS", "MUL", "DIV", "EQUAL", "IF",
  "Then", "Else", "ENDIF", "WHILE", "DO", "ENDWHILE", "REPEAT", "UNTIL",
  "BREAK", "CONTINUE", "DECL", "ENDDECL", "INT", "STR", "VOID", "STRING",
  "MOD", "RET", "MAIN", "AND", "OR", "NOT", "XOR", "TYPE", "ENDTYPE",
  "INITIALIZE", "ALLOC", "FREE", "NULLPTR", "CLASS", "ENDCLASS", "Extends",
  "NEW", "DELETE", "SELF", "COMP", "'{'", "'}'", "';'", "'('", "')'",
  "','", "'['", "']'", "'.'", "$accept", "Program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "FieldDeclList", "FieldDecl", "ClassDefBlock",
  "ClassDefList", "Classdef", "Cname", "Fieldlists", "Fld", "MethodDecl",
  "MDecl", "MethodDefns", "GDeclBlock", "GDeclList", "GDecl", "Type",
  "Gidlist", "Gid", "ParamList", "Param", "Slistblock", "Slist", "Stmt",
  "Ifstmt", "Whilestmt", "Dowhilestmt", "Repeatuntil", "InputStmt",
  "FreeStmt", "OutputStmt", "AsgStmt", "FIELD", "FieldFunction", "E",
  "ArglistBlock", "ArgList", "MainBlock", "FDefList", "FDefBlock",
  "FdefParamListBlock", "FdefParamList", "FdefParam", "LdeclBlock",
  "LDecList", "LDecl", "IdList", "Body", "Retstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-280)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,    27,    59,    10,    26,    -2,  -280,  -280,    76,    64,
     318,  -280,  -280,    53,    58,  -280,    79,   174,   389,  -280,
    -280,  -280,  -280,    95,    88,    97,   148,  -280,  -280,   135,
    -280,   267,   125,   188,   155,   192,  -280,   389,  -280,  -280,
     151,  -280,  -280,  -280,  -280,  -280,   153,  -280,   -35,   152,
    -280,   156,   165,  -280,  -280,  -280,   318,  -280,    14,   213,
     188,   168,   318,  -280,   309,  -280,   218,  -280,   231,   118,
    -280,   185,  -280,   199,   244,   207,   205,  -280,   318,  -280,
     261,   181,  -280,  -280,   318,   212,    15,  -280,   221,   318,
     225,  -280,   222,  -280,   157,  -280,   271,   353,   371,   272,
     228,    15,  -280,  -280,  -280,   230,   172,   234,   249,   256,
       7,   257,   260,   353,   353,   264,   265,   268,   280,   262,
     287,   353,  -280,   295,  -280,  -280,   297,   299,   300,   303,
     308,    -9,  -280,   342,   404,   310,   312,  -280,   272,   317,
    -280,   326,  -280,    24,   206,   175,   206,   366,   206,   206,
     362,   369,  -280,  -280,    38,    63,   385,   206,   390,  -280,
    -280,  -280,  -280,  -280,  -280,  -280,   190,   386,  -280,   347,
    -280,   352,  -280,  -280,   354,  -280,  -280,   132,   -46,    54,
    -280,  -280,   206,  -280,   355,   206,   360,  -280,   236,   367,
     368,   370,   378,    18,  -280,   247,   278,   375,   380,    12,
      66,   361,    81,  -280,   373,  -280,   381,   382,   383,   378,
    -280,   418,  -280,  -280,  -280,   206,  -280,   206,   206,   420,
     254,   431,   289,   432,   206,   206,   206,   206,   206,   206,
     206,   206,   206,  -280,   387,   388,   433,    22,   426,   425,
     206,   206,  -280,  -280,   392,  -280,   391,   393,   440,  -280,
      51,   378,   394,   395,   108,   396,   398,  -280,   399,   104,
     104,  -280,  -280,  -280,   254,   254,   254,   296,  -280,  -280,
     400,   206,   206,   353,   353,   320,   331,  -280,  -280,  -280,
     401,    89,  -280,   206,   397,   206,   206,   206,  -280,   378,
     117,   224,   437,   405,  -280,  -280,  -280,   206,   378,   206,
     406,   407,   408,   446,   353,  -280,   411,  -280,   122,   159,
    -280,  -280,  -280,   206,   443,  -280,   410,  -280,   378,  -280,
    -280
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    13,     0,     0,     7,     1,     0,    30,
       0,     4,     6,    17,     0,    15,     0,     0,     0,    37,
      34,    35,    36,     0,     0,     0,     0,    12,    14,     0,
      29,     0,     0,     0,    34,     0,     3,     0,   118,     8,
       0,    10,    11,    18,    20,    28,     0,    32,    42,    33,
      39,     0,     0,     2,   117,     9,     0,    31,     0,     0,
       0,     0,   122,    19,     0,    23,     0,    44,     0,     0,
      46,     0,    38,     0,     0,     0,   121,   124,     0,    22,
       0,     0,    47,    43,     0,    40,     0,   125,     0,     0,
       0,    27,     0,    21,     0,    45,     0,    49,     0,     0,
       0,     0,   123,    16,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    49,     0,     0,     0,     0,     0,
       0,    48,    51,     0,    56,    57,     0,     0,     0,     0,
       0,     0,   127,     0,     0,     0,     0,   116,     0,     0,
      25,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    60,    61,     0,     0,     0,     0,     0,    50,
      55,    58,    52,    59,    53,    54,     0,     0,   132,   130,
     126,     0,   129,   115,     0,   120,    24,     0,     0,   100,
      99,   102,     0,   101,     0,     0,   109,   110,     0,     0,
       0,     0,    75,     0,    86,     0,     0,     0,     0,     0,
       0,     0,     0,    85,     0,   133,     0,     0,     0,    78,
      87,     0,   128,   119,    68,     0,    71,   112,     0,     0,
     107,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    74,     0,     0,     0,     0,     0,     0,
       0,     0,    72,    73,     0,   134,     0,     0,     0,   131,
       0,   114,     0,   111,     0,    86,    85,    96,    87,    91,
      92,    93,    94,    95,   104,   105,   106,   103,    81,    79,
       0,     0,     0,    49,    49,     0,     0,    62,    82,    80,
       0,     0,   108,     0,    97,   112,   112,   112,    83,    76,
       0,     0,     0,     0,    67,    84,    69,     0,   113,     0,
       0,     0,     0,     0,    49,    64,     0,    66,     0,     0,
      89,    88,    90,     0,     0,    65,     0,    98,    77,    63,
      70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -280,  -280,  -280,  -280,   461,  -280,   444,  -280,  -280,   454,
    -280,  -280,  -280,  -280,   409,  -280,  -280,  -280,   438,    16,
    -280,   412,   376,   402,  -112,  -280,   350,  -280,  -280,  -280,
    -280,  -280,  -280,  -280,  -280,   -97,  -280,  -134,  -279,  -280,
     439,  -280,   -34,  -280,  -280,   403,   374,  -280,   340,  -280,
     -63,  -280
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    23,    24,     9,    14,    15,
      16,    56,    63,    64,    65,    90,    18,    31,    32,    35,
      49,    50,    69,    70,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   186,   187,   251,   252,   253,
      36,    37,    38,    75,    76,    77,    99,   134,   135,   169,
     100,   158
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     131,   150,   151,    54,   166,     4,   300,   301,   302,   216,
     188,   192,   193,   167,   195,   196,   131,   131,    97,    58,
     145,    19,    59,   204,   131,     1,    25,   224,   225,   226,
     227,   177,   209,    33,     4,   271,   136,    11,   139,    25,
      98,    20,    21,    22,    91,   199,   178,    33,   220,   228,
     167,   222,   229,   230,     8,   231,   104,   200,   202,     7,
     224,   225,   226,   227,   146,    13,   147,   242,   232,    67,
     201,   147,    66,   119,    68,   174,   237,    10,    74,   272,
      80,   250,   228,    13,   254,   229,   230,   119,   231,    17,
     259,   260,   261,   262,   263,   264,   265,   266,   267,    26,
      68,   232,    19,    27,    42,    74,   275,   276,   217,   281,
      68,   218,   119,   219,   133,   226,   227,   224,   225,   226,
     227,   243,    20,    21,    22,   167,   224,   225,   226,   227,
      29,   224,   225,   226,   227,   228,   244,   289,   290,   228,
     167,    41,   229,   230,   296,   231,   297,    39,   228,   298,
     133,   229,   230,   228,   231,    43,   229,   230,   232,   231,
      44,   291,   292,   308,    19,   309,   284,   232,   224,   225,
     226,   227,   232,    83,    84,   303,   131,   131,    47,   318,
     316,    19,   179,   180,    20,    21,    22,   214,    51,   215,
     228,   147,   314,   229,   230,    48,   231,   179,   180,    52,
      30,    20,    21,    22,    55,   181,    57,   131,    60,   232,
      61,   182,   105,   179,   180,   189,   190,   317,   183,    62,
     181,    71,   191,    73,   184,    81,   182,   141,    84,   185,
     206,   207,    19,   183,    93,    94,   181,   208,    82,   184,
     304,   305,   182,    85,   185,   224,   225,   226,   227,   183,
      86,    87,    20,    21,    22,   184,   224,   225,   226,   227,
     185,    89,    88,   224,   225,   226,   227,   228,    92,    96,
     229,   230,   101,   231,    19,    97,    94,   103,   228,   107,
     137,   229,   230,   140,   231,   228,   232,   224,   225,   226,
     227,   233,   142,    45,    20,    21,    22,   232,   224,   225,
     226,   227,   238,   143,   232,   224,   225,   226,   227,   228,
     144,   148,   229,   230,   149,   231,    19,   152,   153,   157,
     228,   156,   154,   229,   230,    19,   231,   228,   232,   224,
     225,   226,   227,   239,   155,    78,    20,    21,    22,   232,
     224,   225,   226,   227,   257,    20,    21,    22,   160,   168,
     161,   228,   162,   163,   229,   230,   164,   231,   108,   109,
     110,   165,   228,   172,   173,   229,   230,   111,   231,   175,
     232,   112,   113,   194,   114,   293,   115,   116,    19,   176,
     197,   232,   224,   225,   226,   227,   294,   224,   225,   226,
     227,   198,   203,   210,   205,   117,    19,   132,    20,    21,
      22,   118,   119,   211,   228,   212,   213,   229,   230,   228,
     231,    19,   229,   230,   221,   231,    34,    21,    22,   223,
     147,   234,   235,   232,   236,   249,   245,   255,   232,   240,
     170,    20,    21,    22,   241,   246,   247,   248,   256,   258,
     270,   273,   268,   269,   274,   277,   278,   280,   279,   282,
     285,   283,   286,   287,   299,   288,   295,   306,   307,   313,
     319,   310,   311,   312,   315,   320,    12,    40,    28,    46,
     106,   159,    72,    79,   171,   138,    53,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    95,     0,     0,     0,
       0,     0,   102
};

static const yytype_int16 yycheck[] =
{
      97,   113,   114,    37,    13,     7,   285,   286,   287,    55,
     144,   145,   146,    59,   148,   149,   113,   114,     3,    54,
      13,     7,    57,   157,   121,    38,    10,     9,    10,    11,
      12,     7,   166,    17,     7,    13,    99,    39,   101,    23,
      25,    27,    28,    29,    78,     7,   143,    31,   182,    31,
      59,   185,    34,    35,    44,    37,    90,   154,   155,     0,
       9,    10,    11,    12,    57,     7,    59,    55,    50,    55,
       7,    59,    56,    49,    58,   138,    58,    51,    62,    57,
      64,   215,    31,     7,   218,    34,    35,    49,    37,    25,
     224,   225,   226,   227,   228,   229,   230,   231,   232,    46,
      84,    50,     7,    45,     7,    89,   240,   241,    54,    58,
      94,    57,    49,    59,    98,    11,    12,     9,    10,    11,
      12,    55,    27,    28,    29,    59,     9,    10,    11,    12,
      51,     9,    10,    11,    12,    31,    55,   271,   272,    31,
      59,    53,    34,    35,    55,    37,    57,    52,    31,   283,
     134,    34,    35,    31,    37,     7,    34,    35,    50,    37,
      25,   273,   274,   297,     7,   299,    58,    50,     9,    10,
      11,    12,    50,    55,    56,    58,   273,   274,    53,   313,
      58,     7,     7,     8,    27,    28,    29,    55,    33,    57,
      31,    59,   304,    34,    35,     7,    37,     7,     8,     7,
      26,    27,    28,    29,    53,    30,    53,   304,    56,    50,
      54,    36,    55,     7,     8,    40,    41,    58,    43,    54,
      30,     8,    47,    55,    49,     7,    36,    55,    56,    54,
      40,    41,     7,    43,    53,    54,    30,    47,     7,    49,
      16,    17,    36,    58,    54,     9,    10,    11,    12,    43,
      51,     7,    27,    28,    29,    49,     9,    10,    11,    12,
      54,    56,    55,     9,    10,    11,    12,    31,     7,    57,
      34,    35,    51,    37,     7,     3,    54,    52,    31,     8,
      52,    34,    35,    53,    37,    31,    50,     9,    10,    11,
      12,    55,    58,    26,    27,    28,    29,    50,     9,    10,
      11,    12,    55,    54,    50,     9,    10,    11,    12,    31,
      54,    54,    34,    35,    54,    37,     7,    53,    53,    32,
      31,    59,    54,    34,    35,     7,    37,    31,    50,     9,
      10,    11,    12,    55,    54,    26,    27,    28,    29,    50,
       9,    10,    11,    12,    55,    27,    28,    29,    53,     7,
      53,    31,    53,    53,    34,    35,    53,    37,     5,     6,
       7,    53,    31,    53,    52,    34,    35,    14,    37,    52,
      50,    18,    19,     7,    21,    55,    23,    24,     7,    53,
      18,    50,     9,    10,    11,    12,    55,     9,    10,    11,
      12,    22,     7,     7,     4,    42,     7,    26,    27,    28,
      29,    48,    49,    56,    31,    53,    52,    34,    35,    31,
      37,     7,    34,    35,    59,    37,    27,    28,    29,    59,
      59,    54,    54,    50,    54,     7,    53,     7,    50,    54,
      26,    27,    28,    29,    54,    54,    54,    54,     7,     7,
       7,    15,    55,    55,    19,    53,    55,     7,    55,    55,
      54,    56,    54,    54,    57,    55,    55,    20,    53,    13,
      17,    55,    55,    55,    53,    55,     5,    23,    14,    31,
      94,   121,    60,    64,   134,   101,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    84,    -1,    -1,    -1,
      -1,    -1,    89
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    61,    62,     7,    63,    64,     0,    44,    67,
      51,    39,    64,     7,    68,    69,    70,    25,    76,     7,
      27,    28,    29,    65,    66,    79,    46,    45,    69,    51,
      26,    77,    78,    79,    27,    79,   100,   101,   102,    52,
      66,    53,     7,     7,    25,    26,    78,    53,     7,    80,
      81,    33,     7,   100,   102,    53,    71,    53,    54,    57,
      56,    54,    54,    72,    73,    74,    79,    55,    79,    82,
      83,     8,    81,    55,    79,   103,   104,   105,    26,    74,
      79,     7,     7,    55,    56,    58,    51,     7,    55,    56,
      75,   102,     7,    53,    54,    83,    57,     3,    25,   106,
     110,    51,   105,    52,   102,    55,    82,     8,     5,     6,
       7,    14,    18,    19,    21,    23,    24,    42,    48,    49,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    26,    79,   107,   108,   110,    52,   106,   110,
      53,    55,    58,    54,    54,    13,    57,    59,    54,    54,
      84,    84,    53,    53,    54,    54,    59,    32,   111,    86,
      53,    53,    53,    53,    53,    53,    13,    59,     7,   109,
      26,   108,    53,    52,   110,    52,    53,     7,    95,     7,
       8,    30,    36,    43,    49,    54,    95,    96,    97,    40,
      41,    47,    97,    97,     7,    97,    97,    18,    22,     7,
      95,     7,    95,     7,    97,     4,    40,    41,    47,    97,
       7,    56,    53,    52,    55,    57,    55,    54,    57,    59,
      97,    59,    97,    59,     9,    10,    11,    12,    31,    34,
      35,    37,    50,    55,    54,    54,    54,    58,    55,    55,
      54,    54,    55,    55,    55,    53,    54,    54,    54,     7,
      97,    97,    98,    99,    97,     7,     7,    55,     7,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    55,    55,
       7,    13,    57,    15,    19,    97,    97,    53,    55,    55,
       7,    58,    55,    56,    58,    54,    54,    54,    55,    97,
      97,    84,    84,    55,    55,    55,    55,    57,    97,    57,
      98,    98,    98,    58,    16,    17,    20,    53,    97,    97,
      55,    55,    55,    13,    84,    53,    58,    58,    97,    17,
      55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    60,    61,    61,    62,    62,    63,    63,    64,    65,
      65,    66,    67,    67,    68,    68,    69,    70,    70,    71,
      71,    72,    73,    73,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    78,    79,    79,    79,    79,    80,    80,
      81,    81,    81,    81,    81,    82,    82,    83,    84,    84,
      85,    85,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    89,    90,    91,    91,
      91,    91,    92,    92,    93,    94,    94,    94,    94,    94,
      94,    94,    94,    94,    94,    95,    95,    95,    96,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   106,   106,   107,   107,
     108,   109,   109,   110,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     3,     0,     2,     1,     4,     3,
       2,     2,     3,     0,     2,     1,     8,     1,     3,     2,
       0,     3,     2,     1,     6,     5,     2,     1,     3,     2,
       0,     3,     2,     2,     1,     1,     1,     1,     3,     1,
       4,     7,     1,     4,     3,     3,     1,     2,     1,     0,
       2,     1,     2,     2,     2,     2,     1,     1,     2,     2,
       2,     2,     5,     9,     7,     8,     7,     6,     4,     7,
      10,     4,     4,     4,     4,     3,     6,     9,     3,     5,
       5,     5,     5,     6,     6,     3,     3,     3,     6,     6,
       6,     3,     3,     3,     3,     3,     3,     4,     7,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     4,     1,
       1,     1,     0,     3,     1,     8,     7,     2,     1,     9,
       8,     1,     0,     3,     1,     2,     3,     2,     3,     2,
       2,     3,     1,     4,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: TypeDefBlock ClassDefBlock GDeclBlock FDefList MainBlock  */
#line 60 "parse.y"
                                                                              {exit(1);}
#line 1610 "y.tab.c"
    break;

  case 3: /* Program: TypeDefBlock ClassDefBlock GDeclBlock MainBlock  */
#line 61 "parse.y"
                                                                              {exit(1);}
#line 1616 "y.tab.c"
    break;

  case 6: /* TypeDefList: TypeDefList TypeDef  */
#line 67 "parse.y"
                                            {printtypetable();}
#line 1622 "y.tab.c"
    break;

  case 7: /* TypeDefList: TypeDef  */
#line 68 "parse.y"
                                                        {printtypetable();}
#line 1628 "y.tab.c"
    break;

  case 8: /* TypeDef: ID '{' FieldDeclList '}'  */
#line 71 "parse.y"
                                           { 
												//Flags error if the number of member fields is 9 or more
												if(fieldindex>9)   //only 8 members because the first index of every block is used for storing the next free block
												{
													printf("Too Many Member Fields:\n");
													exit(1);
												}
												int size=fieldindex-1;
												fieldindex=1;
												
												struct Typetable* Tptr = TInstall((yyvsp[-3].c),size,(yyvsp[-1].field)); 

												struct Fieldlist* field=(yyvsp[-1].field);
										
												while(field!=NULL){
													if(field->type==NULL)
													{
														if(strcmp(field->nametype,(yyvsp[-3].c))==0)
															field->type=Tptr;                       //Assigning the type to the fields;
														
														else
														{
															printf("Invalid type:\n");
															exit(1);
														}
													}
													field=field->next;
												}

											}
#line 1663 "y.tab.c"
    break;

  case 9: /* FieldDeclList: FieldDeclList FieldDecl ';'  */
#line 103 "parse.y"
                                               {Fappend((yyvsp[-2].field),(yyvsp[-1].field));(yyval.field)=(yyvsp[-2].field);}
#line 1669 "y.tab.c"
    break;

  case 10: /* FieldDeclList: FieldDecl ';'  */
#line 104 "parse.y"
                                                           {(yyval.field)=(yyvsp[-1].field);}
#line 1675 "y.tab.c"
    break;

  case 11: /* FieldDecl: Type ID  */
#line 107 "parse.y"
                        {(yyval.field)=Fcreate((yyvsp[0].c),(yyvsp[-1].c));}
#line 1681 "y.tab.c"
    break;

  case 16: /* Classdef: Cname '{' DECL Fieldlists MethodDecl ENDDECL MethodDefns '}'  */
#line 116 "parse.y"
                                                                                    {
																						//Allocates space for the vft and initializes the vft with the flabels of the member functions

																						used_space+=8;
																						
																						printf("Classtable:\n");
																						printclasstable(Cptr);
																						Cptr=NULL;
																					}
#line 1695 "y.tab.c"
    break;

  case 17: /* Cname: ID  */
#line 127 "parse.y"
                                {Cptr = CInstall((yyvsp[0].c),NULL);}
#line 1701 "y.tab.c"
    break;

  case 18: /* Cname: ID Extends ID  */
#line 128 "parse.y"
                                                {Cptr = CInstall((yyvsp[-2].c),(yyvsp[0].c));}
#line 1707 "y.tab.c"
    break;

  case 21: /* Fld: Type ID ';'  */
#line 135 "parse.y"
                                {
								if(Cptr==NULL){printf("CPTR NULL in fieldlist\n");exit(1);}
								   
								if(Cptr->fieldcount==8)
								{
									printf("Only 8 data members possible at max\n");
									exit(1);
								}
								DInstall(Cptr,(yyvsp[-2].c),(yyvsp[-1].c));
							}
#line 1722 "y.tab.c"
    break;

  case 24: /* MDecl: Type ID '(' ParamList ')' ';'  */
#line 151 "parse.y"
                                               {
												if(Cptr==NULL){printf("CPTR NULL in MDecl\n");exit(1);}
								   
												if(Cptr->methodcount==8)
												{
													printf("Only 8 member functions possible at max\n");
													exit(1);
												}
												MInstall(Cptr,(yyvsp[-4].c),TLookup((yyvsp[-5].c)),(yyvsp[-2].param));
												
											}
#line 1738 "y.tab.c"
    break;

  case 25: /* MDecl: Type ID '(' ')' ';'  */
#line 163 "parse.y"
                                                    {
												
												if(Cptr==NULL){printf("CPTR NULL in MDecl\n");exit(1);}
								   
												if(Cptr->methodcount==8)
												{
													printf("Only 8 member functions possible at max\n");
													exit(1);
												}
												MInstall(Cptr,(yyvsp[-3].c),TLookup((yyvsp[-4].c)),NULL);
								}
#line 1754 "y.tab.c"
    break;

  case 28: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 181 "parse.y"
                                                    {  
														printgst();
														if(flag==0)
														{
															flag=1;
															fprintf(fptr,"MOV SP,%d\n",4095+used_space);
															fprintf(fptr,"MOV BP,SP\n");
															fprintf(fptr,"ADD SP,1\n");    //For return value
															fprintf(fptr,"CALL F0\n");
															fprintf(fptr,"SUB SP,1\n");     //Popping the return value
															fprintf(fptr,"INT 10\n");
														}
													}
#line 1772 "y.tab.c"
    break;

  case 29: /* GDeclBlock: DECL ENDDECL  */
#line 194 "parse.y"
                                                                {}
#line 1778 "y.tab.c"
    break;

  case 30: /* GDeclBlock: %empty  */
#line 195 "parse.y"
                                                                {}
#line 1784 "y.tab.c"
    break;

  case 33: /* GDecl: Type Gidlist  */
#line 199 "parse.y"
                                                    {addgtype((yyvsp[-1].c));}
#line 1790 "y.tab.c"
    break;

  case 34: /* Type: INT  */
#line 201 "parse.y"
                                                    {(yyval.c)=(yyvsp[0].c);}
#line 1796 "y.tab.c"
    break;

  case 35: /* Type: STR  */
#line 202 "parse.y"
                                                        {(yyval.c)=(yyvsp[0].c);}
#line 1802 "y.tab.c"
    break;

  case 36: /* Type: VOID  */
#line 203 "parse.y"
                                                                                                {(yyval.c)=(yyvsp[0].c);}
#line 1808 "y.tab.c"
    break;

  case 37: /* Type: ID  */
#line 204 "parse.y"
                                                                                                {(yyval.c)=(yyvsp[0].c);}
#line 1814 "y.tab.c"
    break;

  case 40: /* Gid: ID '[' NUM ']'  */
#line 207 "parse.y"
                                                    {GInstall((yyvsp[-3].c),NULL,(yyvsp[-1].i),-1,-1,NULL);}
#line 1820 "y.tab.c"
    break;

  case 41: /* Gid: ID '[' NUM ']' '[' NUM ']'  */
#line 208 "parse.y"
                                                            {GInstall((yyvsp[-6].c),NULL,(yyvsp[-4].i)*(yyvsp[-1].i),(yyvsp[-4].i),(yyvsp[-1].i),NULL);}
#line 1826 "y.tab.c"
    break;

  case 42: /* Gid: ID  */
#line 209 "parse.y"
                                                            {GInstall((yyvsp[0].c),NULL,1,-1,-1,NULL);}
#line 1832 "y.tab.c"
    break;

  case 43: /* Gid: ID '(' ParamList ')'  */
#line 210 "parse.y"
                                                                        {GInstall((yyvsp[-3].c),NULL,-1,-1,-1,(yyvsp[-1].param));}
#line 1838 "y.tab.c"
    break;

  case 44: /* Gid: ID '(' ')'  */
#line 211 "parse.y"
                                                                                        {GInstall((yyvsp[-2].c),NULL,-1,-1,-1,NULL);}
#line 1844 "y.tab.c"
    break;

  case 45: /* ParamList: ParamList ',' Param  */
#line 212 "parse.y"
                                                                {AppendParamlist((yyvsp[-2].param),(yyvsp[0].param));(yyval.param)=(yyvsp[-2].param);}
#line 1850 "y.tab.c"
    break;

  case 46: /* ParamList: Param  */
#line 213 "parse.y"
                                                                                {(yyval.param)=(yyvsp[0].param);}
#line 1856 "y.tab.c"
    break;

  case 47: /* Param: Type ID  */
#line 214 "parse.y"
                                                                                        {(yyval.param)=CreateParamlist((yyvsp[-1].c),(yyvsp[0].c));}
#line 1862 "y.tab.c"
    break;

  case 48: /* Slistblock: Slist  */
#line 216 "parse.y"
                                                      {(yyval.no)=(yyvsp[0].no);}
#line 1868 "y.tab.c"
    break;

  case 49: /* Slistblock: %empty  */
#line 217 "parse.y"
                                                              {(yyval.no)=NULL;}
#line 1874 "y.tab.c"
    break;

  case 50: /* Slist: Slist Stmt  */
#line 219 "parse.y"
                                                   {(yyval.no)=makeConnectorNode('.',(yyvsp[-1].no),(yyvsp[0].no));}
#line 1880 "y.tab.c"
    break;

  case 51: /* Slist: Stmt  */
#line 220 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1886 "y.tab.c"
    break;

  case 52: /* Stmt: InputStmt ';'  */
#line 222 "parse.y"
                                                   {(yyval.no)=(yyvsp[-1].no);}
#line 1892 "y.tab.c"
    break;

  case 53: /* Stmt: OutputStmt ';'  */
#line 223 "parse.y"
                                                           {(yyval.no)=(yyvsp[-1].no);}
#line 1898 "y.tab.c"
    break;

  case 54: /* Stmt: AsgStmt ';'  */
#line 224 "parse.y"
                                                        {(yyval.no)=(yyvsp[-1].no);}
#line 1904 "y.tab.c"
    break;

  case 55: /* Stmt: Ifstmt ';'  */
#line 225 "parse.y"
                                                       {(yyval.no)=(yyvsp[-1].no);}
#line 1910 "y.tab.c"
    break;

  case 56: /* Stmt: Whilestmt  */
#line 226 "parse.y"
                                                       {(yyval.no)=(yyvsp[0].no);}
#line 1916 "y.tab.c"
    break;

  case 57: /* Stmt: Dowhilestmt  */
#line 227 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1922 "y.tab.c"
    break;

  case 58: /* Stmt: Repeatuntil ';'  */
#line 228 "parse.y"
                                                         {(yyval.no)=(yyvsp[-1].no);}
#line 1928 "y.tab.c"
    break;

  case 59: /* Stmt: FreeStmt ';'  */
#line 229 "parse.y"
                                                                                                {(yyval.no)=(yyvsp[-1].no);}
#line 1934 "y.tab.c"
    break;

  case 60: /* Stmt: BREAK ';'  */
#line 230 "parse.y"
                                                          {char c[6]="break";
													(yyval.no)=makeBreak_ContinueNode(c);}
#line 1941 "y.tab.c"
    break;

  case 61: /* Stmt: CONTINUE ';'  */
#line 232 "parse.y"
                                                          {char c[9]="continue";
													(yyval.no)=makeBreak_ContinueNode(c);}
#line 1948 "y.tab.c"
    break;

  case 62: /* Stmt: DELETE '(' FIELD ')' ';'  */
#line 234 "parse.y"
                                                           {(yyval.no)==dynamicmemorynode((yyvsp[-2].no)->type,Delete,(yyvsp[-2].no),NULL);}
#line 1954 "y.tab.c"
    break;

  case 63: /* Ifstmt: IF '(' E ')' Then Slistblock Else Slistblock ENDIF  */
#line 237 "parse.y"
                                                             {struct tnode* else_node;
													struct tnode* connector_node;
													else_node=makeBranchingNode("Else",(yyvsp[-1].no),NULL);
													connector_node=makeConnectorNode('.',(yyvsp[-3].no),else_node);
													(yyval.no)=makeBranchingNode("If",(yyvsp[-6].no),connector_node);}
#line 1964 "y.tab.c"
    break;

  case 64: /* Ifstmt: IF '(' E ')' Then Slistblock ENDIF  */
#line 242 "parse.y"
                                                                {(yyval.no)=makeBranchingNode("If",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1970 "y.tab.c"
    break;

  case 65: /* Whilestmt: WHILE '(' E ')' DO Slistblock ENDWHILE ';'  */
#line 243 "parse.y"
                                                           {(yyval.no)=makeBranchingNode("While",(yyvsp[-5].no),(yyvsp[-2].no));}
#line 1976 "y.tab.c"
    break;

  case 66: /* Dowhilestmt: DO Slistblock WHILE '(' E ')' ';'  */
#line 244 "parse.y"
                                                           {(yyval.no)=makeBranchingNode("Do",(yyvsp[-5].no),(yyvsp[-2].no));}
#line 1982 "y.tab.c"
    break;

  case 67: /* Repeatuntil: REPEAT Slistblock UNTIL '(' E ')'  */
#line 245 "parse.y"
                                                        {(yyval.no)=makeBranchingNode("Repeat",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1988 "y.tab.c"
    break;

  case 68: /* InputStmt: READ '(' ID ')'  */
#line 247 "parse.y"
                                                   {struct tnode* var=makeVariableNode((yyvsp[-1].c));
													(yyval.no)=makereadnode(var);}
#line 1995 "y.tab.c"
    break;

  case 69: /* InputStmt: READ '(' ID '[' E ']' ')'  */
#line 249 "parse.y"
                                                           {struct tnode* var=makeVariableNode((yyvsp[-4].c));
													indextypecheck((yyvsp[-2].no)->type->name);
													var->left=(yyvsp[-2].no);
													(yyval.no)=makereadnode(var);}
#line 2004 "y.tab.c"
    break;

  case 70: /* InputStmt: READ '(' ID '[' E ']' '[' E ']' ')'  */
#line 253 "parse.y"
                                                               {struct tnode* var=makeVariableNode((yyvsp[-7].c));
													indextypecheck((yyvsp[-5].no)->type->name);
													indextypecheck((yyvsp[-2].no)->type->name);
													var->left=(yyvsp[-5].no);    //Row
													var->right=(yyvsp[-2].no);  //Column
													(yyval.no)=makereadnode(var);}
#line 2015 "y.tab.c"
    break;

  case 71: /* InputStmt: READ '(' FIELD ')'  */
#line 259 "parse.y"
                                                                {(yyval.no)=makereadnode((yyvsp[-1].no));}
#line 2021 "y.tab.c"
    break;

  case 72: /* FreeStmt: FREE '(' ID ')'  */
#line 262 "parse.y"
                                                    {
														struct tnode* var=makeVariableNode((yyvsp[-1].c));
														(yyval.no)==dynamicmemorynode(var->type,Free,var,NULL);
													}
#line 2030 "y.tab.c"
    break;

  case 73: /* FreeStmt: FREE '(' FIELD ')'  */
#line 266 "parse.y"
                                                            { (yyval.no)==dynamicmemorynode((yyvsp[-1].no)->type,Free,(yyvsp[-1].no),NULL);}
#line 2036 "y.tab.c"
    break;

  case 74: /* OutputStmt: WRITE '(' E ')'  */
#line 269 "parse.y"
                                                                   {(yyval.no)=makewritenode((yyvsp[-1].no));}
#line 2042 "y.tab.c"
    break;

  case 75: /* AsgStmt: ID EQUAL E  */
#line 271 "parse.y"
                                                                           {
													struct tnode* var=makeVariableNode((yyvsp[-2].c));
													//if ID and E are classes then makeoperator node typechecks and also checks if E is a valid descendent of ID
													(yyval.no) = makeOperatorNode('=',var,(yyvsp[0].no));  
												   }
#line 2052 "y.tab.c"
    break;

  case 76: /* AsgStmt: ID '[' E ']' EQUAL E  */
#line 276 "parse.y"
                                                                           {struct tnode* var=makeVariableNode((yyvsp[-5].c));
													indextypecheck((yyvsp[-3].no)->type->name);
													var->left=(yyvsp[-3].no);
													(yyval.no) = makeOperatorNode('=',var,(yyvsp[0].no));}
#line 2061 "y.tab.c"
    break;

  case 77: /* AsgStmt: ID '[' E ']' '[' E ']' EQUAL E  */
#line 280 "parse.y"
                                                                   {struct tnode* var=makeVariableNode((yyvsp[-8].c));
													indextypecheck((yyvsp[-6].no)->type->name);
													indextypecheck((yyvsp[-3].no)->type->name);
													var->left=(yyvsp[-6].no);    //Row
													var->right=(yyvsp[-3].no);  //Column
													(yyval.no)=makeOperatorNode('=',var,(yyvsp[0].no));}
#line 2072 "y.tab.c"
    break;

  case 78: /* AsgStmt: FIELD EQUAL E  */
#line 286 "parse.y"
                                                        {
													//FIELD CAN ONLY BE A CLASS:SELF.ID
													//operator node checks if is descendant class or not.
													(yyval.no) = makeOperatorNode('=',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2081 "y.tab.c"
    break;

  case 79: /* AsgStmt: ID EQUAL ALLOC '(' ')'  */
#line 290 "parse.y"
                                                        { 
												 struct tnode* var=makeVariableNode((yyvsp[-4].c));
												 struct tnode* allocnode=dynamicmemorynode(var->type,Alloc,NULL,NULL);
												 (yyval.no)=makeOperatorNode('=',var,allocnode);
												}
#line 2091 "y.tab.c"
    break;

  case 80: /* AsgStmt: FIELD EQUAL ALLOC '(' ')'  */
#line 295 "parse.y"
                                                                        {
													struct tnode* allocnode=dynamicmemorynode((yyvsp[-4].no)->type,Alloc,NULL,NULL);
													(yyval.no)=makeOperatorNode('=',(yyvsp[-4].no),allocnode);
												}
#line 2100 "y.tab.c"
    break;

  case 81: /* AsgStmt: ID EQUAL INITIALIZE '(' ')'  */
#line 299 "parse.y"
                                                        { 
												 struct tnode* var=makeVariableNode((yyvsp[-4].c));
												 struct tnode* initializenode=dynamicmemorynode(var->type,Initialize,NULL,NULL);
												 (yyval.no)=makeOperatorNode('=',var,initializenode);
												}
#line 2110 "y.tab.c"
    break;

  case 82: /* AsgStmt: FIELD EQUAL INITIALIZE '(' ')'  */
#line 304 "parse.y"
                                                                {
													struct tnode* initializenode=dynamicmemorynode((yyvsp[-4].no)->type,Initialize,NULL,NULL);
													(yyval.no)=makeOperatorNode('=',(yyvsp[-4].no),initializenode);
												}
#line 2119 "y.tab.c"
    break;

  case 83: /* AsgStmt: ID EQUAL NEW '(' ID ')'  */
#line 308 "parse.y"
                                                        {
													//checks if valid(descendent and parent class or not) and exits if error else does nothing
													//descendent class validation
													struct tnode* var=makeVariableNode((yyvsp[-5].c));
													if(var->Lentry!=NULL) //it will surely be a userdefined datatype     
													{
														printf("Cannot assign new to non-object:Lentry\n");
														exit(1);
													}
												   
													if(var->Gentry->ctype==NULL)
													{
														printf("Cannot assign new to non-object:Gentry\n");
														exit(1);
													}

													int valid=isvalid(var->Gentry->ctype->name,(yyvsp[-1].c));  

													if(valid==-1)
													{   
														printf("Desc class and parent class mismatch:\n");
														exit(1);
													} 

													struct Classtable* descclass=CLookup((yyvsp[-1].c));
													struct tnode* var1=makeVariableNode((yyvsp[-5].c));
													struct tnode* constnode=makeConstantNode(4096+8*(descclass->class_index),NULL);
													struct tnode* newnode=dynamicmemorynode(var1->type,New,var1,constnode);
													(yyval.no)=makeOperatorNode('=',var,newnode);
												}
#line 2154 "y.tab.c"
    break;

  case 84: /* AsgStmt: FIELD EQUAL NEW '(' ID ')'  */
#line 338 "parse.y"
                                                        {
													//FIELD CAN ONLY be a class or userdeftype.
													struct tnode* var=(yyvsp[-5].no);
													struct tnode *var1=makeVariableNode(var->varname);
													var1->type=var->type;	//since var's type is changed to field type.
													///////////////////////////////////////////////////////////////
													struct tnode* iterfield=var->left;
						
													while(iterfield->next!=NULL)
														iterfield=iterfield->next;
													
													if(iterfield->field->ctype==NULL)
													{
														printf("Cannot assign new to non-object field:field equal new(id)\n");
														exit(1);
													}
													int valid=isvalid(iterfield->field->ctype->name,(yyvsp[-1].c));  

													if(valid==-1)
													{   
														printf("Desc class and parent class mismatch:field equal new(id)\n");
														exit(1);
													} 
													///////////////////////////////////////////////////////////////
													struct tnode* temp=var1;
													iterfield=var->left;
													
													temp->left=(struct tnode *)malloc(sizeof(struct tnode));
													temp->left->type=iterfield->type;
													temp->left->nodetype=iterfield->nodetype;
													temp->left->field=iterfield->field;
													temp->left->left=NULL;
													temp->left->right=NULL;
													temp->left->next=NULL;
													
													temp=temp->left;
													iterfield=iterfield->next;

													while(iterfield!=NULL)
													{
														temp->next=(struct tnode *)malloc(sizeof(struct tnode));
														temp->next->type=iterfield->type;
														temp->next->nodetype=iterfield->nodetype;
														temp->next->field=iterfield->field;
														temp->next->left=NULL;
														temp->next->right=NULL;
														temp->next->next=NULL;
														
														temp=temp->next;
														iterfield=iterfield->next;
													}
													//////////////////////////////////////////////////////////////////////
													//After above step indicates that the type is null.Hence by default ctype will not be null.
													//NOTE:Inside dynamic memory node we check if field is a class or not.
													struct Classtable* descclass=CLookup((yyvsp[-1].c));
													struct tnode* constnode=makeConstantNode(4096+8*(descclass->class_index),NULL);
													struct tnode* newnode=dynamicmemorynode(var->type,New,var1,constnode);   
													//the beow code is put after dynamic memory node because it will detect if it is a class or not
													(yyval.no)=makeOperatorNode('=',var,newnode);
												}
#line 2219 "y.tab.c"
    break;

  case 85: /* FIELD: SELF '.' ID  */
#line 400 "parse.y"
                                                    { 
														 //Below code is incase there is no parameters and local declarations inside the function of the class
														 if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
															LInstall("self",NULL,NULL,Cptr);
														
														if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
															LInstall("vft",NULL,NULL,Cptr);
														
														struct tnode* var=makeVariableNode("self");
														struct tnode* field;
														if(Cptr==NULL)
														{
															printf("CPTR IS NULL\n");
															exit(1);
														}
														field=makefieldnode((yyvsp[0].c),NULL,Cptr);   //field can be of class or userdefined type:Hence 3 arguments are given to makefieldnode
														var->left=field;
														var->type=field->type;
														(yyval.no)=var;
													}
#line 2244 "y.tab.c"
    break;

  case 86: /* FIELD: ID '.' ID  */
#line 421 "parse.y"
                                                                                            {   //First ID always has a type,can never be a class
														//First ID cannot be a class because the second id cannot be a data member
														//printf("%s,%s",$<c>1,$<c>3);
														struct tnode* var=makeVariableNode((yyvsp[-2].c));	
														struct tnode* field;
														if(var->Gentry!=NULL && var->Lentry==NULL && var->Gentry->ctype!=NULL)
														{
															printf("Data members can only be accessed through member functions:%s\n",(yyvsp[0].c));
															exit(1);
														}
														field=makefieldnode((yyvsp[0].c),var->type,NULL);
														var->left=field;
														var->type=field->type;
														(yyval.no)=var;
													}
#line 2264 "y.tab.c"
    break;

  case 87: /* FIELD: FIELD '.' ID  */
#line 436 "parse.y"
                                                                                        {
														struct tnode* var=(yyvsp[-2].no);
														//If field is a class then var->type will be null else it won't be null
														struct tnode* field;
														
														if(var->type==NULL)      //Classes cannot access data members directly
														{
																printf("Cannot access member function from non-object\n in field");
																exit(1);
														}
														struct tnode* iterfield=var->left;

		  												while(iterfield->next!=NULL)
															iterfield=iterfield->next;
														
														field=makefieldnode((yyvsp[0].c),iterfield->field->type,iterfield->field->ctype);

														iterfield->next=field;
														var->type=field->type;
														(yyval.no)=var;
		  											}
#line 2290 "y.tab.c"
    break;

  case 88: /* FieldFunction: SELF '.' ID '(' ArglistBlock ')'  */
#line 459 "parse.y"
                                                             {   
															//Below code is incase there is no parameters and local declarations inside the function of the class
															if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
																LInstall("self",NULL,NULL,Cptr);
															
															if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
																LInstall("vft",NULL,NULL,Cptr);

															struct Memberfunclist* member=MLookup(Cptr,(yyvsp[-3].c));
															if(member==NULL)
																{yyerror("Yacc : Undefined Member function for self");exit(1);}
															
															struct tnode* temp=(yyvsp[-1].no);

															int typecheck=funccallargsvalidate(NULL,temp,member);
															if(typecheck==-1)
															{yyerror("Yacc :invalid argument return type for member function of class\n");exit(1);}
														   
															//Arguments(makefunctionnode):funcname,arglist(left child),gsymboltable(outside class functions),memberfunclist pointer(inside class functions),rightnode(for self/id/field)
															struct tnode* var=makeVariableNode("self");     //It is present in the local symbol table
															struct tnode* vft=makeVariableNode("vft");      //vft from local symbol table
															var->next=vft;
															(yyval.no) = makeFunctionNode((yyvsp[-3].c),(yyvsp[-1].no),NULL,member,var);
														}
#line 2319 "y.tab.c"
    break;

  case 89: /* FieldFunction: ID '.' ID '(' ArglistBlock ')'  */
#line 483 "parse.y"
                                                                             {   //The class variable is always declared in the global symbol table.
															//This will not occurinside a class.Eg:a.b(c):WIthin functions outside class
															struct tnode* temp=(yyvsp[-1].no);
															struct tnode* var=makeVariableNode((yyvsp[-5].c));
															if(var->Lentry!=NULL)     
															{
																printf("Cannot access member function from non-object\n");
																exit(1);
															}
															
															if(var->Gentry->ctype==NULL)
															{
																printf("Cannot access member function from non-object\n");
																exit(1);
															}

															//gets the class and checks if such a member function exists
															struct Memberfunclist* member=MLookup(var->Gentry->ctype,(yyvsp[-3].c));
															if(member==NULL)
																{yyerror("Yacc : Undefined Member function for object");exit(1);}

															//Type checks the return types of each argument with the formal parameters;
															//funccallargsvalidate(arguments):gtemp(to get the actual parameters(functions not member functions),temp(call parameters),member(to get the actual parameters for member functions))
															int typecheck=funccallargsvalidate(NULL,temp,member);
															if(typecheck==-1)
															{yyerror("Yacc :invalid argument return type for member function of class\n");exit(1);}

															//Arguments(makefunctionnode):funcname,arglist(left child),gsymboltable(outside class functions),classtable(inside class functions),rightnode(for self/id/field)
															struct tnode* constnode=makeConstantNode((var->Gentry->binding)+1,NULL);//stores the vft pointer address
															var->next=constnode;
															(yyval.no) = makeFunctionNode((yyvsp[-3].c),(yyvsp[-1].no),NULL,member,var);
														}
#line 2356 "y.tab.c"
    break;

  case 90: /* FieldFunction: FIELD '.' ID '(' ArglistBlock ')'  */
#line 515 "parse.y"
                                                                           {
															//can only be self.id where id is a class
															struct tnode* var=(yyvsp[-5].no);	//HERE VAR IS A FIELD NODE
															struct tnode* temp=(yyvsp[-1].no);
															
															if(var->type!=NULL)      //Not a class
															{
																printf("Cannot access member function from non-object\n");
																exit(1);
															}
															struct tnode* iterfield=var->left;

		  													while(iterfield->next!=NULL)
																iterfield=iterfield->next;

															//gets the class and checks if such a member function exists
															struct Memberfunclist* member=MLookup(iterfield->field->ctype,(yyvsp[-3].c));
															if(member==NULL)
																{yyerror("Yacc : Undefined Member function for field");exit(1);}

															//Type checks the return types of each argument with the formal parameters;
															//funccallargsvalidate(arguments):gtemp(to get the actual parameters(functions not member functions),temp(call parameters),member(to get the actual parameters for member functions))
															int typecheck=funccallargsvalidate(NULL,temp,member);
															if(typecheck==-1)
															{yyerror("Yacc :invalid argument return type for member function of class\n");exit(1);}
															

														   // struct tnode* =makeVariableNode("vft");      //vft from local symbol table
															// var->next=vft;
															//Arguments(makefunctionnode):funcname,arglist(left child),gsymboltable(outside class functions),classtable(inside class functions),rightchild(for self/id/field)
															(yyval.no) = makeFunctionNode((yyvsp[-3].c),(yyvsp[-1].no),NULL,member,var);
														  }
#line 2393 "y.tab.c"
    break;

  case 91: /* E: E PLUS E  */
#line 549 "parse.y"
                                                                                   {(yyval.no) = makeOperatorNode('+',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2399 "y.tab.c"
    break;

  case 92: /* E: E MINUS E  */
#line 550 "parse.y"
                                                                                   {(yyval.no) = makeOperatorNode('-',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2405 "y.tab.c"
    break;

  case 93: /* E: E MUL E  */
#line 551 "parse.y"
                                                                                           {(yyval.no) = makeOperatorNode('*',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2411 "y.tab.c"
    break;

  case 94: /* E: E DIV E  */
#line 552 "parse.y"
                                                                                           {(yyval.no) = makeOperatorNode('/',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2417 "y.tab.c"
    break;

  case 95: /* E: E MOD E  */
#line 553 "parse.y"
                                                                                           {(yyval.no) = makeOperatorNode('%',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2423 "y.tab.c"
    break;

  case 96: /* E: '(' E ')'  */
#line 554 "parse.y"
                                                                                   {(yyval.no) = (yyvsp[-1].no);}
#line 2429 "y.tab.c"
    break;

  case 97: /* E: ID '[' E ']'  */
#line 555 "parse.y"
                                                                                   {struct tnode* var=makeVariableNode((yyvsp[-3].c));
													indextypecheck((yyvsp[-1].no)->type->name);
													var->left=(yyvsp[-1].no);
													(yyval.no)=var;}
#line 2438 "y.tab.c"
    break;

  case 98: /* E: ID '[' E ']' '[' E ']'  */
#line 559 "parse.y"
                                                                                {struct tnode* var=makeVariableNode((yyvsp[-6].c));
													indextypecheck((yyvsp[-4].no)->type->name);
													indextypecheck((yyvsp[-1].no)->type->name);
													var->left=(yyvsp[-4].no);    //Row
													var->right=(yyvsp[-1].no);  //Column 
													(yyval.no)=var;}
#line 2449 "y.tab.c"
    break;

  case 99: /* E: NUM  */
#line 565 "parse.y"
                                                                                           {(yyval.no)= makeConstantNode((yyvsp[0].i),NULL);}
#line 2455 "y.tab.c"
    break;

  case 100: /* E: ID  */
#line 566 "parse.y"
                                                                                   {(yyval.no)= makeVariableNode((yyvsp[0].c));}
#line 2461 "y.tab.c"
    break;

  case 101: /* E: NULLPTR  */
#line 567 "parse.y"
                                                          {(yyval.no)= makeConstantNode(-1,NULL);}
#line 2467 "y.tab.c"
    break;

  case 102: /* E: STRING  */
#line 568 "parse.y"
                                                                                   {(yyval.no)= makeConstantNode(-1,(yyvsp[0].c));}
#line 2473 "y.tab.c"
    break;

  case 103: /* E: E COMP E  */
#line 569 "parse.y"
                                                                                   {(yyval.no)= makeComparisonNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 2479 "y.tab.c"
    break;

  case 104: /* E: E AND E  */
#line 570 "parse.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 2485 "y.tab.c"
    break;

  case 105: /* E: E OR E  */
#line 571 "parse.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 2491 "y.tab.c"
    break;

  case 106: /* E: E XOR E  */
#line 572 "parse.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 2497 "y.tab.c"
    break;

  case 107: /* E: NOT E  */
#line 573 "parse.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[0].no),NULL);}
#line 2503 "y.tab.c"
    break;

  case 108: /* E: ID '(' ArglistBlock ')'  */
#line 576 "parse.y"
                                                        {
													struct Gsymbol* gtemp= GLookup((yyvsp[-3].c));
													if(gtemp == NULL){yyerror("Yacc : Undefined function\n");exit(1);}
													//Type checks the return types of each argument with the formal parameters;
													int typecheck=funccallargsvalidate(gtemp,(yyvsp[-1].no),NULL);
													if(typecheck==-1)
													{yyerror("Yacc :invalid argument return type \n");exit(1);}
													(yyval.no) = makeFunctionNode((yyvsp[-3].c),(yyvsp[-1].no),gtemp,NULL,NULL);
												   }
#line 2517 "y.tab.c"
    break;

  case 109: /* E: FIELD  */
#line 586 "parse.y"
                                                           {(yyval.no)=(yyvsp[0].no);}
#line 2523 "y.tab.c"
    break;

  case 110: /* E: FieldFunction  */
#line 587 "parse.y"
                                                       {(yyval.no)=(yyvsp[0].no);}
#line 2529 "y.tab.c"
    break;

  case 111: /* ArglistBlock: ArgList  */
#line 589 "parse.y"
                                                    {(yyval.no)=(yyvsp[0].no);}
#line 2535 "y.tab.c"
    break;

  case 112: /* ArglistBlock: %empty  */
#line 590 "parse.y"
                                                                {(yyval.no)=NULL;}
#line 2541 "y.tab.c"
    break;

  case 113: /* ArgList: ArgList ',' E  */
#line 592 "parse.y"
                                                 {
													struct tnode* temp=(yyvsp[-2].no);
													if(temp==NULL)
														printf("Arg NULL error");
													else
													{
														while(temp->next!=NULL)
															temp=temp->next;
														
														temp->next=(yyvsp[0].no);

													}
													(yyval.no)=(yyvsp[-2].no);   
												   }
#line 2560 "y.tab.c"
    break;

  case 114: /* ArgList: E  */
#line 606 "parse.y"
                                                           {(yyval.no)=(yyvsp[0].no);}
#line 2566 "y.tab.c"
    break;

  case 115: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 610 "parse.y"
                                                                                                                {
															if(flag==0) //NO CLASS AND GDECL BLOCK AND OUTSIDE FUNCTION DEF
															{
																flag=1;
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															fprintf(fptr,"F0:\n");
															//INITIALIZING THE VIRTUAL FUNCTION TABLES OF ALL FUNCTIONS
															if(CHEAD!=NULL)
															{
																printf("USED SPACE:%d\n",used_space);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																//INITIALIZING THE VIRTUAL FUNCTION TABLES OF ALL FUNCTIONS
																initializeallvfts(fptr);    
															}
															///////////////////////////////////////////////////////////
															//Function code generation
															funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-7].c),1);
															//After function code generation
															struct tnode* temp=(yyvsp[-1].no);
															LClear((yyvsp[-6].c));//to clear the symbol table
															
															Freeast((yyvsp[-1].no)->left);//Clear the function body ast
															printf("AST CLEARED\n");
															Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
															freereg_no=-1;
														}
#line 2604 "y.tab.c"
    break;

  case 116: /* MainBlock: INT MAIN '(' ')' '{' Body '}'  */
#line 644 "parse.y"
                                                                                                                {
															if(flag==0) //NO GDECL BLOCK and function definition
															{
																flag=1;
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");    //initiliazes initial value of BP
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															fprintf(fptr,"F0:\n");
															 if(CHEAD!=NULL)
															{
																printf("USED SPACE:%d\n",used_space);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");

																//INITIALIZING THE VIRTUAL FUNCTION TABLES OF ALL FUNCTIONS
																initializeallvfts(fptr);   
															}
															 
															//Function code generation
															funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-6].c),1);
															//After function code generation
															LClear((yyvsp[-5].c));//to clear the symbol table
															Freeast((yyvsp[-1].no)->left);//Clear the function body ast
															Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
															freereg_no=-1;
														}
#line 2639 "y.tab.c"
    break;

  case 119: /* FDefBlock: Type ID '(' FdefParamListBlock ')' '{' LdeclBlock Body '}'  */
#line 680 "parse.y"
                                                                        {    

																		if(flag==0) //first function and no global declaration
																		{   
																			flag=1;
																			
																				
																			fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																			fprintf(fptr,"MOV BP,SP\n");
																			fprintf(fptr,"ADD SP,1\n");    //For return value
																			fprintf(fptr,"CALL F0\n");
																			fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																			fprintf(fptr,"INT 10\n");
																		}

																		int isdefined=validate((yyvsp[-8].c),(yyvsp[-7].c),(yyvsp[-5].param),Cptr); 
																		if(isdefined!=-1)   //if function is defined(either inside class or outside)
																		{
																			int funclabel;

																			if(Cptr==NULL)      //outside class function
																			{ 
																				struct Gsymbol* func=GLookup((yyvsp[-7].c));
																				funclabel=func->flabel;
																			}
																			
																			else                //inside class function
																			{ 
																				struct Memberfunclist* func=MLookup(Cptr,(yyvsp[-7].c));
																				funclabel=func->flabel;
																			}
																				
																		   
																			if(Cptr==NULL)
																				fprintf(fptr,"F%d:\n",funclabel);                                      //Function label 
																			
																			else
																				fprintf(fptr,"C%d:\n",funclabel);                                      //Member Function label
																			

																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-8].c),-1);
																			////////////////////////////////////////////
																			//After function code generation
																			LClear((yyvsp[-7].c));//to clear the symbol table
																			Freeast((yyvsp[-1].no)->left);//Clear the function body ast
																			Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
																			freereg_no=-1;
																			
																			////////////////////////////////////////////
																		}
																		else
																		{
																			printf("Function arguments invalid:\n");
																			LClear((yyvsp[-7].c));//to clear the symbol table and resets the localargs and localvar
																			Freeast((yyvsp[-1].no)->left);//Clear the function body ast
																			Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
																			freereg_no=-1;
																			exit(1);
																		}
																	}
#line 2706 "y.tab.c"
    break;

  case 120: /* FDefBlock: Type ID '(' FdefParamListBlock ')' '{' Body '}'  */
#line 742 "parse.y"
                                                                                 {

																		if(flag==0) //first function and no global declaration
																		{   
																			flag=1;
																		   
																			fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																			fprintf(fptr,"MOV BP,SP\n");
																			fprintf(fptr,"ADD SP,1\n");    //For return value
																			fprintf(fptr,"CALL F0\n");
																			fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																			fprintf(fptr,"INT 10\n");
																		}

																		
																		int isdefined=validate((yyvsp[-7].c),(yyvsp[-6].c),(yyvsp[-4].param),Cptr); 
																		if(isdefined!=-1)   //if function is defined(either inside class or outside)
																		{
																			struct tnode* temp=(yyvsp[-1].no);

																			int funclabel;

																			if(Cptr==NULL)      //outside class function
																			{ 
																				struct Gsymbol* func=GLookup((yyvsp[-6].c));
																				funclabel=func->flabel;
																			}
																			
																			else                //inside class function
																			{ 
																				struct Memberfunclist* func=MLookup(Cptr,(yyvsp[-6].c));
																				funclabel=func->flabel;
																			}

																			if(Cptr==NULL)
																				fprintf(fptr,"F%d:\n",funclabel);                                      //Function label 
																			
																			else
																				fprintf(fptr,"C%d:\n",funclabel);                                      //Member Function label
																			
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-7].c),-1);
																			////////////////////////////////////////////
																			//After function code generation
																			LClear((yyvsp[-6].c));//to clear the symbol table
																			Freeast((yyvsp[-1].no)->left);//Clear the function body ast
																			Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
																			freereg_no=-1;

																			
																			////////////////////////////////////////////
																		}
																		else
																		{
																			printf("Function arguments invalid:\n");
																			LClear((yyvsp[-6].c));//to clear the symbol table and resets the localargs and localvar
																			Freeast((yyvsp[-1].no)->left);//Clear the function body ast
																			Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
																			freereg_no=-1;
																			exit(1);
																		}
																	}
#line 2774 "y.tab.c"
    break;

  case 121: /* FdefParamListBlock: FdefParamList  */
#line 807 "parse.y"
                                            {(yyval.param)=(yyvsp[0].param);}
#line 2780 "y.tab.c"
    break;

  case 122: /* FdefParamListBlock: %empty  */
#line 808 "parse.y"
                                                            {(yyval.param)=NULL;}
#line 2786 "y.tab.c"
    break;

  case 123: /* FdefParamList: FdefParamList ',' FdefParam  */
#line 810 "parse.y"
                                                                                {AppendParamlist((yyvsp[-2].param),(yyvsp[0].param));(yyval.param)=(yyvsp[-2].param);}
#line 2792 "y.tab.c"
    break;

  case 124: /* FdefParamList: FdefParam  */
#line 811 "parse.y"
                                                                                                {(yyval.param)=(yyvsp[0].param);}
#line 2798 "y.tab.c"
    break;

  case 125: /* FdefParam: Type ID  */
#line 812 "parse.y"
                                                                                                    {   
																	if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
																		LInstall("self",NULL,NULL,Cptr);

																	if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
																		LInstall("vft",NULL,NULL,Cptr);
																	
																	struct Parameter* temp=CreateParamlist((yyvsp[-1].c),(yyvsp[0].c));
																	//Create local symbol table
																	//Linstall Adds the arguments and increments num_args
																	LInstall(NULL,NULL,temp,NULL);  
																	(yyval.param)=temp;         
																}
#line 2816 "y.tab.c"
    break;

  case 130: /* LDecl: Type IdList  */
#line 832 "parse.y"
                                              {addltype((yyvsp[-1].c));}
#line 2822 "y.tab.c"
    break;

  case 131: /* IdList: IdList ',' ID  */
#line 834 "parse.y"
                                              {LInstall((yyvsp[0].c),NULL,NULL,NULL);}
#line 2828 "y.tab.c"
    break;

  case 132: /* IdList: ID  */
#line 835 "parse.y"
                                                      {
												if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
													LInstall("self",NULL,NULL,Cptr);
											   
												if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
													LInstall("vft",NULL,NULL,Cptr);

												LInstall((yyvsp[0].c),NULL,NULL,NULL);
											  }
#line 2842 "y.tab.c"
    break;

  case 133: /* Body: BEG Slistblock Retstmt END  */
#line 847 "parse.y"
                                                    {
												if(Cptr!=NULL && LLookup("self")==NULL)   //functions inside class and self has not been defined before
													LInstall("self",NULL,NULL,Cptr);
											   
												if(Cptr!=NULL && LLookup("vft")==NULL)   //functions inside class and self has not been defined before
													LInstall("vft",NULL,NULL,Cptr);

												(yyval.no)=makeConnectorNode('.',(yyvsp[-2].no),(yyvsp[-1].no));
												//printtree($<no>2);
												addlbinding();
												printlst();                                        
											  }
#line 2859 "y.tab.c"
    break;

  case 134: /* Retstmt: RET E ';'  */
#line 859 "parse.y"
                                                {(yyval.no)=(yyvsp[-1].no);}
#line 2865 "y.tab.c"
    break;


#line 2869 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 861 "parse.y"


int yyerror(char const *s)
{
	printf("yyerror %s at line number : %d char : %s\n",s, yylineno, yytext);
	return 0;
}

void indextypecheck(char* type)
{
	if(strcmp(type,"int")!=0)
	{
		printf("Invalid 2D array index\n");
		exit(1);
	}
}

int main(void) 
{
	yyin=fopen("input.txt","r");
	fptr=fopen("input.o","w");

	fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);

	//Initializing the default values in the type table
	TypetableCreate();
	printtypetable();
	yyparse();
	
	return 0;
}
												
												

