%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "sintactico.tab.h"
	#pragma warning(disable: 4996 6011 6385 4013 4244 4267)
    extern int yyerror(char* s);
    
    #define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno;
%}

%option outfile = "scanner.c"
%option noyywrap
%option case-insensitive
%option yylineno
%pointer


LETRA [a-zA-Z]
DIGITO [0-9]

DELIMITADOR [\t\r\f ]

%%

{DELIMITADOR}   {}

"program"            { yylval.cadena = yytext; return PROGRAM; }
"var"                { yylval.cadena = yytext; return VAR; }
"integer"            { yylval.cadena = yytext; return INTEGER_TIPO; }
"real"               { yylval.cadena = yytext; return REAL_TIPO; }
"string"             { yylval.cadena = yytext; return STRING_TIPO; }
"boolean"            { yylval.cadena = yytext; return BOOLEAN_TIPO; }
"const"              { yylval.cadena = yytext; return CONST; }
"function"           { yylval.cadena = yytext; return FUNCTION; }
"procedure"          { yylval.cadena = yytext; return PROCEDURE; }
"begin"              { yylval.cadena = yytext; return BEG;}
"end"                { yylval.cadena = yytext; return END; }
"array"              { yylval.cadena = yytext; return ARRAY; }
"of"                 { yylval.cadena = yytext; return OF; }
"if"                 { yylval.cadena = yytext; return IF; }
"then"               { yylval.cadena = yytext; return THEN; }
"else"               { yylval.cadena = yytext; return ELSE; }
"while"              { yylval.cadena = yytext; return WHILE; }
"do"                 { yylval.cadena = yytext; return DO; }
"for"                { yylval.cadena = yytext; return FOR; }
"to"                 { yylval.cadena = yytext; return TO; }
"downto"             { yylval.cadena = yytext; return DOWNTO; }
"read"               { yylval.cadena = yytext; return READ; }
"readln"             { yylval.cadena = yytext; return READLN; }
"write"              { yylval.cadena = yytext; return WRITE; }
"writeln"            { yylval.cadena = yytext; return WRITELN; }
"and"                { yylval.cadena = yytext; return AND; }
"or"                 { yylval.cadena = yytext; return OR; }
"not"                { yylval.cadena = yytext; return NOT; }
"div"                { yylval.cadena = yytext; return DIV; }
"mod"                { yylval.cadena = yytext; return MOD; }
"("                  { yylval.cadena = yytext; return LPAREN;}
")"                  { yylval.cadena = yytext; return RPAREN;}
"["                  { yylval.cadena = yytext; return LBRACKET;}
"]"                  { yylval.cadena = yytext; return RBRACKET;}
"+"                  { yylval.cadena = yytext; return PLUS;}
"-"                  { yylval.cadena = yytext; return MINUS;}
"*"                  { yylval.cadena = yytext; return ASTERISK;}
"/"                  { yylval.cadena = yytext; return SLASH;} 
"="                  { yylval.cadena = yytext; return EQUALS; }
":"                  { yylval.cadena = yytext; return COLON; }
";"                  { yylval.cadena = yytext; return SEMICOLON; }
","                  { yylval.cadena = yytext; return COMMA; }
"."                  { yylval.cadena = yytext; return PERIOD; }
"<"                  { yylval.cadena = yytext; return LESSTHAN; }
">"                  { yylval.cadena = yytext; return GREATERTHAN; }
"<="                 { yylval.cadena = yytext; return LESSTHANEQUALS; }
">="                 { yylval.cadena = yytext; return GREATERTHANEQUALS; }
"<>"                 { yylval.cadena = yytext; return NOTEQUALS; }
"\n"                 { ; }    

{DIGITO}+\.{DIGITO}*["e" | "E"]{DIGITO}+ { 
    yylval.cadena = yytext; return EXP;
}

\(\*([^*]|\*+[^)*])*\*\) {
    printf("Comentario: %s\n", yytext);
};

\"[^\"]*\" {
    yylval.cadena = strdup(yytext);
    return CADENA;
};

{LETRA}({DIGITO}|{LETRA})*  {
    yylval.cadena = yytext;
    return IDENTIFICADOR;
};

{DIGITO} {
    yylval.cadena = yytext;
    return DIGITO;
}

.               {printf("Caracter invalido");}

%%