%{
    #include <stdio.h>
	#include <stdlib.h>
	#pragma warning(disable: 4996 6011 6385 4013 4244 4267)
%}

%option c++
%option outfile = "scanner.cpp"
%option noyywrap


LETRA [a-zA-z]
DIGITO [0-9]
ENTERO {DIGITO}+



DELIMITADOR [\t\r\f ""]

%%

"program"            { yylval = yytext; return PROGRAM; }
"var"                { yylval = yytext; return VAR; }
"integer"                { yylval = yytext; return INTEGER_TIPO; }
"real"                { yylval = yytext; return REAL_TIPO; }
"string"                { yylval = yytext; return STRING_TIPO; }
"boolean"                { yylval = yytext; return BOOLEAN_TIPO; }
"const"              { yylval = yytext; return CONST; }
"function"           { yylval = yytext; return FUNCTION; }
"procedure"          { yylval = yytext; return PROCEDURE; }
"begin"              { yylval = yytext; return BEGIN;}
"end"                { yylval = yytext; return END; }
"array"              { yylval = yytext; return ARRAY; }
"of"                 { yylval = yytext; return OF; }
"if"                 { yylval = yytext; return IF; }
"then"               { yylval = yytext; return THEN; }
"else"               { yylval = yytext; return ELSE; }
"while"              { yylval = yytext; return WHILE; }
"do"                 { yylval = yytext; return DO; }
"for"                { yylval = yytext; return FOR; }
"to"                 { yylval = yytext; return TO; }
"downto"             { yylval = yytext; return DOWNTO; }
"read"               { yylval = yytext; return READ; }
"readln"             { yylval = yytext; return READLN; }
"write"              { yylval = yytext; return WRITE; }
"writeln"            { yylval = yytext; return WRITELN; }
"and"                { yylval = yytext; return AND; }
"or"                 { yylval = yytext; return OR; }
"not"                { yylval = yytext; return NOT; }
"div"                { yylval = yytext; return DIV; }
"mod"                { yylval = yytext; return MOD; }
"e" | "E"            { yylval = yytext[0]; return EXP}
"{"                  { yylval = yytext[0]; return LBRACE;}
"}"                  { yylval = yytext[0]; return RBRACE;}
"("                  { yylval = yytext[0]; return LPAREN;}
")"                  { yylval = yytext[0]; return RPAREN;}
"["                  { yylval = yytext[0]; return LBRACKET;}
"]"                  { yylval = yytext[0]; return RBRACKET;}
"+"                  { yylval = yytext[0]; return PLUS;}
"-"                  { yylval = yytext[0]; return MINUS;}
"*"                  { yylval = yytext[0]; return ASTERISK;}
"/"                  { yylval = yytext[0]; return SLASH;} 
"$"                  { yylval = yytext[0]; return DOLLAR; }
"&"                  { yylval = yytext[0]; return AMPERSAND; }
"%"                  { yylval = yytext[0]; return PERCENT; }
"="                  { yylval = yytext[0]; return EQUALS; }
":"                  { yylval = yytext[0]; return COLON; }
">"                  { yylval = yytext[0]; return GREATER_THAN; }
"<"                  { yylval = yytext[0]; return LESS_THAN; }
";"                  { yylval = yytext[0]; return SEMICOLON; }
","                  { yylval = yytext[0]; return COMMA; }
"."                  { yylval = yytext[0]; return PERIOD; }
"#"                  { yylval = yytext[0]; return HASH; }
"\""                  { yylval = yytext[0]; return QUOTATION; }
" "                  { yylval = yytext[0]; return WHITESPACE; }


{LETRA} {
    yylval = yytext[0];
    return LETRA;
}

{DIGITO} {
    yylval = yytext[0];
    return DIGITO;
}


{ENTERO}        {   
                    yylval = yytext;
                    return ENTERO;
                }


{DELIMITADOR}   {}
.               {yyerror("Carácter inválido")}
%%