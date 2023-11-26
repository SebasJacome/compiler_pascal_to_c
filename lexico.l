%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #include "sintactico.tab.h"
	#pragma warning(disable: 4996 6011 6385 4013 4244 4267)
    extern int yyerror(char* s);
    
    #define YY_USER_ACTION \
    yylloc.first_line = yylloc.last_line; \
    yylloc.first_column = yylloc.last_column; \
    for(int i = 0; yytext[i] != '\0'; i++) { \
        if(yytext[i] == '\n') { \
            yylloc.last_line++; \
            yylloc.last_column = 0; \
        } \
        else { \
            yylloc.last_column++; \
        } \
    }
%}

%option outfile = "scanner.c"
%option noyywrap
%option case-insensitive
%option yylineno
%pointer


LETRA [a-zA-Z]
DIGITO [0-9]
DIGITO_NO_CERO [1-9]

DELIMITADOR [\t\r\f ]

%%

{DELIMITADOR}   {}

"program"            { yylval.cadena = strdup(yytext); return PROGRAM; }
"var"                { yylval.cadena = strdup(yytext); return VAR; }
"integer"            { yylval.cadena = strdup(yytext); return INTEGER_TIPO; }
"real"               { yylval.cadena = strdup(yytext); return REAL_TIPO; }
"string"             { yylval.cadena = strdup(yytext); return STRING_TIPO; }
"boolean"            { yylval.cadena = strdup(yytext); return BOOLEAN_TIPO; }
"const"              { yylval.cadena = strdup(yytext); return CONST; }
"function"           { yylval.cadena = strdup(yytext); return FUNCTION; }
"procedure"          { yylval.cadena = strdup(yytext); return PROCEDURE; }
"begin"              { yylval.cadena = strdup(yytext); return BEG;}
"end"                { yylval.cadena = strdup(yytext); return END; }
"array"              { yylval.cadena = strdup(yytext); return ARRAY; }
"of"                 { yylval.cadena = strdup(yytext); return OF; }
"if"                 { yylval.cadena = strdup(yytext); return IF; }
"then"               { yylval.cadena = strdup(yytext); return THEN; }
"else"               { yylval.cadena = strdup(yytext); return ELSE; }
"while"              { yylval.cadena = strdup(yytext); return WHILE; }
"do"                 { yylval.cadena = strdup(yytext); return DO; }
"for"                { yylval.cadena = strdup(yytext); return FOR; }
"to"                 { yylval.cadena = strdup(yytext); return TO; }
"downto"             { yylval.cadena = strdup(yytext); return DOWNTO; }
"read"               { yylval.cadena = strdup(yytext); return READ; }
"readln"             { yylval.cadena = strdup(yytext); return READLN; }
"write"              { yylval.cadena = strdup(yytext); return WRITE; }
"writeln"            { yylval.cadena = strdup(yytext); return WRITELN; }
"and"                { yylval.cadena = strdup(yytext); return AND; }
"or"                 { yylval.cadena = strdup(yytext); return OR; }
"not"                { yylval.cadena = strdup(yytext); return NOT; }
"div"                { yylval.cadena = strdup(yytext); return DIV; }
"mod"                { yylval.cadena = strdup(yytext); return MOD; }
"("                  { yylval.cadena = strdup(yytext); return LPAREN;}
")"                  { yylval.cadena = strdup(yytext); return RPAREN;}
"["                  { yylval.cadena = strdup(yytext); return LBRACKET;}
"]"                  { yylval.cadena = strdup(yytext); return RBRACKET;}
"+"                  { yylval.cadena = strdup(yytext); return PLUS;}
"-"                  { yylval.cadena = strdup(yytext); return MINUS;}
"*"                  { yylval.cadena = strdup(yytext); return ASTERISK;}
"/"                  { yylval.cadena = strdup(yytext); return SLASH;} 
"="                  { yylval.cadena = strdup(yytext); return EQUALS; }
":"                  { yylval.cadena = strdup(yytext); return COLON; }
";"                  { yylval.cadena = strdup(yytext); return SEMICOLON; }
","                  { yylval.cadena = strdup(yytext); return COMMA; }
"."                  { yylval.cadena = strdup(yytext); return PERIOD; }
"<"                  { yylval.cadena = strdup(yytext); return LESSTHAN; }
">"                  { yylval.cadena = strdup(yytext); return GREATERTHAN; }
"<="                 { yylval.cadena = strdup(yytext); return LESSTHANEQUALS; }
">="                 { yylval.cadena = strdup(yytext); return GREATERTHANEQUALS; }
"<>"                 { yylval.cadena = strdup(yytext); return NOTEQUALS; }
"\n"                 { ; }    

{DIGITO}+\.{DIGITO}*["e" | "E"]{DIGITO}+ { 
    yylval.cadena = strdup(yytext); return EXP;
}

\(\*([^*]|\*+[^)*])*\*\) {
    // printf("Comentario: %s\n", strdup(yytext));
};

\"[^\"]*\" {
    yylval.cadena = strdup(strdup(yytext));
    return CADENA;
};

{LETRA}({DIGITO}|{LETRA})*  {
    yylval.cadena = strdup(yytext);
    return IDENTIFICADOR;
};

{DIGITO_NO_CERO}{DIGITO}*|{DIGITO} {
    yylval.cadena = strdup(yytext);
    return NUM_ENTERO;
}

.               {printf("Caracter invalido");}

%%