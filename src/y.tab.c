/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "grammar.y"

	#include "grammar.h"


/* Line 268 of yacc.c  */
#line 76 "y.tab.c"

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
     NUMBER = 258,
     ID = 259,
     AUTO = 260,
     BREAK = 261,
     CASE = 262,
     CHAR = 263,
     CONST = 264,
     CONTINUE = 265,
     DEFAULT = 266,
     DO = 267,
     DOUBLE = 268,
     ELSE = 269,
     ENUM = 270,
     EXTERN = 271,
     FLOAT = 272,
     FOR = 273,
     GOTO = 274,
     IF = 275,
     INT = 276,
     LONG = 277,
     REGISTER = 278,
     RETURN = 279,
     SHORT = 280,
     SIGNED = 281,
     SIZEOF = 282,
     STATIC = 283,
     STRUCT = 284,
     SWITCH = 285,
     TYPEDEF = 286,
     UNION = 287,
     UNSIGNED = 288,
     VOID = 289,
     VOLATILE = 290,
     WHILE = 291,
     PLUS = 292,
     MINUS = 293,
     TIMES = 294,
     DIVIDE = 295,
     MODULO = 296,
     EQUALS = 297,
     BITAND = 298,
     BITOR = 299,
     BITXOR = 300,
     NOT = 301,
     LESS = 302,
     GREATER = 303,
     HASH = 304,
     DOLLAR = 305,
     ATRATE = 306,
     LS = 307,
     RS = 308,
     LB = 309,
     RB = 310,
     LP = 311,
     RP = 312,
     QMARK = 313,
     COLON = 314,
     DOT = 315,
     SEMI = 316,
     COMMA = 317,
     PLUSEQ = 318,
     MINUSEQ = 319,
     TIMESEQ = 320,
     DIVEQ = 321,
     MODULOEQ = 322,
     EMPEQ = 323,
     AND = 324,
     OR = 325,
     REQUALS = 326,
     NOTEQUAL = 327,
     LESSEQ = 328,
     GREATEREQ = 329,
     INCR = 330,
     DECR = 331,
     LSHIFT = 332,
     RSHIFT = 333,
     OREQ = 334,
     XOREQ = 335,
     PTRREF = 336,
     LSHIFTEQ = 337,
     RSHIFTEQ = 338,
     REAL = 339,
     INTPTR = 340,
     LOWER_THAN_ELSE = 341
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define ID 259
#define AUTO 260
#define BREAK 261
#define CASE 262
#define CHAR 263
#define CONST 264
#define CONTINUE 265
#define DEFAULT 266
#define DO 267
#define DOUBLE 268
#define ELSE 269
#define ENUM 270
#define EXTERN 271
#define FLOAT 272
#define FOR 273
#define GOTO 274
#define IF 275
#define INT 276
#define LONG 277
#define REGISTER 278
#define RETURN 279
#define SHORT 280
#define SIGNED 281
#define SIZEOF 282
#define STATIC 283
#define STRUCT 284
#define SWITCH 285
#define TYPEDEF 286
#define UNION 287
#define UNSIGNED 288
#define VOID 289
#define VOLATILE 290
#define WHILE 291
#define PLUS 292
#define MINUS 293
#define TIMES 294
#define DIVIDE 295
#define MODULO 296
#define EQUALS 297
#define BITAND 298
#define BITOR 299
#define BITXOR 300
#define NOT 301
#define LESS 302
#define GREATER 303
#define HASH 304
#define DOLLAR 305
#define ATRATE 306
#define LS 307
#define RS 308
#define LB 309
#define RB 310
#define LP 311
#define RP 312
#define QMARK 313
#define COLON 314
#define DOT 315
#define SEMI 316
#define COMMA 317
#define PLUSEQ 318
#define MINUSEQ 319
#define TIMESEQ 320
#define DIVEQ 321
#define MODULOEQ 322
#define EMPEQ 323
#define AND 324
#define OR 325
#define REQUALS 326
#define NOTEQUAL 327
#define LESSEQ 328
#define GREATEREQ 329
#define INCR 330
#define DECR 331
#define LSHIFT 332
#define RSHIFT 333
#define OREQ 334
#define XOREQ 335
#define PTRREF 336
#define LSHIFTEQ 337
#define RSHIFTEQ 338
#define REAL 339
#define INTPTR 340
#define LOWER_THAN_ELSE 341




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 5 "grammar.y"

		class AST* node ;
		int number ;
		char* name ;
	


/* Line 293 of yacc.c  */
#line 292 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 304 "y.tab.c"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  20
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   81

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  87
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  39
/* YYNRULES -- Number of states.  */
#define YYNSTATES  68

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   341

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     8,    10,    12,    14,    16,    20,
      22,    24,    26,    31,    35,    42,    48,    55,    58,    59,
      63,    66,    67,    71,    75,    77,    79,    81,    83,    85,
      87,    89,    93,    97,    99,   103,   107,   109,   113,   115
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      88,     0,    -1,    92,    -1,    97,    61,    -1,    93,    -1,
      95,    -1,    89,    -1,    61,    -1,    90,    91,    61,    -1,
      21,    -1,    85,    -1,     4,    -1,     4,    52,     3,    53,
      -1,     4,    62,    91,    -1,     4,    52,     3,    53,    62,
      91,    -1,    36,    56,    98,    57,    88,    -1,    20,    56,
      98,    57,    88,    94,    -1,    14,    88,    -1,    -1,    54,
      96,    55,    -1,    88,    96,    -1,    -1,     4,    42,    98,
      -1,    98,    99,   100,    -1,   100,    -1,    71,    -1,    47,
      -1,    48,    -1,    73,    -1,    74,    -1,    72,    -1,   100,
      37,   101,    -1,   100,    38,   101,    -1,   101,    -1,   101,
      39,   102,    -1,   101,    40,   102,    -1,   102,    -1,    56,
      98,    57,    -1,     4,    -1,     3,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    23,    76,    81,    85,    89,    93,    97,   102,   110,
     115,   121,   126,   134,   142,   152,   166,   179,   186,   191,
     196,   205,   209,   220,   233,   238,   244,   250,   256,   262,
     267,   274,   286,   298,   303,   315,   327,   332,   336,   344
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "ID", "AUTO", "BREAK", "CASE",
  "CHAR", "CONST", "CONTINUE", "DEFAULT", "DO", "DOUBLE", "ELSE", "ENUM",
  "EXTERN", "FLOAT", "FOR", "GOTO", "IF", "INT", "LONG", "REGISTER",
  "RETURN", "SHORT", "SIGNED", "SIZEOF", "STATIC", "STRUCT", "SWITCH",
  "TYPEDEF", "UNION", "UNSIGNED", "VOID", "VOLATILE", "WHILE", "PLUS",
  "MINUS", "TIMES", "DIVIDE", "MODULO", "EQUALS", "BITAND", "BITOR",
  "BITXOR", "NOT", "LESS", "GREATER", "HASH", "DOLLAR", "ATRATE", "LS",
  "RS", "LB", "RB", "LP", "RP", "QMARK", "COLON", "DOT", "SEMI", "COMMA",
  "PLUSEQ", "MINUSEQ", "TIMESEQ", "DIVEQ", "MODULOEQ", "EMPEQ", "AND",
  "OR", "REQUALS", "NOTEQUAL", "LESSEQ", "GREATEREQ", "INCR", "DECR",
  "LSHIFT", "RSHIFT", "OREQ", "XOREQ", "PTRREF", "LSHIFTEQ", "RSHIFTEQ",
  "REAL", "INTPTR", "LOWER_THAN_ELSE", "$accept", "STMT", "DECLARATION",
  "DTYPE", "IDLIST", "WHILESTMT", "IFSTMT", "ELSEPART", "CMPDSTMT",
  "STMTLIST", "ASSIGN", "EXPR", "COMPARE", "MAG", "TERM", "FACTOR", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    87,    88,    88,    88,    88,    88,    88,    89,    90,
      90,    91,    91,    91,    91,    92,    93,    94,    94,    95,
      96,    96,    97,    98,    98,    99,    99,    99,    99,    99,
      99,   100,   100,   100,   101,   101,   101,   102,   102,   102
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     3,     1,
       1,     1,     4,     3,     6,     5,     6,     2,     0,     3,
       2,     0,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     1,     3,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     9,     0,    21,     7,    10,     0,     6,
       0,     2,     4,     5,     0,     0,     0,     0,    21,     0,
       1,    11,     0,     3,    39,    38,     0,    22,    24,    33,
      36,     0,     0,    20,    19,     0,     0,     8,     0,    26,
      27,    25,    30,    28,    29,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    37,    23,    31,    32,    34,    35,
      18,    15,    12,     0,    16,     0,    17,    14
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    18,     9,    10,    22,    11,    12,    64,    13,    19,
      14,    27,    45,    28,    29,    30
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -48
static const yytype_int8 yypact[] =
{
      -4,   -15,   -47,   -48,   -27,    -4,   -48,   -48,    30,   -48,
      52,   -48,   -48,   -48,    -3,    -1,    -1,    -1,    -4,     4,
     -48,   -31,     0,   -48,   -48,   -48,    -1,   -25,   -30,   -34,
     -48,   -37,   -33,   -48,   -48,    57,    52,   -48,   -29,   -48,
     -48,   -48,   -48,   -48,   -48,    -1,    -1,    -1,    -1,    -1,
      -4,    -4,     9,   -48,   -48,   -30,   -34,   -34,   -48,   -48,
      51,   -48,     5,    -4,   -48,    52,   -48,   -48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,     1,   -48,   -48,   -32,   -48,   -48,   -48,   -48,    48,
     -48,    37,   -48,    23,   -21,   -36
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
       1,     8,    24,    25,    53,    48,    49,    46,    47,    16,
      39,    40,    58,    59,    39,    40,     2,     3,    39,    40,
      50,    35,    39,    40,    51,    56,    57,    15,    54,    17,
      20,    36,     4,    67,    41,    42,    43,    44,    41,    42,
      43,    44,    41,    42,    43,    44,    41,    42,    43,    44,
       5,    60,    61,    31,    32,    26,    21,     6,    23,    34,
      52,    37,    62,    38,    66,    63,    33,    65,    55,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     7
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-48))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       4,     0,     3,     4,    36,    39,    40,    37,    38,    56,
      47,    48,    48,    49,    47,    48,    20,    21,    47,    48,
      57,    52,    47,    48,    57,    46,    47,    42,    57,    56,
       0,    62,    36,    65,    71,    72,    73,    74,    71,    72,
      73,    74,    71,    72,    73,    74,    71,    72,    73,    74,
      54,    50,    51,    16,    17,    56,     4,    61,    61,    55,
       3,    61,    53,    26,    63,    14,    18,    62,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    85
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    20,    21,    36,    54,    61,    85,    88,    89,
      90,    92,    93,    95,    97,    42,    56,    56,    88,    96,
       0,     4,    91,    61,     3,     4,    56,    98,   100,   101,
     102,    98,    98,    96,    55,    52,    62,    61,    98,    47,
      48,    71,    72,    73,    74,    99,    37,    38,    39,    40,
      57,    57,     3,    91,    57,   100,   101,   101,   102,   102,
      88,    88,    53,    14,    94,    62,    88,    91
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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


/*----------.
| yyparse.  |
`----------*/

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
  if (yypact_value_is_default (yyn))
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
        case 2:

/* Line 1806 of yacc.c  */
#line 77 "grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (1)].node) ;				
				std::cout<<(yyval.node)->getCode()<<std::endl;
			}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 82 "grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (2)].node) ;
			}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 86 "grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (1)].node) ;
			}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 90 "grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (1)].node);
			}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 94 "grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (1)].node) ;
			}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 98 "grammar.y"
    {
				(yyval.node) = new AST(0) ;
			}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 103 "grammar.y"
    {
				AST **p = new AST*[2] ;
				p[0] = (yyvsp[(1) - (3)].node) ;
				p[1] = (yyvsp[(2) - (3)].node) ;
				(yyval.node) = new AST(AST::_VAR,p,2) ;
			}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 111 "grammar.y"
    {
				AST::DataType x = AST::_INT;
				(yyval.node) = new AST(AST::_DTYPE,&x);
			}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 116 "grammar.y"
    {
				AST::DataType x = AST::_INTPTR;
				(yyval.node) = new AST(AST::_DTYPE,&x);
			}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 122 "grammar.y"
    {
				std::string s((yyvsp[(1) - (1)].name));
				(yyval.node) = new AST(AST::_VARIABLE,&s) ;
			}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 127 "grammar.y"
    {
				AST **p = new AST*[2] ;
				std::string s((yyvsp[(1) - (4)].name));
				p[0] = new AST(AST::_VARIABLE,&s) ;
				p[1] = new AST(AST::_CONSTANT,&(yyvsp[(3) - (4)].number)) ;
				(yyval.node) = new AST(AST::_VARIABLE,p,2) ;
			}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 135 "grammar.y"
    {
				AST **p = new AST*[2] ;
				std::string s((yyvsp[(1) - (3)].name));
				p[0] = new AST(AST::_VARIABLE,&s) ;
				p[1] = (yyvsp[(3) - (3)].node) ;
				(yyval.node) = new AST(AST::_IDLIST,p,2) ;
			}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 143 "grammar.y"
    {
				AST **p = new AST*[3] ;
				std::string s((yyvsp[(1) - (6)].name));
				p[0] = new AST(AST::_VARIABLE,&s) ;
				p[1] = new AST(AST::_CONSTANT,&(yyvsp[(3) - (6)].number)) ;
				p[2] = (yyvsp[(6) - (6)].node) ;
				(yyval.node) = new AST(AST::_IDLIST,p,3) ;
			}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 153 "grammar.y"
    {
				AST **p = new AST*[2] ;
				p[0] = (yyvsp[(3) - (5)].node) ;
				p[1] = (yyvsp[(5) - (5)].node) ;
				(yyval.node) = new AST(AST::_BRANCH,p,2) ;
				(yyval.node)->setCode((yyvsp[(3) - (5)].node)->getCode());
				(yyval.node)->label = getLabel();
				(yyval.node)->addCode((yyval.node)->label+": if "+(yyvsp[(3) - (5)].node)->getRevValue()+" goto "+getLabel());
				(yyval.node)->addCode((yyvsp[(5) - (5)].node)->getCode(),"");
				(yyval.node)->addCode("goto "+(yyval.node)->label);
				(yyval.node)->addCode(getLabel(lcount)+": ","");
			}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 167 "grammar.y"
    {
				AST **p = new AST*[3] ;
				p[0] = (yyvsp[(3) - (6)].node) ;
				p[1] = (yyvsp[(5) - (6)].node) ;
				p[2] = (yyvsp[(6) - (6)].node) ;
				(yyval.node) = new AST(AST::_BRANCH,p,3) ;
				(yyval.node)->setCode((yyvsp[(3) - (6)].node)->getCode());
				(yyval.node)->addCode("if "+(yyvsp[(3) - (6)].node)->getRevValue()+" goto "+getLabel());
				(yyval.node)->addCode((yyvsp[(5) - (6)].node)->getCode(),"");
				(yyval.node)->addCode(getLabel(lcount)+": "+(yyvsp[(6) - (6)].node)->getCode());
			}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 180 "grammar.y"
    {
				AST **p = new AST*[1] ;
				p[0] = (yyvsp[(2) - (2)].node) ;
				(yyval.node) = new AST(AST::_ELSE,p,1) ;
				(yyval.node)->addCode((yyvsp[(2) - (2)].node)->getCode());
			}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 187 "grammar.y"
    {
				(yyval.node) = new AST(0) ;
			}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 192 "grammar.y"
    {
					(yyval.node) = (yyvsp[(2) - (3)].node) ;
			}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 197 "grammar.y"
    {
				AST **p = new AST*[2] ;
				p[0] = (yyvsp[(1) - (2)].node) ;
				p[1] = (yyvsp[(2) - (2)].node) ;
				(yyval.node) = new AST(AST::_STATEMENT,p,2);
				(yyval.node)->setCode((yyvsp[(1) - (2)].node)->getCode()+(yyvsp[(2) - (2)].node)->getCode(),"");
			}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 205 "grammar.y"
    {
				(yyval.node) = new AST(0) ;
			}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 210 "grammar.y"
    {
				std::string id((yyvsp[(1) - (3)].name));
				AST **p = new AST*[2];
				p[0] = new AST(AST::_VARIABLE,&id);
				p[1] = (yyvsp[(3) - (3)].node);
				(yyval.node) = new AST(AST::_ASSIGN,p,2);
				(yyval.node)->setCode((yyvsp[(3) - (3)].node)->getCode(),"");
				(yyval.node)->addCode(id+" := "+(yyvsp[(3) - (3)].node)->getValue());
			}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 221 "grammar.y"
    {
				std::string condition((yyvsp[(2) - (3)].node)->getCode());
				(yyvsp[(2) - (3)].node)->childLength=2;
				(yyvsp[(2) - (3)].node)->childrens = new AST*[2];
				(yyvsp[(2) - (3)].node)->childrens[0] = (yyvsp[(1) - (3)].node);
				(yyvsp[(2) - (3)].node)->childrens[1] = (yyvsp[(3) - (3)].node);
				(yyval.node) = (yyvsp[(2) - (3)].node);
				(yyval.node)->setCode((yyvsp[(1) - (3)].node)->getCode(),"");
				(yyval.node)->setCode((yyvsp[(3) - (3)].node)->getCode(),"");
				(yyval.node)->value = (yyvsp[(1) - (3)].node)->getValue()+condition+(yyvsp[(3) - (3)].node)->getValue()	;
				(yyval.node)->revValue = (yyvsp[(1) - (3)].node)->getValue()+opposite(condition)+(yyvsp[(3) - (3)].node)->getValue();	
			}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 234 "grammar.y"
    {				
				(yyval.node) = (yyvsp[(1) - (1)].node);
			}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 239 "grammar.y"
    {
				AST::CondType x = AST::EQ ;
				(yyval.node) = new AST(AST::_CONDITION,&x) ;
				(yyval.node)->setCode(" == ","");
			}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 245 "grammar.y"
    {
				AST::CondType x = AST::LT ;
				(yyval.node) = new AST(AST::_CONDITION,&x) ;
				(yyval.node)->setCode(" < ","");
			}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 251 "grammar.y"
    {
				AST::CondType x = AST::GT ;
				(yyval.node) = new AST(AST::_CONDITION,&x) ;
				(yyval.node)->setCode(" >= ","");
			}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 257 "grammar.y"
    {
				AST::CondType x = AST::LTE ;
				(yyval.node) = new AST(AST::_CONDITION,&x) ;
				(yyval.node)->setCode(" <= ","");
			}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 262 "grammar.y"
    {
				AST::CondType x = AST::GTE ;
				(yyval.node) = new AST(AST::_CONDITION,&x) ;
				(yyval.node)->setCode(" >= ","");
			}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 268 "grammar.y"
    {
				AST::CondType x = AST::NT ;
				(yyval.node) = new AST(AST::_CONDITION,&x) ;
				(yyval.node)->setCode(" != ","");
			}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 275 "grammar.y"
    {
				AST **n1 = new AST*[2];
				n1[0] = ((yyvsp[(1) - (3)].node));
				n1[1] = ((yyvsp[(3) - (3)].node));
				AST::OpType x = AST::ADD;
				(yyval.node) = new AST(AST::_OPERATION,&x,n1,2) ;	
				(yyval.node)->reg = getRegister();
				(yyval.node)->setCode((yyvsp[(1) - (3)].node)->getCode(),"");
				(yyval.node)->addCode((yyvsp[(3) - (3)].node)->getCode(),"");
				(yyval.node)->addCode((yyval.node)->getValue()+" := "+(yyvsp[(1) - (3)].node)->getValue()+" + "+(yyvsp[(3) - (3)].node)->getValue());	
			}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 287 "grammar.y"
    {
				AST **n1 = new AST*[2];
				n1[0] = (yyvsp[(1) - (3)].node);
				n1[1] = (yyvsp[(3) - (3)].node);
				AST::OpType x = AST::SUB;
				(yyval.node) = new AST(AST::_OPERATION,&x,n1,2) ;
				(yyval.node)->reg = getRegister();
				(yyval.node)->setCode((yyvsp[(1) - (3)].node)->getCode(),"");
				(yyval.node)->addCode((yyvsp[(3) - (3)].node)->getCode(),"");
				(yyval.node)->addCode((yyval.node)->getValue()+" := "+(yyvsp[(1) - (3)].node)->getValue()+" - "+(yyvsp[(3) - (3)].node)->getValue());	
			}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 299 "grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (1)].node) ;	
			}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 304 "grammar.y"
    {
				AST **n1 = new AST*[2];
				n1[0] = (yyvsp[(1) - (3)].node);
				n1[1] = (yyvsp[(3) - (3)].node);
				AST::OpType x = AST::MUL;
				(yyval.node) = new AST(AST::_OPERATION,&x,n1,2) ;
				(yyval.node)->reg = getRegister();
				(yyval.node)->setCode((yyvsp[(1) - (3)].node)->getCode(),"");
				(yyval.node)->addCode((yyvsp[(3) - (3)].node)->getCode(),"");
				(yyval.node)->addCode((yyval.node)->getValue()+" := "+(yyvsp[(1) - (3)].node)->getValue()+" * "+(yyvsp[(3) - (3)].node)->getValue());
			}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 316 "grammar.y"
    {
				AST **n1 = new AST*[2];
				n1[0] = (yyvsp[(1) - (3)].node);
				n1[1] = (yyvsp[(3) - (3)].node);
				AST::OpType x = AST::DIV;
				(yyval.node) = new AST(AST::_OPERATION,&x,n1,2) ;	
				(yyval.node)->reg = getRegister();
				(yyval.node)->setCode((yyvsp[(1) - (3)].node)->getCode(),"");
				(yyval.node)->addCode((yyvsp[(3) - (3)].node)->getCode(),"");
				(yyval.node)->addCode((yyval.node)->getValue()+" := "+(yyvsp[(1) - (3)].node)->getValue()+" / "+(yyvsp[(3) - (3)].node)->getValue());
			}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 328 "grammar.y"
    {
				(yyval.node) = (yyvsp[(1) - (1)].node) ;
			}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 333 "grammar.y"
    {
				(yyval.node)  = (yyvsp[(2) - (3)].node) ;
			}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 337 "grammar.y"
    {
				std::string s((yyvsp[(1) - (1)].name));
				(yyval.node) = new AST(AST::_VARIABLE,&s) ;
				(yyval.node)->reg = getRegister();
				code = (yyval.node)->getValue() + " := "+(yyval.node)->getValue();
				(yyval.node)->setCode(code);
			}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 345 "grammar.y"
    {
				(yyval.node) = new AST(AST::_CONSTANT,&(yyvsp[(1) - (1)].number));
			}
    break;



/* Line 1806 of yacc.c  */
#line 2050 "y.tab.c"
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 350 "grammar.y"

std::string getRegister(){
	std::stringstream reg;
	reg<<"R"<<rcount++;
	return 	reg.str();
}

std::string getLabel(){
	std::stringstream label;
	label<<"L"<<++lcount<<"";
	return 	label.str();
}

std::string getLabel(int lastLabel){
	std::stringstream label;
	label<<"L"<<lastLabel<<"";
	return 	label.str();
}

std::string opposite(std::string str){
	if(str==" == ")
		return " != ";
	if(str==" >= ")
		return " < ";
	if(str==" <= ")
		return " > ";
	if(str==" > ")
		return " <= ";
	if(str==" < ")
		return " >= ";
	if(str==" != ")
		return " == ";
}

int yyerror(char *s){
	fprintf(stderr, "%s %s %d\n", s , yytext , yylineno );
	return 0;
}
	
int main(void)	{
	yyparse();
	return 0;
}
