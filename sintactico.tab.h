
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
     NUM_ENTERO = 298,
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

