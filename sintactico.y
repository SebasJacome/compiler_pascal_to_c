%{
      #include <stdio.h>
      #include "hash_table.h"
	#pragma warning(disable: 4013 4244 4267 4996)
	extern FILE * yyin;   
      extern int yylineno; 

      // yydebug = 1;
      int yyerror(char* s);
      int yylex();
%}

%locations

%union {
      char* cadena;
}

%token <cadena> PROGRAM VAR CONST FUNCTION PROCEDURE BEG END ARRAY OF IF THEN ELSE 
%token <cadena> WHILE DO FOR TO DOWNTO READ READLN WRITE WRITELN AND OR NOT DIV MOD 
%token <cadena> LPAREN RPAREN LBRACKET RBRACKET PLUS MINUS ASTERISK SLASH 
%token <cadena> EQUALS COLON SEMICOLON COMMA PERIOD
%token <cadena> IDENTIFICADOR DIGITO INTEGER_TIPO REAL_TIPO STRING_TIPO BOOLEAN_TIPO
%token <cadena> EXP CADENA LESSTHAN GREATERTHAN LESSTHANEQUALS GREATERTHANEQUALS NOTEQUALS

%%

programa : PROGRAM identificador LPAREN identificador_lista RPAREN SEMICOLON declaraciones subprograma_declaraciones instruccion_compuesta PERIOD
         ;

identificador : IDENTIFICADOR {printf("***\nIdentificador encontrado: %s Linea: %d\n***\n", $1, @1.last_line);}
              ;

relop : AND | OR | EQUALS | LESSTHAN | GREATERTHAN | LESSTHANEQUALS | GREATERTHANEQUALS | NOTEQUALS
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
                      | WRITE LPAREN identificador RPAREN
                      | WRITELN LPAREN identificador RPAREN
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
               | signo EXP
               ;

digito_no_cero : DIGITO;

%%

int yyerror(char *s){
    printf("Error: %s\nEn linea: %d", s, yylineno);
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
      
      HashTable ht;
      create_table(ht);

     	yyparse();
     	printf("Programa parseado correctamente . . .\n");

      data_value data_1 = { 0, BOOLEAN, 20, 1000, "12 , 13, 14", 1 };
      ht_insert(ht, "X1", data_1);
      data_value data_2 = { 4,FLOAT,30,2000, "112 , 113, 114", 2 };
      ht_insert(ht, "H1", data_2);
      data_value data_3 = { 10,INTEGER,40,3000, "212 , 213, 214", 3 };
      ht_insert(ht, "Z1", data_3);
      data_value data_4 = { 15,STRING,80,5000, "312 , 313", 4};
      ht_insert(ht, "P1", data_4);
      data_value data_5 = { 20,BOOLEAN,100,6000, "412 , 413, 414", 1 };
      ht_insert(ht, "A1", data_5);
      data_value data_6 = { 24,FLOAT,130,7000, "512 , 513, 14", 2 };
      ht_insert(ht, "B1", data_6);
      data_value data_7 = { 210,INTEGER,140,8000, "913, 914", 3 };
      ht_insert(ht, "C1", data_7);
      data_value data_8 = { 215,STRING,180,9000, "712 , 713, 714", 4 };
      ht_insert(ht, "K1", data_8);
      print_table(ht);
      ht_delete(ht, "X1");
      print_table(ht);
      ht_delete(ht, "B1");
      print_table(ht);
      print_search(ht, "C1");
      print_search(ht, "K1");
      free_table(ht);
      print_table(ht);

            return 0;
}