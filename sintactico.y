%{
      #include <stdio.h>
	#pragma warning(disable: 4013 4244 4267 4996)
	extern FILE * yyin;    
      yydebug = 1;
%}


%union {
      char* cadena;
}

%token PROGRAM VAR CONST FUNCTION PROCEDURE BEG END ARRAY OF IF THEN ELSE 
%token WHILE DO FOR TO DOWNTO READ READLN WRITE WRITELN AND OR NOT DIV MOD 
%token LPAREN RPAREN LBRACKET RBRACKET PLUS MINUS ASTERISK SLASH 
%token EQUALS COLON SEMICOLON COMMA PERIOD
%token IDENTIFICADOR DIGITO INTEGER_TIPO REAL_TIPO STRING_TIPO BOOLEAN_TIPO
%token EXP CADENA



%%

programa : PROGRAM identificador LPAREN identificador_lista RPAREN SEMICOLON declaraciones subprograma_declaraciones instruccion_compuesta PERIOD
         ;

identificador : IDENTIFICADOR
              ;

relop : AND | OR
      ;

addop : PLUS | MINUS
      ;

mulop : ASTERISK | SLASH | DIV | MOD
      ;
    
identificador_lista : identificador
                    | identificador_lista COMMA identificador
                    ;

declaraciones : declaraciones_variables
              | declaraciones_constantes
              ;

declaraciones_variables : declaraciones_variables VAR identificador_lista COLON tipo SEMICOLON
                        | /* empty */

declaraciones_constantes : declaraciones_constantes CONST identificador EQUALS constante_entera SEMICOLON
                         | declaraciones_constantes CONST identificador EQUALS constante_real SEMICOLON
                         | declaraciones_constantes CONST identificador EQUALS CADENA SEMICOLON
                         | /* empty */
                         ;

tipo : estandar_tipo
     | ARRAY LBRACKET numero_entero PERIOD PERIOD numero_entero RBRACKET OF estandar_tipo
     ;

estandar_tipo : INTEGER_TIPO
              | REAL_TIPO
              | STRING_TIPO
              | BOOLEAN_TIPO
              ;

subprograma_declaraciones : subprograma_declaraciones subprograma_declaracion SEMICOLON
                          | /* empty */
                          ;

subprograma_declaracion : subprograma_encabezado declaraciones subprograma_declaraciones instruccion_compuesta
                        ;

subprograma_encabezado : FUNCTION identificador argumentos COLON estandar_tipo SEMICOLON
                       | PROCEDURE identificador argumentos SEMICOLON
                       ;

argumentos : LPAREN parametros_lista RPAREN 
           | /* empty */
           ;

parametros_lista : identificador_lista COLON tipo 
                 | parametros_lista SEMICOLON identificador_lista COLON tipo
                 ;

instruccion_compuesta : BEG instrucciones_opcionales END
                      ;

instrucciones_opcionales : instrucciones_lista
                         | /* empty */
                         ;

instrucciones_lista : instrucciones
                    | instrucciones_lista SEMICOLON instrucciones
                    ;

instrucciones : variable_asignacion
              | procedure_instruccion
              | instruccion_compuesta
              | if_instruccion
              | repeticion_instruccion
              | lectura_instruccion
              | escritura_instruccion
              ;

repeticion_instruccion : WHILE relop_expresion DO instrucciones
                       | FOR for_asignacion TO expresion DO instrucciones
                       | FOR for_asignacion DOWNTO expresion DO instrucciones
                       ;

lectura_instruccion : READ LPAREN identificador RPAREN
                    | READLN LPAREN identificador RPAREN
                    ;

escritura_instruccion : WRITE LPAREN CADENA COMMA identificador RPAREN
                      | WRITELN LPAREN CADENA COMMA identificador RPAREN
                      | WRITE LPAREN CADENA RPAREN
                      | WRITELN LPAREN CADENA RPAREN
                      | WRITE LPAREN CADENA COMMA expresion RPAREN
                      | WRITELN LPAREN CADENA COMMA expresion RPAREN
                      ;

if_instruccion : IF relop_expresion THEN instrucciones
               | IF relop_expresion THEN instrucciones ELSE instrucciones
               ;

variable_asignacion : variable COLON EQUALS expresion
                    ;

for_asignacion : variable_asignacion
               | variable
               ;

variable : identificador
         | identificador LBRACKET expresion RBRACKET
         ;

procedure_instruccion : identificador | identificador LPAREN expresion_lista RPAREN

relop_expresion : relop_expresion OR relop_and 
                | relop_and
                ;

relop_and : relop_and AND relop_not 
          | relop_not
          ;

relop_not : NOT relop_not
          | relop_paren
          ;

relop_paren : LPAREN relop_expresion RPAREN 
            | relop_expresion_simple
            ;

relop_expresion_simple : expresion relop expresion

expresion_lista : expresion 
                | expresion_lista COMMA expresion
                ;

expresion : termino
          | expresion addop termino
          ;

termino : factor
        | termino mulop factor
        ;

llamado_funcion : identificador LPAREN expresion_lista RPAREN
                ; 

factor : identificador
       | identificador LBRACKET expresion RBRACKET
       | llamado_funcion
       | constante_entera
       | constante_real
       | signo factor
       | LPAREN expresion RPAREN
       ;

signo : PLUS
      | MINUS
      | /* empty */
      ;

constante_entera : signo numero_entero

numero_entero : digito_no_cero numero
              ;

numero : numero DIGITO
       | /* empty */
       ;

constante_real : signo numero_entero PERIOD numero_entero
               | signo numero_entero PERIOD numero_entero exponente
               ;

exponente : EXP signo numero_entero
          ;

digito_no_cero : DIGITO;

%%

int yyerror(char *s){
    printf("Error %s\n", s);
	exit(1);
	return 0;
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
     	yyparse();
     	printf("Linea reconocida correctamente\n");
     	return 0;
}