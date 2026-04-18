
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern FILE* yyin;
int yylex(void);
void yyerror(const char* s);

FILE *tac_fp, *asm_fp;

int temp_count = 1;
int label_count = 0;

char* new_temp() {
    char* buf = malloc(10);
    sprintf(buf, "t%d", temp_count++);
    return buf;
}

char* new_label() {
    char* buf = malloc(10);
    sprintf(buf, "L%d", label_count++);
    return buf;
}

#define MAX_REGS 20
char reg_names[MAX_REGS][4];
int reg_stack[MAX_REGS];
int reg_sp = -1;
int reg_next = 0;

void init_regs() {
    for (int i = 0; i < MAX_REGS; i++) {
        sprintf(reg_names[i], "R%d", i);
    }
}

char* alloc_reg() {
    if (reg_next >= MAX_REGS) {
        fprintf(stderr, "Out of registers!\n");
        exit(1);
    }
    int idx = reg_next++;
    reg_stack[++reg_sp] = idx;
    return reg_names[idx];
}

char* pop_reg() {
    if (reg_sp < 0) {
        fprintf(stderr, "Register stack underflow!\n");
        exit(1);
    }
    int idx = reg_stack[reg_sp--];
    return reg_names[idx];
}

void push_reg(const char* name) {
    int idx = atoi(name + 1);
    reg_stack[++reg_sp] = idx;
}

void reset_regs() {
    reg_sp = -1;
    reg_next = 0;
}



/* Line 189 of yacc.c  */
#line 143 "parser.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     VAR = 258,
     NUM = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     FOR = 263,
     FUNC = 264,
     EQ = 265,
     NE = 266,
     LE = 267,
     GE = 268,
     AND = 269,
     OR = 270,
     NOT = 271,
     PEQ = 272,
     MEQ = 273,
     TEQ = 274,
     DEQ = 275,
     MODEQ = 276,
     UMINUS = 277,
     IFX = 278
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 70 "parser.y"

    char cvar[20];
    struct {
        char code[20];
        char true_label[10];
        char false_label[10];
    } expr_attr;
    struct {
        char* first;
        char* second;
    } lbl_pair;



/* Line 214 of yacc.c  */
#line 217 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 229 "parser.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  50
/* YYNRULES -- Number of states.  */
#define YYNSTATES  102

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    28,     2,     2,
      33,    34,    26,    24,    37,    25,     2,    27,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      22,    32,    23,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    29,    30
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    13,    16,    18,    20,
      22,    24,    28,    32,    36,    40,    44,    48,    51,    52,
      58,    63,    66,    67,    73,    76,    77,    78,    89,    93,
      97,   101,   105,   109,   113,   117,   121,   125,   129,   133,
     137,   141,   145,   148,   151,   155,   157,   159,   161,   166,
     168
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    40,    -1,    41,    -1,    40,    41,    -1,
      42,    31,    -1,    54,    31,    -1,    43,    -1,    46,    -1,
      49,    -1,    53,    -1,     3,    32,    54,    -1,     3,    17,
      54,    -1,     3,    18,    54,    -1,     3,    19,    54,    -1,
       3,    20,    54,    -1,     3,    21,    54,    -1,    45,    53,
      -1,    -1,    45,    53,     6,    44,    53,    -1,     5,    33,
      54,    34,    -1,    47,    53,    -1,    -1,     7,    48,    33,
      54,    34,    -1,    50,    53,    -1,    -1,    -1,     8,    33,
      42,    31,    51,    54,    31,    52,    42,    34,    -1,    35,
      40,    36,    -1,    54,    15,    54,    -1,    54,    14,    54,
      -1,    54,    10,    54,    -1,    54,    11,    54,    -1,    54,
      22,    54,    -1,    54,    23,    54,    -1,    54,    12,    54,
      -1,    54,    13,    54,    -1,    54,    24,    54,    -1,    54,
      25,    54,    -1,    54,    26,    54,    -1,    54,    27,    54,
      -1,    54,    28,    54,    -1,    16,    54,    -1,    25,    54,
      -1,    33,    54,    34,    -1,    55,    -1,     3,    -1,     4,
      -1,     9,    33,    56,    34,    -1,    54,    -1,    56,    37,
      54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   107,   107,   111,   112,   116,   117,   118,   119,   120,
     121,   125,   131,   143,   155,   167,   179,   195,   202,   202,
     219,   233,   245,   245,   266,   278,   285,   278,   301,   305,
     315,   325,   335,   345,   355,   365,   375,   385,   395,   405,
     415,   425,   435,   444,   453,   456,   462,   467,   474,   508,
     509
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "VAR", "NUM", "IF", "ELSE", "WHILE",
  "FOR", "FUNC", "EQ", "NE", "LE", "GE", "AND", "OR", "NOT", "PEQ", "MEQ",
  "TEQ", "DEQ", "MODEQ", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'",
  "UMINUS", "IFX", "';'", "'='", "'('", "')'", "'{'", "'}'", "','",
  "$accept", "program", "statement_list", "statement", "assignment",
  "if_stmt", "@1", "if_head", "while_stmt", "while_head", "@2", "for_stmt",
  "for_head", "@3", "@4", "block", "expr", "primary", "argument_list", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,    60,    62,    43,    45,    42,    47,    37,   277,
     278,    59,    61,    40,    41,   123,   125,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      41,    42,    42,    42,    42,    42,    42,    43,    44,    43,
      45,    46,    48,    47,    49,    51,    52,    50,    53,    54,
      54,    54,    54,    54,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    55,    55,    55,    56,
      56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     2,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     2,     0,     5,
       4,     2,     0,     5,     2,     0,     0,    10,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     3,     1,     1,     1,     4,     1,
       3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    46,    47,     0,    22,     0,     0,     0,     0,     0,
       0,     0,     2,     3,     0,     7,     0,     8,     0,     9,
       0,    10,     0,    45,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    46,    42,    43,     0,     0,     1,
       4,     5,    17,    21,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     6,    12,
      13,    14,    15,    16,    11,     0,     0,     0,     0,    49,
       0,    44,    28,    18,    31,    32,    35,    36,    30,    29,
      33,    34,    37,    38,    39,    40,    41,    20,     0,    25,
      48,     0,     0,    23,     0,    50,    19,     0,    26,     0,
       0,    27
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    11,    12,    13,    14,    15,    92,    16,    17,    18,
      31,    19,    20,    94,    99,    21,    22,    23,    70
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -29
static const yytype_int16 yypact[] =
{
      87,    -8,   -29,   -25,   -29,    -4,    -3,    98,    98,    98,
      87,    27,    87,   -29,     0,   -29,    -2,   -29,    -2,   -29,
      -2,   -29,   189,   -29,    98,    98,    98,    98,    98,    98,
      98,     1,    32,    98,   -29,   -29,   -29,   114,    53,   -29,
     -29,   -29,    30,   -29,   -29,    98,    98,    98,    98,    98,
      98,    98,    98,    98,    98,    98,    98,    98,   -29,   233,
     233,   233,   233,   233,   233,   139,    98,    -8,     6,   233,
      -9,   -29,   -29,   -29,   259,   259,   283,   283,   266,   240,
     283,   283,   -12,   -12,   -29,   -29,   -29,   -29,   164,   -29,
     -29,    98,    -2,   -29,    98,   233,   -29,   211,   -29,    32,
      17,   -29
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -29,   -29,    42,    -6,   -28,   -29,   -29,   -29,   -29,   -29,
     -29,   -29,   -29,   -29,   -29,   -13,    -7,   -29,   -29
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_int8 yytable[] =
{
      35,    36,    37,    42,    68,    43,    40,    44,    30,    24,
      25,    26,    27,    28,    55,    56,    57,    59,    60,    61,
      62,    63,    64,    65,    29,    90,    69,    39,    91,    32,
      33,    41,    40,    10,    66,    67,    73,    89,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,   101,    38,     0,     0,     0,     1,     2,     3,    88,
       4,     5,     6,     0,     0,     0,     0,     0,     0,     7,
       0,   100,     0,     0,     0,     0,     0,     0,     8,    96,
       0,     0,     0,     0,    95,     0,     9,    97,    10,    72,
       1,     2,     3,     0,     4,     5,     6,     0,     0,     0,
       0,    34,     2,     7,     0,     0,     0,     6,     0,     0,
       0,     0,     8,     0,     7,     0,     0,     0,     0,     0,
       9,     0,    10,     8,    45,    46,    47,    48,    49,    50,
       0,     9,     0,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,    71,    45,
      46,    47,    48,    49,    50,     0,     0,     0,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,     0,     0,
       0,     0,     0,    87,    45,    46,    47,    48,    49,    50,
       0,     0,     0,     0,     0,     0,    51,    52,    53,    54,
      55,    56,    57,     0,     0,     0,     0,     0,    93,    45,
      46,    47,    48,    49,    50,     0,     0,     0,     0,     0,
       0,    51,    52,    53,    54,    55,    56,    57,     0,     0,
      58,    45,    46,    47,    48,    49,    50,     0,     0,     0,
       0,     0,     0,    51,    52,    53,    54,    55,    56,    57,
       0,     0,    98,    45,    46,    47,    48,    49,    50,     0,
      45,    46,    47,    48,    49,    51,    52,    53,    54,    55,
      56,    57,    51,    52,    53,    54,    55,    56,    57,    -1,
      -1,    47,    48,     0,     0,     0,    45,    46,    47,    48,
       0,    51,    52,    53,    54,    55,    56,    57,    51,    52,
      53,    54,    55,    56,    57,    -1,    -1,     0,     0,     0,
       0,     0,     0,     0,     0,    -1,    -1,    53,    54,    55,
      56,    57
};

static const yytype_int8 yycheck[] =
{
       7,     8,     9,    16,    32,    18,    12,    20,    33,    17,
      18,    19,    20,    21,    26,    27,    28,    24,    25,    26,
      27,    28,    29,    30,    32,    34,    33,     0,    37,    33,
      33,    31,    38,    35,    33,     3,     6,    31,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    34,    10,    -1,    -1,    -1,     3,     4,     5,    66,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    16,
      -1,    99,    -1,    -1,    -1,    -1,    -1,    -1,    25,    92,
      -1,    -1,    -1,    -1,    91,    -1,    33,    94,    35,    36,
       3,     4,     5,    -1,     7,     8,     9,    -1,    -1,    -1,
      -1,     3,     4,    16,    -1,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    25,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      33,    -1,    35,    25,    10,    11,    12,    13,    14,    15,
      -1,    33,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    34,    10,    11,    12,    13,    14,    15,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    34,    10,
      11,    12,    13,    14,    15,    -1,    -1,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27,    28,    -1,    -1,
      31,    10,    11,    12,    13,    14,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    22,    23,    24,    25,    26,    27,    28,
      -1,    -1,    31,    10,    11,    12,    13,    14,    15,    -1,
      10,    11,    12,    13,    14,    22,    23,    24,    25,    26,
      27,    28,    22,    23,    24,    25,    26,    27,    28,    10,
      11,    12,    13,    -1,    -1,    -1,    10,    11,    12,    13,
      -1,    22,    23,    24,    25,    26,    27,    28,    22,    23,
      24,    25,    26,    27,    28,    12,    13,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,    26,
      27,    28
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     7,     8,     9,    16,    25,    33,
      35,    39,    40,    41,    42,    43,    45,    46,    47,    49,
      50,    53,    54,    55,    17,    18,    19,    20,    21,    32,
      33,    48,    33,    33,     3,    54,    54,    54,    40,     0,
      41,    31,    53,    53,    53,    10,    11,    12,    13,    14,
      15,    22,    23,    24,    25,    26,    27,    28,    31,    54,
      54,    54,    54,    54,    54,    54,    33,     3,    42,    54,
      56,    34,    36,     6,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    54,    54,    54,    34,    54,    31,
      34,    37,    44,    34,    51,    54,    53,    54,    31,    52,
      42,    34
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    { reset_regs(); ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 125 "parser.y"
    {
        fprintf(tac_fp, "%s = %s\n", (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* result_reg = pop_reg();
        fprintf(asm_fp, "MOV %s, %s\n", (yyvsp[(1) - (3)].cvar), result_reg);
        reset_regs();
    ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s + %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        fprintf(tac_fp, "%s = %s\n", (yyvsp[(1) - (3)].cvar), t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, (yyvsp[(1) - (3)].cvar));
        fprintf(asm_fp, "ADD %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", (yyvsp[(1) - (3)].cvar), var_reg);
        reset_regs();
        free(t);
    ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 143 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s - %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        fprintf(tac_fp, "%s = %s\n", (yyvsp[(1) - (3)].cvar), t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, (yyvsp[(1) - (3)].cvar));
        fprintf(asm_fp, "SUB %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", (yyvsp[(1) - (3)].cvar), var_reg);
        reset_regs();
        free(t);
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s * %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        fprintf(tac_fp, "%s = %s\n", (yyvsp[(1) - (3)].cvar), t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, (yyvsp[(1) - (3)].cvar));
        fprintf(asm_fp, "MUL %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", (yyvsp[(1) - (3)].cvar), var_reg);
        reset_regs();
        free(t);
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 167 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s / %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        fprintf(tac_fp, "%s = %s\n", (yyvsp[(1) - (3)].cvar), t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, (yyvsp[(1) - (3)].cvar));
        fprintf(asm_fp, "DIV %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", (yyvsp[(1) - (3)].cvar), var_reg);
        reset_regs();
        free(t);
    ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s %% %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        fprintf(tac_fp, "%s = %s\n", (yyvsp[(1) - (3)].cvar), t);
        char* expr_reg = pop_reg();
        char* var_reg = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", var_reg, (yyvsp[(1) - (3)].cvar));
        fprintf(asm_fp, "MOD %s, %s\n", var_reg, expr_reg);
        fprintf(asm_fp, "MOV %s, %s\n", (yyvsp[(1) - (3)].cvar), var_reg);
        reset_regs();
        free(t);
    ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {
        fprintf(tac_fp, "%s:\n", (yyvsp[(1) - (2)].lbl_pair).second);
        fprintf(asm_fp, "%s:\n", (yyvsp[(1) - (2)].lbl_pair).second);
        free((yyvsp[(1) - (2)].lbl_pair).first);
        free((yyvsp[(1) - (2)].lbl_pair).second);
        reset_regs();
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 202 "parser.y"
    {
        fprintf(tac_fp, "goto %s\n", (yyvsp[(1) - (3)].lbl_pair).second);
        fprintf(asm_fp, "JMP %s\n", (yyvsp[(1) - (3)].lbl_pair).second);
        fprintf(tac_fp, "%s:\n", (yyvsp[(1) - (3)].lbl_pair).first);
        fprintf(asm_fp, "%s:\n", (yyvsp[(1) - (3)].lbl_pair).first);
        (yyval.lbl_pair).first  = (yyvsp[(1) - (3)].lbl_pair).first;
        (yyval.lbl_pair).second = (yyvsp[(1) - (3)].lbl_pair).second;
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {
        fprintf(tac_fp, "%s:\n", (yyvsp[(5) - (5)].lbl_pair).second);
        fprintf(asm_fp, "%s:\n", (yyvsp[(5) - (5)].lbl_pair).second);
        free((yyvsp[(5) - (5)].lbl_pair).first);
        free((yyvsp[(5) - (5)].lbl_pair).second);
        reset_regs();
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {
        char* else_lbl = new_label();
        char* end_lbl  = new_label();
        fprintf(tac_fp, "ifFalse %s goto %s\n", (yyvsp[(3) - (4)].cvar), else_lbl);
        char* cond_reg = pop_reg();
        fprintf(asm_fp, "CMP %s, #0\n", cond_reg);
        fprintf(asm_fp, "JE %s\n", else_lbl);
        (yyval.lbl_pair).first  = else_lbl;
        (yyval.lbl_pair).second = end_lbl;
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {
        fprintf(tac_fp, "goto %s\n", (yyvsp[(1) - (2)].lbl_pair).first);
        fprintf(asm_fp, "JMP %s\n", (yyvsp[(1) - (2)].lbl_pair).first);
        fprintf(tac_fp, "%s:\n", (yyvsp[(1) - (2)].lbl_pair).second);
        fprintf(asm_fp, "%s:\n", (yyvsp[(1) - (2)].lbl_pair).second);
        free((yyvsp[(1) - (2)].lbl_pair).first);
        free((yyvsp[(1) - (2)].lbl_pair).second);
        reset_regs();
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 245 "parser.y"
    {
        char* start_lbl = new_label();
        char* end_lbl   = new_label();
        fprintf(tac_fp, "%s:\n", start_lbl);
        fprintf(asm_fp, "%s:\n", start_lbl);
        (yyval.lbl_pair).first  = start_lbl;
        (yyval.lbl_pair).second = end_lbl;
    ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 252 "parser.y"
    {
        char* start_lbl = (yyvsp[(2) - (5)].lbl_pair).first;
        char* end_lbl   = (yyvsp[(2) - (5)].lbl_pair).second;
        fprintf(tac_fp, "ifFalse %s goto %s\n", (yyvsp[(4) - (5)].cvar), end_lbl);
        char* cond_reg = pop_reg();
        fprintf(asm_fp, "CMP %s, #0\n", cond_reg);
        fprintf(asm_fp, "JE %s\n", end_lbl);
        (yyval.lbl_pair).first  = start_lbl;
        (yyval.lbl_pair).second = end_lbl;
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 266 "parser.y"
    {
        fprintf(tac_fp, "goto %s\n", (yyvsp[(1) - (2)].lbl_pair).first);
        fprintf(asm_fp, "JMP %s\n", (yyvsp[(1) - (2)].lbl_pair).first);
        fprintf(tac_fp, "%s:\n", (yyvsp[(1) - (2)].lbl_pair).second);
        fprintf(asm_fp, "%s:\n", (yyvsp[(1) - (2)].lbl_pair).second);
        free((yyvsp[(1) - (2)].lbl_pair).first);
        free((yyvsp[(1) - (2)].lbl_pair).second);
        reset_regs();
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    {
        char* start_lbl = new_label();
        char* end_lbl   = new_label();
        fprintf(tac_fp, "%s:\n", start_lbl);
        fprintf(asm_fp, "%s:\n", start_lbl);
        (yyval.lbl_pair).first  = start_lbl;
        (yyval.lbl_pair).second = end_lbl;
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 285 "parser.y"
    {
        char* start_lbl = (yyvsp[(5) - (7)].lbl_pair).first;
        char* end_lbl   = (yyvsp[(5) - (7)].lbl_pair).second;
        fprintf(tac_fp, "ifFalse %s goto %s\n", (yyvsp[(6) - (7)].cvar), end_lbl);
        char* cond_reg = pop_reg();
        fprintf(asm_fp, "CMP %s, #0\n", cond_reg);
        fprintf(asm_fp, "JE %s\n", end_lbl);
        (yyval.lbl_pair).first  = start_lbl;
        (yyval.lbl_pair).second = end_lbl;
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 294 "parser.y"
    {
        (yyval.lbl_pair).first  = (yyvsp[(8) - (10)].lbl_pair).first;
        (yyval.lbl_pair).second = (yyvsp[(8) - (10)].lbl_pair).second;
    ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s || %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "OR %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 315 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s && %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "AND %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 325 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s == %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPEQ %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s != %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPNE %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 345 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s < %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPLT %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 355 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s > %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPGT %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 365 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s <= %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPLE %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 375 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s >= %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "CMPGE %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 385 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s + %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "ADD %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 395 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s - %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "SUB %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 405 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s * %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "MUL %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 415 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s / %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "DIV %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 425 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s %% %s\n", t, (yyvsp[(1) - (3)].cvar), (yyvsp[(3) - (3)].cvar));
        char* right = pop_reg();
        char* left  = pop_reg();
        fprintf(asm_fp, "MOD %s, %s\n", left, right);
        push_reg(left);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 435 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = !%s\n", t, (yyvsp[(2) - (2)].cvar));
        char* op = pop_reg();
        fprintf(asm_fp, "NOT %s\n", op);
        push_reg(op);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 444 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = -%s\n", t, (yyvsp[(2) - (2)].cvar));
        char* op = pop_reg();
        fprintf(asm_fp, "NEG %s\n", op);
        push_reg(op);
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 453 "parser.y"
    {
        strcpy((yyval.cvar), (yyvsp[(2) - (3)].cvar));
    ;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 456 "parser.y"
    {
        strcpy((yyval.cvar), (yyvsp[(1) - (1)].cvar));
    ;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 462 "parser.y"
    {
        strcpy((yyval.cvar), (yyvsp[(1) - (1)].cvar));
        char* r = alloc_reg();
        fprintf(asm_fp, "MOV %s, %s\n", r, (yyvsp[(1) - (1)].cvar));
    ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 467 "parser.y"
    {
        strcpy((yyval.cvar), (yyvsp[(1) - (1)].cvar));
        /* Load immediate into a register first */
        char* r = alloc_reg();
        fprintf(asm_fp, "MOV %s, #%s\n", r, (yyvsp[(1) - (1)].cvar));
        /* The register is already on the stack (alloc_reg pushed it) */
    ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 474 "parser.y"
    {
        char* t = new_temp();
        fprintf(tac_fp, "%s = %s()\n", t,
                ((yyvsp[(0) - (4)].cvar)[0]=='s'?"sqrt":
                 (yyvsp[(0) - (4)].cvar)[0]=='p'?"pow":
                 (yyvsp[(0) - (4)].cvar)[0]=='l'?"log":
                 (yyvsp[(0) - (4)].cvar)[0]=='e'?"exp":
                 (yyvsp[(0) - (4)].cvar)[0]=='i'?"sin":
                 (yyvsp[(0) - (4)].cvar)[0]=='c'?"cos":
                 (yyvsp[(0) - (4)].cvar)[0]=='t'?"tan":"abs"));
        if ((yyvsp[(0) - (4)].cvar)[0] == 'p') {
            char* arg2 = pop_reg();
            char* arg1 = pop_reg();
            char* res = alloc_reg();
            fprintf(asm_fp, "POW %s, %s, %s\n", res, arg1, arg2);
        } else {
            char* arg = pop_reg();
            char* res = alloc_reg();
            switch((yyvsp[(0) - (4)].cvar)[0]) {
                case 's': fprintf(asm_fp, "SQRT %s, %s\n", res, arg); break;
                case 'l': fprintf(asm_fp, "LOG %s, %s\n", res, arg); break;
                case 'e': fprintf(asm_fp, "EXP %s, %s\n", res, arg); break;
                case 'i': fprintf(asm_fp, "SIN %s, %s\n", res, arg); break;
                case 'c': fprintf(asm_fp, "COS %s, %s\n", res, arg); break;
                case 't': fprintf(asm_fp, "TAN %s, %s\n", res, arg); break;
                case 'a': fprintf(asm_fp, "ABS %s, %s\n", res, arg); break;
            }
        }
        strcpy((yyval.cvar), t);
        free(t);
    ;}
    break;



/* Line 1455 of yacc.c  */
#line 2129 "parser.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 512 "parser.y"


void yyerror(const char* s) {
    fprintf(stderr, "Syntax error: %s\n", s);
}

int main() {
    init_regs();
    yyin = fopen("input.txt", "r");
    tac_fp = fopen("ThreeAdressCode.txt", "w");
    asm_fp = fopen("Assembly.txt", "w");
    if (!yyin || !tac_fp || !asm_fp) {
        perror("File open error");
        return 1;
    }
    yyparse();
    fclose(yyin);
    fclose(tac_fp);
    fclose(asm_fp);
    return 0;
}
