
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

extern YYSTYPE yylval;

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

extern YYLTYPE yylloc;

