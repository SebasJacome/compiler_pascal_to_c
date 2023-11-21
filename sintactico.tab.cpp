
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
      #include <string.h>
      #include <cstring>
      #include "hash_table.h"
      #include "arbol_sintactico.h"
	#pragma warning(disable: 4013 4244 4267 4996)
	extern FILE * yyin;   
      extern int yylineno; 

      //yydebug = 1;
      int yyerror(char* s);
      int yylex();

      unsigned short scope = 0; 
      unsigned short current_scope = 0;
      unsigned long mem_acum = 0;

      struct variable_line {
            char* name;
            int line_used;
      };
      vector<variable_line> last;
      
      HashTable ht;
      Var_Types last_variable_type = VOID;
      
      void insert_table(Var_Types type, variable_line identifier);
      void insert_table_defsize(Var_Types type, variable_line identifier, unsigned long size);
      void insert_table_var_def(Var_Types type, variable_line identifier);
      void insert_table_var_used(Var_Types type, variable_line identifier);
      void insert_table_func_def(Var_Types type, variable_line identifier);

      typedef struct Nodo Nodo;



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
     INTEGER_TIPO = 297,
     REAL_TIPO = 298,
     STRING_TIPO = 299,
     BOOLEAN_TIPO = 300,
     EXP = 301,
     CADENA = 302,
     LESSTHAN = 303,
     GREATERTHAN = 304,
     LESSTHANEQUALS = 305,
     GREATERTHANEQUALS = 306,
     NOTEQUALS = 307,
     IDENTIFICADOR = 308,
     NUM_ENTERO = 309
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{


      char* cadena;
      int entero;
      struct Nodo* nodo;



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
#define YYLAST   255

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNRULES -- Number of states.  */
#define YYNSTATES  218

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
       0,     0,     3,     4,     5,     6,    18,    22,    24,    26,
      28,    30,    32,    34,    36,    38,    40,    42,    44,    46,
      48,    50,    52,    54,    58,    60,    62,    69,    70,    77,
      84,    91,    92,    94,   104,   106,   108,   110,   112,   116,
     117,   121,   122,   123,   132,   133,   139,   143,   144,   148,
     154,   158,   160,   161,   163,   167,   169,   171,   173,   175,
     177,   179,   181,   186,   193,   195,   197,   202,   207,   214,
     221,   226,   231,   238,   245,   250,   255,   261,   264,   265,
     270,   272,   274,   276,   281,   283,   288,   292,   294,   298,
     300,   303,   305,   309,   311,   315,   317,   321,   323,   327,
     329,   333,   338,   340,   345,   347,   349,   351,   354,   358,
     360,   362,   363,   366,   371
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    -1,    -1,    -1,     3,    57,    61,    58,
      29,    65,    59,    30,    39,    60,    41,    -1,    66,    71,
      79,    -1,    53,    -1,    24,    -1,    25,    -1,    37,    -1,
      48,    -1,    49,    -1,    50,    -1,    51,    -1,    52,    -1,
      33,    -1,    34,    -1,    35,    -1,    36,    -1,    27,    -1,
      28,    -1,    61,    -1,    65,    40,    61,    -1,    67,    -1,
      68,    -1,    67,     4,    65,    38,    69,    39,    -1,    -1,
      68,     5,    61,    37,   104,    39,    -1,    68,     5,    61,
      37,   105,    39,    -1,    68,     5,    61,    37,    47,    39,
      -1,    -1,    70,    -1,    10,    31,    54,    41,    41,    54,
      32,    11,    70,    -1,    42,    -1,    43,    -1,    44,    -1,
      45,    -1,    71,    72,    39,    -1,    -1,    73,    66,    79,
      -1,    -1,    -1,     6,    74,    61,    77,    38,    70,    75,
      39,    -1,    -1,     7,    76,    61,    77,    39,    -1,    29,
      78,    30,    -1,    -1,    65,    38,    69,    -1,    78,    39,
      65,    38,    69,    -1,     8,    80,     9,    -1,    81,    -1,
      -1,    82,    -1,    81,    39,    82,    -1,    89,    -1,    92,
      -1,    79,    -1,    87,    -1,    83,    -1,    85,    -1,    86,
      -1,    15,    93,    16,    82,    -1,    17,    90,    84,    99,
      16,    82,    -1,    18,    -1,    19,    -1,    20,    29,    61,
      30,    -1,    21,    29,    61,    30,    -1,    22,    29,    47,
      40,    61,    30,    -1,    23,    29,    47,    40,    61,    30,
      -1,    22,    29,    47,    30,    -1,    23,    29,    47,    30,
      -1,    22,    29,    47,    40,    99,    30,    -1,    23,    29,
      47,    40,    99,    30,    -1,    22,    29,    61,    30,    -1,
      23,    29,    61,    30,    -1,    12,    93,    13,    82,    88,
      -1,    14,    82,    -1,    -1,    91,    38,    37,    99,    -1,
      89,    -1,    91,    -1,    61,    -1,    61,    31,    99,    32,
      -1,    61,    -1,    61,    29,    98,    30,    -1,    93,    25,
      94,    -1,    94,    -1,    94,    24,    95,    -1,    95,    -1,
      26,    95,    -1,    96,    -1,    29,    93,    30,    -1,    97,
      -1,    99,    62,    99,    -1,    99,    -1,    98,    40,    99,
      -1,   100,    -1,    99,    63,   100,    -1,   102,    -1,   100,
      64,   102,    -1,    61,    29,    98,    30,    -1,    61,    -1,
      61,    31,    99,    32,    -1,   101,    -1,   104,    -1,   105,
      -1,   103,   102,    -1,    29,    99,    30,    -1,    33,    -1,
      34,    -1,    -1,   103,    54,    -1,   103,    54,    41,    54,
      -1,   103,    46,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    75,    80,    70,   103,   117,   128,   132,
     136,   140,   144,   148,   152,   156,   162,   166,   172,   176,
     180,   184,   190,   194,   200,   204,   210,   220,   225,   234,
     243,   253,   258,   259,   270,   276,   282,   288,   296,   301,
     306,   313,   318,   312,   327,   326,   340,   345,   350,   359,
     370,   379,   384,   389,   393,   399,   403,   407,   411,   415,
     419,   423,   429,   433,   439,   443,   449,   453,   459,   468,
     477,   481,   485,   489,   493,   502,   513,   519,   524,   529,
     540,   544,   550,   554,   560,   564,   569,   573,   579,   583,
     589,   593,   599,   603,   609,   614,   618,   624,   628,   634,
     638,   644,   650,   654,   658,   662,   666,   670,   674,   680,
     684,   689,   694,   700,   704
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
  "COMMA", "PERIOD", "INTEGER_TIPO", "REAL_TIPO", "STRING_TIPO",
  "BOOLEAN_TIPO", "EXP", "CADENA", "LESSTHAN", "GREATERTHAN",
  "LESSTHANEQUALS", "GREATERTHANEQUALS", "NOTEQUALS", "IDENTIFICADOR",
  "NUM_ENTERO", "$accept", "programa", "$@1", "$@2", "$@3",
  "contenido_programa", "identificador", "relop", "addop", "mulop",
  "identificador_lista", "declaraciones", "declaraciones_variables",
  "declaraciones_constantes", "tipo", "estandar_tipo",
  "subprograma_declaraciones", "subprograma_declaracion",
  "subprograma_encabezado", "$@4", "$@5", "$@6", "argumentos",
  "parametros_lista", "instruccion_compuesta", "instrucciones_opcionales",
  "instrucciones_lista", "instrucciones", "repeticion_instruccion",
  "for_comportamiento", "lectura_instruccion", "escritura_instruccion",
  "if_instruccion", "instruccion_else", "variable_asignacion",
  "for_asignacion", "variable", "procedure_instruccion", "relop_expresion",
  "relop_and", "relop_not", "relop_paren", "relop_expresion_simple",
  "expresion_lista", "expresion", "termino", "llamado_funcion", "factor",
  "signo", "constante_entera", "constante_real", 0
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
       0,    55,    57,    58,    59,    56,    60,    61,    62,    62,
      62,    62,    62,    62,    62,    62,    63,    63,    64,    64,
      64,    64,    65,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    69,    69,    70,    70,    70,    70,    71,    71,
      72,    74,    75,    73,    76,    73,    77,    77,    78,    78,
      79,    80,    80,    81,    81,    82,    82,    82,    82,    82,
      82,    82,    83,    83,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    88,    88,    89,
      90,    90,    91,    91,    92,    92,    93,    93,    94,    94,
      95,    95,    96,    96,    97,    98,    98,    99,    99,   100,
     100,   101,   102,   102,   102,   102,   102,   102,   102,   103,
     103,   103,   104,   105,   105
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,    11,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     1,     6,     0,     6,     6,
       6,     0,     1,     9,     1,     1,     1,     1,     3,     0,
       3,     0,     0,     8,     0,     5,     3,     0,     3,     5,
       3,     1,     0,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     4,     6,     1,     1,     4,     4,     6,     6,
       4,     4,     6,     6,     4,     4,     5,     2,     0,     4,
       1,     1,     1,     4,     1,     4,     3,     1,     3,     1,
       2,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     4,     1,     4,     1,     1,     1,     2,     3,     1,
       1,     0,     2,     4,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     7,     3,     0,     0,    22,
       4,     0,     0,    23,     0,    27,     0,    39,    24,    25,
       5,     0,     0,     0,    41,    44,    52,     0,    27,     6,
       0,     0,     0,     0,   111,   111,     0,     0,     0,     0,
       0,    84,    57,     0,    51,    53,    59,    60,    61,    58,
      55,     0,    56,    38,     0,     0,   111,    47,    47,   111,
     111,   109,   110,   102,     0,    87,    89,    91,    93,     0,
      97,   104,    99,     0,   105,   106,     0,    82,    80,     0,
      81,     0,     0,     0,     0,   111,   111,    50,     0,     0,
      40,     0,    34,    35,    36,    37,     0,    32,     0,     0,
       0,     0,     0,     0,     0,    90,     0,     0,   111,   111,
       0,   111,   111,     8,     9,    16,    17,    10,    11,    12,
      13,    14,    15,   111,   111,    20,    21,    18,    19,   111,
     111,   114,   112,   107,     0,    64,    65,   111,     0,     0,
       0,     0,     0,     0,     0,    95,     0,    54,   111,     0,
      26,    30,    28,    29,     0,     0,     0,    45,    92,   108,
       0,     0,    78,    86,    88,    94,    98,   100,     0,     0,
      62,     0,    66,    67,    70,   111,    74,    71,   111,    75,
      85,   111,    83,    79,     0,     0,    46,     0,    42,   101,
     103,     0,    76,   113,     0,   102,     0,   102,     0,    96,
       0,    48,     0,     0,    77,    63,    68,    72,    69,    73,
       0,     0,    43,     0,    49,     0,     0,    33
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    12,    16,    63,   123,   124,   129,
      10,    17,    18,    19,    96,    97,    21,    27,    28,    32,
     203,    33,   103,   155,    42,    43,    44,    45,    46,   137,
      47,    48,    49,   192,    50,    79,    51,    52,    64,    65,
      66,    67,    68,   144,    69,    70,    71,    72,    73,    74,
      75
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -171
static const yytype_int16 yypact[] =
{
      11,  -171,    66,   -25,  -171,  -171,  -171,    76,   -25,  -171,
      88,   -25,   118,  -171,   127,   172,   138,  -171,   179,   182,
    -171,   148,   -25,   -25,  -171,  -171,    36,   150,   172,  -171,
      80,   153,   -25,   -25,   -16,   -16,   -25,   164,   165,   166,
     167,   101,  -171,   183,   158,  -171,  -171,  -171,  -171,  -171,
    -171,   160,  -171,  -171,   191,    28,    30,   171,   171,   -16,
     -16,  -171,  -171,   142,    -1,   177,  -171,  -171,  -171,    92,
     110,  -171,  -171,    -7,  -171,  -171,    18,   173,  -171,   163,
     160,   -25,   -25,    51,    55,    57,    57,  -171,    36,   168,
    -171,   175,  -171,  -171,  -171,  -171,   169,  -171,   170,    49,
     174,   176,   -25,   178,   180,  -171,    -9,    63,    57,    57,
      36,   -16,   -16,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,  -171,    57,    57,  -171,  -171,  -171,  -171,    57,
      57,  -171,   161,  -171,    36,  -171,  -171,    57,   181,   184,
       5,   187,    12,   188,    35,   152,   125,  -171,    57,   149,
    -171,  -171,  -171,  -171,   136,    62,    91,  -171,  -171,  -171,
      44,   128,   193,   177,  -171,   152,   110,  -171,    89,   156,
    -171,    34,  -171,  -171,  -171,    57,  -171,  -171,    57,  -171,
    -171,    57,  -171,   152,   185,    28,  -171,   -25,  -171,  -171,
    -171,    36,  -171,  -171,    36,   134,   117,   139,   119,   152,
     186,  -171,   140,   189,  -171,  -171,  -171,  -171,  -171,  -171,
     190,    28,  -171,   192,  -171,   201,    91,  -171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,  -171,  -171,    -3,  -171,  -171,  -171,
     -20,   194,  -171,  -171,  -170,  -155,  -171,  -171,  -171,  -171,
    -171,  -171,   162,  -171,   -14,  -171,  -171,   -85,  -171,  -171,
    -171,  -171,  -171,  -171,   195,  -171,   196,  -171,   -24,   112,
     -50,  -171,  -171,   113,   -54,   105,  -171,   -69,   197,   198,
     199
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -83
static const yytype_int16 yytable[] =
{
       6,   188,    30,   147,   133,     9,   107,    29,    13,   105,
      59,    76,   110,    60,     1,   201,   111,    61,    62,     9,
      31,   158,   130,    41,   111,   162,    61,    62,     5,    57,
      58,   145,   146,    77,   134,   174,   106,     5,    91,   131,
      90,   214,   177,   111,    26,   175,     5,   132,    34,   170,
     194,    35,   178,    36,   145,   161,    37,    38,    39,    40,
     167,   217,   164,    61,    62,   180,     4,   115,   116,   165,
      92,    93,    94,    95,   189,   181,   168,    98,   138,   139,
     141,   143,   154,   171,   181,    41,   130,   113,   114,     5,
      61,    62,   186,   159,   183,   131,   115,   116,   140,     9,
     117,   187,   142,   132,     5,     8,   204,    41,     5,   205,
       5,   118,   119,   120,   121,   122,   113,   114,    55,   159,
      11,   196,   115,   116,   198,   115,   116,   199,    11,   117,
      85,    41,    86,    92,    93,    94,    95,   125,   126,   -82,
     118,   119,   120,   121,   122,   127,   128,   207,    14,   209,
     115,   116,   115,   116,    24,    25,    26,   182,   115,   116,
     190,   115,   116,   108,   206,   109,    15,   202,   108,   208,
     109,   108,   195,   109,   185,   197,    11,   -31,   211,    20,
      11,   135,   136,    22,     9,   115,   116,    23,    41,    53,
      56,    41,    87,    81,    82,    83,    84,    88,    89,    26,
     102,   112,   169,   184,    86,   148,   149,   191,   150,   151,
     193,   172,   216,   152,   173,   153,   156,   176,   179,   157,
     104,   160,    54,   163,   215,     0,   200,   210,   212,   166,
       0,    78,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   213,     0,     0,     0,     0,     0,
       0,     0,     0,    99,   100,   101
};

static const yytype_int16 yycheck[] =
{
       3,   156,    22,    88,    73,     8,    60,    21,    11,    59,
      26,    35,    13,    29,     3,   185,    25,    33,    34,    22,
      23,    30,    29,    26,    25,   110,    33,    34,    53,    32,
      33,    85,    86,    36,    16,    30,    60,    53,    10,    46,
      54,   211,    30,    25,     8,    40,    53,    54,    12,   134,
      16,    15,    40,    17,   108,   109,    20,    21,    22,    23,
     129,   216,   112,    33,    34,    30,     0,    33,    34,   123,
      42,    43,    44,    45,    30,    40,   130,    47,    81,    82,
      83,    84,   102,   137,    40,    88,    29,    24,    25,    53,
      33,    34,    30,    30,   148,    46,    33,    34,    47,   102,
      37,    39,    47,    54,    53,    29,   191,   110,    53,   194,
      53,    48,    49,    50,    51,    52,    24,    25,    38,    30,
      40,   175,    33,    34,   178,    33,    34,   181,    40,    37,
      29,   134,    31,    42,    43,    44,    45,    27,    28,    38,
      48,    49,    50,    51,    52,    35,    36,    30,    30,    30,
      33,    34,    33,    34,     6,     7,     8,    32,    33,    34,
      32,    33,    34,    29,    30,    31,    39,   187,    29,    30,
      31,    29,   175,    31,    38,   178,    40,     5,    38,    41,
      40,    18,    19,     4,   187,    33,    34,     5,   191,    39,
      37,   194,     9,    29,    29,    29,    29,    39,    38,     8,
      29,    24,    41,    54,    31,    37,    31,    14,    39,    39,
      54,    30,    11,    39,    30,    39,    38,    30,    30,    39,
      58,   108,    28,   111,    32,    -1,    41,    41,    39,   124,
      -1,    36,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    56,    56,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    56,    57,     0,    53,    61,    58,    29,    61,
      65,    40,    59,    61,    30,    39,    60,    66,    67,    68,
      41,    71,     4,     5,     6,     7,     8,    72,    73,    79,
      65,    61,    74,    76,    12,    15,    17,    20,    21,    22,
      23,    61,    79,    80,    81,    82,    83,    85,    86,    87,
      89,    91,    92,    39,    66,    38,    37,    61,    61,    26,
      29,    33,    34,    61,    93,    94,    95,    96,    97,    99,
     100,   101,   102,   103,   104,   105,    93,    61,    89,    90,
      91,    29,    29,    29,    29,    29,    31,     9,    39,    38,
      79,    10,    42,    43,    44,    45,    69,    70,    47,   103,
     104,   105,    29,    77,    77,    95,    93,    99,    29,    31,
      13,    25,    24,    24,    25,    33,    34,    37,    48,    49,
      50,    51,    52,    62,    63,    27,    28,    35,    36,    64,
      29,    46,    54,   102,    16,    18,    19,    84,    61,    61,
      47,    61,    47,    61,    98,    99,    99,    82,    37,    31,
      39,    39,    39,    39,    65,    78,    38,    39,    30,    30,
      98,    99,    82,    94,    95,    99,   100,   102,    99,    41,
      82,    99,    30,    30,    30,    40,    30,    30,    40,    30,
      30,    40,    32,    99,    54,    38,    30,    39,    70,    30,
      32,    14,    88,    54,    16,    61,    99,    61,    99,    99,
      41,    69,    65,    75,    82,    82,    30,    30,    30,    30,
      41,    38,    39,    54,    69,    32,    11,    70
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
                  scope = 0;
            ;}
    break;

  case 3:

    {
                  insert_table_var_def(VOID, last[last.size() - 1]);
                  last.clear();
            ;}
    break;

  case 4:

    {
                  for (unsigned int i = 0; i < last.size(); i++) {
                        insert_table_var_def(VOID, last[i]);
                  }
                  last.clear();
            ;}
    break;

  case 5:

    {
                  if (current_scope != 0) yyerror("Scope error, no se cerro el scope actual");

                  Nodo* raiz = crearNodo();
                  raiz->tipo = PROGRAMA;
                  // insertarNodoHijos(raiz, $3, $6, $10);
                  Nodo* prueba = crearNodo();
                  prueba->tipo = SIN_TIPO;
                  raiz->hijo[0] = prueba;
                  raiz->hijo[1] = prueba;
                  raiz->hijo[2] = (yyvsp[(10) - (11)].nodo);
                  (yyval.nodo) = raiz; 
                  imprimirArbol(raiz);
            ;}
    break;

  case 6:

    {
                        Nodo* nodo = crearNodo();
                        nodo->tipo = CONTENIDO_PROGRAMA;
                        //insertarNodoHijos(nodo, $1, $2, $3);
                        Nodo* prueba = crearNodo();
                        prueba->tipo = SIN_TIPO;
                        nodo->hijo[0] = prueba;
                        nodo->hijo[1] = prueba;
                        nodo->hijo[2] = prueba;
                        (yyval.nodo) = nodo;
                   ;}
    break;

  case 7:

    {
                        char* var_name = strdup((yyvsp[(1) - (1)].cadena));
                        int var_line = (yylsp[(1) - (1)]).last_line;
                        last.push_back({var_name, var_line}); 

                        // ARBOL
                            
                  ;}
    break;

  case 8:

    {
            // ARBOL
      ;}
    break;

  case 9:

    {
            // ARBOL
      ;}
    break;

  case 10:

    {
            // ARBOL
      ;}
    break;

  case 11:

    {
            // ARBOL
      ;}
    break;

  case 12:

    {
            // ARBOL
      ;}
    break;

  case 13:

    {
            // ARBOL
      ;}
    break;

  case 14:

    {
            // ARBOL
      ;}
    break;

  case 15:

    {
            // ARBOL
      ;}
    break;

  case 16:

    {
            // ARBOL
      ;}
    break;

  case 17:

    {
            // ARBOL
      ;}
    break;

  case 18:

    {
            // ARBOL
      ;}
    break;

  case 19:

    {
            // ARBOL
      ;}
    break;

  case 20:

    {
            // ARBOL
      ;}
    break;

  case 21:

    {
            // ARBOL
      ;}
    break;

  case 22:

    {
                        // ARBOL
                    ;}
    break;

  case 23:

    {
                        // ARBOL
                    ;}
    break;

  case 24:

    {
                  // ARBOL
              ;}
    break;

  case 25:

    {
                  // ARBOL
              ;}
    break;

  case 26:

    {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(last_variable_type, last[i]);
                              }
                              last.clear();

                              // ARBOL
                        ;}
    break;

  case 27:

    {
                              // ARBOL
                        ;}
    break;

  case 28:

    {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_ENTERO, last[i]);
                              }
                              last.clear();

                              // ARBOL
                         ;}
    break;

  case 29:

    {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_REAL, last[i]);
                              }
                              last.clear();

                              // ARBOL
                        ;}
    break;

  case 30:

    {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_CADENA, last[i]);
                              }
                              last.clear();

                              // ARBOL
                         ;}
    break;

  case 31:

    {
                              // ARBOL
                         ;}
    break;

  case 33:

    {
      for (unsigned int i = 0; i < last.size(); i++) {
            insert_table_defsize(last_variable_type, last[i], ((yyvsp[(6) - (9)].entero)) - ((yyvsp[(3) - (9)].entero)) + 1);
      }
      last.clear();

      // ARBOL
     ;}
    break;

  case 34:

    { 
                  last_variable_type = INTEGER;

                  // ARBOL
              ;}
    break;

  case 35:

    { 
                  last_variable_type = FLOAT;

                  // ARBOL
              ;}
    break;

  case 36:

    { 
                  last_variable_type = STRING;

                  // ARBOL
              ;}
    break;

  case 37:

    { 
                  last_variable_type = BOOLEAN;

                  // ARBOL
              ;}
    break;

  case 38:

    {
                              // ARBOL
                          ;}
    break;

  case 39:

    {
                              // ARBOL
                          ;}
    break;

  case 40:

    {
                              // ARBOL
                        ;}
    break;

  case 41:

    {
                              scope++;
                              current_scope = scope;
                        ;}
    break;

  case 42:

    {
                              insert_table_func_def(last_variable_type, last[0]);
                              last.clear();
                        ;}
    break;

  case 43:

    {
                              // ARBOL
                        ;}
    break;

  case 44:

    {
                              scope++;
                              current_scope = scope;
                       ;}
    break;

  case 45:

    {
                              insert_table_func_def(VOID, last[0]);
                              last.clear();

                              // ARBOL
                       ;}
    break;

  case 46:

    {
            // ARBOL
           ;}
    break;

  case 47:

    {
            // ARBOL
           ;}
    break;

  case 48:

    {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }

                  // ARBOL
                 ;}
    break;

  case 49:

    {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }

                  // ARBOL
                 ;}
    break;

  case 50:

    { 
                              current_scope = 0;

                              // ARBOL
                        ;}
    break;

  case 51:

    {
                              // ARBOL
                         ;}
    break;

  case 52:

    {
                              // ARBOL
                         ;}
    break;

  case 53:

    {
                        // ARBOL
                    ;}
    break;

  case 54:

    {
                        // ARBOL
                    ;}
    break;

  case 55:

    {
                  // ARBOL
              ;}
    break;

  case 56:

    {
                  // ARBOL
              ;}
    break;

  case 57:

    {
                  // ARBOL
              ;}
    break;

  case 58:

    {
                  // ARBOL
              ;}
    break;

  case 59:

    {
                  // ARBOL
              ;}
    break;

  case 60:

    {
                  // ARBOL
              ;}
    break;

  case 61:

    {
                  // ARBOL
              ;}
    break;

  case 62:

    {
                        // ARBOL
                       ;}
    break;

  case 63:

    {
                        // ARBOL
                       ;}
    break;

  case 64:

    {
                        // ARBOL
                  ;}
    break;

  case 65:

    {
                        // ARBOL
                  ;}
    break;

  case 66:

    {
                        // ARBOL
                    ;}
    break;

  case 67:

    {
                        // ARBOL
                    ;}
    break;

  case 68:

    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                      ;}
    break;

  case 69:

    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                      ;}
    break;

  case 70:

    {
                        // ARBOL
                      ;}
    break;

  case 71:

    {
                        // ARBOL
                      ;}
    break;

  case 72:

    {
                        // ARBOL
                      ;}
    break;

  case 73:

    {
                        // ARBOL
                      ;}
    break;

  case 74:

    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                      ;}
    break;

  case 75:

    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                       ;}
    break;

  case 76:

    {
                  // ARBOL
               ;}
    break;

  case 77:

    {
                        // ARBOL
                  ;}
    break;

  case 78:

    {
                        // ARBOL
                  ;}
    break;

  case 79:

    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                    ;}
    break;

  case 80:

    {
                  // ARBOL
               ;}
    break;

  case 81:

    {
                  // ARBOL
               ;}
    break;

  case 82:

    {
            // ARBOL
         ;}
    break;

  case 83:

    {
            // ARBOL
         ;}
    break;

  case 84:

    {
                        // ARBOL
                      ;}
    break;

  case 85:

    {
                        // ARBOL
                      ;}
    break;

  case 86:

    {
                  // ARBOL
                ;}
    break;

  case 87:

    {
                  // ARBOL
                ;}
    break;

  case 88:

    {
            // ARBOL
          ;}
    break;

  case 89:

    {
            // ARBOL
          ;}
    break;

  case 90:

    {
            // ARBOL
          ;}
    break;

  case 91:

    {
            // ARBOL
          ;}
    break;

  case 92:

    {
                  // ARBOL
            ;}
    break;

  case 93:

    {
                  // ARBOL
            ;}
    break;

  case 94:

    {
                        // ARBOL
                       ;}
    break;

  case 95:

    {
                  // ARBOL
                ;}
    break;

  case 96:

    {
                  // ARBOL
                ;}
    break;

  case 97:

    {
            // ARBOL
          ;}
    break;

  case 98:

    {
            // ARBOL
          ;}
    break;

  case 99:

    {
            // ARBOL
        ;}
    break;

  case 100:

    {
            // ARBOL
        ;}
    break;

  case 101:

    {
                  // ARBOL
                ;}
    break;

  case 102:

    {
            // ARBOL
       ;}
    break;

  case 103:

    {
            // ARBOL
       ;}
    break;

  case 104:

    {
            // ARBOL
       ;}
    break;

  case 105:

    {
            // ARBOL
       ;}
    break;

  case 106:

    {
            // ARBOL
       ;}
    break;

  case 107:

    {
            // ARBOL
       ;}
    break;

  case 108:

    {
            // ARBOL
       ;}
    break;

  case 109:

    {
            // ARBOL
      ;}
    break;

  case 110:

    {
            // ARBOL
      ;}
    break;

  case 111:

    {
            // ARBOL
      ;}
    break;

  case 112:

    {
                  // ARBOL
                 ;}
    break;

  case 113:

    {
                  // ARBOL
               ;}
    break;

  case 114:

    {
                  // ARBOL
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

void insert_table_var_def(Var_Types type, variable_line identifier) {
      unsigned long index;
      long collision_list_position;
      ht_search(ht, identifier.name, index, collision_list_position);
      if (index != -1 && ht_is_scope_already_declared(ht, identifier.name, index, scope)) {
            printf("Error: variable %s ya declarada en linea %d\n", identifier.name, identifier.line_used);
            std::string errorS = "Error";
            char* errorC = new char[errorS.length() + 1];
            strcpy(errorC, errorS.c_str());
            yyerror(errorC);
      }
      else {
            insert_table(type, identifier);
      }
}

void insert_table_var_used(Var_Types type, variable_line identifier) {
      unsigned long index;
      long collision_list_position;
      ht_search(ht, identifier.name, index, collision_list_position);
      if (index == -1) {
            printf("Error: variable %s no declarada en linea %d\n", identifier.name, identifier.line_used);
            std::string errorS = "Error";
            char* errorC = new char[errorS.length() + 1];
            strcpy(errorC, errorS.c_str());
            yyerror(errorC);;
      }
      else if (!ht_is_scope_less_than_defined(ht, identifier.name, index, current_scope)) {
            printf("Error: variable %s en scope diferente en linea %d\n", identifier.name, identifier.line_used);
            std::string errorS = "Error";
            char* errorC = new char[errorS.length() + 1];
            strcpy(errorC, errorS.c_str());
            yyerror(errorC);
      }
      else {
            ht_insert_lines_used(ht, identifier.name, index, identifier.line_used, current_scope);
      }
}

void insert_table_func_def(Var_Types type, variable_line identifier) {
      unsigned short temp_scope = current_scope;
      current_scope = 0;
      insert_table_var_def(type, identifier);
      current_scope = temp_scope;
}

void insert_table(Var_Types type, variable_line identifier) {
      char* nombre = identifier.name;
      unsigned long lugar = identifier.line_used;
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
                  bytesize = 256;
                  break;
            case CONST_ENTERO:
                  bytesize = 4;
                  break;
            case CONST_REAL:
                  bytesize = 6;
                  break;
            case CONST_CADENA:
                  bytesize = 256;
                  break;
            default:
                  bytesize = 0;
                  break;
      }
      data_value datos = {mem_acum, type, bytesize, lugar, "", current_scope};
      ht_insert(ht, nombre, datos);
      mem_acum += bytesize;
}

void insert_table_defsize(Var_Types type, variable_line identifier, unsigned long size) {
      char* nombre = identifier.name;
      unsigned long lugar = identifier.line_used;
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
      bytesize *= size;
      data_value datos = {mem_acum, type, bytesize, lugar, nombre, scope};
      ht_insert(ht, nombre, datos);      mem_acum += bytesize;
}

int main( int argc, char* argv[] )
{
	++argv, --argc;
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

      printf("Ya acabe king\n");

      //print_table(ht);

      return 0;
}
