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
#line 1 "codel-syn.y"

#include <stdio.h>
#include <stdlib.h>
#include "symbol_table.h"
// extern NODE *yyroot;
SymbolTable* symbolTable;
#define EXIT_FAILURE 1
char* storedID;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
extern int yylineno;
// forloop counter
// Helper function to get the size of the array
int arr_size(char** arr) {
    int size = 0;
    while (arr[size] != NULL) {
        size++;
    }
    return size;
}
void checkCounterID(char* id) {
    if (strcmp(id, storedID) != 0) {
        fprintf(stderr, "Semantic error: Counter ID '%s' does not match loop head ID '%s'\n", id, storedID);
    }
}
void yyerror(const char* msg) {
    fprintf(stderr, "Error at line %d: %s\n", yylineno, msg);
    exit(EXIT_FAILURE);
}

#line 104 "codel-syn.tab.c"

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

#include "codel-syn.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BEGIN = 3,                      /* BEGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_CONST = 5,                      /* CONST  */
  YYSYMBOL_TRUE = 6,                       /* TRUE  */
  YYSYMBOL_FALSE = 7,                      /* FALSE  */
  YYSYMBOL_BOOL = 8,                       /* BOOL  */
  YYSYMBOL_INT = 9,                        /* INT  */
  YYSYMBOL_FLOAT = 10,                     /* FLOAT  */
  YYSYMBOL_PLUS = 11,                      /* PLUS  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_MULT = 13,                      /* MULT  */
  YYSYMBOL_DIV = 14,                       /* DIV  */
  YYSYMBOL_LESS = 15,                      /* LESS  */
  YYSYMBOL_GREATER = 16,                   /* GREATER  */
  YYSYMBOL_NOTEQUAL = 17,                  /* NOTEQUAL  */
  YYSYMBOL_LESSEQ = 18,                    /* LESSEQ  */
  YYSYMBOL_GREATEQ = 19,                   /* GREATEQ  */
  YYSYMBOL_EQUAL = 20,                     /* EQUAL  */
  YYSYMBOL_NOT = 21,                       /* NOT  */
  YYSYMBOL_PARENTH_OPEN = 22,              /* PARENTH_OPEN  */
  YYSYMBOL_PARENTH_CLOSE = 23,             /* PARENTH_CLOSE  */
  YYSYMBOL_BRACKET_OPEN = 24,              /* BRACKET_OPEN  */
  YYSYMBOL_BRACKET_CLOSE = 25,             /* BRACKET_CLOSE  */
  YYSYMBOL_ASSIGN_OP = 26,                 /* ASSIGN_OP  */
  YYSYMBOL_INTEGER = 27,                   /* INTEGER  */
  YYSYMBOL_REAL = 28,                      /* REAL  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_COLON = 31,                     /* COLON  */
  YYSYMBOL_SEMICOLON = 32,                 /* SEMICOLON  */
  YYSYMBOL_FOR = 33,                       /* FOR  */
  YYSYMBOL_IF = 34,                        /* IF  */
  YYSYMBOL_ELSE = 35,                      /* ELSE  */
  YYSYMBOL_UMINUS = 36,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_start = 38,                     /* start  */
  YYSYMBOL_declaration_list = 39,          /* declaration_list  */
  YYSYMBOL_declaration = 40,               /* declaration  */
  YYSYMBOL_variable_declaration = 41,      /* variable_declaration  */
  YYSYMBOL_int_constant_declaration = 42,  /* int_constant_declaration  */
  YYSYMBOL_float_constant_declaration = 43, /* float_constant_declaration  */
  YYSYMBOL_type_specifier = 44,            /* type_specifier  */
  YYSYMBOL_identifier_list = 45,           /* identifier_list  */
  YYSYMBOL_int_arithmetic_expression = 46, /* int_arithmetic_expression  */
  YYSYMBOL_float_arithmetic_expression = 47, /* float_arithmetic_expression  */
  YYSYMBOL_instruction_list = 48,          /* instruction_list  */
  YYSYMBOL_instruction = 49,               /* instruction  */
  YYSYMBOL_for_loop_ins = 50,              /* for_loop_ins  */
  YYSYMBOL_condition = 51,                 /* condition  */
  YYSYMBOL_expression_condition = 52,      /* expression_condition  */
  YYSYMBOL_assign_ins = 53,                /* assign_ins  */
  YYSYMBOL_if_ins = 54,                    /* if_ins  */
  YYSYMBOL_counter = 55                    /* counter  */
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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   144

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  137

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    76,    78,    78,    79,    80,    81,    82,
      83,    84,    87,    97,   102,   107,   108,   109,   111,   112,
     120,   121,   122,   123,   129,   130,   135,   139,   140,   141,
     142,   148,   149,   154,   158,   158,   160,   161,   162,   163,
     164,   167,   177,   182,   183,   186,   187,   188,   189,   190,
     191,   192,   198,   199,   202,   208,   214,   219,   228,   238,
     239,   240,   241,   242,   243,   244
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
  "\"end of file\"", "error", "\"invalid token\"", "BEGIN", "END",
  "CONST", "TRUE", "FALSE", "BOOL", "INT", "FLOAT", "PLUS", "MINUS",
  "MULT", "DIV", "LESS", "GREATER", "NOTEQUAL", "LESSEQ", "GREATEQ",
  "EQUAL", "NOT", "PARENTH_OPEN", "PARENTH_CLOSE", "BRACKET_OPEN",
  "BRACKET_CLOSE", "ASSIGN_OP", "INTEGER", "REAL", "ID", "COMMA", "COLON",
  "SEMICOLON", "FOR", "IF", "ELSE", "UMINUS", "$accept", "start",
  "declaration_list", "declaration", "variable_declaration",
  "int_constant_declaration", "float_constant_declaration",
  "type_specifier", "identifier_list", "int_arithmetic_expression",
  "float_arithmetic_expression", "instruction_list", "instruction",
  "for_loop_ins", "condition", "expression_condition", "assign_ins",
  "if_ins", "counter", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-6)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      56,   -75,     9,    80,   -75,   -75,   102,   -75,   -75,   -75,
     -75,    10,    11,    12,   -22,    -3,    -7,    27,   -75,   -75,
     -75,   -75,   -75,   -75,   -75,    29,   -75,    41,    47,    93,
     -75,   -75,    13,   -75,    94,    95,    89,    43,    90,    -5,
     -75,   -75,    -8,    -4,   -75,   -75,   -75,    46,   -75,   -75,
     -75,    92,    96,    97,    -5,     0,    99,    -8,   -75,    92,
      -4,   -75,    96,   -75,   -75,    -8,    -8,    -8,    -8,    -4,
      -4,    -4,    -4,    17,   -75,   -75,   -75,   -75,    61,   101,
      49,    49,   -75,   -75,   100,   100,   -75,   -75,    -5,    -5,
       0,     0,     0,     0,     0,     0,   -75,    53,   123,    98,
      76,    76,    76,    76,    76,    76,   104,    19,    19,    91,
     -75,    42,   107,   108,   109,   116,   120,   -24,   110,   111,
      53,   -75,   -75,   -75,   103,    53,    53,   112,   113,   114,
     115,   119,   -75,   -75,   -75,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     3,     0,     0,     1,    35,     0,    17,    15,    16,
       4,     0,     0,     0,     0,     0,     0,     0,     9,     6,
      10,     7,    11,     8,    18,     0,     2,     0,     0,     0,
      34,    39,     0,    40,     0,     0,    12,     0,     0,     0,
      38,    37,     0,     0,    19,    56,    57,     0,    26,    33,
      25,    54,    55,     0,     0,     0,     0,     0,    25,    13,
       0,    32,    14,    24,    31,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    44,    52,    53,    51,     0,     0,
      20,    21,    22,    23,    27,    28,    29,    30,     0,     0,
       0,     0,     0,     0,     0,     0,    43,    36,     0,     0,
      45,    46,    47,    48,    49,    50,     0,     0,     0,     0,
      65,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      36,    59,    60,    64,    61,    36,    36,     0,     0,     0,
       0,     0,    58,    62,    63,    42,    41
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -75,   -27,
     -37,   -75,   -74,   -75,   -52,     7,   -75,   -75,    28
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,    10,    11,    12,    13,    14,    25,    63,
      64,    15,    30,    31,    56,    78,    32,    33,   112
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      52,    26,    74,   123,    57,   124,    62,    24,    60,     4,
      51,    18,    20,    22,    40,    59,    54,    55,    88,    48,
     110,    58,    34,   106,    49,    61,    27,    75,    76,    77,
      28,    29,    84,    85,    86,    87,    98,    99,    80,    81,
      82,    83,    19,    21,    23,    41,   127,    89,   111,    45,
      46,   130,   131,   115,   116,    47,    35,     1,    47,    -5,
      36,    -5,    67,    68,    -5,    -5,    -5,    37,   117,    38,
      48,    49,    50,    48,    49,    50,    90,    91,    92,    93,
      94,    95,    27,     5,    96,     6,    28,    29,     7,     8,
       9,    90,    91,    92,    93,    94,    95,   100,   101,   102,
     103,   104,   105,    65,    66,    67,    68,    69,    70,    71,
      72,    16,    17,    71,    72,    39,   128,   129,    44,    53,
      42,    43,    79,    73,   107,    97,   114,   121,   108,   109,
     118,   119,   122,   120,   125,   126,   113,   132,     0,     0,
     135,     0,   133,   134,   136
};

static const yytype_int8 yycheck[] =
{
      37,     4,    54,    27,    12,    29,    43,    29,    12,     0,
      37,     1,     1,     1,     1,    42,    21,    22,     1,    27,
       1,    29,    29,    97,    28,    29,    29,    27,    28,    29,
      33,    34,    69,    70,    71,    72,    88,    89,    65,    66,
      67,    68,    32,    32,    32,    32,   120,    30,    29,     6,
       7,   125,   126,    11,    12,    12,    29,     1,    12,     3,
      31,     5,    13,    14,     8,     9,    10,    26,    26,    22,
      27,    28,    29,    27,    28,    29,    15,    16,    17,    18,
      19,    20,    29,     3,    23,     5,    33,    34,     8,     9,
      10,    15,    16,    17,    18,    19,    20,    90,    91,    92,
      93,    94,    95,    11,    12,    13,    14,    11,    12,    13,
      14,     9,    10,    13,    14,    22,    13,    14,    29,    29,
      26,    26,    23,    26,     1,    24,    35,    11,    30,    25,
      23,    23,    12,    24,    24,    24,   108,    25,    -1,    -1,
      25,    -1,    29,    29,    25
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    38,    39,     0,     3,     5,     8,     9,    10,
      40,    41,    42,    43,    44,    48,     9,    10,     1,    32,
       1,    32,     1,    32,    29,    45,     4,    29,    33,    34,
      49,    50,    53,    54,    29,    29,    31,    26,    22,    22,
       1,    32,    26,    26,    29,     6,     7,    12,    27,    28,
      29,    46,    47,    29,    21,    22,    51,    12,    29,    46,
      12,    29,    47,    46,    47,    11,    12,    13,    14,    11,
      12,    13,    14,    26,    51,    27,    28,    29,    52,    23,
      46,    46,    46,    46,    47,    47,    47,    47,     1,    30,
      15,    16,    17,    18,    19,    20,    23,    24,    51,    51,
      52,    52,    52,    52,    52,    52,    49,     1,    30,    25,
       1,    29,    55,    55,    35,    11,    12,    26,    23,    23,
      24,    11,    12,    27,    29,    24,    24,    49,    13,    14,
      49,    49,    25,    29,    29,    25,    25
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    40,    40,
      40,    40,    41,    42,    43,    44,    44,    44,    45,    45,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    48,    48,    49,    49,    49,    49,
      49,    50,    50,    51,    51,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    53,    53,    53,    53,    54,    55,
      55,    55,    55,    55,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     1,     2,     0,     2,     2,     2,     2,
       2,     2,     3,     5,     5,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     2,     1,     1,     3,     3,     3,
       3,     2,     1,     1,     2,     0,     0,     2,     2,     1,
       1,    12,    12,     3,     2,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     3,     3,     3,     3,    11,     3,
       3,     3,     5,     5,     3,     1
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

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
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
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
      yyerror_range[1] = yylloc;
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
  *++yylsp = yylloc;

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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* start: error  */
#line 76 "codel-syn.y"
                                {yyerror("Missing BEGIN or END");}
#line 1349 "codel-syn.tab.c"
    break;

  case 9: /* declaration: variable_declaration error  */
#line 82 "codel-syn.y"
                                                     { yyerror("Missing SEMICOLON after variable declaration");}
#line 1355 "codel-syn.tab.c"
    break;

  case 10: /* declaration: int_constant_declaration error  */
#line 83 "codel-syn.y"
                                                         { yyerror("Missing SEMICOLON after constant declaration");}
#line 1361 "codel-syn.tab.c"
    break;

  case 11: /* declaration: float_constant_declaration error  */
#line 84 "codel-syn.y"
                                                           { yyerror("Missing SEMICOLON after constant declaration");}
#line 1367 "codel-syn.tab.c"
    break;

  case 12: /* variable_declaration: type_specifier identifier_list COLON  */
#line 87 "codel-syn.y"
                                                           {
    // Add each ID to the symbol table with type and isConstant set to False
    int size = arr_size((yyvsp[-1].str));
    for (int i = 0; i < size; i++) {
        modifyEntry(symbolTable, (yyvsp[-1].str)[i], (yyvsp[-2].str), false);
        free((yyvsp[-1].str)[i]);
    }
    free((yyvsp[-1].str));
}
#line 1381 "codel-syn.tab.c"
    break;

  case 13: /* int_constant_declaration: CONST INT ID ASSIGN_OP int_arithmetic_expression  */
#line 97 "codel-syn.y"
                                                                           {
    // Add the ID to the symbol table with type and isConstant set to True
   modifyEntry(symbolTable, (yyvsp[-2].str), (yyvsp[-3].str), true);
}
#line 1390 "codel-syn.tab.c"
    break;

  case 14: /* float_constant_declaration: CONST FLOAT ID ASSIGN_OP float_arithmetic_expression  */
#line 102 "codel-syn.y"
                                                                                 {
    // Add the ID to the symbol table with type and isConstant set to True
   modifyEntry(symbolTable, (yyvsp[-2].str), (yyvsp[-3].str), true);
}
#line 1399 "codel-syn.tab.c"
    break;

  case 15: /* type_specifier: INT  */
#line 107 "codel-syn.y"
                       { (yyval.str) = strdup("INT"); }
#line 1405 "codel-syn.tab.c"
    break;

  case 16: /* type_specifier: FLOAT  */
#line 108 "codel-syn.y"
                       { (yyval.str) = strdup("FLOAT"); }
#line 1411 "codel-syn.tab.c"
    break;

  case 17: /* type_specifier: BOOL  */
#line 109 "codel-syn.y"
                       { (yyval.str) = strdup("BOOL"); }
#line 1417 "codel-syn.tab.c"
    break;

  case 18: /* identifier_list: ID  */
#line 111 "codel-syn.y"
                    { (yyval.str) = malloc(sizeof(char*)); (yyval.str)[0] = strdup((yyvsp[0].str)); }
#line 1423 "codel-syn.tab.c"
    break;

  case 19: /* identifier_list: identifier_list COLON ID  */
#line 112 "codel-syn.y"
                                          {
                   int size = arr_size((yyvsp[-2].str));
                   (yyval.str) = realloc((yyvsp[-2].str), (size + 1) * sizeof(char*));
                   (yyval.str)[size] = strdup((yyvsp[0].str));
               }
#line 1433 "codel-syn.tab.c"
    break;

  case 20: /* int_arithmetic_expression: int_arithmetic_expression PLUS int_arithmetic_expression  */
#line 120 "codel-syn.y"
                                                                                    { (yyval.entier) = (yyvsp[-2].entier) + (yyvsp[0].entier); }
#line 1439 "codel-syn.tab.c"
    break;

  case 21: /* int_arithmetic_expression: int_arithmetic_expression MINUS int_arithmetic_expression  */
#line 121 "codel-syn.y"
                                                                                { (yyval.entier) = (yyvsp[-2].entier) - (yyvsp[0].entier); }
#line 1445 "codel-syn.tab.c"
    break;

  case 22: /* int_arithmetic_expression: int_arithmetic_expression MULT int_arithmetic_expression  */
#line 122 "codel-syn.y"
                                                                               { (yyval.entier) = (yyvsp[-2].entier) * (yyvsp[0].entier); }
#line 1451 "codel-syn.tab.c"
    break;

  case 23: /* int_arithmetic_expression: int_arithmetic_expression DIV int_arithmetic_expression  */
#line 123 "codel-syn.y"
                                                                              {
                        if ((yyvsp[0].entier) == 0)
                            printf("Semantic error: Division by zero at line %d\n", yylineno);
                        else
                            (yyval.entier) = (yyvsp[-2].entier) / (yyvsp[0].entier);
                         }
#line 1462 "codel-syn.tab.c"
    break;

  case 24: /* int_arithmetic_expression: MINUS int_arithmetic_expression  */
#line 129 "codel-syn.y"
                                                                   { (yyval.entier) = -((yyvsp[0].entier)); }
#line 1468 "codel-syn.tab.c"
    break;

  case 25: /* int_arithmetic_expression: ID  */
#line 130 "codel-syn.y"
                         { 
                        if (searchSymbol(symbolTable, (yyvsp[0].str)) == NULL) {
                            yyerror("Undeclared variable used in assignment");
                        }
                        (yyval.entier) = strdup((yyvsp[0].str)); free((yyvsp[0].str));}
#line 1478 "codel-syn.tab.c"
    break;

  case 26: /* int_arithmetic_expression: INTEGER  */
#line 135 "codel-syn.y"
                              { (yyval.entier) = atoi((yyvsp[0].entier)); }
#line 1484 "codel-syn.tab.c"
    break;

  case 27: /* float_arithmetic_expression: float_arithmetic_expression PLUS float_arithmetic_expression  */
#line 139 "codel-syn.y"
                                                                                          { (yyval.real) = float((yyvsp[-2].real)) + float((yyvsp[0].real)); }
#line 1490 "codel-syn.tab.c"
    break;

  case 28: /* float_arithmetic_expression: float_arithmetic_expression MINUS float_arithmetic_expression  */
#line 140 "codel-syn.y"
                                                                                    { (yyval.real) = float((yyvsp[-2].real)) - float((yyvsp[0].real)); }
#line 1496 "codel-syn.tab.c"
    break;

  case 29: /* float_arithmetic_expression: float_arithmetic_expression MULT float_arithmetic_expression  */
#line 141 "codel-syn.y"
                                                                                   { (yyval.real) = float((yyvsp[-2].real)) * float((yyvsp[0].real)); }
#line 1502 "codel-syn.tab.c"
    break;

  case 30: /* float_arithmetic_expression: float_arithmetic_expression DIV float_arithmetic_expression  */
#line 142 "codel-syn.y"
                                                                                  {
                        if ((yyvsp[0].real) == 0)
                            printf("Semantic error: Division by zero at line %d\n", yylineno);
                        else
                            (yyval.real) = (yyvsp[-2].real) / (yyvsp[0].real);
                         }
#line 1513 "codel-syn.tab.c"
    break;

  case 31: /* float_arithmetic_expression: MINUS float_arithmetic_expression  */
#line 148 "codel-syn.y"
                                                                     { (yyval.real) = -((yyvsp[0].real)); }
#line 1519 "codel-syn.tab.c"
    break;

  case 32: /* float_arithmetic_expression: ID  */
#line 149 "codel-syn.y"
                         { 
                        if (searchSymbol(symbolTable, (yyvsp[0].str)) == NULL) {
                            yyerror("Undeclared variable used in assignment");
                        }
                        (yyval.real) = strdup((yyvsp[0].str)); free((yyvsp[0].str));}
#line 1529 "codel-syn.tab.c"
    break;

  case 33: /* float_arithmetic_expression: REAL  */
#line 154 "codel-syn.y"
                           { (yyval.real) = atof((yyvsp[0].real)); }
#line 1535 "codel-syn.tab.c"
    break;

  case 38: /* instruction: assign_ins error  */
#line 162 "codel-syn.y"
                                           { yyerror("Missing SEMICOLON after assign instruction");}
#line 1541 "codel-syn.tab.c"
    break;

  case 41: /* for_loop_ins: FOR PARENTH_OPEN ID ASSIGN_OP COMMA condition COMMA counter PARENTH_CLOSE BRACKET_OPEN instruction BRACKET_CLOSE  */
#line 171 "codel-syn.y"
{ 
                        if (searchSymbol(symbolTable, (yyvsp[-9].str)) == NULL) {
                            yyerror("Undeclared variable used in assignment");
                        }
                        }
#line 1551 "codel-syn.tab.c"
    break;

  case 42: /* for_loop_ins: FOR PARENTH_OPEN ID ASSIGN_OP error condition error counter PARENTH_CLOSE BRACKET_OPEN instruction BRACKET_CLOSE  */
#line 180 "codel-syn.y"
                                      { yyerror("Missing COMMAS in forloop head"); }
#line 1557 "codel-syn.tab.c"
    break;

  case 43: /* condition: PARENTH_OPEN expression_condition PARENTH_CLOSE  */
#line 182 "codel-syn.y"
                                                                       { (yyval.boolean) = (yyvsp[-1].boolean) }
#line 1563 "codel-syn.tab.c"
    break;

  case 44: /* condition: NOT condition  */
#line 183 "codel-syn.y"
                                      { (yyval.boolean) = !(yyvsp[0].boolean); }
#line 1569 "codel-syn.tab.c"
    break;

  case 51: /* expression_condition: ID  */
#line 192 "codel-syn.y"
                           {
                    if (searchSymbol(symbolTable, (yyvsp[0].str)) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    }
#line 1579 "codel-syn.tab.c"
    break;

  case 52: /* expression_condition: INTEGER  */
#line 198 "codel-syn.y"
                                {(yyval.boolean) = (yyvsp[0].entier)}
#line 1585 "codel-syn.tab.c"
    break;

  case 53: /* expression_condition: REAL  */
#line 199 "codel-syn.y"
                             {(yyval.boolean) = (yyvsp[0].real)}
#line 1591 "codel-syn.tab.c"
    break;

  case 54: /* assign_ins: ID ASSIGN_OP int_arithmetic_expression  */
#line 202 "codel-syn.y"
                                                               {
                    if (searchSymbol(symbolTable, (yyvsp[-2].str)) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    (yyval.real) = (yyvsp[0].entier);
                    }
#line 1602 "codel-syn.tab.c"
    break;

  case 55: /* assign_ins: ID ASSIGN_OP float_arithmetic_expression  */
#line 208 "codel-syn.y"
                                                                  {
                    if (searchSymbol(symbolTable, (yyvsp[-2].str)) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    (yyval.real) = (yyvsp[0].real);
                    }
#line 1613 "codel-syn.tab.c"
    break;

  case 56: /* assign_ins: ID ASSIGN_OP TRUE  */
#line 214 "codel-syn.y"
                                        {
                    if (searchSymbol(symbolTable, (yyvsp[-2].str)) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    }
#line 1623 "codel-syn.tab.c"
    break;

  case 57: /* assign_ins: ID ASSIGN_OP FALSE  */
#line 219 "codel-syn.y"
                                         {
                    if (searchSymbol(symbolTable, (yyvsp[-2].str)) == NULL) {
                    yyerror("Undeclared variable used in assignment");
                    }
                    }
#line 1633 "codel-syn.tab.c"
    break;

  case 59: /* counter: ID PLUS PLUS  */
#line 238 "codel-syn.y"
                      { checkCounterID((yyvsp[-2].str)); /* handle i++ */ }
#line 1639 "codel-syn.tab.c"
    break;

  case 60: /* counter: ID MINUS MINUS  */
#line 239 "codel-syn.y"
                        { checkCounterID((yyvsp[-2].str)); /* handle i-- */ }
#line 1645 "codel-syn.tab.c"
    break;

  case 61: /* counter: ID ASSIGN_OP ID  */
#line 240 "codel-syn.y"
                         { checkCounterID((yyvsp[-2].str)); /* handle i := j */ }
#line 1651 "codel-syn.tab.c"
    break;

  case 62: /* counter: ID ASSIGN_OP ID MULT ID  */
#line 241 "codel-syn.y"
                                 { checkCounterID((yyvsp[-4].str)); /* handle i := j * k */ }
#line 1657 "codel-syn.tab.c"
    break;

  case 63: /* counter: ID ASSIGN_OP ID DIV ID  */
#line 242 "codel-syn.y"
                                 { checkCounterID((yyvsp[-4].str)); /* handle i := j / k */ }
#line 1663 "codel-syn.tab.c"
    break;

  case 64: /* counter: ID ASSIGN_OP INTEGER  */
#line 243 "codel-syn.y"
                              { checkCounterID((yyvsp[-2].str)); /* handle i := 5 */ }
#line 1669 "codel-syn.tab.c"
    break;

  case 65: /* counter: error  */
#line 244 "codel-syn.y"
               { yyerror("inappropriate counter in forloop");}
#line 1675 "codel-syn.tab.c"
    break;


#line 1679 "codel-syn.tab.c"

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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;
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
                      yytoken, &yylval, &yylloc);
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 246 "codel-syn.y"


int main() {
    symbolTable = createSymbolTable();
    yyparse();
    // print_tree(yyroot);
    printSymbolTable(symbolTable);  // Print the symbol table at the end
    return 0;
}

