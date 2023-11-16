
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
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */


      #include <stdio.h>
      #include <vector>
      #include <string>
      #include "hash_table.h"
	#pragma warning(disable: 4013 4244 4267 4996)
	extern FILE * yyin;   
      extern int yylineno; 

      // yydebug = 1;
      int yyerror(char* s);
      int yylex();

      int scope_aux = -1;
      string scope; 
      unsigned long mem_acum = 0;
      struct variable_line {
            char* name;
            unsigned int line_used;
      };
      vector<variable_line> last;
      
      HashTable ht;
      Var_Types last_variable_type = VOID;
      
      void insert_table(Var_Types type, variable_line identifier);
      void inc_scope();
      void dec_scope();



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
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
     PROGRAM = 258,
     VAR = 259,
     CONST = 260,
     FUNCTION = 261,
     PROCEDURE = 262,
     BEG = 263,
     END = 264,
     ARRAY = 265,
     OF = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     WHILE = 270,
     DO = 271,
     FOR = 272,
     TO = 273,
     DOWNTO = 274,
     READ = 275,
     READLN = 276,
     WRITE = 277,
     WRITELN = 278,
     AND = 279,
     OR = 280,
     NOT = 281,
     DIV = 282,
     MOD = 283,
     LPAREN = 284,
     RPAREN = 285,
     LBRACKET = 286,
     RBRACKET = 287,
     PLUS = 288,
     MINUS = 289,
     ASTERISK = 290,
     SLASH = 291,
     EQUALS = 292,
     COLON = 293,
     SEMICOLON = 294,
     COMMA = 295,
     PERIOD = 296,
     IDENTIFICADOR = 297,
     DIGITO = 298,
     INTEGER_TIPO = 299,
     REAL_TIPO = 300,
     STRING_TIPO = 301,
     BOOLEAN_TIPO = 302,
     EXP = 303,
     CADENA = 304,
     LESSTHAN = 305,
     GREATERTHAN = 306,
     LESSTHANEQUALS = 307,
     GREATERTHANEQUALS = 308,
     NOTEQUALS = 309
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


      char* cadena;



} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */



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
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   252

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  57
/* YYNRULES -- Number of rules.  */
#define YYNRULES  121
/* YYNRULES -- Number of states.  */
#define YYNSTATES  233

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   309

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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     5,     6,    20,    22,    24,    26,
      28,    30,    32,    34,    36,    38,    40,    42,    44,    46,
      48,    50,    52,    56,    58,    60,    67,    68,    75,    82,
      89,    90,    92,   102,   104,   106,   108,   110,   114,   115,
     120,   121,   122,   131,   132,   138,   142,   143,   147,   153,
     154,   159,   161,   162,   164,   168,   170,   172,   174,   176,
     178,   180,   182,   183,   189,   190,   198,   199,   207,   212,
     217,   224,   231,   236,   241,   248,   255,   260,   265,   266,
     272,   273,   281,   286,   288,   290,   292,   297,   299,   304,
     308,   310,   314,   316,   319,   321,   325,   327,   331,   333,
     337,   339,   343,   345,   349,   354,   356,   361,   363,   365,
     367,   370,   374,   376,   378,   379,   382,   385,   388,   389,
     394,   397
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    -1,    -1,    -1,     3,    57,    60,    58,
      29,    64,    59,    30,    39,    65,    70,    78,    41,    -1,
      42,    -1,    24,    -1,    25,    -1,    37,    -1,    50,    -1,
      51,    -1,    52,    -1,    53,    -1,    54,    -1,    33,    -1,
      34,    -1,    35,    -1,    36,    -1,    27,    -1,    28,    -1,
      60,    -1,    64,    40,    60,    -1,    66,    -1,    67,    -1,
      66,     4,    64,    38,    68,    39,    -1,    -1,    67,     5,
      60,    37,   107,    39,    -1,    67,     5,    60,    37,   110,
      39,    -1,    67,     5,    60,    37,    49,    39,    -1,    -1,
      69,    -1,    10,    31,   108,    41,    41,   108,    32,    11,
      69,    -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,
      70,    71,    39,    -1,    -1,    72,    65,    70,    78,    -1,
      -1,    -1,     6,    73,    60,    76,    38,    69,    74,    39,
      -1,    -1,     7,    75,    60,    76,    39,    -1,    29,    77,
      30,    -1,    -1,    64,    38,    68,    -1,    77,    39,    64,
      38,    68,    -1,    -1,     8,    79,    80,     9,    -1,    81,
      -1,    -1,    82,    -1,    81,    39,    82,    -1,    92,    -1,
      95,    -1,    78,    -1,    89,    -1,    83,    -1,    87,    -1,
      88,    -1,    -1,    15,    84,    96,    16,    82,    -1,    -1,
      17,    85,    93,    18,   102,    16,    82,    -1,    -1,    17,
      86,    93,    19,   102,    16,    82,    -1,    20,    29,    60,
      30,    -1,    21,    29,    60,    30,    -1,    22,    29,    49,
      40,    60,    30,    -1,    23,    29,    49,    40,    60,    30,
      -1,    22,    29,    49,    30,    -1,    23,    29,    49,    30,
      -1,    22,    29,    49,    40,   102,    30,    -1,    23,    29,
      49,    40,   102,    30,    -1,    22,    29,    60,    30,    -1,
      23,    29,    60,    30,    -1,    -1,    12,    90,    96,    13,
      82,    -1,    -1,    12,    91,    96,    13,    82,    14,    82,
      -1,    94,    38,    37,   102,    -1,    92,    -1,    94,    -1,
      60,    -1,    60,    31,   102,    32,    -1,    60,    -1,    60,
      29,   101,    30,    -1,    96,    25,    97,    -1,    97,    -1,
      97,    24,    98,    -1,    98,    -1,    26,    98,    -1,    99,
      -1,    29,    96,    30,    -1,   100,    -1,   102,    61,   102,
      -1,   102,    -1,   101,    40,   102,    -1,   103,    -1,   102,
      62,   103,    -1,   105,    -1,   103,    63,   105,    -1,    60,
      29,   101,    30,    -1,    60,    -1,    60,    31,   102,    32,
      -1,   104,    -1,   107,    -1,   110,    -1,   106,   105,    -1,
      29,   102,    30,    -1,    33,    -1,    34,    -1,    -1,   106,
     108,    -1,   111,   109,    -1,   109,    43,    -1,    -1,   106,
     108,    41,   108,    -1,   106,    48,    -1,    43,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    49,    49,    92,    97,    48,   110,   120,   120,   120,
     120,   120,   120,   120,   120,   123,   123,   126,   126,   126,
     126,   129,   130,   133,   134,   137,   138,   140,   141,   142,
     143,   146,   147,   150,   154,   158,   162,   168,   169,   172,
     176,   181,   175,   191,   190,   202,   203,   206,   213,   216,
     216,   228,   229,   232,   233,   236,   237,   238,   239,   240,
     241,   242,   246,   245,   256,   255,   266,   265,   277,   278,
     281,   282,   283,   284,   285,   286,   287,   288,   292,   291,
     302,   301,   313,   316,   317,   320,   321,   324,   324,   326,
     327,   330,   331,   334,   335,   338,   339,   342,   344,   345,
     348,   349,   352,   353,   356,   359,   360,   361,   362,   363,
     364,   365,   368,   369,   370,   373,   375,   378,   379,   382,
     383,   386
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "VAR", "CONST", "FUNCTION",
  "PROCEDURE", "BEG", "END", "ARRAY", "OF", "IF", "THEN", "ELSE", "WHILE",
  "DO", "FOR", "TO", "DOWNTO", "READ", "READLN", "WRITE", "WRITELN", "AND",
  "OR", "NOT", "DIV", "MOD", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
  "PLUS", "MINUS", "ASTERISK", "SLASH", "EQUALS", "COLON", "SEMICOLON",
  "COMMA", "PERIOD", "IDENTIFICADOR", "DIGITO", "INTEGER_TIPO",
  "REAL_TIPO", "STRING_TIPO", "BOOLEAN_TIPO", "EXP", "CADENA", "LESSTHAN",
  "GREATERTHAN", "LESSTHANEQUALS", "GREATERTHANEQUALS", "NOTEQUALS",
  "$accept", "programa", "$@1", "$@2", "$@3", "identificador", "relop",
  "addop", "mulop", "identificador_lista", "declaraciones",
  "declaraciones_variables", "declaraciones_constantes", "tipo",
  "estandar_tipo", "subprograma_declaraciones", "subprograma_declaracion",
  "subprograma_encabezado", "$@4", "$@5", "$@6", "argumentos",
  "parametros_lista", "instruccion_compuesta", "$@7",
  "instrucciones_opcionales", "instrucciones_lista", "instrucciones",
  "repeticion_instruccion", "$@8", "$@9", "$@10", "lectura_instruccion",
  "escritura_instruccion", "if_instruccion", "$@11", "$@12",
  "variable_asignacion", "for_asignacion", "variable",
  "procedure_instruccion", "relop_expresion", "relop_and", "relop_not",
  "relop_paren", "relop_expresion_simple", "expresion_lista", "expresion",
  "termino", "llamado_funcion", "factor", "signo", "constante_entera",
  "numero_entero", "numero", "constante_real", "digito_no_cero", 0
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
     305,   306,   307,   308,   309
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    55,    57,    58,    59,    56,    60,    61,    61,    61,
      61,    61,    61,    61,    61,    62,    62,    63,    63,    63,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    71,
      73,    74,    72,    75,    72,    76,    76,    77,    77,    79,
      78,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    84,    83,    85,    83,    86,    83,    87,    87,
      88,    88,    88,    88,    88,    88,    88,    88,    90,    89,
      91,    89,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    98,    98,    99,    99,   100,   101,   101,
     102,   102,   103,   103,   104,   105,   105,   105,   105,   105,
     105,   105,   106,   106,   106,   107,   108,   109,   109,   110,
     110,   111
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,    13,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     1,     6,     0,     6,     6,     6,
       0,     1,     9,     1,     1,     1,     1,     3,     0,     4,
       0,     0,     8,     0,     5,     3,     0,     3,     5,     0,
       4,     1,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     0,     5,     0,     7,     0,     7,     4,     4,
       6,     6,     4,     4,     6,     6,     4,     4,     0,     5,
       0,     7,     4,     1,     1,     1,     4,     1,     4,     3,
       1,     3,     1,     2,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     4,     1,     4,     1,     1,     1,
       2,     3,     1,     1,     0,     2,     2,     2,     0,     4,
       2,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     6,     3,     0,     0,    21,
       4,     0,     0,    22,     0,    26,    38,    23,    24,     0,
       0,     0,    40,    43,    49,     0,    26,     0,     0,     0,
       0,     0,    52,    37,    38,     5,     0,   114,    46,    46,
      78,    62,    64,     0,     0,     0,     0,    87,    57,     0,
      51,    53,    59,    60,    61,    58,    55,     0,    56,     0,
       0,    33,    34,    35,    36,     0,    31,   112,   113,     0,
       0,     0,     0,     0,     0,     0,   114,   114,   114,     0,
       0,     0,     0,     0,     0,   114,   114,    50,     0,     0,
      39,     0,    25,    29,   121,   120,   115,   118,    27,    28,
       0,     0,     0,    44,   114,   114,   105,     0,    90,    92,
      94,    96,     0,   100,   107,   102,     0,   108,   109,     0,
       0,    85,    83,     0,    84,     0,     0,     0,     0,     0,
       0,     0,   114,     0,    98,     0,    54,   114,     0,     0,
     116,     0,    45,     0,    41,    93,     0,     0,   114,   114,
       0,   114,   114,     7,     8,    15,    16,     9,    10,    11,
      12,    13,    14,   114,   114,    19,    20,    17,    18,   114,
     110,     0,     0,   114,   114,    68,    69,    72,   114,    76,
      73,   114,    77,     0,    88,   114,    86,    82,     0,   119,
     117,    47,     0,     0,    95,   111,     0,     0,    79,    89,
      91,    97,   101,   103,     0,    63,     0,     0,   105,     0,
     105,     0,    99,     0,     0,    42,   104,   106,     0,     0,
       0,    70,    74,    71,    75,     0,    48,    81,    65,    67,
       0,     0,    32
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    12,   106,   163,   164,   169,    10,
      16,    17,    18,    65,    66,    19,    25,    26,    30,   193,
      31,    74,   101,    48,    32,    49,    50,    51,    52,    78,
      79,    80,    53,    54,    55,    76,    77,    56,   123,    57,
      58,   107,   108,   109,   110,   111,   133,   112,   113,   114,
     115,   116,   117,    96,   140,   118,    97
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -133
static const yytype_int16 yypact[] =
{
      58,  -133,    66,    49,  -133,  -133,  -133,    78,    49,  -133,
      72,    49,    85,  -133,    93,   136,  -133,   144,   162,   114,
      49,    49,  -133,  -133,  -133,   142,   136,   141,    29,   157,
      49,    49,    96,  -133,  -133,  -133,     4,    -8,   122,   122,
    -133,  -133,  -133,   166,   179,   180,   181,    71,  -133,   202,
     173,  -133,  -133,  -133,  -133,  -133,  -133,   176,  -133,   114,
     182,  -133,  -133,  -133,  -133,   183,  -133,  -133,  -133,   184,
      -6,   185,   186,    49,   188,   189,    63,    63,    63,    49,
      49,    49,    49,   -29,    52,   110,   110,  -133,    96,   190,
    -133,   177,  -133,  -133,  -133,  -133,   178,  -133,  -133,  -133,
      91,    45,   140,  -133,    63,    63,   175,    21,   194,  -133,
    -133,  -133,   146,    36,  -133,  -133,   -10,  -133,  -133,    31,
      98,   198,  -133,   203,   176,   211,   201,   204,    -9,   205,
       5,   206,   110,    28,   123,   156,  -133,   110,   191,   177,
     195,     4,  -133,    49,  -133,  -133,    65,   112,   110,   110,
      96,    63,    63,  -133,  -133,  -133,  -133,  -133,  -133,  -133,
    -133,  -133,  -133,   110,   110,  -133,  -133,  -133,  -133,   110,
    -133,    96,    96,   110,   110,  -133,  -133,  -133,   110,  -133,
    -133,   110,  -133,    94,  -133,   110,  -133,   123,   192,  -133,
    -133,  -133,   167,   200,  -133,  -133,    53,   159,  -133,   194,
    -133,   123,    36,  -133,   223,  -133,     6,    20,   143,   120,
     172,   125,   123,   177,     4,  -133,  -133,  -133,    96,    96,
      96,  -133,  -133,  -133,  -133,   208,  -133,  -133,  -133,  -133,
     230,   140,  -133
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -133,  -133,  -133,  -133,  -133,    -3,  -133,  -133,  -133,   -18,
     216,  -133,  -133,  -132,  -101,   209,  -133,  -133,  -133,  -133,
    -133,   207,  -133,   -12,  -133,  -133,  -133,   -85,  -133,  -133,
    -133,  -133,  -133,  -133,  -133,  -133,  -133,    81,   164,    97,
    -133,   -62,    99,   -92,  -133,  -133,   100,   -75,    83,  -133,
    -110,   212,   214,   -87,  -133,   215,  -133
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -86
static const yytype_int16 yytable[] =
{
       6,   144,    28,   136,   138,     9,   170,    27,    13,   191,
     134,   135,   145,     5,    60,   119,   120,     9,    29,   132,
     128,   177,   219,    67,    68,    67,    68,    38,    39,    47,
     147,   178,     5,    94,   150,   180,   220,    94,    95,   155,
     156,    69,    95,   146,   171,   181,   151,    90,    61,    62,
      63,    64,   189,   155,   156,   100,   151,   183,   184,   203,
     200,     1,   187,   165,   166,   198,     4,    36,   185,    11,
       9,   167,   168,   134,   197,   142,   121,   121,   126,   127,
     129,   131,   226,   216,   143,    47,   204,   205,   201,   104,
     151,     5,   105,   185,     5,   194,    67,    68,   206,   207,
      85,   130,    86,   209,    24,     5,   211,     8,    40,   -85,
     212,    41,    11,    42,   172,    14,    43,    44,    45,    46,
      22,    23,    24,   151,   195,   192,   225,   155,   156,   141,
     232,    11,    15,   227,   228,   229,   153,   154,     5,   132,
       9,   -30,   195,    67,    68,   155,   156,    47,    20,   157,
     222,    73,     5,   155,   156,   224,   155,   156,   155,   156,
     122,   122,   158,   159,   160,   161,   162,    21,    47,    47,
     153,   154,   148,   221,   149,   208,   124,   124,   210,   155,
     156,    33,    35,   157,    61,    62,    63,    64,   186,   155,
     156,   217,   155,   156,    37,    81,   158,   159,   160,   161,
     162,   148,   223,   149,   148,   214,   149,    11,    82,    83,
      84,    87,    88,    91,    89,    47,    47,    47,   152,   139,
      94,   173,    92,    93,    98,    99,   102,   137,   103,    86,
     174,   175,   188,   213,   176,   179,   182,   218,   190,   215,
     230,   231,    34,    59,   125,     0,    75,   202,   196,    70,
     199,    71,    72
};

static const yytype_int16 yycheck[] =
{
       3,   102,    20,    88,    91,     8,   116,    19,    11,   141,
      85,    86,   104,    42,    10,    77,    78,    20,    21,    29,
      49,    30,    16,    33,    34,    33,    34,    30,    31,    32,
     105,    40,    42,    43,    13,    30,    16,    43,    48,    33,
      34,    49,    48,   105,    13,    40,    25,    59,    44,    45,
      46,    47,   139,    33,    34,    73,    25,   132,    30,   169,
     152,     3,   137,    27,    28,   150,     0,    38,    40,    40,
      73,    35,    36,   148,   149,    30,    79,    80,    81,    82,
      83,    84,   214,    30,    39,    88,   171,   172,   163,    26,
      25,    42,    29,    40,    42,    30,    33,    34,   173,   174,
      29,    49,    31,   178,     8,    42,   181,    29,    12,    38,
     185,    15,    40,    17,    16,    30,    20,    21,    22,    23,
       6,     7,     8,    25,    30,   143,   213,    33,    34,    38,
     231,    40,    39,   218,   219,   220,    24,    25,    42,    29,
     143,     5,    30,    33,    34,    33,    34,   150,     4,    37,
      30,    29,    42,    33,    34,    30,    33,    34,    33,    34,
      79,    80,    50,    51,    52,    53,    54,     5,   171,   172,
      24,    25,    29,    30,    31,   178,    79,    80,   181,    33,
      34,    39,    41,    37,    44,    45,    46,    47,    32,    33,
      34,    32,    33,    34,    37,    29,    50,    51,    52,    53,
      54,    29,    30,    31,    29,    38,    31,    40,    29,    29,
      29,     9,    39,    31,    38,   218,   219,   220,    24,    41,
      43,    18,    39,    39,    39,    39,    38,    37,    39,    31,
      19,    30,    41,    41,    30,    30,    30,    14,    43,    39,
      32,    11,    26,    34,    80,    -1,    39,   164,   148,    37,
     151,    37,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    56,    57,     0,    42,    60,    58,    29,    60,
      64,    40,    59,    60,    30,    39,    65,    66,    67,    70,
       4,     5,     6,     7,     8,    71,    72,    78,    64,    60,
      73,    75,    79,    39,    65,    41,    38,    37,    60,    60,
      12,    15,    17,    20,    21,    22,    23,    60,    78,    80,
      81,    82,    83,    87,    88,    89,    92,    94,    95,    70,
      10,    44,    45,    46,    47,    68,    69,    33,    34,    49,
     106,   107,   110,    29,    76,    76,    90,    91,    84,    85,
      86,    29,    29,    29,    29,    29,    31,     9,    39,    38,
      78,    31,    39,    39,    43,    48,   108,   111,    39,    39,
      64,    77,    38,    39,    26,    29,    60,    96,    97,    98,
      99,   100,   102,   103,   104,   105,   106,   107,   110,    96,
      96,    60,    92,    93,    94,    93,    60,    60,    49,    60,
      49,    60,    29,   101,   102,   102,    82,    37,   108,    41,
     109,    38,    30,    39,    69,    98,    96,   102,    29,    31,
      13,    25,    24,    24,    25,    33,    34,    37,    50,    51,
      52,    53,    54,    61,    62,    27,    28,    35,    36,    63,
     105,    13,    16,    18,    19,    30,    30,    30,    40,    30,
      30,    40,    30,   102,    30,    40,    32,   102,    41,   108,
      43,    68,    64,    74,    30,    30,   101,   102,    82,    97,
      98,   102,   103,   105,    82,    82,   102,   102,    60,   102,
      60,   102,   102,    41,    38,    39,    30,    32,    14,    16,
      16,    30,    30,    30,    30,   108,    68,    82,    82,    82,
      32,    11,    69
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
		  Type, Value, Location); \
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
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
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
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

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

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

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
       `yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
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
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

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
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
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
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

    {
                  /*
                        int s = -1;
                        stack<int> scope;
                        program main(){ scope.push(s + 1) // [0]
                              funcion suma(){ scope.push(s + 1) [0,1]
                                    s = 0;
                                    if(){ scope.push(s + 1) [0.1.1]
                                          s = 0;
                                    } s = scope[scope.size()-1] // 1; scope.pop() [0.1] s=1
                                    a = 1;
                                    for(){ scope.push(s+1) [0.1.2]
                                          s = 0;
                                    } s = scope[scope.size()-1]; scope.pop() [0.1] s=2
                                    
                                    while(){ scope.push(s+1) [0.1.3]
                                          s = 0;
                                    } s = scope[scope.size()-1]; scope.pop() scope =[0.1] s=3

                              } s = scope[scope.size()-1]; scope.pop() [0] s=1
                              
                              funcion resta(){ scope.push(s+1) [0.2]
                                    s = 0;
                                    if(){ scope.push(s + 1); [0.2.1]
                                          s = 0;
                                          if(){ scope.push(s + 1); [0.2.1.1]
                                                s = 0;
                                          } s = scope[scope.size()-1]; scope.pop() [0.2.1] s=1

                                    } s = scope[scope.size()-1]; scope.pop() [0.2] s=1
                                    
                              } s = scope[scope.size()-1]; scope.pop() [0] s=2

                              funcion mult(){ scope.push(s+1) [0.3] 
                                    s=0
                              }
                        }

                  */
                  scope = "0";
                  printf("Scope changed to: %s\n", scope);
            ;}
    break;

  case 3:

    {
                  insert_table(VOID, last[last.size() - 1]);
                  last.clear();
            ;}
    break;

  case 4:

    {
                  for (unsigned int i = 0; i < last.size(); i++) {
                        insert_table(VOID, last[i]);
                  }
                  last.clear();
            ;}
    break;

  case 5:

    {
                  if (scope != "0") yyerror("Scope error");
            ;}
    break;

  case 6:

    { 
                        char* var_name = strdup((yyvsp[(1) - (1)].cadena));
                        int var_line = (yylsp[(1) - (1)]).last_line;
                        last.push_back({var_name, var_line}); 
                        printf("Variable encontrada: %s\n", var_name);
                        printf("Ultimo en arreglo: %s\n", last[last.size()-1].name);
                  ;}
    break;

  case 33:

    { 
                        last_variable_type = INTEGER;
                  ;}
    break;

  case 34:

    { 
                        last_variable_type = FLOAT;
                  ;}
    break;

  case 35:

    { 
                        last_variable_type = STRING;
                  ;}
    break;

  case 36:

    { 
                        last_variable_type = BOOLEAN;
                  ;}
    break;

  case 40:

    {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 41:

    {
                              insert_table(last_variable_type, last[last.size() - 1]);
                              last.clear()
                        ;}
    break;

  case 42:

    {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 43:

    {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                       ;}
    break;

  case 44:

    {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                       ;}
    break;

  case 47:

    {
                        while (last.size() > 1) {
                              insert_table(last_variable_type, last[last.size() - 1]);
                              last.pop_back();
                        }
                  ;}
    break;

  case 49:

    {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 50:

    { 
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 62:

    {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 63:

    {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 64:

    {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 65:

    {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 66:

    {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 67:

    {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        ;}
    break;

  case 78:

    {
                        inc_scope();
                        printf("Scope changed to: %s", scope);
                  ;}
    break;

  case 79:

    {
                        dec_scope();
                        printf("Scope changed to: %s", scope);
                  ;}
    break;

  case 80:

    {
                        inc_scope();
                        printf("Scope changed to: %s", scope);
                  ;}
    break;

  case 81:

    {
                        dec_scope();
                        printf("Scope changed to: %s", scope);
                  ;}
    break;



      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

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

  yyerror_range[0] = yylloc;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
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

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

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
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
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





int yyerror(char *s){
      printf("Error: %s\nEn linea: %d", s, yylineno);
      exit(1);
      return 0;
}

void inc_scope() {
      scope = scope + "." + to_string(scope_aux);
      scope_aux = 0;
}

void dec_scope() {
      scope_aux = (int)scope[scope.size() - 1];
      scope.substr(0, scope.size() - 2);
}

void insert_table(Var_Types type, variable_line identifier) {
      char* nombre = identifier.name;
      unsigned long lugar = identifier.line_used;
      printf("Insertando a HT: %s\n", nombre);
      unsigned long bytesize = 0;
      switch (type) {
            case BOOLEAN:
                  bytesize = 1;
                  break;
            case INTEGER:
                  bytesize = 4;
                  break;
            case FLOAT:
                  bytesize = 6;
                  break;
            case VOID:
                  bytesize = 0;
                  break;
            case STRING:
                  bytesize = 255;
                  break;
            default:
                  bytesize = 0;
                  break;
      }
      ht_insert(ht, nombre, {mem_acum, type, bytesize, lugar, "a", scope});
      mem_acum += bytesize;
      printf("Insertado correctamente\n");
}

int main( int argc, char* argv[] )
{
	++argv, --argc; /* salta el nombre del programa que se ejecuta */
	if ( argc > 0 ){
		yyin = fopen(argv[0], "r");
		if(!yyin)
			yyin = stdin;
	}
	else
	{
		yyin = stdin;
	}

      create_table(ht);
     	
      yyparse();
      
      print_table(ht);
      return 0;
}
