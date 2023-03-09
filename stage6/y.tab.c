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

	//Symbol table
	#include "symboltable.h"
	#include "symboltable.c"
	
	//AST CREATION
	#include "ast.h"
	#include "ast.c"

	//CODEGENERATION
    #include "codegen.h"
	#include "codegen.c"
	
	extern FILE* yyin;
	extern char* yytext;
	FILE* fptr;
    int flag=0;

	int yylex(void);
	int yyerror();
	void indextypecheck(char* type);

#line 102 "y.tab.c"

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

#line 252 "y.tab.c"

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
  YYSYMBOL_COMP = 44,                      /* COMP  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* '['  */
  YYSYMBOL_49_ = 49,                       /* ']'  */
  YYSYMBOL_50_ = 50,                       /* '('  */
  YYSYMBOL_51_ = 51,                       /* ')'  */
  YYSYMBOL_52_ = 52,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 53,                  /* $accept  */
  YYSYMBOL_Program = 54,                   /* Program  */
  YYSYMBOL_TypeDefBlock = 55,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 56,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 57,                   /* TypeDef  */
  YYSYMBOL_FieldDeclList = 58,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 59,                 /* FieldDecl  */
  YYSYMBOL_GDeclBlock = 60,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 61,                 /* GDeclList  */
  YYSYMBOL_GDecl = 62,                     /* GDecl  */
  YYSYMBOL_Type = 63,                      /* Type  */
  YYSYMBOL_Gidlist = 64,                   /* Gidlist  */
  YYSYMBOL_Gid = 65,                       /* Gid  */
  YYSYMBOL_ParamList = 66,                 /* ParamList  */
  YYSYMBOL_Param = 67,                     /* Param  */
  YYSYMBOL_Slist = 68,                     /* Slist  */
  YYSYMBOL_Stmt = 69,                      /* Stmt  */
  YYSYMBOL_Ifstmt = 70,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 71,                 /* Whilestmt  */
  YYSYMBOL_Dowhilestmt = 72,               /* Dowhilestmt  */
  YYSYMBOL_Repeatuntil = 73,               /* Repeatuntil  */
  YYSYMBOL_InputStmt = 74,                 /* InputStmt  */
  YYSYMBOL_FreeStmt = 75,                  /* FreeStmt  */
  YYSYMBOL_OutputStmt = 76,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 77,                   /* AsgStmt  */
  YYSYMBOL_FIELD = 78,                     /* FIELD  */
  YYSYMBOL_E = 79,                         /* E  */
  YYSYMBOL_ArgList = 80,                   /* ArgList  */
  YYSYMBOL_MainBlock = 81,                 /* MainBlock  */
  YYSYMBOL_FDefList = 82,                  /* FDefList  */
  YYSYMBOL_FDefBlock = 83,                 /* FDefBlock  */
  YYSYMBOL_FdefParamList = 84,             /* FdefParamList  */
  YYSYMBOL_FdefParam = 85,                 /* FdefParam  */
  YYSYMBOL_LdeclBlock = 86,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 87,                  /* LDecList  */
  YYSYMBOL_LDecl = 88,                     /* LDecl  */
  YYSYMBOL_IdList = 89,                    /* IdList  */
  YYSYMBOL_Body = 90,                      /* Body  */
  YYSYMBOL_Retstmt = 91                    /* Retstmt  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   589

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  106
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      50,    51,     2,     2,    47,     2,    52,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    48,     2,    49,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    53,    53,    54,    56,    57,    60,    61,    64,    96,
      97,   100,   102,   112,   113,   115,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   132,   133,   134,   136,   137,   138,   139,   140,
     141,   142,   143,   144,   146,   149,   154,   155,   156,   157,
     159,   161,   165,   171,   174,   178,   181,   183,   185,   189,
     195,   196,   201,   205,   210,   217,   225,   240,   241,   242,
     243,   244,   245,   246,   250,   256,   257,   258,   259,   260,
     261,   262,   263,   264,   267,   269,   279,   280,   293,   296,
     318,   342,   343,   345,   389,   440,   441,   442,   452,   453,
     454,   454,   455,   457,   458,   462,   468
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
  "INITIALIZE", "ALLOC", "FREE", "NULLPTR", "COMP", "'{'", "'}'", "','",
  "'['", "']'", "'('", "')'", "'.'", "$accept", "Program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "FieldDeclList", "FieldDecl", "GDeclBlock",
  "GDeclList", "GDecl", "Type", "Gidlist", "Gid", "ParamList", "Param",
  "Slist", "Stmt", "Ifstmt", "Whilestmt", "Dowhilestmt", "Repeatuntil",
  "InputStmt", "FreeStmt", "OutputStmt", "AsgStmt", "FIELD", "E",
  "ArgList", "MainBlock", "FDefList", "FDefBlock", "FdefParamList",
  "FdefParam", "LdeclBlock", "LDecList", "LDecl", "IdList", "Body",
  "Retstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -36,     2,    15,    10,   -19,     1,   -83,   -83,    88,   163,
     266,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   139,   -83,
      35,    18,    60,   -83,   163,   -83,    25,   -83,    77,   -83,
     -83,    62,    26,   -83,    46,    50,   -83,   -83,   -83,   -83,
     -83,   105,    -4,    35,    54,   266,    70,   -83,   113,   -29,
     -83,   -83,    79,   115,    34,   -83,    83,   -83,   266,   -83,
      11,   -83,   266,    93,   126,   -83,   526,   193,   141,   108,
     -83,    11,   107,   112,   119,    14,   123,   125,   526,   526,
     -83,   -83,   131,   444,   -83,   -83,   -83,   -83,   -83,   -83,
     -83,   -83,   -83,    -2,   -83,   151,   230,   -83,   136,   -83,
     141,   140,   -83,   181,   153,    68,   153,   188,   153,   153,
     546,   466,   190,   153,   -83,   195,   144,   202,   -83,   165,
     -83,   -83,   -83,   164,   -83,    17,    76,    22,   -83,   -83,
     153,   -83,   153,   171,   167,   174,   175,   545,   278,   -83,
     196,   204,   176,   178,    89,   120,   545,   -83,   179,   182,
     545,   -83,   210,   -83,   153,   -83,   -83,   153,    13,   337,
     233,   153,   153,   153,   153,   153,   153,   153,   153,   153,
     -83,   183,   185,    -9,   231,   235,   153,   153,   -83,   -83,
     198,   209,   -83,   307,   323,   -83,   545,    52,   -83,    66,
      66,   -83,   -83,   -83,   337,   337,   337,    49,   -83,   -83,
     153,   153,   526,   526,   241,   270,   -83,   -83,   -41,   213,
     153,   -83,   545,   352,   419,   486,   235,   -83,   153,   -83,
     153,   545,   249,   526,   -83,   -83,   368,   397,   153,   506,
     212,   -83,   545,   -83,   -83
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     0,    14,     0,     0,     7,     1,     0,     0,
       0,     4,     6,    21,    13,    18,    19,    20,     0,    16,
       0,    18,     0,     3,     0,    92,     0,    10,     0,    12,
      15,    26,    17,    23,     0,     0,     2,    91,     8,     9,
      11,     0,     0,     0,     0,     0,     0,    28,     0,     0,
      30,    22,     0,     0,     0,    96,    24,    31,     0,    27,
       0,    97,     0,     0,     0,    29,    34,     0,     0,     0,
      95,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      43,    44,     0,     0,    33,    38,    39,    40,    41,    35,
      42,    36,    37,     0,    99,     0,     0,   101,     0,    90,
       0,     0,    25,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    32,     0,     0,     0,   104,   102,
      98,   100,    89,     0,    94,     0,     0,    76,    75,    78,
       0,    77,     0,    86,     0,     0,     0,    57,     0,    65,
       0,     0,     0,     0,     0,     0,   106,   105,     0,     0,
      60,    66,     0,    93,     0,    50,    53,     0,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      56,     0,     0,     0,     0,     0,     0,     0,    54,    55,
       0,     0,   103,     0,     0,    84,    88,     0,    72,    67,
      68,    69,    70,    71,    80,    81,    82,    79,    63,    61,
       0,     0,    34,    34,     0,     0,    64,    62,     0,    73,
       0,    85,    58,     0,     0,     0,    48,    49,     0,    51,
       0,    87,     0,    34,    46,    47,     0,     0,     0,     0,
       0,    74,    59,    45,    52
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,   -83,   260,   -83,   240,   -83,   -83,   251,
      97,   -83,   228,   -83,   216,   -73,   -82,   -83,   -83,   -83,
     -83,   -83,   -83,   -83,   -83,   -66,   -75,   -83,   259,   -83,
     262,   -83,   229,   225,   -83,   201,   -83,   -52,   -83
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     5,     6,    26,    27,     9,    18,    19,
      20,    32,    33,    49,    50,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,   133,   134,   187,    23,    24,
      25,    54,    55,    68,    96,    97,   119,    69,   115
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      93,   114,     1,    13,   200,   110,   111,   218,     4,     4,
     219,   116,    93,    93,    66,     7,    98,    93,    58,   101,
     127,   128,    59,    15,    16,    17,    10,   105,   114,   114,
     137,   138,    13,   140,   141,     8,    67,   126,   146,   201,
      11,   150,    31,   129,    93,    93,   145,    47,   123,   130,
     117,    34,    15,    16,    17,   159,   131,   160,   161,   162,
     163,   164,   106,   132,   185,   154,   107,    35,   155,   107,
     157,    38,   158,    43,   107,   127,   128,   163,   164,   183,
     165,    62,   184,   186,    40,    63,   189,   190,   191,   192,
     193,   194,   195,   196,   197,    13,    44,   165,   129,   210,
      45,   204,   205,   211,   130,    52,    22,    28,   135,   136,
      41,   131,    42,    46,    14,    15,    16,    17,   132,    56,
      57,    22,    61,    28,    60,   212,   213,   156,   117,   214,
     215,    64,   114,   114,    72,   221,    93,    93,    71,    48,
     178,   107,    53,   226,    66,   227,    13,   114,    93,    93,
     229,   127,   128,   232,    99,    48,   102,    93,   118,    53,
     127,   128,   103,    93,    95,    29,    15,    16,    17,   104,
      13,   179,   117,   108,   129,   109,   161,   162,   163,   164,
     130,   112,   122,   129,   148,   149,   124,   131,   125,   130,
      21,    16,    17,    95,   132,   139,   131,   144,   165,   147,
      13,   166,   167,   132,   168,   161,   162,   163,   164,   151,
     153,   169,   152,   161,   162,   163,   164,   182,   170,    94,
      15,    16,    17,   117,   171,   172,   176,   165,   177,   180,
     166,   167,   181,   168,   198,   165,   199,    13,   166,   167,
     169,   168,   161,   162,   163,   164,   202,   174,   169,   206,
     161,   162,   163,   164,   203,   175,   120,    15,    16,    17,
     207,   220,   228,   234,   165,    12,    39,   166,   167,    30,
     168,    51,   165,    13,    65,   166,   167,   169,   168,   161,
     162,   163,   164,    36,   188,   169,    37,   161,   162,   163,
     164,    70,   216,    15,    16,    17,   100,   121,     0,     0,
       0,   165,     0,     0,   166,   167,     0,   168,     0,   165,
       0,     0,   166,   167,   169,   168,   161,   162,   163,   164,
       0,   217,   169,     0,     0,     0,     0,   173,     0,     0,
       0,     0,   161,   162,   163,   164,     0,     0,   165,     0,
       0,   166,   167,     0,   168,     0,   161,   162,   163,   164,
       0,   169,     0,     0,   165,     0,   208,   166,   167,     0,
     168,   161,   162,   163,   164,     0,     0,   169,   165,     0,
       0,     0,   209,     0,     0,     0,     0,   161,   162,   163,
     164,   169,     0,   165,     0,     0,   166,   167,     0,   168,
       0,     0,     0,     0,     0,     0,   169,     0,     0,   165,
       0,   222,   166,   167,     0,   168,   161,   162,   163,   164,
       0,     0,   169,     0,     0,     0,     0,   230,     0,     0,
       0,     0,     0,     0,    73,    74,    75,     0,   165,     0,
       0,   166,   167,    76,   168,   223,   224,    77,    78,     0,
      79,   169,    80,    81,     0,     0,   231,     0,     0,    73,
      74,    75,     0,     0,     0,     0,     0,     0,    76,     0,
       0,    82,    77,    78,     0,    79,     0,    80,    81,     0,
       0,    73,    74,    75,     0,     0,   113,     0,     0,     0,
      76,     0,     0,     0,    77,    78,    82,    79,   143,    80,
      81,    73,    74,    75,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,    77,    78,   225,    79,    82,    80,
      81,    73,    74,    75,     0,     0,     0,     0,     0,     0,
      76,     0,     0,   233,    77,    78,     0,    79,    82,    80,
      81,    73,    74,    75,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,    77,    78,     0,    79,    82,    80,
      81,    73,    74,    75,   161,   162,   163,   164,     0,     0,
      76,     0,     0,     0,   142,    78,     0,    79,    82,    80,
      81,     0,     0,     0,     0,     0,   165,     0,     0,   166,
     167,     0,   168,     0,     0,     0,     0,     0,    82,   169
};

static const yytype_int16 yycheck[] =
{
      66,    83,    38,     7,    13,    78,    79,    48,     7,     7,
      51,    13,    78,    79,     3,     0,    68,    83,    47,    71,
       7,     8,    51,    27,    28,    29,    45,    13,   110,   111,
     105,   106,     7,   108,   109,    25,    25,   103,   113,    48,
      39,   116,     7,    30,   110,   111,   112,    51,   100,    36,
      52,    33,    27,    28,    29,   130,    43,   132,     9,    10,
      11,    12,    48,    50,    51,    48,    52,     7,    51,    52,
      48,    46,    50,    47,    52,     7,     8,    11,    12,   154,
      31,    47,   157,   158,     7,    51,   161,   162,   163,   164,
     165,   166,   167,   168,   169,     7,    50,    31,    30,    47,
      50,   176,   177,    51,    36,    51,     9,    10,    40,    41,
      48,    43,    50,     8,    26,    27,    28,    29,    50,    49,
       7,    24,     7,    26,    45,   200,   201,    51,    52,   202,
     203,    48,   214,   215,     8,   210,   202,   203,    45,    42,
      51,    52,    45,   218,     3,   220,     7,   229,   214,   215,
     223,     7,     8,   228,    46,    58,    49,   223,     7,    62,
       7,     8,    50,   229,    67,    26,    27,    28,    29,    50,
       7,    51,    52,    50,    30,    50,     9,    10,    11,    12,
      36,    50,    46,    30,    40,    41,    46,    43,     7,    36,
      27,    28,    29,    96,    50,     7,    43,     7,    31,     4,
       7,    34,    35,    50,    37,     9,    10,    11,    12,     7,
      46,    44,    47,     9,    10,    11,    12,     7,    51,    26,
      27,    28,    29,    52,    50,    50,    50,    31,    50,    50,
      34,    35,    50,    37,    51,    31,    51,     7,    34,    35,
      44,    37,     9,    10,    11,    12,    15,    51,    44,    51,
       9,    10,    11,    12,    19,    51,    26,    27,    28,    29,
      51,    48,    13,    51,    31,     5,    26,    34,    35,    18,
      37,    43,    31,     7,    58,    34,    35,    44,    37,     9,
      10,    11,    12,    24,    51,    44,    24,     9,    10,    11,
      12,    62,    51,    27,    28,    29,    71,    96,    -1,    -1,
      -1,    31,    -1,    -1,    34,    35,    -1,    37,    -1,    31,
      -1,    -1,    34,    35,    44,    37,     9,    10,    11,    12,
      -1,    51,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,     9,    10,    11,    12,    -1,    -1,    31,    -1,
      -1,    34,    35,    -1,    37,    -1,     9,    10,    11,    12,
      -1,    44,    -1,    -1,    31,    -1,    49,    34,    35,    -1,
      37,     9,    10,    11,    12,    -1,    -1,    44,    31,    -1,
      -1,    -1,    49,    -1,    -1,    -1,    -1,     9,    10,    11,
      12,    44,    -1,    31,    -1,    -1,    34,    35,    -1,    37,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    31,
      -1,    49,    34,    35,    -1,    37,     9,    10,    11,    12,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    49,    -1,    -1,
      -1,    -1,    -1,    -1,     5,     6,     7,    -1,    31,    -1,
      -1,    34,    35,    14,    37,    16,    17,    18,    19,    -1,
      21,    44,    23,    24,    -1,    -1,    49,    -1,    -1,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    42,    18,    19,    -1,    21,    -1,    23,    24,    -1,
      -1,     5,     6,     7,    -1,    -1,    32,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    18,    19,    42,    21,    22,    23,
      24,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    18,    19,    20,    21,    42,    23,
      24,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    17,    18,    19,    -1,    21,    42,    23,
      24,     5,     6,     7,    -1,    -1,    -1,    -1,    -1,    -1,
      14,    -1,    -1,    -1,    18,    19,    -1,    21,    42,    23,
      24,     5,     6,     7,     9,    10,    11,    12,    -1,    -1,
      14,    -1,    -1,    -1,    18,    19,    -1,    21,    42,    23,
      24,    -1,    -1,    -1,    -1,    -1,    31,    -1,    -1,    34,
      35,    -1,    37,    -1,    -1,    -1,    -1,    -1,    42,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    54,    55,     7,    56,    57,     0,    25,    60,
      45,    39,    57,     7,    26,    27,    28,    29,    61,    62,
      63,    27,    63,    81,    82,    83,    58,    59,    63,    26,
      62,     7,    64,    65,    33,     7,    81,    83,    46,    59,
       7,    48,    50,    47,    50,    50,     8,    51,    63,    66,
      67,    65,    51,    63,    84,    85,    49,     7,    47,    51,
      45,     7,    47,    51,    48,    67,     3,    25,    86,    90,
      85,    45,     8,     5,     6,     7,    14,    18,    19,    21,
      23,    24,    42,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    26,    63,    87,    88,    90,    46,
      86,    90,    49,    50,    50,    13,    48,    52,    50,    50,
      68,    68,    50,    32,    69,    91,    13,    52,     7,    89,
      26,    88,    46,    90,    46,     7,    78,     7,     8,    30,
      36,    43,    50,    78,    79,    40,    41,    79,    79,     7,
      79,    79,    18,    22,     7,    78,    79,     4,    40,    41,
      79,     7,    47,    46,    48,    51,    51,    48,    50,    79,
      79,     9,    10,    11,    12,    31,    34,    35,    37,    44,
      51,    50,    50,    49,    51,    51,    50,    50,    51,    51,
      50,    50,     7,    79,    79,    51,    79,    80,    51,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    51,    51,
      13,    48,    15,    19,    79,    79,    51,    51,    49,    49,
      47,    51,    79,    79,    68,    68,    51,    51,    48,    51,
      48,    79,    49,    16,    17,    20,    79,    79,    13,    68,
      49,    49,    79,    17,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    53,    54,    54,    55,    55,    56,    56,    57,    58,
      58,    59,    60,    60,    60,    61,    61,    62,    63,    63,
      63,    63,    64,    64,    65,    65,    65,    65,    65,    66,
      66,    67,    68,    68,    68,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    69,    70,    70,    71,    72,    73,
      74,    74,    74,    74,    75,    75,    76,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    80,    80,    81,
      81,    82,    82,    83,    83,    84,    84,    85,    86,    86,
      87,    87,    88,    89,    89,    90,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     3,     0,     2,     1,     4,     2,
       1,     2,     3,     2,     0,     2,     1,     2,     1,     1,
       1,     1,     3,     1,     4,     7,     1,     4,     3,     3,
       1,     2,     2,     1,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     9,     7,     7,     6,     6,
       4,     7,    10,     4,     4,     4,     4,     3,     6,     9,
       3,     5,     5,     5,     5,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     7,     1,     1,     1,     1,     3,
       3,     3,     3,     2,     3,     4,     1,     3,     1,     8,
       7,     2,     1,     9,     8,     3,     1,     2,     3,     2,
       2,     1,     2,     3,     1,     4,     2
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
  case 2: /* Program: TypeDefBlock GDeclBlock FDefList MainBlock  */
#line 53 "parse.y"
                                                                {exit(1);}
#line 1545 "y.tab.c"
    break;

  case 3: /* Program: TypeDefBlock GDeclBlock MainBlock  */
#line 54 "parse.y"
                                                        {exit(1);}
#line 1551 "y.tab.c"
    break;

  case 6: /* TypeDefList: TypeDefList TypeDef  */
#line 60 "parse.y"
                                            {printtypetable();}
#line 1557 "y.tab.c"
    break;

  case 7: /* TypeDefList: TypeDef  */
#line 61 "parse.y"
                                                        {printtypetable();}
#line 1563 "y.tab.c"
    break;

  case 8: /* TypeDef: ID '{' FieldDeclList '}'  */
#line 64 "parse.y"
                                           { 
                                                //Flags error if the number of member fields is 9 or more
                                                if(fieldindex>=9)   //only 7 members because the first index of every block is used for storing the next free block
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
#line 1598 "y.tab.c"
    break;

  case 9: /* FieldDeclList: FieldDeclList FieldDecl  */
#line 96 "parse.y"
                                            {Fappend((yyvsp[-1].field),(yyvsp[0].field));(yyval.field)=(yyvsp[-1].field);}
#line 1604 "y.tab.c"
    break;

  case 10: /* FieldDeclList: FieldDecl  */
#line 97 "parse.y"
                                                        {(yyval.field)=(yyvsp[0].field);}
#line 1610 "y.tab.c"
    break;

  case 11: /* FieldDecl: Type ID  */
#line 100 "parse.y"
                        {(yyval.field)=Fcreate((yyvsp[0].c),(yyvsp[-1].c));}
#line 1616 "y.tab.c"
    break;

  case 12: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 102 "parse.y"
                                                    {  
														printgst();
														fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
														fprintf(fptr,"MOV SP,%d\n",4095+used_space);
														fprintf(fptr,"MOV BP,SP\n");
														fprintf(fptr,"ADD SP,1\n");    //For return value
														fprintf(fptr,"CALL F0\n");
														fprintf(fptr,"SUB SP,1\n");     //Popping the return value
														fprintf(fptr,"INT 10\n");
													}
#line 1631 "y.tab.c"
    break;

  case 13: /* GDeclBlock: DECL ENDDECL  */
#line 112 "parse.y"
                                                                {}
#line 1637 "y.tab.c"
    break;

  case 14: /* GDeclBlock: %empty  */
#line 113 "parse.y"
                                                                {}
#line 1643 "y.tab.c"
    break;

  case 17: /* GDecl: Type Gidlist  */
#line 116 "parse.y"
                                                    {addgtype((yyvsp[-1].c));}
#line 1649 "y.tab.c"
    break;

  case 18: /* Type: INT  */
#line 117 "parse.y"
                                                    {(yyval.c)=(yyvsp[0].c);}
#line 1655 "y.tab.c"
    break;

  case 19: /* Type: STR  */
#line 118 "parse.y"
                                                        {(yyval.c)=(yyvsp[0].c);}
#line 1661 "y.tab.c"
    break;

  case 20: /* Type: VOID  */
#line 119 "parse.y"
                                                                                                {(yyval.c)=(yyvsp[0].c);}
#line 1667 "y.tab.c"
    break;

  case 21: /* Type: ID  */
#line 120 "parse.y"
                                                                                                {(yyval.c)=(yyvsp[0].c);}
#line 1673 "y.tab.c"
    break;

  case 24: /* Gid: ID '[' NUM ']'  */
#line 123 "parse.y"
                                                    {GInstall((yyvsp[-3].c),NULL,(yyvsp[-1].i),-1,-1,NULL);}
#line 1679 "y.tab.c"
    break;

  case 25: /* Gid: ID '[' NUM ']' '[' NUM ']'  */
#line 124 "parse.y"
                                                            {GInstall((yyvsp[-6].c),NULL,(yyvsp[-4].i)*(yyvsp[-1].i),(yyvsp[-4].i),(yyvsp[-1].i),NULL);}
#line 1685 "y.tab.c"
    break;

  case 26: /* Gid: ID  */
#line 125 "parse.y"
                                                            {GInstall((yyvsp[0].c),NULL,1,-1,-1,NULL);}
#line 1691 "y.tab.c"
    break;

  case 27: /* Gid: ID '(' ParamList ')'  */
#line 126 "parse.y"
                                                                        {GInstall((yyvsp[-3].c),NULL,-1,-1,-1,(yyvsp[-1].param));}
#line 1697 "y.tab.c"
    break;

  case 28: /* Gid: ID '(' ')'  */
#line 127 "parse.y"
                                                                                        {GInstall((yyvsp[-2].c),NULL,-1,-1,-1,NULL);}
#line 1703 "y.tab.c"
    break;

  case 29: /* ParamList: ParamList ',' Param  */
#line 128 "parse.y"
                                                                {AppendParamlist((yyvsp[-2].param),(yyvsp[0].param));(yyval.param)=(yyvsp[-2].param);}
#line 1709 "y.tab.c"
    break;

  case 30: /* ParamList: Param  */
#line 129 "parse.y"
                                                                                {(yyval.param)=(yyvsp[0].param);}
#line 1715 "y.tab.c"
    break;

  case 31: /* Param: Type ID  */
#line 130 "parse.y"
                                                                                        {(yyval.param)=CreateParamlist((yyvsp[-1].c),(yyvsp[0].c));}
#line 1721 "y.tab.c"
    break;

  case 32: /* Slist: Slist Stmt  */
#line 132 "parse.y"
                                                    {(yyval.no)=makeConnectorNode('.',(yyvsp[-1].no),(yyvsp[0].no));}
#line 1727 "y.tab.c"
    break;

  case 33: /* Slist: Stmt  */
#line 133 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1733 "y.tab.c"
    break;

  case 34: /* Slist: %empty  */
#line 134 "parse.y"
                                                        {}
#line 1739 "y.tab.c"
    break;

  case 35: /* Stmt: InputStmt  */
#line 136 "parse.y"
                                                    {(yyval.no)=(yyvsp[0].no);}
#line 1745 "y.tab.c"
    break;

  case 36: /* Stmt: OutputStmt  */
#line 137 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1751 "y.tab.c"
    break;

  case 37: /* Stmt: AsgStmt  */
#line 138 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1757 "y.tab.c"
    break;

  case 38: /* Stmt: Ifstmt  */
#line 139 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1763 "y.tab.c"
    break;

  case 39: /* Stmt: Whilestmt  */
#line 140 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1769 "y.tab.c"
    break;

  case 40: /* Stmt: Dowhilestmt  */
#line 141 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1775 "y.tab.c"
    break;

  case 41: /* Stmt: Repeatuntil  */
#line 142 "parse.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1781 "y.tab.c"
    break;

  case 42: /* Stmt: FreeStmt  */
#line 143 "parse.y"
                                                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1787 "y.tab.c"
    break;

  case 43: /* Stmt: BREAK  */
#line 144 "parse.y"
                                                        {char c[6]="break";
													(yyval.no)=makeBreak_ContinueNode(c);}
#line 1794 "y.tab.c"
    break;

  case 44: /* Stmt: CONTINUE  */
#line 146 "parse.y"
                                                        {char c[9]="continue";
													(yyval.no)=makeBreak_ContinueNode(c);}
#line 1801 "y.tab.c"
    break;

  case 45: /* Ifstmt: IF '(' E ')' Then Slist Else Slist ENDIF  */
#line 149 "parse.y"
                                                   {struct tnode* else_node;
													struct tnode* connector_node;
													else_node=makeBranchingNode("Else",(yyvsp[-1].no),NULL);
													connector_node=makeConnectorNode('.',(yyvsp[-3].no),else_node);
													(yyval.no)=makeBranchingNode("If",(yyvsp[-6].no),connector_node);}
#line 1811 "y.tab.c"
    break;

  case 46: /* Ifstmt: IF '(' E ')' Then Slist ENDIF  */
#line 154 "parse.y"
                                                           {(yyval.no)=makeBranchingNode("If",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1817 "y.tab.c"
    break;

  case 47: /* Whilestmt: WHILE '(' E ')' DO Slist ENDWHILE  */
#line 155 "parse.y"
                                                   {(yyval.no)=makeBranchingNode("While",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1823 "y.tab.c"
    break;

  case 48: /* Dowhilestmt: DO Slist WHILE '(' E ')'  */
#line 156 "parse.y"
                                                   {(yyval.no)=makeBranchingNode("Do",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1829 "y.tab.c"
    break;

  case 49: /* Repeatuntil: REPEAT Slist UNTIL '(' E ')'  */
#line 157 "parse.y"
                                                   {(yyval.no)=makeBranchingNode("Repeat",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1835 "y.tab.c"
    break;

  case 50: /* InputStmt: READ '(' ID ')'  */
#line 159 "parse.y"
                                                   {struct tnode* var=makeVariableNode((yyvsp[-1].c));
													(yyval.no)=makereadnode(var);}
#line 1842 "y.tab.c"
    break;

  case 51: /* InputStmt: READ '(' ID '[' E ']' ')'  */
#line 161 "parse.y"
                                                           {struct tnode* var=makeVariableNode((yyvsp[-4].c));
													indextypecheck((yyvsp[-2].no)->type->name);
													var->left=(yyvsp[-2].no);
													(yyval.no)=makereadnode(var);}
#line 1851 "y.tab.c"
    break;

  case 52: /* InputStmt: READ '(' ID '[' E ']' '[' E ']' ')'  */
#line 165 "parse.y"
                                                               {struct tnode* var=makeVariableNode((yyvsp[-7].c));
													indextypecheck((yyvsp[-5].no)->type->name);
													indextypecheck((yyvsp[-2].no)->type->name);
													var->left=(yyvsp[-5].no);    //Row
													var->right=(yyvsp[-2].no);  //Column
													(yyval.no)=makereadnode(var);}
#line 1862 "y.tab.c"
    break;

  case 53: /* InputStmt: READ '(' FIELD ')'  */
#line 171 "parse.y"
                                                                {(yyval.no)=makereadnode((yyvsp[-1].no));}
#line 1868 "y.tab.c"
    break;

  case 54: /* FreeStmt: FREE '(' ID ')'  */
#line 174 "parse.y"
                                                    {
                                                        struct tnode* var=makeVariableNode((yyvsp[-1].c));
												        (yyval.no)==dynamicmemorynode(var->type,Free,var,NULL);
                                                    }
#line 1877 "y.tab.c"
    break;

  case 55: /* FreeStmt: FREE '(' FIELD ')'  */
#line 178 "parse.y"
                                                    { (yyval.no)==dynamicmemorynode((yyvsp[-1].no)->type,Free,(yyvsp[-1].no),NULL);}
#line 1883 "y.tab.c"
    break;

  case 56: /* OutputStmt: WRITE '(' E ')'  */
#line 181 "parse.y"
                                                                   {(yyval.no)=makewritenode((yyvsp[-1].no));}
#line 1889 "y.tab.c"
    break;

  case 57: /* AsgStmt: ID EQUAL E  */
#line 183 "parse.y"
                                                                           {struct tnode* var=makeVariableNode((yyvsp[-2].c));
													(yyval.no) = makeOperatorNode('=',var,(yyvsp[0].no));}
#line 1896 "y.tab.c"
    break;

  case 58: /* AsgStmt: ID '[' E ']' EQUAL E  */
#line 185 "parse.y"
                                                                           {struct tnode* var=makeVariableNode((yyvsp[-5].c));
													indextypecheck((yyvsp[-3].no)->type->name);
													var->left=(yyvsp[-3].no);
													(yyval.no) = makeOperatorNode('=',var,(yyvsp[0].no));}
#line 1905 "y.tab.c"
    break;

  case 59: /* AsgStmt: ID '[' E ']' '[' E ']' EQUAL E  */
#line 189 "parse.y"
                                                                   {struct tnode* var=makeVariableNode((yyvsp[-8].c));
													indextypecheck((yyvsp[-6].no)->type->name);
													indextypecheck((yyvsp[-3].no)->type->name);
													var->left=(yyvsp[-6].no);    //Row
													var->right=(yyvsp[-3].no);  //Column
													(yyval.no)=makeOperatorNode('=',var,(yyvsp[0].no));}
#line 1916 "y.tab.c"
    break;

  case 60: /* AsgStmt: FIELD EQUAL E  */
#line 195 "parse.y"
                                                {(yyval.no) = makeOperatorNode('=',(yyvsp[-2].no),(yyvsp[0].no));}
#line 1922 "y.tab.c"
    break;

  case 61: /* AsgStmt: ID EQUAL ALLOC '(' ')'  */
#line 196 "parse.y"
                                                        { 
												 struct tnode* var=makeVariableNode((yyvsp[-4].c));
												 struct tnode* allocnode=dynamicmemorynode(var->type,Alloc,NULL,NULL);
												 (yyval.no)=makeOperatorNode('=',var,allocnode);
												}
#line 1932 "y.tab.c"
    break;

  case 62: /* AsgStmt: FIELD EQUAL ALLOC '(' ')'  */
#line 201 "parse.y"
                                                                {
													struct tnode* allocnode=dynamicmemorynode((yyvsp[-4].no)->type,Alloc,NULL,NULL);
													(yyval.no)=makeOperatorNode('=',(yyvsp[-4].no),allocnode);
												}
#line 1941 "y.tab.c"
    break;

  case 63: /* AsgStmt: ID EQUAL INITIALIZE '(' ')'  */
#line 205 "parse.y"
                                                { 
												 struct tnode* var=makeVariableNode((yyvsp[-4].c));
												 struct tnode* initializenode=dynamicmemorynode(var->type,Initialize,NULL,NULL);
												 (yyval.no)=makeOperatorNode('=',var,initializenode);
												}
#line 1951 "y.tab.c"
    break;

  case 64: /* AsgStmt: FIELD EQUAL INITIALIZE '(' ')'  */
#line 210 "parse.y"
                                                        {
													struct tnode* initializenode=dynamicmemorynode((yyvsp[-4].no)->type,Initialize,NULL,NULL);
													(yyval.no)=makeOperatorNode('=',(yyvsp[-4].no),initializenode);
												}
#line 1960 "y.tab.c"
    break;

  case 65: /* FIELD: ID '.' ID  */
#line 217 "parse.y"
                                                                        {	
                                                    //printf("%s,%s",$<c>1,$<c>3);
													struct tnode* var=makeVariableNode((yyvsp[-2].c));	
													struct tnode* field=makefieldnode((yyvsp[0].c),var->type);
													var->left=field;
													var->type=field->type;
													(yyval.no)=var;
												}
#line 1973 "y.tab.c"
    break;

  case 66: /* FIELD: FIELD '.' ID  */
#line 225 "parse.y"
                                                                                {
														struct tnode* var=(yyvsp[-2].no);
														struct tnode* field=makefieldnode((yyvsp[0].c),var->type);
														
														struct tnode* iterfield=var->left;

		  												while(iterfield->next!=NULL)
															iterfield=iterfield->next;
														
														iterfield->next=field;
														var->type=field->type;
														(yyval.no)=var;
		  											}
#line 1991 "y.tab.c"
    break;

  case 67: /* E: E PLUS E  */
#line 240 "parse.y"
                                                                                   {(yyval.no) = makeOperatorNode('+',(yyvsp[-2].no),(yyvsp[0].no));}
#line 1997 "y.tab.c"
    break;

  case 68: /* E: E MINUS E  */
#line 241 "parse.y"
                                                                                   {(yyval.no) = makeOperatorNode('-',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2003 "y.tab.c"
    break;

  case 69: /* E: E MUL E  */
#line 242 "parse.y"
                                                                                           {(yyval.no) = makeOperatorNode('*',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2009 "y.tab.c"
    break;

  case 70: /* E: E DIV E  */
#line 243 "parse.y"
                                                                                           {(yyval.no) = makeOperatorNode('/',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2015 "y.tab.c"
    break;

  case 71: /* E: E MOD E  */
#line 244 "parse.y"
                                                                                           {(yyval.no) = makeOperatorNode('%',(yyvsp[-2].no),(yyvsp[0].no));}
#line 2021 "y.tab.c"
    break;

  case 72: /* E: '(' E ')'  */
#line 245 "parse.y"
                                                                                   {(yyval.no) = (yyvsp[-1].no);}
#line 2027 "y.tab.c"
    break;

  case 73: /* E: ID '[' E ']'  */
#line 246 "parse.y"
                                                                                   {struct tnode* var=makeVariableNode((yyvsp[-3].c));
													indextypecheck((yyvsp[-1].no)->type->name);
													var->left=(yyvsp[-1].no);
													(yyval.no)=var;}
#line 2036 "y.tab.c"
    break;

  case 74: /* E: ID '[' E ']' '[' E ']'  */
#line 250 "parse.y"
                                                                                {struct tnode* var=makeVariableNode((yyvsp[-6].c));
													indextypecheck((yyvsp[-4].no)->type->name);
													indextypecheck((yyvsp[-1].no)->type->name);
													var->left=(yyvsp[-4].no);    //Row
													var->right=(yyvsp[-1].no);  //Column 
													(yyval.no)=var;}
#line 2047 "y.tab.c"
    break;

  case 75: /* E: NUM  */
#line 256 "parse.y"
                                                                                           {(yyval.no)= makeConstantNode((yyvsp[0].i),NULL);}
#line 2053 "y.tab.c"
    break;

  case 76: /* E: ID  */
#line 257 "parse.y"
                                                                                   {(yyval.no)= makeVariableNode((yyvsp[0].c));}
#line 2059 "y.tab.c"
    break;

  case 77: /* E: NULLPTR  */
#line 258 "parse.y"
                                                      {(yyval.no)= makeConstantNode(-1,NULL);}
#line 2065 "y.tab.c"
    break;

  case 78: /* E: STRING  */
#line 259 "parse.y"
                                                                                   {(yyval.no)= makeConstantNode(-1,(yyvsp[0].c));}
#line 2071 "y.tab.c"
    break;

  case 79: /* E: E COMP E  */
#line 260 "parse.y"
                                                                                   {(yyval.no)= makeComparisonNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 2077 "y.tab.c"
    break;

  case 80: /* E: E AND E  */
#line 261 "parse.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 2083 "y.tab.c"
    break;

  case 81: /* E: E OR E  */
#line 262 "parse.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 2089 "y.tab.c"
    break;

  case 82: /* E: E XOR E  */
#line 263 "parse.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 2095 "y.tab.c"
    break;

  case 83: /* E: NOT E  */
#line 264 "parse.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[0].no),NULL);}
#line 2101 "y.tab.c"
    break;

  case 84: /* E: ID '(' ')'  */
#line 267 "parse.y"
                                                       {struct Gsymbol* gtemp = GLookup((yyvsp[-2].c));
													if(gtemp == NULL){yyerror("Yacc : Undefined function");exit(1);}}
#line 2108 "y.tab.c"
    break;

  case 85: /* E: ID '(' ArgList ')'  */
#line 269 "parse.y"
                                                       {
													struct Gsymbol* gtemp= GLookup((yyvsp[-3].c));
													if(gtemp == NULL){yyerror("Yacc : Undefined function\n");exit(1);}
													//Type checks the return types of each argument with the formal parameters;
													int typecheck=funccallargsvalidate(gtemp,(yyvsp[-1].no));
													if(typecheck==-1)
													{yyerror("Yacc :invalid argument return type \n");exit(1);}
													(yyval.no) = makeFunctionNode((yyvsp[-3].c),(yyvsp[-1].no),gtemp);
												   }
#line 2122 "y.tab.c"
    break;

  case 86: /* E: FIELD  */
#line 279 "parse.y"
                                                           {(yyval.no)=(yyvsp[0].no);}
#line 2128 "y.tab.c"
    break;

  case 87: /* ArgList: ArgList ',' E  */
#line 280 "parse.y"
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
#line 2146 "y.tab.c"
    break;

  case 88: /* ArgList: E  */
#line 293 "parse.y"
                                                           {(yyval.no)=(yyvsp[0].no);}
#line 2152 "y.tab.c"
    break;

  case 89: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 297 "parse.y"
                                                                                                                {
															if(GHEAD==NULL && flag==0) //NO GDECL BLOCK
															{
																fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															fprintf(fptr,"F0:\n");
															//Function code generation
															funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-7].c));
															//After function code generation
															LClear((yyvsp[-6].c));//to clear the symbol table
															Freeast((yyvsp[-1].no)->left);//Clear the function body ast
															printf("AST CLEARED\n");
															Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
															freereg_no=-1;
														}
#line 2178 "y.tab.c"
    break;

  case 90: /* MainBlock: INT MAIN '(' ')' '{' Body '}'  */
#line 319 "parse.y"
                                                                                                                {
															if(GHEAD==NULL && flag==0) //NO GDECL BLOCK and function definition
															{
																fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															fprintf(fptr,"F0:\n");
															//Function code generation
															funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-6].c));
															//After function code generation
															LClear((yyvsp[-5].c));//to clear the symbol table
															Freeast((yyvsp[-1].no)->left);//Clear the function body ast
															Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
															freereg_no=-1;
														}
#line 2203 "y.tab.c"
    break;

  case 93: /* FDefBlock: Type ID '(' FdefParamList ')' '{' LdeclBlock Body '}'  */
#line 345 "parse.y"
                                                                   {    

                                                                        if(GHEAD==NULL && flag==0) //first function and no global declaration
                                                                        {   
                                                                            flag=1;

                                                                            fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
                                                                            fprintf(fptr,"MOV SP,%d\n",4095+used_space);
                                                                            fprintf(fptr,"MOV BP,SP\n");
                                                                            fprintf(fptr,"ADD SP,1\n");    //For return value
                                                                            fprintf(fptr,"CALL F0\n");
                                                                            fprintf(fptr,"SUB SP,1\n");     //Popping the return value
                                                                            fprintf(fptr,"INT 10\n");
                                                                        }

                                                                        int isdefined=validate((yyvsp[-8].c),(yyvsp[-7].c),(yyvsp[-5].param)); 
																		if(isdefined!=-1)   //if function is defined
																		{
																			
																			struct Gsymbol* func=GLookup((yyvsp[-7].c));
																			int funclabel=func->flabel;
																			fprintf(fptr,"F%d:\n",funclabel);                                      //Function label
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-8].c));
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
																			LClear((yyvsp[-7].c));//to clear the symbol table and resets the localargs and localvar
																			Freeast((yyvsp[-1].no)->left);//Clear the function body ast
																			Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
																			freereg_no=-1;
																			printf("Function arguments invalid:\n");
																			exit(1);
																		}
																	}
#line 2252 "y.tab.c"
    break;

  case 94: /* FDefBlock: Type ID '(' FdefParamList ')' '{' Body '}'  */
#line 389 "parse.y"
                                                                            {

                                                                        if(GHEAD==NULL && flag==0) //first function and no global declaration
                                                                        {   
                                                                            flag=1;
                                                                           
                                                                            fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
                                                                            fprintf(fptr,"MOV SP,%d\n",4095+used_space);
                                                                            fprintf(fptr,"MOV BP,SP\n");
                                                                            fprintf(fptr,"ADD SP,1\n");    //For return value
                                                                            fprintf(fptr,"CALL F0\n");
                                                                            fprintf(fptr,"SUB SP,1\n");     //Popping the return value
                                                                            fprintf(fptr,"INT 10\n");
                                                                        }

																		int isdefined=validate((yyvsp[-7].c),(yyvsp[-6].c),(yyvsp[-4].param)); 
																		if(isdefined!=-1)   //if function is defined
																		{
																			struct tnode* temp=(yyvsp[-1].no);

																			struct Gsymbol* func=GLookup((yyvsp[-6].c));
																			int funclabel=func->flabel;
																			fprintf(fptr,"F%d:\n",funclabel);                                      //Function label
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-7].c));
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
																			LClear((yyvsp[-6].c));//to clear the symbol table and resets the localargs and localvar
																			Freeast((yyvsp[-1].no)->left);//Clear the function body ast
																			Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
																			freereg_no=-1;
																			printf("Function arguments invalid:\n");
																			exit(1);
																		}
																	}
#line 2305 "y.tab.c"
    break;

  case 95: /* FdefParamList: FdefParamList ',' FdefParam  */
#line 440 "parse.y"
                                                                                {AppendParamlist((yyvsp[-2].param),(yyvsp[0].param));(yyval.param)=(yyvsp[-2].param);}
#line 2311 "y.tab.c"
    break;

  case 96: /* FdefParamList: FdefParam  */
#line 441 "parse.y"
                                                                                                {(yyval.param)=(yyvsp[0].param);}
#line 2317 "y.tab.c"
    break;

  case 97: /* FdefParam: Type ID  */
#line 442 "parse.y"
                                                                                                    {   
																	struct Parameter* temp=CreateParamlist((yyvsp[-1].c),(yyvsp[0].c));
																	//Create local symbol table
																	//Linstall Adds the arguments and increments num_args
																	LInstall(NULL,NULL,temp);  
																	(yyval.param)=temp;         
																}
#line 2329 "y.tab.c"
    break;

  case 102: /* LDecl: Type IdList  */
#line 455 "parse.y"
                                              {addltype((yyvsp[-1].c));}
#line 2335 "y.tab.c"
    break;

  case 103: /* IdList: IdList ',' ID  */
#line 457 "parse.y"
                                              {LInstall((yyvsp[0].c),NULL,NULL);}
#line 2341 "y.tab.c"
    break;

  case 104: /* IdList: ID  */
#line 458 "parse.y"
                                                      {LInstall((yyvsp[0].c),NULL,NULL);}
#line 2347 "y.tab.c"
    break;

  case 105: /* Body: BEG Slist Retstmt END  */
#line 462 "parse.y"
                                               {(yyval.no)=makeConnectorNode('.',(yyvsp[-2].no),(yyvsp[-1].no));
												//printtree($<no>2);
												addlbinding();
                                                printlst();
                                                
                                              }
#line 2358 "y.tab.c"
    break;

  case 106: /* Retstmt: RET E  */
#line 468 "parse.y"
                                               {(yyval.no)=(yyvsp[0].no);}
#line 2364 "y.tab.c"
    break;


#line 2368 "y.tab.c"

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

#line 470 "parse.y"


int yyerror(char const *s)
{
	printf("yyerror %s",s);
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

	//Initializing the default values in the type table
	TypetableCreate();
	printtypetable();
	yyparse();
	
	return 0;
}
												
												

