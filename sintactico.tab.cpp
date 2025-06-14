
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
      #include <iostream>
      #include <vector>
      #include <string>
      #include <string.h>
      #include <cstring>
      #include "hash_table.h"
      #include "codegen.h"
	#pragma warning(disable: 4013 4244 4267 4996)
	extern FILE * yyin;   
      extern int yylineno; 

      //yydebug = 1;
      void yyerror(const char* s);
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

      bool warning = false;



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
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
     OF = 265,
     IF = 266,
     THEN = 267,
     ELSE = 268,
     WHILE = 269,
     DO = 270,
     FOR = 271,
     TO = 272,
     DOWNTO = 273,
     READ = 274,
     READLN = 275,
     WRITE = 276,
     WRITELN = 277,
     AND = 278,
     OR = 279,
     NOT = 280,
     DIV = 281,
     MOD = 282,
     LPAREN = 283,
     RPAREN = 284,
     LBRACKET = 285,
     RBRACKET = 286,
     PLUS = 287,
     MINUS = 288,
     ASTERISK = 289,
     SLASH = 290,
     EQUALS = 291,
     COLON = 292,
     SEMICOLON = 293,
     COMMA = 294,
     PERIOD = 295,
     EXP = 296,
     CADENA = 297,
     LESSTHAN = 298,
     GREATERTHAN = 299,
     LESSTHANEQUALS = 300,
     GREATERTHANEQUALS = 301,
     NOTEQUALS = 302,
     IDENTIFICADOR = 303,
     ARRAY = 304,
     INTEGER_TIPO = 305,
     REAL_TIPO = 306,
     STRING_TIPO = 307,
     BOOLEAN_TIPO = 308,
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
#define YYLAST   286

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  55
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNRULES -- Number of states.  */
#define YYNSTATES  215

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
      48,    50,    52,    54,    56,    60,    62,    64,    71,    72,
      79,    86,    93,    94,    96,   106,   108,   110,   112,   114,
     118,   119,   123,   124,   125,   134,   135,   141,   145,   146,
     150,   156,   160,   162,   163,   165,   169,   171,   173,   175,
     177,   179,   181,   183,   188,   195,   202,   207,   212,   219,
     226,   231,   236,   243,   250,   255,   260,   267,   272,   277,
     279,   281,   283,   288,   290,   295,   299,   303,   306,   310,
     312,   316,   318,   322,   326,   330,   332,   337,   342,   344,
     346,   349,   353,   355,   357,   358,   361,   363,   368
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      56,     0,    -1,    -1,    -1,    -1,     3,    57,    61,    58,
      28,    66,    59,    29,    38,    60,    40,    -1,    67,    72,
      80,    -1,    48,    -1,    23,    -1,    24,    -1,    36,    -1,
      43,    -1,    44,    -1,    45,    -1,    46,    -1,    47,    -1,
      32,    -1,    33,    -1,    34,    -1,    35,    -1,    26,    -1,
      27,    -1,    42,    -1,    61,    -1,    66,    39,    61,    -1,
      68,    -1,    69,    -1,    68,     4,    66,    37,    70,    38,
      -1,    -1,    69,     5,    61,    36,    97,    38,    -1,    69,
       5,    61,    36,    99,    38,    -1,    69,     5,    61,    36,
      65,    38,    -1,    -1,    71,    -1,    49,    30,    54,    40,
      40,    54,    31,    10,    71,    -1,    50,    -1,    51,    -1,
      52,    -1,    53,    -1,    72,    73,    38,    -1,    -1,    74,
      67,    80,    -1,    -1,    -1,     6,    75,    61,    78,    37,
      71,    76,    38,    -1,    -1,     7,    77,    61,    78,    38,
      -1,    28,    79,    29,    -1,    -1,    66,    37,    70,    -1,
      79,    38,    66,    37,    70,    -1,     8,    81,     9,    -1,
      82,    -1,    -1,    83,    -1,    82,    38,    83,    -1,    88,
      -1,    91,    -1,    80,    -1,    87,    -1,    84,    -1,    85,
      -1,    86,    -1,    14,    92,    15,    83,    -1,    16,    89,
      17,    95,    15,    83,    -1,    16,    89,    18,    95,    15,
      83,    -1,    19,    28,    61,    29,    -1,    20,    28,    61,
      29,    -1,    21,    28,    65,    39,    61,    29,    -1,    22,
      28,    65,    39,    61,    29,    -1,    21,    28,    65,    29,
      -1,    22,    28,    65,    29,    -1,    21,    28,    65,    39,
      95,    29,    -1,    22,    28,    65,    39,    95,    29,    -1,
      21,    28,    61,    29,    -1,    22,    28,    61,    29,    -1,
      11,    92,    12,    83,    13,    83,    -1,    11,    92,    12,
      83,    -1,    90,    37,    36,    95,    -1,    88,    -1,    90,
      -1,    61,    -1,    61,    30,    95,    31,    -1,    61,    -1,
      61,    28,    94,    29,    -1,    92,    24,    92,    -1,    92,
      23,    92,    -1,    25,    92,    -1,    28,    92,    29,    -1,
      93,    -1,    95,    62,    95,    -1,    95,    -1,    94,    39,
      95,    -1,    95,    63,    95,    -1,    95,    64,    95,    -1,
      61,    -1,    61,    30,    95,    31,    -1,    61,    28,    94,
      29,    -1,    97,    -1,    99,    -1,    96,    95,    -1,    28,
      95,    29,    -1,    32,    -1,    33,    -1,    -1,    96,    98,
      -1,    54,    -1,    96,    54,    40,    54,    -1,    96,    41,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    74,    74,    78,    84,    73,   119,   127,   140,   146,
     152,   158,   164,   170,   176,   182,   190,   196,   204,   210,
     216,   222,   230,   238,   242,   255,   259,   265,   286,   291,
     311,   331,   352,   357,   361,   379,   387,   395,   403,   413,
     429,   434,   443,   448,   442,   460,   459,   476,   481,   486,
     497,   516,   526,   531,   536,   540,   553,   559,   565,   571,
     577,   583,   589,   597,   604,   611,   620,   627,   636,   647,
     658,   665,   672,   679,   686,   697,   710,   717,   726,   739,
     743,   749,   753,   761,   769,   776,   783,   790,   797,   804,
     810,   817,   821,   834,   841,   848,   855,   862,   869,   876,
     883,   890,   899,   905,   912,   917,   925,   933,   942
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "VAR", "CONST", "FUNCTION",
  "PROCEDURE", "BEG", "END", "OF", "IF", "THEN", "ELSE", "WHILE", "DO",
  "FOR", "TO", "DOWNTO", "READ", "READLN", "WRITE", "WRITELN", "AND", "OR",
  "NOT", "DIV", "MOD", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "PLUS",
  "MINUS", "ASTERISK", "SLASH", "EQUALS", "COLON", "SEMICOLON", "COMMA",
  "PERIOD", "EXP", "CADENA", "LESSTHAN", "GREATERTHAN", "LESSTHANEQUALS",
  "GREATERTHANEQUALS", "NOTEQUALS", "IDENTIFICADOR", "ARRAY",
  "INTEGER_TIPO", "REAL_TIPO", "STRING_TIPO", "BOOLEAN_TIPO", "NUM_ENTERO",
  "$accept", "programa", "$@1", "$@2", "$@3", "contenido_programa",
  "identificador", "relop", "addop", "mulop", "cadena",
  "identificador_lista", "declaraciones", "declaraciones_variables",
  "declaraciones_constantes", "tipo", "estandar_tipo",
  "subprograma_declaraciones", "subprograma_declaracion",
  "subprograma_encabezado", "$@4", "$@5", "$@6", "argumentos",
  "parametros_lista", "instruccion_compuesta", "instrucciones_opcionales",
  "instrucciones_lista", "instrucciones", "repeticion_instruccion",
  "lectura_instruccion", "escritura_instruccion", "if_instruccion",
  "variable_asignacion", "for_asignacion", "variable",
  "procedure_instruccion", "relop_expresion", "relop_expresion_simple",
  "expresion_lista", "expresion", "signo", "constante_entera", "numero",
  "constante_real", 0
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
      64,    64,    65,    66,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    70,    70,    71,    71,    71,    71,    72,
      72,    73,    75,    76,    74,    77,    74,    78,    78,    79,
      79,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    83,    84,    84,    84,    85,    85,    86,    86,
      86,    86,    86,    86,    86,    86,    87,    87,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    92,    92,    92,
      93,    94,    94,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    96,    96,    97,    98,    99,    99
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     0,     0,    11,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     1,     6,     0,     6,
       6,     6,     0,     1,     9,     1,     1,     1,     1,     3,
       0,     3,     0,     0,     8,     0,     5,     3,     0,     3,
       5,     3,     1,     0,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     4,     6,     6,     4,     4,     6,     6,
       4,     4,     6,     6,     4,     4,     6,     4,     4,     1,
       1,     1,     4,     1,     4,     3,     3,     2,     3,     1,
       3,     1,     3,     3,     3,     1,     4,     4,     1,     1,
       2,     3,     1,     1,     0,     2,     1,     4,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     2,     0,     0,     1,     7,     3,     0,     0,    23,
       4,     0,     0,    24,     0,    28,     0,    40,    25,    26,
       5,     0,     0,     0,    42,    45,    53,     0,    28,     6,
       0,     0,     0,     0,   104,   104,     0,     0,     0,     0,
       0,    83,    58,     0,    52,    54,    60,    61,    62,    59,
      56,     0,    57,    39,     0,     0,   104,    48,    48,   104,
     104,   102,   103,    95,     0,    89,     0,     0,    98,    99,
       0,    81,    79,     0,    80,     0,     0,     0,     0,   104,
     104,    51,     0,     0,    41,     0,    35,    36,    37,    38,
       0,    33,    22,     0,     0,     0,     0,     0,     0,     0,
      87,     0,     0,   104,   104,     0,   104,   104,     8,     9,
      20,    21,    16,    17,    18,    19,    10,    11,    12,    13,
      14,    15,   104,   104,   104,   104,   108,   106,   100,   105,
       0,   104,   104,     0,     0,     0,     0,     0,     0,     0,
      91,     0,    55,   104,     0,    27,    31,    29,    30,     0,
       0,     0,    46,    88,   101,     0,     0,    77,    86,    85,
      90,    93,    94,     0,     0,    63,     0,     0,    66,    67,
      74,    70,   104,    75,    71,   104,    84,   104,    82,    78,
       0,     0,    47,     0,    43,    97,    96,     0,   107,     0,
       0,    95,     0,    95,     0,    92,     0,    49,     0,     0,
      76,    64,    65,    68,    72,    69,    73,     0,     0,    44,
       0,    50,     0,     0,    34
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     7,    12,    16,    63,   122,   123,   124,
      93,    10,    17,    18,    19,    90,    91,    21,    27,    28,
      32,   199,    33,    98,   150,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    73,    51,    52,    64,    65,   139,
      66,    67,    68,   129,    69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -171
static const yytype_int16 yypact[] =
{
       4,  -171,    18,    -9,  -171,  -171,  -171,    39,    -9,  -171,
      49,    -9,    90,  -171,    94,   134,   104,  -171,   152,   163,
    -171,   175,    -9,    -9,  -171,  -171,    37,   132,   134,  -171,
       5,   135,    -9,    -9,   -16,   -16,    -9,   145,   151,   157,
     164,   113,  -171,   181,   153,  -171,  -171,  -171,  -171,  -171,
    -171,   165,  -171,  -171,   204,   193,   -11,   173,   173,   -16,
     -16,  -171,  -171,    92,    72,  -171,   131,    59,  -171,  -171,
      93,   170,  -171,    48,   165,    -9,    -9,   111,   111,    82,
      82,  -171,    37,   174,  -171,   183,  -171,  -171,  -171,  -171,
     184,  -171,  -171,   185,   -26,   219,   220,    -9,   222,   224,
     128,    17,   102,    82,    82,    37,   -16,   -16,  -171,  -171,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,  -171,
    -171,  -171,    82,    82,    82,    82,  -171,   180,   206,  -171,
      37,    82,    82,   201,   231,   232,   -15,   234,     8,    51,
     206,   162,  -171,    82,   210,  -171,  -171,  -171,  -171,    62,
      95,   197,  -171,  -171,  -171,    54,   172,   252,   128,   128,
     206,   206,   206,   182,   212,  -171,    28,    71,  -171,  -171,
    -171,  -171,    82,  -171,  -171,    82,  -171,    82,  -171,   206,
     227,   193,  -171,    -9,  -171,  -171,  -171,    37,  -171,    37,
      37,   223,   192,   226,   202,   206,   228,  -171,   103,   233,
    -171,  -171,  -171,  -171,  -171,  -171,  -171,   215,   193,  -171,
     239,  -171,   262,   197,  -171
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -171,  -171,  -171,  -171,  -171,  -171,    -3,  -171,  -171,  -171,
      83,   -21,   245,  -171,  -171,  -170,  -149,  -171,  -171,  -171,
    -171,  -171,  -171,   216,  -171,   -18,  -171,  -171,   -78,  -171,
    -171,  -171,  -171,   240,  -171,   241,  -171,   -25,  -171,   176,
     -54,   225,   229,  -171,   230
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -82
static const yytype_int16 yytable[] =
{
       6,    30,   184,    29,   142,     9,   102,     1,    13,    59,
      70,   197,    60,   128,   171,   126,    61,    62,     4,     9,
      31,    61,    62,    41,   172,   140,   141,   157,   127,    57,
      58,    92,     5,    71,   100,   101,    84,   174,   211,     5,
     106,   107,    55,   189,    11,    26,   153,   175,    34,   140,
     156,    35,   165,    36,   110,   111,    37,    38,    39,    40,
     112,   113,   114,   115,   214,   131,   132,     8,   160,   161,
     162,   163,   133,   134,   135,   137,   149,   166,   167,    41,
     176,   158,   159,   185,   105,     5,   190,   125,    11,   179,
     177,    61,    62,   177,     9,   106,   107,   110,   111,   181,
     126,    11,    41,   112,   113,   114,   115,     5,   130,   200,
     125,   201,   202,   127,    61,    62,   106,   107,   192,    14,
     103,   194,   104,   195,   182,   108,   109,    41,   110,   111,
       5,   154,    15,   183,   112,   113,   114,   115,   116,   -32,
     208,    79,    11,    80,    20,   117,   118,   119,   120,   121,
     -81,   106,   107,    92,   108,   109,    22,   110,   111,     5,
     136,   138,   198,   112,   113,   114,   115,   116,    23,   191,
      53,    56,   193,    75,   117,   118,   119,   120,   121,    76,
       9,    24,    25,    26,    41,    77,    41,    41,   110,   111,
      81,    82,    78,   178,   112,   113,   114,   115,   110,   111,
      80,    97,    83,   186,   112,   113,   114,   115,   110,   111,
     143,   154,    26,   144,   112,   113,   114,   115,   110,   111,
     164,   204,   145,   146,   112,   113,   114,   115,   110,   111,
     168,   206,   110,   111,   112,   113,   114,   115,   112,   113,
     114,   115,    85,    86,    87,    88,    89,    86,    87,    88,
      89,   103,   203,   104,   103,   205,   104,   147,   148,   151,
     169,   170,   152,   173,   180,   187,   188,   196,   207,   210,
     212,   209,   213,    54,    99,     0,    72,    74,     0,   155,
       0,    94,     0,     0,     0,    95,    96
};

static const yytype_int16 yycheck[] =
{
       3,    22,   151,    21,    82,     8,    60,     3,    11,    25,
      35,   181,    28,    67,    29,    41,    32,    33,     0,    22,
      23,    32,    33,    26,    39,    79,    80,   105,    54,    32,
      33,    42,    48,    36,    59,    60,    54,    29,   208,    48,
      23,    24,    37,    15,    39,     8,    29,    39,    11,   103,
     104,    14,   130,    16,    26,    27,    19,    20,    21,    22,
      32,    33,    34,    35,   213,    17,    18,    28,   122,   123,
     124,   125,    75,    76,    77,    78,    97,   131,   132,    82,
      29,   106,   107,    29,    12,    48,    15,    28,    39,   143,
      39,    32,    33,    39,    97,    23,    24,    26,    27,    37,
      41,    39,   105,    32,    33,    34,    35,    48,    15,   187,
      28,   189,   190,    54,    32,    33,    23,    24,   172,    29,
      28,   175,    30,   177,    29,    23,    24,   130,    26,    27,
      48,    29,    38,    38,    32,    33,    34,    35,    36,     5,
      37,    28,    39,    30,    40,    43,    44,    45,    46,    47,
      37,    23,    24,    42,    23,    24,     4,    26,    27,    48,
      77,    78,   183,    32,    33,    34,    35,    36,     5,   172,
      38,    36,   175,    28,    43,    44,    45,    46,    47,    28,
     183,     6,     7,     8,   187,    28,   189,   190,    26,    27,
       9,    38,    28,    31,    32,    33,    34,    35,    26,    27,
      30,    28,    37,    31,    32,    33,    34,    35,    26,    27,
      36,    29,     8,    30,    32,    33,    34,    35,    26,    27,
      40,    29,    38,    38,    32,    33,    34,    35,    26,    27,
      29,    29,    26,    27,    32,    33,    34,    35,    32,    33,
      34,    35,    49,    50,    51,    52,    53,    50,    51,    52,
      53,    28,    29,    30,    28,    29,    30,    38,    38,    37,
      29,    29,    38,    29,    54,    13,    54,    40,    40,    54,
      31,    38,    10,    28,    58,    -1,    36,    36,    -1,   103,
      -1,    56,    -1,    -1,    -1,    56,    56
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    56,    57,     0,    48,    61,    58,    28,    61,
      66,    39,    59,    61,    29,    38,    60,    67,    68,    69,
      40,    72,     4,     5,     6,     7,     8,    73,    74,    80,
      66,    61,    75,    77,    11,    14,    16,    19,    20,    21,
      22,    61,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    90,    91,    38,    67,    37,    36,    61,    61,    25,
      28,    32,    33,    61,    92,    93,    95,    96,    97,    99,
      92,    61,    88,    89,    90,    28,    28,    28,    28,    28,
      30,     9,    38,    37,    80,    49,    50,    51,    52,    53,
      70,    71,    42,    65,    96,    97,    99,    28,    78,    78,
      92,    92,    95,    28,    30,    12,    23,    24,    23,    24,
      26,    27,    32,    33,    34,    35,    36,    43,    44,    45,
      46,    47,    62,    63,    64,    28,    41,    54,    95,    98,
      15,    17,    18,    61,    61,    61,    65,    61,    65,    94,
      95,    95,    83,    36,    30,    38,    38,    38,    38,    66,
      79,    37,    38,    29,    29,    94,    95,    83,    92,    92,
      95,    95,    95,    95,    40,    83,    95,    95,    29,    29,
      29,    29,    39,    29,    29,    39,    29,    39,    31,    95,
      54,    37,    29,    38,    71,    29,    31,    13,    54,    15,
      15,    61,    95,    61,    95,    95,    40,    70,    66,    76,
      83,    83,    83,    29,    29,    29,    29,    40,    37,    38,
      54,    70,    31,    10,    71
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
                  insert_table_var_used(VOID, {last[last.size() - 1].name, 0});
                  last.clear();
            ;}
    break;

  case 4:

    {
                  for (unsigned int i = 0; i < last.size(); i++) {
                        insert_table_var_def(VOID, last[i]);
                        insert_table_var_used(VOID, {last[i].name, 0});
                  }
                  last.clear();
            ;}
    break;

  case 5:

    {
                  if (current_scope != 0) {
                        printf("Error, algun scope no se cerro correctamente");
                        warning = true;
                  }

                  Nodo* raiz = crearNodo("PROGRAMA");
                  
                  insertarNodoHijos(raiz, (yyvsp[(3) - (11)].nodo), (yyvsp[(6) - (11)].nodo), (yyvsp[(10) - (11)].nodo));
                  (yyval.nodo) = raiz; 

                  string vars = "";
                  if (ht_return_all_values_not_used(ht, vars)) {
                        printf("Warning[Variables sin uso]: variables definidas, pero nunca usadas: %s\n", vars.c_str());
                        warning = 1;
                  }

                  print_table(ht);

                  imprimirArbolFinal(raiz);

                  generar(raiz, warning);

                  limpiarArbol(raiz);
            ;}
    break;

  case 6:

    {
                        Nodo* nodo = crearNodo("CONTENIDO_PROGRAMA");
                        insertarNodoHijos(nodo, (yyvsp[(1) - (3)].nodo), (yyvsp[(2) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
                        (yyval.nodo) = nodo;
                   ;}
    break;

  case 7:

    {
                        char* var_name = strdup((yyvsp[(1) - (1)].cadena));
                        int var_line = (yylsp[(1) - (1)]).last_line;
                        last.push_back({var_name, var_line}); 

                        Nodo* nodo = crearNodo("ID");
                        nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
                        (yyval.nodo) = nodo;
                            
                  ;}
    break;

  case 8:

    {
            Nodo* nodo = crearNodo("RELOP");
            nodo->valorCadena = strdup("&&");
            (yyval.nodo) = nodo;
      ;}
    break;

  case 9:

    {
            Nodo* nodo = crearNodo("RELOP");
            nodo->valorCadena = strdup("||");
            (yyval.nodo) = nodo;
      ;}
    break;

  case 10:

    {
            Nodo* nodo = crearNodo("RELOP");
            nodo->valorCadena = strdup("==");
            (yyval.nodo) = nodo;
      ;}
    break;

  case 11:

    {
            Nodo* nodo = crearNodo("RELOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 12:

    {
            Nodo* nodo = crearNodo("RELOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 13:

    {
            Nodo* nodo = crearNodo("RELOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 14:

    {
            Nodo* nodo = crearNodo("RELOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 15:

    {
            Nodo* nodo = crearNodo("RELOP");
            nodo->valorCadena = strdup("!=");
            (yyval.nodo) = nodo;
      ;}
    break;

  case 16:

    {
            Nodo* nodo = crearNodo("ADDOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 17:

    {
            Nodo* nodo = crearNodo("ADDOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 18:

    {
            Nodo* nodo = crearNodo("MULOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 19:

    {
            Nodo* nodo = crearNodo("MULOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 20:

    {
            Nodo* nodo = crearNodo("MULOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 21:

    {
            Nodo* nodo = crearNodo("MULOP");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 22:

    {
            Nodo* nodo = crearNodo("CADENA_CONST");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 23:

    {
                        (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
                    ;}
    break;

  case 24:

    {
                        Nodo* temp = (yyvsp[(1) - (3)].nodo);
                        if(temp){
                              while(temp->hermano != nullptr){
                                    temp = temp->hermano;
                              }
                              agregarHermano(temp, (yyvsp[(3) - (3)].nodo));
                              (yyval.nodo) = (yyvsp[(1) - (3)].nodo);
                        }
                    ;}
    break;

  case 25:

    {
                  (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
              ;}
    break;

  case 26:

    {
                  (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
              ;}
    break;

  case 27:

    {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(last_variable_type, last[i]);
                              }
                              last.clear();

                              Nodo* temp = (yyvsp[(1) - (6)].nodo);
                              if(temp){
                                    agregarHijo(temp, (yyvsp[(3) - (6)].nodo));
                                    agregarHijo((yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                                    (yyval.nodo) = (yyvsp[(1) - (6)].nodo);
                              }
                              else{
                                    Nodo* nodo = crearNodo("DECLARACIONES_VARIABLES");
                                    insertarNodoHijos(nodo, (yyvsp[(1) - (6)].nodo), (yyvsp[(3) - (6)].nodo));
                                    agregarHijo((yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                                    (yyval.nodo) = nodo;
                              }
                        ;}
    break;

  case 28:

    {
                              (yyval.nodo) = NULL;
                        ;}
    break;

  case 29:

    {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_ENTERO, last[i]);
                              }
                              last.clear();

                              Nodo* temp = (yyvsp[(1) - (6)].nodo);
                              if(temp){
                                    agregarHijo(temp, (yyvsp[(3) - (6)].nodo));
                                    agregarHijo((yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                                    (yyval.nodo) = (yyvsp[(1) - (6)].nodo);
                              }
                              else{
                                    Nodo* nodo = crearNodo("DECLARACIONES_CONSTANTES");
                                    insertarNodoHijos(nodo, (yyvsp[(1) - (6)].nodo), (yyvsp[(3) - (6)].nodo));
                                    agregarHijo((yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                                    (yyval.nodo) = nodo;
                              }
                         ;}
    break;

  case 30:

    {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_REAL, last[i]);
                              }
                              last.clear();

                              Nodo* temp = (yyvsp[(1) - (6)].nodo);
                              if(temp){
                                    agregarHijo(temp, (yyvsp[(3) - (6)].nodo));
                                    agregarHijo((yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                                    (yyval.nodo) = (yyvsp[(1) - (6)].nodo);
                              }
                              else{
                                    Nodo* nodo = crearNodo("DECLARACIONES_CONSTANTES");
                                    insertarNodoHijos(nodo, (yyvsp[(1) - (6)].nodo), (yyvsp[(3) - (6)].nodo));
                                    agregarHijo((yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                                    (yyval.nodo) = nodo;
                              }
                        ;}
    break;

  case 31:

    {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_CADENA, last[i]);
                              }
                              last.clear();

                              Nodo* temp = (yyvsp[(1) - (6)].nodo);
                              if(temp){
                                    agregarHijo(temp, (yyvsp[(3) - (6)].nodo));
                                    agregarHijo((yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                                    (yyval.nodo) = (yyvsp[(1) - (6)].nodo);
                              }
                              else{
                                    Nodo* nodo = crearNodo("DECLARACIONES_CONSTANTES");
                                    insertarNodoHijos(nodo, (yyvsp[(1) - (6)].nodo), (yyvsp[(3) - (6)].nodo));
                                    agregarHijo((yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                                    (yyval.nodo) = nodo;
                              }
                         ;}
    break;

  case 32:

    {
                              (yyval.nodo) = NULL;
                         ;}
    break;

  case 33:

    {
      (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
     ;}
    break;

  case 34:

    {
      for (unsigned int i = 0; i < last.size(); i++) {
            insert_table_defsize(last_variable_type, last[i], stoi((yyvsp[(6) - (9)].cadena)) - stoi((yyvsp[(3) - (9)].cadena)) + 1);
      }
      last.clear();

      Nodo* nodo = crearNodo("ESTANDAR_TIPO");
      nodo->valorCadena = strdup((yyvsp[(1) - (9)].cadena));
      Nodo* hijo1 = crearNodo("ESTANDAR_TIPO");
      hijo1->valorCadena = strdup((yyvsp[(3) - (9)].cadena));
      Nodo* hijo2 = crearNodo("ESTANDAR_TIPO");
      hijo2->valorCadena = strdup((yyvsp[(6) - (9)].cadena));
      insertarNodoHijos(nodo, hijo1, hijo2, (yyvsp[(9) - (9)].nodo));
      (yyval.nodo) = nodo;
     ;}
    break;

  case 35:

    { 
                  last_variable_type = INTEGER;

                  Nodo* nodo = crearNodo("ESTANDAR_TIPO");
                  nodo->valorCadena = strdup("int");
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 36:

    { 
                  last_variable_type = FLOAT;

                  Nodo* nodo = crearNodo("ESTANDAR_TIPO");
                  nodo->valorCadena = strdup("float");
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 37:

    { 
                  last_variable_type = STRING;

                  Nodo* nodo = crearNodo("ESTANDAR_TIPO");
                  nodo->valorCadena = strdup("string");
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 38:

    { 
                  last_variable_type = BOOLEAN;

                  Nodo* nodo = crearNodo("ESTANDAR_TIPO");
                  nodo->valorCadena = strdup("bool");
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 39:

    {
                              Nodo* temp = (yyvsp[(1) - (3)].nodo);
                              if(temp){
                                    while(temp->hermano != nullptr){
                                          temp = temp->hermano;
                                    }
                                    agregarHermano(temp, (yyvsp[(2) - (3)].nodo));
                                    (yyval.nodo) = (yyvsp[(1) - (3)].nodo);
                              } else {
                                    Nodo* nodo = (yyvsp[(2) - (3)].nodo);
                                    insertarNodoHijos(nodo, (yyvsp[(1) - (3)].nodo));
                                    (yyval.nodo) = nodo;
                              }
                          ;}
    break;

  case 40:

    {
                              (yyval.nodo) = NULL;
                          ;}
    break;

  case 41:

    {
                              Nodo* nodo = crearNodo("SUBPROGRAMA_DECLARACION");
                              insertarNodoHijos(nodo, (yyvsp[(1) - (3)].nodo), (yyvsp[(2) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
                              (yyval.nodo) = nodo;
                        ;}
    break;

  case 42:

    {
                              scope++;
                              current_scope = scope;
                        ;}
    break;

  case 43:

    {
                              insert_table_func_def(last_variable_type, last[0]);
                              last.clear();
                        ;}
    break;

  case 44:

    {
                              Nodo* nodo = crearNodo("SUBPROGRAMA_ENCABEZADO");
                              nodo->valorCadena = strdup("function");
                              insertarNodoHijos(nodo, (yyvsp[(3) - (8)].nodo), (yyvsp[(4) - (8)].nodo), (yyvsp[(6) - (8)].nodo));
                              (yyval.nodo) = nodo;
                        ;}
    break;

  case 45:

    {
                              scope++;
                              current_scope = scope;
                        ;}
    break;

  case 46:

    {
                              insert_table_func_def(VOID, last[0]);
                              last.clear();

                              Nodo* nodo = crearNodo("SUBPROGRAMA_ENCABEZADO");
                              nodo->valorCadena = strdup("procedure");
                              insertarNodoHijos(nodo, (yyvsp[(3) - (5)].nodo), (yyvsp[(4) - (5)].nodo));
                              (yyval.nodo) = nodo;
                       ;}
    break;

  case 47:

    {
            (yyval.nodo) = (yyvsp[(2) - (3)].nodo);
           ;}
    break;

  case 48:

    {
            (yyval.nodo) = NULL;
           ;}
    break;

  case 49:

    {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }
                  Nodo* nodo = crearNodo("PARAMETROS_LISTA");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (3)].nodo));
                  insertarNodoHijos((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
                  (yyval.nodo) = nodo;
                 ;}
    break;

  case 50:

    {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }

                  Nodo* temp = (yyvsp[(1) - (5)].nodo);
                  if(temp){
                        while(temp->hermano != nullptr){
                              temp = temp->hermano;
                        }
                        agregarHijo(temp, (yyvsp[(3) - (5)].nodo));
                        agregarHijo((yyvsp[(3) - (5)].nodo), (yyvsp[(5) - (5)].nodo));
                        (yyval.nodo) = (yyvsp[(1) - (5)].nodo);
                  }
                 ;}
    break;

  case 51:

    { 
                              current_scope = 0;
                              Nodo* nodo = crearNodo("INSTRUCCION_COMPUESTA");
                              insertarNodoHijos(nodo, (yyvsp[(2) - (3)].nodo));
                              (yyval.nodo) = nodo;
                        ;}
    break;

  case 52:

    {
                              (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
                         ;}
    break;

  case 53:

    {
                              (yyval.nodo) = NULL;
                         ;}
    break;

  case 54:

    {
                        (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
                    ;}
    break;

  case 55:

    {
                        Nodo* temp = (yyvsp[(1) - (3)].nodo);
                        if(temp){
                              while(temp->hermano != nullptr){
                                    temp = temp->hermano;
                              }
                              agregarHermano(temp, (yyvsp[(3) - (3)].nodo));
                              (yyval.nodo) = (yyvsp[(1) - (3)].nodo);
                        }
                    ;}
    break;

  case 56:

    {
                  Nodo* nodo = crearNodo("INSTRUCCIONES");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 57:

    {
                  Nodo* nodo = crearNodo("INSTRUCCIONES");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 58:

    {
                  Nodo* nodo = crearNodo("INSTRUCCIONES");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 59:

    {
                  Nodo* nodo = crearNodo("INSTRUCCIONES");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 60:

    {
                  Nodo* nodo = crearNodo("INSTRUCCIONES");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 61:

    {
                  Nodo* nodo = crearNodo("INSTRUCCIONES");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 62:

    {
                  Nodo* nodo = crearNodo("INSTRUCCIONES");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
              ;}
    break;

  case 63:

    {
                        Nodo* nodo = crearNodo("REPETICION_INSTRUCCION");
                        nodo->valorCadena = strdup("while");
                        insertarNodoHijos(nodo, (yyvsp[(2) - (4)].nodo), (yyvsp[(4) - (4)].nodo));
                        (yyval.nodo) = nodo;
                       ;}
    break;

  case 64:

    {
                        Nodo* nodo = crearNodo("REPETICION_INSTRUCCION");
                        nodo->valorCadena = strdup("for++");
                        insertarNodoHijos(nodo, (yyvsp[(2) - (6)].nodo), (yyvsp[(4) - (6)].nodo), (yyvsp[(6) - (6)].nodo));
                        (yyval.nodo) = nodo;
                       ;}
    break;

  case 65:

    {
                        Nodo* nodo = crearNodo("REPETICION_INSTRUCCION");
                        nodo->valorCadena = strdup("for--");
                        insertarNodoHijos(nodo, (yyvsp[(2) - (6)].nodo), (yyvsp[(4) - (6)].nodo), (yyvsp[(6) - (6)].nodo));
                        (yyval.nodo) = nodo;
                       ;}
    break;

  case 66:

    {
                        Nodo* nodo = crearNodo("LECTURA_INSTRUCCION");
                        nodo->valorCadena = strdup("read");
                        agregarHijo(nodo, (yyvsp[(3) - (4)].nodo));
                        (yyval.nodo) = nodo;
                    ;}
    break;

  case 67:

    {
                        Nodo* nodo = crearNodo("LECTURA_INSTRUCCION");
                        nodo->valorCadena = strdup("readln");
                        agregarHijo(nodo, (yyvsp[(3) - (4)].nodo));
                        (yyval.nodo) = nodo;
                    ;}
    break;

  case 68:

    {

                        insert_table_var_used(last_variable_type, last[0]);
                        last.clear();

                        Nodo* nodo = crearNodo("ESCRITURA_INSTRUCCION");
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, (yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 69:

    {

                        insert_table_var_used(last_variable_type, last[0]);
                        last.clear();

                        Nodo* nodo = crearNodo("ESCRITURA_INSTRUCCION");
                        nodo->valorCadena = strdup("writeln");
                        insertarNodoHijos(nodo, (yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 70:

    {
                        Nodo* nodo = crearNodo("ESCRITURA_INSTRUCCION");
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, (yyvsp[(3) - (4)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 71:

    {
                        Nodo* nodo = crearNodo("ESCRITURA_INSTRUCCION");
                        nodo->valorCadena = strdup("writeln");
                        insertarNodoHijos(nodo, (yyvsp[(3) - (4)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 72:

    {
                        Nodo* nodo = crearNodo("ESCRITURA_INSTRUCCION");
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, (yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 73:

    {
                        Nodo* nodo = crearNodo("ESCRITURA_INSTRUCCION");
                        nodo->valorCadena = strdup("writeln");
                        insertarNodoHijos(nodo, (yyvsp[(3) - (6)].nodo), (yyvsp[(5) - (6)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 74:

    {

                        insert_table_var_used(last_variable_type, last[0]);
                        last.clear();

                        Nodo* nodo = crearNodo("ESCRITURA_INSTRUCCION");
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, (yyvsp[(3) - (4)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 75:

    {

                        insert_table_var_used(last_variable_type, last[0]);
                        last.clear();

                        Nodo* nodo = crearNodo("ESCRITURA_INSTRUCCION");
                        nodo->valorCadena = strdup("writeln");
                        insertarNodoHijos(nodo, (yyvsp[(3) - (4)].nodo));
                        (yyval.nodo) = nodo;
                       ;}
    break;

  case 76:

    {
                  Nodo* nodo = crearNodo("IF_INSTRUCCION");
                  nodo->valorCadena = strdup("if");
                  insertarNodoHijos(nodo, (yyvsp[(2) - (6)].nodo), (yyvsp[(4) - (6)].nodo), (yyvsp[(6) - (6)].nodo));
                  (yyval.nodo) = nodo;
               ;}
    break;

  case 77:

    {
                  Nodo* nodo = crearNodo("IF_INSTRUCCION");
                  nodo->valorCadena = strdup("if");
                  insertarNodoHijos(nodo, (yyvsp[(2) - (4)].nodo), (yyvsp[(4) - (4)].nodo));
                  (yyval.nodo) = nodo;
               ;}
    break;

  case 78:

    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        Nodo* nodo = crearNodo("VARIABLE_ASIGNACION");
                        insertarNodoHijos(nodo, (yyvsp[(1) - (4)].nodo), (yyvsp[(4) - (4)].nodo));
                        (yyval.nodo) = nodo;
                    ;}
    break;

  case 79:

    {
                  (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
               ;}
    break;

  case 80:

    {
                  (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
               ;}
    break;

  case 81:

    {
            (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
         ;}
    break;

  case 82:

    {
            Nodo* nodo = crearNodo("VARIABLE");
            insertarNodoHijos(nodo, (yyvsp[(1) - (4)].nodo), (yyvsp[(3) - (4)].nodo));
            (yyval.nodo) = nodo;
         ;}
    break;

  case 83:

    {
                        insert_table_var_used(VOID, last[0]);
                        last.clear();
                        Nodo* nodo = crearNodo("PROCEDURE_INSTRUCCION");
                        insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 84:

    {
                        Nodo* nodo = crearNodo("PROCEDURE_INSTRUCCION");
                        insertarNodoHijos(nodo, (yyvsp[(1) - (4)].nodo), (yyvsp[(3) - (4)].nodo));
                        (yyval.nodo) = nodo;
                      ;}
    break;

  case 85:

    {
                  Nodo* nodo = crearNodo("RELOP_EXPRESION");
                  nodo->valorCadena = strdup("||");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
                  (yyval.nodo) = nodo;
               ;}
    break;

  case 86:

    {
                  Nodo* nodo = crearNodo("RELOP_EXPRESION");
                  nodo->valorCadena = strdup("&&");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
                  (yyval.nodo) = nodo;
               ;}
    break;

  case 87:

    {
                  Nodo* nodo = crearNodo("RELOP_EXPRESION");
                  nodo->valorCadena = strdup("!");
                  insertarNodoHijos(nodo, (yyvsp[(2) - (2)].nodo));
                  (yyval.nodo) = nodo;
               ;}
    break;

  case 88:

    {
                  Nodo* nodo = crearNodo("RELOP_EXPRESION");
                  nodo->valorCadena = strdup("()");
                  insertarNodoHijos(nodo, (yyvsp[(2) - (3)].nodo));
                  (yyval.nodo) = nodo;
               ;}
    break;

  case 89:

    {
                  (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
               ;}
    break;

  case 90:

    {
                        Nodo* nodo = crearNodo("RELOP_EXPRESION_SIMPLE");
                        insertarNodoHijos(nodo, (yyvsp[(1) - (3)].nodo), (yyvsp[(2) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
                        (yyval.nodo) = nodo;
                       ;}
    break;

  case 91:

    {
                  (yyval.nodo) = (yyvsp[(1) - (1)].nodo);
                ;}
    break;

  case 92:

    {
                  Nodo* temp = (yyvsp[(1) - (3)].nodo);
                        if(temp){
                              while(temp->hermano != nullptr){
                                    temp = temp->hermano;
                              }
                              agregarHermano(temp, (yyvsp[(3) - (3)].nodo));
                              (yyval.nodo) = (yyvsp[(1) - (3)].nodo);
                        }
                ;}
    break;

  case 93:

    {
                  Nodo* temp = (yyvsp[(1) - (3)].nodo);
                  agregarHijo(temp, (yyvsp[(2) - (3)].nodo));
                  agregarHermano((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
                  (yyval.nodo) = (yyvsp[(1) - (3)].nodo);
            ;}
    break;

  case 94:

    {
                  Nodo* temp = (yyvsp[(1) - (3)].nodo);
                  agregarHijo(temp, (yyvsp[(2) - (3)].nodo));
                  agregarHermano((yyvsp[(1) - (3)].nodo), (yyvsp[(3) - (3)].nodo));
                  (yyval.nodo) = (yyvsp[(1) - (3)].nodo);
            ;}
    break;

  case 95:

    {
                  Nodo* nodo = crearNodo("EXPRESION");
                  nodo->valorCadena = "identificador";
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
            ;}
    break;

  case 96:

    {
                  Nodo* nodo = crearNodo("EXPRESION");
                  nodo->valorCadena = "arreglo";
                  insertarNodoHijos(nodo, (yyvsp[(1) - (4)].nodo), (yyvsp[(3) - (4)].nodo));
                  (yyval.nodo) = nodo;
            ;}
    break;

  case 97:

    {
                  Nodo* nodo = crearNodo("EXPRESION");
                  nodo->valorCadena = "llamado funciones";
                  insertarNodoHijos(nodo, (yyvsp[(1) - (4)].nodo), (yyvsp[(3) - (4)].nodo));
                  (yyval.nodo) = nodo;
            ;}
    break;

  case 98:

    {
                  Nodo* nodo = crearNodo("EXPRESION");
                  nodo->valorCadena = "constante entera";
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
            ;}
    break;

  case 99:

    {
                  Nodo* nodo = crearNodo("EXPRESION");
                  nodo->valorCadena = "constante real";
                  insertarNodoHijos(nodo, (yyvsp[(1) - (1)].nodo));
                  (yyval.nodo) = nodo;
            ;}
    break;

  case 100:

    {
                  Nodo* nodo = crearNodo("EXPRESION");
                  nodo->valorCadena = "signo";
                  insertarNodoHijos(nodo, (yyvsp[(1) - (2)].nodo), (yyvsp[(2) - (2)].nodo));
                  (yyval.nodo) = nodo;
            ;}
    break;

  case 101:

    {
                  Nodo* nodo = crearNodo("EXPRESION");
                  nodo->valorCadena = "parentesis";
                  insertarNodoHijos(nodo, (yyvsp[(2) - (3)].nodo));
                  (yyval.nodo) = nodo;
            ;}
    break;

  case 102:

    {
            Nodo* nodo = crearNodo("SIGNO");
            nodo->valorCadena = strdup("+");
            (yyval.nodo) = nodo;
      ;}
    break;

  case 103:

    {
            Nodo* nodo = crearNodo("SIGNO");
            nodo->valorCadena = strdup("-");
            (yyval.nodo) = nodo;
      ;}
    break;

  case 104:

    {
            (yyval.nodo) = NULL;
      ;}
    break;

  case 105:

    {
                  Nodo* nodo = crearNodo("CONSTANTE_ENTERA");
                  insertarNodoHijos(nodo, (yyvsp[(1) - (2)].nodo), (yyvsp[(2) - (2)].nodo));
                  (yyval.nodo) = nodo;
                 ;}
    break;

  case 106:

    {
            Nodo* nodo = crearNodo("NUMERO");
            nodo->valorCadena = strdup((yyvsp[(1) - (1)].cadena));
            (yyval.nodo) = nodo;
      ;}
    break;

  case 107:

    {
                  Nodo* nodo = crearNodo("CONSTANTE_REAL");
                  nodo->valorCadena += strdup((yyvsp[(2) - (4)].cadena));
                  nodo->valorCadena += strdup((yyvsp[(3) - (4)].cadena));
                  nodo->valorCadena += strdup((yyvsp[(4) - (4)].cadena));
                  insertarNodoHijos(nodo, (yyvsp[(1) - (4)].nodo));
                  (yyval.nodo) = nodo;
               ;}
    break;

  case 108:

    {
                  Nodo* nodo = crearNodo("CONSTANTE_REAL");
                  nodo->valorCadena = strdup((yyvsp[(2) - (2)].cadena));
                  insertarNodoHijos(nodo, (yyvsp[(1) - (2)].nodo));
                  (yyval.nodo) = nodo;
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





void yyerror(const char *s){
      printf("Error: %s\n en linea: %d caracter : %d", s, yylloc.last_line, yylloc.first_column+1);
      exit(1);
}

void insert_table_var_def(Var_Types type, variable_line identifier) {
      unsigned long index;
      long collision_list_position;
      ht_search(ht, identifier.name, index, collision_list_position);
      if (index != -1 && ht_is_scope_already_declared(ht, identifier.name, index, scope)) {
            printf("Warning[Redeclaracion de variable]: variable %s ya declarada en linea %d\n", identifier.name, identifier.line_used);
            warning = true;
      }
      else {
            insert_table(type, identifier);
      }
}

void insert_table_var_used(Var_Types type, variable_line identifier) {
      unsigned long index;
      long collision_list_position;
      bool found = ht_search(ht, identifier.name, index, collision_list_position);
      if (!found) {
            printf("Warning[Uso de variable no declarada]: variable %s no declarada en linea %d\n", identifier.name, identifier.line_used);
            warning = true;
      }
      else if (!ht_is_scope_less_than_defined(ht, identifier.name, index, current_scope)) {
            printf("Warning[Error de ambito]: variable %s declarada en ambito diferente en linea %d\n", identifier.name, identifier.line_used);
            warning = true;
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
      std::string vacio = "";
      char* vacioC = new char[vacio.length() + 1];
      strcpy(vacioC, vacio.c_str());
      data_value datos = {mem_acum, type, bytesize, lugar, vacioC, current_scope};
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
      ht_insert(ht, nombre, datos);      
      mem_acum += bytesize;
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
            printf("Uso del compilador:\ncompiladorPascal.exe archivo.pas\nCambiando a entrada estandar\n");
		yyin = stdin;
	}

      create_table(ht);

      // yydebug = 1;
      yyparse();

      return 0;
}
