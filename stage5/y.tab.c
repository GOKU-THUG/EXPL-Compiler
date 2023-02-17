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
#line 1 "ast.y"

	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	
	#include "symboltable.h"
	#include "symboltable.c"
	
	#include "ast.h"
	#include "ast.c"

	#include "codegen.c"
	

	extern FILE* yyin;
	extern char* yytext;
	FILE* fptr;

	int yylex(void);
	int yyerror();
	void indextypecheck(int type);

#line 94 "y.tab.c"

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
    STRING = 284,                  /* STRING  */
    MOD = 285,                     /* MOD  */
    RET = 286,                     /* RET  */
    MAIN = 287,                    /* MAIN  */
    AND = 288,                     /* AND  */
    OR = 289,                      /* OR  */
    NOT = 290,                     /* NOT  */
    XOR = 291,                     /* XOR  */
    COMP = 292                     /* COMP  */
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
#define STRING 284
#define MOD 285
#define RET 286
#define MAIN 287
#define AND 288
#define OR 289
#define NOT 290
#define XOR 291
#define COMP 292

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "ast.y"

	struct tnode *no;
	struct Gsymbol* symbol;
	struct Parameter* param;
	char* c;
	int i;

#line 229 "y.tab.c"

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
  YYSYMBOL_STRING = 29,                    /* STRING  */
  YYSYMBOL_MOD = 30,                       /* MOD  */
  YYSYMBOL_RET = 31,                       /* RET  */
  YYSYMBOL_MAIN = 32,                      /* MAIN  */
  YYSYMBOL_AND = 33,                       /* AND  */
  YYSYMBOL_OR = 34,                        /* OR  */
  YYSYMBOL_NOT = 35,                       /* NOT  */
  YYSYMBOL_XOR = 36,                       /* XOR  */
  YYSYMBOL_COMP = 37,                      /* COMP  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '{'  */
  YYSYMBOL_44_ = 44,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_Program = 46,                   /* Program  */
  YYSYMBOL_GDeclBlock = 47,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 48,                 /* GDeclList  */
  YYSYMBOL_GDecl = 49,                     /* GDecl  */
  YYSYMBOL_Type = 50,                      /* Type  */
  YYSYMBOL_Gidlist = 51,                   /* Gidlist  */
  YYSYMBOL_Gid = 52,                       /* Gid  */
  YYSYMBOL_ParamList = 53,                 /* ParamList  */
  YYSYMBOL_Param = 54,                     /* Param  */
  YYSYMBOL_Slist = 55,                     /* Slist  */
  YYSYMBOL_Stmt = 56,                      /* Stmt  */
  YYSYMBOL_Ifstmt = 57,                    /* Ifstmt  */
  YYSYMBOL_Whilestmt = 58,                 /* Whilestmt  */
  YYSYMBOL_Dowhilestmt = 59,               /* Dowhilestmt  */
  YYSYMBOL_Repeatuntil = 60,               /* Repeatuntil  */
  YYSYMBOL_InputStmt = 61,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 62,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 63,                   /* AsgStmt  */
  YYSYMBOL_E = 64,                         /* E  */
  YYSYMBOL_ArgList = 65,                   /* ArgList  */
  YYSYMBOL_MainBlock = 66,                 /* MainBlock  */
  YYSYMBOL_FDefList = 67,                  /* FDefList  */
  YYSYMBOL_FDefBlock = 68,                 /* FDefBlock  */
  YYSYMBOL_FdefParamList = 69,             /* FdefParamList  */
  YYSYMBOL_FdefParam = 70,                 /* FdefParam  */
  YYSYMBOL_LdeclBlock = 71,                /* LdeclBlock  */
  YYSYMBOL_LDecList = 72,                  /* LDecList  */
  YYSYMBOL_LDecl = 73,                     /* LDecl  */
  YYSYMBOL_IdList = 74,                    /* IdList  */
  YYSYMBOL_Body = 75,                      /* Body  */
  YYSYMBOL_Retstmt = 76                    /* Retstmt  */
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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   458

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  191

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
      41,    42,     2,     2,    38,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    43,     2,    44,     2,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    43,    43,    44,    45,    47,    57,    66,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    92,    95,   100,   101,   102,   103,   104,   106,
     110,   116,   117,   119,   123,   129,   130,   131,   132,   133,
     134,   135,   139,   145,   146,   147,   148,   149,   150,   151,
     152,   155,   157,   166,   179,   182,   205,   229,   230,   231,
     260,   291,   292,   293,   301,   302,   303,   303,   304,   306,
     307,   309,   314
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
  "BREAK", "CONTINUE", "DECL", "ENDDECL", "INT", "STR", "STRING", "MOD",
  "RET", "MAIN", "AND", "OR", "NOT", "XOR", "COMP", "','", "'['", "']'",
  "'('", "')'", "'{'", "'}'", "$accept", "Program", "GDeclBlock",
  "GDeclList", "GDecl", "Type", "Gidlist", "Gid", "ParamList", "Param",
  "Slist", "Stmt", "Ifstmt", "Whilestmt", "Dowhilestmt", "Repeatuntil",
  "InputStmt", "OutputStmt", "AsgStmt", "E", "ArgList", "MainBlock",
  "FDefList", "FDefBlock", "FdefParamList", "FdefParam", "LdeclBlock",
  "LDecList", "LDecl", "IdList", "Body", "Retstmt", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-81)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -15,    71,     0,    39,    63,   -81,   -81,   -81,   -81,    99,
     -81,    49,    21,   -81,     0,    75,   -81,    63,   -81,   -81,
     -81,   -18,    77,   -81,    61,    76,   -81,   -81,   110,    38,
      49,    86,    85,    90,   -81,   126,   -20,   -81,   -81,     6,
     134,    45,   -81,   104,   -81,    85,   -81,   414,   200,   144,
     100,   -81,    85,   113,   147,   -81,   117,   118,   -10,   121,
     129,   414,   414,   -81,   -81,   314,   -81,   -81,   -81,   -81,
     -81,   -81,   -81,   -81,   -81,   165,   223,   -81,   132,   -81,
     -81,     6,   133,   177,    29,    29,    29,    29,    29,   434,
     354,    29,   -81,   181,   -81,   149,   -81,   -81,   -81,   144,
     155,   -81,    42,    32,   -81,   -81,    29,    29,    98,   281,
     185,   112,   127,   150,   160,   281,   -81,   195,   161,   -81,
      29,   -81,    29,    26,    65,   141,    29,    29,    29,    29,
      29,    29,    29,    29,    29,   -81,    -9,   173,   194,    29,
      29,   -81,   -81,   199,   231,   -81,   281,    51,   -81,     8,
       8,   -81,   -81,   -81,    65,    65,    65,     5,    29,    29,
     414,   414,   156,   170,    72,   175,    29,   -81,   281,   236,
     334,   374,   194,   -81,    29,   -81,    29,   281,   203,   414,
     -81,   -81,   244,   276,    29,   394,   178,   -81,   281,   -81,
     -81
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     0,     4,     6,    10,    11,     0,
       8,     0,     0,     1,    10,     0,     3,     0,    68,     5,
       7,    16,     9,    13,     0,     0,     2,    67,     0,     0,
       0,     0,     0,     0,    18,     0,     0,    20,    12,     0,
       0,     0,    72,    14,    21,     0,    17,     0,     0,     0,
       0,    73,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,    31,    32,     0,    23,    27,    28,    29,
      30,    24,    25,    26,    75,     0,     0,    77,     0,    66,
      71,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,    80,    78,    74,    76,    65,     0,
       0,    15,     0,    54,    53,    55,     0,     0,     0,    42,
       0,     0,     0,     0,     0,    82,    81,     0,     0,    70,
       0,    38,     0,     0,    60,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    41,     0,     0,     0,     0,
       0,    79,    69,     0,     0,    61,    64,     0,    50,    45,
      46,    47,    48,    49,    57,    58,    59,    56,     0,     0,
       0,     0,     0,     0,     0,    51,     0,    62,    43,     0,
       0,     0,    36,    37,     0,    39,     0,    63,     0,     0,
      34,    35,     0,     0,     0,     0,     0,    52,    44,    33,
      40
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   -81,   208,    40,   -81,   193,   -81,   179,
     -60,   -65,   -81,   -81,   -81,   -81,   -81,   -81,   -81,   -80,
     -81,    24,   -81,   213,   -81,   182,   157,   -81,   168,   -81,
     -36,   -81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,     9,    10,    11,    22,    23,    36,    37,
      65,    66,    67,    68,    69,    70,    71,    72,    73,   108,
     147,     5,    17,    18,    41,    42,    49,    76,    77,    95,
      50,    93
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      92,    89,    90,    85,   158,   109,   110,   111,   112,    47,
       1,   115,     2,    78,   126,   127,   128,   129,    45,   128,
     129,    28,    46,    29,    92,    92,   124,   125,    16,    86,
     159,    48,    12,   103,   104,   130,   103,   104,   130,    13,
     143,    26,   144,   146,    15,   100,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   105,    21,    15,   105,   162,
     163,   106,    24,   118,   106,     7,     8,   107,   145,    35,
     107,   122,    40,   123,   126,   127,   128,   129,   168,   169,
      34,   120,    25,    52,   121,    35,   177,    53,    75,   166,
      14,     8,    40,   167,   182,   130,   183,     6,     7,     8,
     170,   171,   134,    31,   188,    92,    92,   126,   127,   128,
     129,   174,     7,     8,   175,    30,    75,    32,    33,   185,
      92,   126,   127,   128,   129,    19,     7,     8,   130,    39,
      43,   131,   132,    44,   133,   134,   126,   127,   128,   129,
     135,    51,   130,    54,    79,   131,   132,    47,   133,   134,
     126,   127,   128,   129,   137,    82,    81,   130,    83,    84,
     131,   132,    87,   133,   134,   126,   127,   128,   129,   138,
      88,   130,    94,   101,   131,   132,    98,   133,   134,   126,
     127,   128,   129,   148,   102,   116,   130,   117,   160,   131,
     132,   139,   133,   134,   126,   127,   128,   129,   172,   119,
     130,   140,   141,   131,   132,   142,   133,   134,   126,   127,
     128,   129,   173,   161,   176,   130,   184,    20,   131,   132,
     190,   133,   134,    38,    55,   136,    74,     7,     8,   130,
      27,     0,   131,   132,    80,   133,   134,     0,    99,   164,
     126,   127,   128,   129,    97,   126,   127,   128,   129,    96,
       7,     8,     0,   126,   127,   128,   129,     0,     0,     0,
       0,   130,     0,     0,   131,   132,   130,   133,   134,   131,
     132,   165,   133,   134,   130,     0,   178,   131,   132,     0,
     133,   134,     0,     0,   186,   126,   127,   128,   129,     0,
     126,   127,   128,   129,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   130,     0,     0,   131,
     132,   130,   133,   134,   131,   132,   187,   133,   134,    56,
      57,    58,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,     0,    63,    64,    56,
      57,    58,     0,     0,     0,    91,     0,     0,    59,     0,
     179,   180,    60,    61,     0,    62,     0,    63,    64,    56,
      57,    58,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,   114,    63,    64,    56,
      57,    58,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,    60,    61,   181,    62,     0,    63,    64,    56,
      57,    58,     0,     0,     0,     0,     0,     0,    59,     0,
       0,   189,    60,    61,     0,    62,     0,    63,    64,    56,
      57,    58,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,    60,    61,     0,    62,     0,    63,    64,    56,
      57,    58,     0,     0,     0,     0,     0,     0,    59,     0,
       0,     0,   113,    61,     0,    62,     0,    63,    64
};

static const yytype_int16 yycheck[] =
{
      65,    61,    62,    13,    13,    85,    86,    87,    88,     3,
      25,    91,    27,    49,     9,    10,    11,    12,    38,    11,
      12,    39,    42,    41,    89,    90,   106,   107,     4,    39,
      39,    25,    32,     7,     8,    30,     7,     8,    30,     0,
     120,    17,   122,   123,     4,    81,   126,   127,   128,   129,
     130,   131,   132,   133,   134,    29,     7,    17,    29,   139,
     140,    35,    41,    99,    35,    27,    28,    41,    42,    29,
      41,    39,    32,    41,     9,    10,    11,    12,   158,   159,
      42,    39,     7,    38,    42,    45,   166,    42,    48,    38,
      27,    28,    52,    42,   174,    30,   176,    26,    27,    28,
     160,   161,    37,    42,   184,   170,   171,     9,    10,    11,
      12,    39,    27,    28,    42,    38,    76,    41,     8,   179,
     185,     9,    10,    11,    12,    26,    27,    28,    30,    43,
      40,    33,    34,     7,    36,    37,     9,    10,    11,    12,
      42,     7,    30,    39,    44,    33,    34,     3,    36,    37,
       9,    10,    11,    12,    42,     8,    43,    30,    41,    41,
      33,    34,    41,    36,    37,     9,    10,    11,    12,    42,
      41,    30,     7,    40,    33,    34,    44,    36,    37,     9,
      10,    11,    12,    42,     7,     4,    30,    38,    15,    33,
      34,    41,    36,    37,     9,    10,    11,    12,    42,    44,
      30,    41,     7,    33,    34,    44,    36,    37,     9,    10,
      11,    12,    42,    19,    39,    30,    13,     9,    33,    34,
      42,    36,    37,    30,    45,    40,    26,    27,    28,    30,
      17,    -1,    33,    34,    52,    36,    37,    -1,    81,    40,
       9,    10,    11,    12,    76,     9,    10,    11,    12,    26,
      27,    28,    -1,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    30,    -1,    -1,    33,    34,    30,    36,    37,    33,
      34,    40,    36,    37,    30,    -1,    40,    33,    34,    -1,
      36,    37,    -1,    -1,    40,     9,    10,    11,    12,    -1,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    30,    -1,    -1,    33,
      34,    30,    36,    37,    33,    34,    40,    36,    37,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    19,    -1,    21,    -1,    23,    24,     5,
       6,     7,    -1,    -1,    -1,    31,    -1,    -1,    14,    -1,
      16,    17,    18,    19,    -1,    21,    -1,    23,    24,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    19,    -1,    21,    22,    23,    24,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    19,    20,    21,    -1,    23,    24,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    17,    18,    19,    -1,    21,    -1,    23,    24,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    19,    -1,    21,    -1,    23,    24,     5,
       6,     7,    -1,    -1,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    -1,    18,    19,    -1,    21,    -1,    23,    24
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    25,    27,    46,    47,    66,    26,    27,    28,    48,
      49,    50,    32,     0,    27,    50,    66,    67,    68,    26,
      49,     7,    51,    52,    41,     7,    66,    68,    39,    41,
      38,    42,    41,     8,    42,    50,    53,    54,    52,    43,
      50,    69,    70,    40,     7,    38,    42,     3,    25,    71,
      75,     7,    38,    42,    39,    54,     5,     6,     7,    14,
      18,    19,    21,    23,    24,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    26,    50,    72,    73,    75,    44,
      70,    43,     8,    41,    41,    13,    39,    41,    41,    55,
      55,    31,    56,    76,     7,    74,    26,    73,    44,    71,
      75,    40,     7,     7,     8,    29,    35,    41,    64,    64,
      64,    64,    64,    18,    22,    64,     4,    38,    75,    44,
      39,    42,    39,    41,    64,    64,     9,    10,    11,    12,
      30,    33,    34,    36,    37,    42,    40,    42,    42,    41,
      41,     7,    44,    64,    64,    42,    64,    65,    42,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    13,    39,
      15,    19,    64,    64,    40,    40,    38,    42,    64,    64,
      55,    55,    42,    42,    39,    42,    39,    64,    40,    16,
      17,    20,    64,    64,    13,    55,    40,    40,    64,    17,
      42
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    46,    46,    47,    47,    48,    48,    49,
      50,    50,    51,    51,    52,    52,    52,    52,    52,    53,
      53,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    58,    59,    60,    61,    61,
      61,    62,    63,    63,    63,    64,    64,    64,    64,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      64,    64,    64,    65,    65,    66,    66,    67,    67,    68,
      68,    69,    69,    70,    71,    71,    72,    72,    73,    74,
      74,    75,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     2,
       1,     1,     3,     1,     4,     7,     1,     4,     3,     3,
       1,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     9,     7,     7,     6,     6,     4,     7,
      10,     4,     3,     6,     9,     3,     3,     3,     3,     3,
       3,     4,     7,     1,     1,     1,     3,     3,     3,     3,
       2,     3,     4,     3,     1,     8,     7,     2,     1,     9,
       8,     3,     1,     2,     3,     2,     2,     1,     2,     3,
       1,     4,     2
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
  case 2: /* Program: GDeclBlock FDefList MainBlock  */
#line 43 "ast.y"
                                                   {exit(1);}
#line 1460 "y.tab.c"
    break;

  case 3: /* Program: GDeclBlock MainBlock  */
#line 44 "ast.y"
                                                            {exit(1);}
#line 1466 "y.tab.c"
    break;

  case 4: /* Program: MainBlock  */
#line 45 "ast.y"
                                                            {exit(1);}
#line 1472 "y.tab.c"
    break;

  case 5: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 47 "ast.y"
                                                    {  
														//printgst();
														fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
														fprintf(fptr,"MOV SP,%d\n",4095+used_space);
														fprintf(fptr,"MOV BP,SP\n");
														fprintf(fptr,"ADD SP,1\n");    //For return value
														fprintf(fptr,"CALL F0\n");
														fprintf(fptr,"SUB SP,1\n");     //Popping the return value
														fprintf(fptr,"INT 10\n");
													}
#line 1487 "y.tab.c"
    break;

  case 6: /* GDeclBlock: DECL ENDDECL  */
#line 57 "ast.y"
                                                                {  
														fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
														fprintf(fptr,"MOV SP,%d\n",4095+used_space);
														fprintf(fptr,"MOV BP,SP\n");
														fprintf(fptr,"ADD SP,1\n");    //For return value
														fprintf(fptr,"CALL F0\n");
														fprintf(fptr,"SUB SP,1\n");     //Popping the return value
														fprintf(fptr,"INT 10\n");
													}
#line 1501 "y.tab.c"
    break;

  case 9: /* GDecl: Type Gidlist  */
#line 67 "ast.y"
                                                    {addgtype((yyvsp[-1].i));}
#line 1507 "y.tab.c"
    break;

  case 10: /* Type: INT  */
#line 68 "ast.y"
                                                    {(yyval.i)=Integer;}
#line 1513 "y.tab.c"
    break;

  case 11: /* Type: STR  */
#line 69 "ast.y"
                                                        {(yyval.i)=String;}
#line 1519 "y.tab.c"
    break;

  case 14: /* Gid: ID '[' NUM ']'  */
#line 72 "ast.y"
                                                    {GInstall((yyvsp[-3].c),-1,(yyvsp[-1].i),-1,-1,NULL);}
#line 1525 "y.tab.c"
    break;

  case 15: /* Gid: ID '[' NUM ']' '[' NUM ']'  */
#line 73 "ast.y"
                                                            {GInstall((yyvsp[-6].c),-1,(yyvsp[-4].i)*(yyvsp[-1].i),(yyvsp[-4].i),(yyvsp[-1].i),NULL);}
#line 1531 "y.tab.c"
    break;

  case 16: /* Gid: ID  */
#line 74 "ast.y"
                                                            {GInstall((yyvsp[0].c),-1,1,-1,-1,NULL);}
#line 1537 "y.tab.c"
    break;

  case 17: /* Gid: ID '(' ParamList ')'  */
#line 75 "ast.y"
                                                                        {GInstall((yyvsp[-3].c),-1,-1,-1,-1,(yyvsp[-1].param));}
#line 1543 "y.tab.c"
    break;

  case 18: /* Gid: ID '(' ')'  */
#line 76 "ast.y"
                                                                                        {GInstall((yyvsp[-2].c),-1,-1,-1,-1,NULL);}
#line 1549 "y.tab.c"
    break;

  case 19: /* ParamList: ParamList ',' Param  */
#line 77 "ast.y"
                                                                {AppendParamlist((yyvsp[-2].param),(yyvsp[0].param));(yyval.param)=(yyvsp[-2].param);}
#line 1555 "y.tab.c"
    break;

  case 20: /* ParamList: Param  */
#line 78 "ast.y"
                                                                                {(yyval.param)=(yyvsp[0].param);}
#line 1561 "y.tab.c"
    break;

  case 21: /* Param: Type ID  */
#line 79 "ast.y"
                                                                                        {(yyval.param)=CreateParamlist((yyvsp[-1].i),(yyvsp[0].c));}
#line 1567 "y.tab.c"
    break;

  case 22: /* Slist: Slist Stmt  */
#line 81 "ast.y"
                                                    {(yyval.no)=makeConnectorNode('.',(yyvsp[-1].no),(yyvsp[0].no));}
#line 1573 "y.tab.c"
    break;

  case 23: /* Slist: Stmt  */
#line 82 "ast.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1579 "y.tab.c"
    break;

  case 24: /* Stmt: InputStmt  */
#line 83 "ast.y"
                                                    {(yyval.no)=(yyvsp[0].no);}
#line 1585 "y.tab.c"
    break;

  case 25: /* Stmt: OutputStmt  */
#line 84 "ast.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1591 "y.tab.c"
    break;

  case 26: /* Stmt: AsgStmt  */
#line 85 "ast.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1597 "y.tab.c"
    break;

  case 27: /* Stmt: Ifstmt  */
#line 86 "ast.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1603 "y.tab.c"
    break;

  case 28: /* Stmt: Whilestmt  */
#line 87 "ast.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1609 "y.tab.c"
    break;

  case 29: /* Stmt: Dowhilestmt  */
#line 88 "ast.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1615 "y.tab.c"
    break;

  case 30: /* Stmt: Repeatuntil  */
#line 89 "ast.y"
                                                        {(yyval.no)=(yyvsp[0].no);}
#line 1621 "y.tab.c"
    break;

  case 31: /* Stmt: BREAK  */
#line 90 "ast.y"
                                                        {char c[6]="break";
													(yyval.no)=makeBreak_ContinueNode(c);}
#line 1628 "y.tab.c"
    break;

  case 32: /* Stmt: CONTINUE  */
#line 92 "ast.y"
                                                        {char c[9]="continue";
													(yyval.no)=makeBreak_ContinueNode(c);}
#line 1635 "y.tab.c"
    break;

  case 33: /* Ifstmt: IF '(' E ')' Then Slist Else Slist ENDIF  */
#line 95 "ast.y"
                                                   {struct tnode* else_node;
													struct tnode* connector_node;
													else_node=makeBranchingNode("Else",(yyvsp[-1].no),NULL);
													connector_node=makeConnectorNode('.',(yyvsp[-3].no),else_node);
													(yyval.no)=makeBranchingNode("If",(yyvsp[-6].no),connector_node);}
#line 1645 "y.tab.c"
    break;

  case 34: /* Ifstmt: IF '(' E ')' Then Slist ENDIF  */
#line 100 "ast.y"
                                                           {(yyval.no)=makeBranchingNode("If",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1651 "y.tab.c"
    break;

  case 35: /* Whilestmt: WHILE '(' E ')' DO Slist ENDWHILE  */
#line 101 "ast.y"
                                                   {(yyval.no)=makeBranchingNode("While",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1657 "y.tab.c"
    break;

  case 36: /* Dowhilestmt: DO Slist WHILE '(' E ')'  */
#line 102 "ast.y"
                                                   {(yyval.no)=makeBranchingNode("Do",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1663 "y.tab.c"
    break;

  case 37: /* Repeatuntil: REPEAT Slist UNTIL '(' E ')'  */
#line 103 "ast.y"
                                                   {(yyval.no)=makeBranchingNode("Repeat",(yyvsp[-4].no),(yyvsp[-1].no));}
#line 1669 "y.tab.c"
    break;

  case 38: /* InputStmt: READ '(' ID ')'  */
#line 104 "ast.y"
                                                   {struct tnode* var=makeVariableNode((yyvsp[-1].c));
													(yyval.no)=makereadnode(var);}
#line 1676 "y.tab.c"
    break;

  case 39: /* InputStmt: READ '(' ID '[' E ']' ')'  */
#line 106 "ast.y"
                                                           {struct tnode* var=makeVariableNode((yyvsp[-4].c));
													indextypecheck((yyvsp[-2].no)->type);
													var->left=(yyvsp[-2].no);
													(yyval.no)=makereadnode(var);}
#line 1685 "y.tab.c"
    break;

  case 40: /* InputStmt: READ '(' ID '[' E ']' '[' E ']' ')'  */
#line 110 "ast.y"
                                                               {struct tnode* var=makeVariableNode((yyvsp[-7].c));
													indextypecheck((yyvsp[-5].no)->type);
													indextypecheck((yyvsp[-2].no)->type);
													var->left=(yyvsp[-5].no);    //Row
													var->right=(yyvsp[-2].no);  //Column
													(yyval.no)=makereadnode(var);}
#line 1696 "y.tab.c"
    break;

  case 41: /* OutputStmt: WRITE '(' E ')'  */
#line 116 "ast.y"
                                                                   {(yyval.no)=makewritenode((yyvsp[-1].no));}
#line 1702 "y.tab.c"
    break;

  case 42: /* AsgStmt: ID EQUAL E  */
#line 117 "ast.y"
                                                                           {struct tnode* var=makeVariableNode((yyvsp[-2].c));
													(yyval.no) = makeOperatorNode('=',var,(yyvsp[0].no));}
#line 1709 "y.tab.c"
    break;

  case 43: /* AsgStmt: ID '[' E ']' EQUAL E  */
#line 119 "ast.y"
                                                                           {struct tnode* var=makeVariableNode((yyvsp[-5].c));
													indextypecheck((yyvsp[-3].no)->type);
													var->left=(yyvsp[-3].no);
													(yyval.no) = makeOperatorNode('=',var,(yyvsp[0].no));}
#line 1718 "y.tab.c"
    break;

  case 44: /* AsgStmt: ID '[' E ']' '[' E ']' EQUAL E  */
#line 123 "ast.y"
                                                                   {struct tnode* var=makeVariableNode((yyvsp[-8].c));
													indextypecheck((yyvsp[-6].no)->type);
													indextypecheck((yyvsp[-3].no)->type);
													var->left=(yyvsp[-6].no);    //Row
													var->right=(yyvsp[-3].no);  //Column
													(yyval.no)=makeOperatorNode('=',var,(yyvsp[0].no));}
#line 1729 "y.tab.c"
    break;

  case 45: /* E: E PLUS E  */
#line 129 "ast.y"
                                                                                   {(yyval.no) = makeOperatorNode('+',(yyvsp[-2].no),(yyvsp[0].no));}
#line 1735 "y.tab.c"
    break;

  case 46: /* E: E MINUS E  */
#line 130 "ast.y"
                                                                                   {(yyval.no) = makeOperatorNode('-',(yyvsp[-2].no),(yyvsp[0].no));}
#line 1741 "y.tab.c"
    break;

  case 47: /* E: E MUL E  */
#line 131 "ast.y"
                                                                                           {(yyval.no) = makeOperatorNode('*',(yyvsp[-2].no),(yyvsp[0].no));}
#line 1747 "y.tab.c"
    break;

  case 48: /* E: E DIV E  */
#line 132 "ast.y"
                                                                                           {(yyval.no) = makeOperatorNode('/',(yyvsp[-2].no),(yyvsp[0].no));}
#line 1753 "y.tab.c"
    break;

  case 49: /* E: E MOD E  */
#line 133 "ast.y"
                                                                                           {(yyval.no) = makeOperatorNode('%',(yyvsp[-2].no),(yyvsp[0].no));}
#line 1759 "y.tab.c"
    break;

  case 50: /* E: '(' E ')'  */
#line 134 "ast.y"
                                                                                   {(yyval.no) = (yyvsp[-1].no);}
#line 1765 "y.tab.c"
    break;

  case 51: /* E: ID '[' E ']'  */
#line 135 "ast.y"
                                                                                   {struct tnode* var=makeVariableNode((yyvsp[-3].c));
													indextypecheck((yyvsp[-1].no)->type);
													var->left=(yyvsp[-1].no);
													(yyval.no)=var;}
#line 1774 "y.tab.c"
    break;

  case 52: /* E: ID '[' E ']' '[' E ']'  */
#line 139 "ast.y"
                                                                                {struct tnode* var=makeVariableNode((yyvsp[-6].c));
													indextypecheck((yyvsp[-4].no)->type);
													indextypecheck((yyvsp[-1].no)->type);
													var->left=(yyvsp[-4].no);    //Row
													var->right=(yyvsp[-1].no);  //Column 
													(yyval.no)=var;}
#line 1785 "y.tab.c"
    break;

  case 53: /* E: NUM  */
#line 145 "ast.y"
                                                                                           {(yyval.no)= makeConstantNode((yyvsp[0].i),NULL);}
#line 1791 "y.tab.c"
    break;

  case 54: /* E: ID  */
#line 146 "ast.y"
                                                                                   {(yyval.no)= makeVariableNode((yyvsp[0].c));}
#line 1797 "y.tab.c"
    break;

  case 55: /* E: STRING  */
#line 147 "ast.y"
                                                                                   {(yyval.no)= makeConstantNode(-1,(yyvsp[0].c));}
#line 1803 "y.tab.c"
    break;

  case 56: /* E: E COMP E  */
#line 148 "ast.y"
                                                                                   {(yyval.no)= makeComparisonNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 1809 "y.tab.c"
    break;

  case 57: /* E: E AND E  */
#line 149 "ast.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 1815 "y.tab.c"
    break;

  case 58: /* E: E OR E  */
#line 150 "ast.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 1821 "y.tab.c"
    break;

  case 59: /* E: E XOR E  */
#line 151 "ast.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[-2].no),(yyvsp[0].no));}
#line 1827 "y.tab.c"
    break;

  case 60: /* E: NOT E  */
#line 152 "ast.y"
                                                       {(yyval.no)= makeLogicalNode((yyvsp[-1].c),(yyvsp[0].no),NULL);}
#line 1833 "y.tab.c"
    break;

  case 61: /* E: ID '(' ')'  */
#line 155 "ast.y"
                                                       {struct Gsymbol* gtemp = GLookup((yyvsp[-2].c));
													if(gtemp == NULL){yyerror("Yacc : Undefined function");exit(1);}}
#line 1840 "y.tab.c"
    break;

  case 62: /* E: ID '(' ArgList ')'  */
#line 157 "ast.y"
                                                       {
													struct Gsymbol* gtemp= GLookup((yyvsp[-3].c));
													if(gtemp == NULL){yyerror("Yacc : Undefined function\n");exit(1);}
													//Type checks the return types;
													int typecheck=funccallargsvalidate(gtemp,(yyvsp[-1].no));
													if(typecheck==-1)
													{yyerror("Yacc :invalid argument return type \n");exit(1);}
													(yyval.no) = makeFunctionNode((yyvsp[-3].c),(yyvsp[-1].no),gtemp);
						                           }
#line 1854 "y.tab.c"
    break;

  case 63: /* ArgList: ArgList ',' E  */
#line 166 "ast.y"
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
#line 1872 "y.tab.c"
    break;

  case 64: /* ArgList: E  */
#line 179 "ast.y"
                                                           {(yyval.no)=(yyvsp[0].no);}
#line 1878 "y.tab.c"
    break;

  case 65: /* MainBlock: INT MAIN '(' ')' '{' LdeclBlock Body '}'  */
#line 183 "ast.y"
                                                                                                                {
															if(GHEAD==NULL) //NO GDECL BLOCK
															{
																fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															//printlst();
															fprintf(fptr,"F0:\n");
															//Function code generation
															funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,Integer);
															//After function code generation
															LClear((yyvsp[-6].c));//to clear the symbol table
															Freeast((yyvsp[-1].no)->left);//Clear the function body ast
															printf("AST CLEARED\n");
															Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
															freereg_no=-1;
														}
#line 1905 "y.tab.c"
    break;

  case 66: /* MainBlock: INT MAIN '(' ')' '{' Body '}'  */
#line 206 "ast.y"
                                                                                                                {
															if(GHEAD==NULL) //NO GDECL BLOCK
															{
																fprintf(fptr, "%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nBRKP\n",0,2056,0,0,0,0,0,0);
																fprintf(fptr,"MOV SP,%d\n",4095+used_space);
																fprintf(fptr,"MOV BP,SP\n");
																fprintf(fptr,"ADD SP,1\n");    //For return value
																fprintf(fptr,"CALL F0\n");
																fprintf(fptr,"SUB SP,1\n");     //Popping the return value
																fprintf(fptr,"INT 10\n");
															}
															//printlst();
															fprintf(fptr,"F0:\n");
															//Function code generation
															funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,Integer);
															//After function code generation
															LClear((yyvsp[-5].c));//to clear the symbol table
															Freeast((yyvsp[-1].no)->left);//Clear the function body ast
															Freeast((yyvsp[-1].no)->right);//Clear the return expr ast
															freereg_no=-1;
														}
#line 1931 "y.tab.c"
    break;

  case 69: /* FDefBlock: Type ID '(' FdefParamList ')' '{' LdeclBlock Body '}'  */
#line 231 "ast.y"
                                                                   {    int isdefined=validate((yyvsp[-8].i),(yyvsp[-7].c),(yyvsp[-5].param)); 
																		if(isdefined!=-1)   //if function is defined
																		{
																			//printlst();
																			
																			struct Gsymbol* func=GLookup((yyvsp[-7].c));
																			int funclabel=func->flabel;
																			fprintf(fptr,"F%d:\n",funclabel);                                      //Function label
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-8].i));
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
#line 1965 "y.tab.c"
    break;

  case 70: /* FDefBlock: Type ID '(' FdefParamList ')' '{' Body '}'  */
#line 260 "ast.y"
                                                                            {
																		int isdefined=validate((yyvsp[-7].i),(yyvsp[-6].c),(yyvsp[-4].param)); 
																		if(isdefined!=-1)   //if function is defined
																		{
																			//printlst();
																			
																			struct Gsymbol* func=GLookup((yyvsp[-6].c));
																			int funclabel=func->flabel;
																			fprintf(fptr,"F%d:\n",funclabel);                                      //Function label
																			////////////////////////////////////////////
																			//Function code generation
																			funccode(fptr,(yyvsp[-1].no)->left,(yyvsp[-1].no)->right,(yyvsp[-7].i));
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
#line 2000 "y.tab.c"
    break;

  case 71: /* FdefParamList: FdefParamList ',' FdefParam  */
#line 291 "ast.y"
                                                                                {AppendParamlist((yyvsp[-2].param),(yyvsp[0].param));(yyval.param)=(yyvsp[-2].param);}
#line 2006 "y.tab.c"
    break;

  case 72: /* FdefParamList: FdefParam  */
#line 292 "ast.y"
                                                                                                {(yyval.param)=(yyvsp[0].param);}
#line 2012 "y.tab.c"
    break;

  case 73: /* FdefParam: Type ID  */
#line 293 "ast.y"
                                                                                                    {   
																	struct Parameter* temp=CreateParamlist((yyvsp[-1].i),(yyvsp[0].c));
																	//Create local symbol table
																	//Linstall Adds the arguments and increments num_args
																	LInstall(NULL,-1,temp);  
																	(yyval.param)=temp;         
																}
#line 2024 "y.tab.c"
    break;

  case 78: /* LDecl: Type IdList  */
#line 304 "ast.y"
                                              {addltype((yyvsp[-1].i));}
#line 2030 "y.tab.c"
    break;

  case 79: /* IdList: IdList ',' ID  */
#line 306 "ast.y"
                                              {LInstall((yyvsp[0].c),-1,NULL);}
#line 2036 "y.tab.c"
    break;

  case 80: /* IdList: ID  */
#line 307 "ast.y"
                                                      {LInstall((yyvsp[0].c),-1,NULL);}
#line 2042 "y.tab.c"
    break;

  case 81: /* Body: BEG Slist Retstmt END  */
#line 309 "ast.y"
                                               {(yyval.no)=makeConnectorNode('.',(yyvsp[-2].no),(yyvsp[-1].no));
												//printtree($<no>2);
												addlbinding();
											 	//printlst();
											  }
#line 2052 "y.tab.c"
    break;

  case 82: /* Retstmt: RET E  */
#line 314 "ast.y"
                                               {(yyval.no)=(yyvsp[0].no);}
#line 2058 "y.tab.c"
    break;


#line 2062 "y.tab.c"

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

#line 316 "ast.y"


int yyerror(char const *s)
{
	printf("yyerror %s",s);
	return 0;
}

void indextypecheck(int type)
{
	if(type!=Integer)
	{
		printf("Invalid 2D array index\n");
		exit(1);
	}
}

int main(void) 
{
	yyin=fopen("ast.txt","r");
	fptr=fopen("ast.o","w");

	yyparse();
	
	return 0;
}
												
												

