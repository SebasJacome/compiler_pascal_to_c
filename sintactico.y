%{
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

%type <cadena> programa identificador

%%

programa : PROGRAM
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
            } 
            identificador 
            {
                  insert_table(VOID, last[last.size() - 1]);
                  last.clear();
            }
            LPAREN identificador_lista
            {
                  for (unsigned int i = 0; i < last.size(); i++) {
                        insert_table(VOID, last[i]);
                  }
                  last.clear();
            } 
            RPAREN SEMICOLON declaraciones subprograma_declaraciones instruccion_compuesta PERIOD
            {
                  if (scope != "0") yyerror("Scope error");
            }

         ;

identificador : IDENTIFICADOR 
                  { 
                        char* var_name = strdup($1);
                        int var_line = @1.last_line;
                        last.push_back({var_name, var_line}); 
                        printf("Variable encontrada: %s\n", var_name);
                        printf("Ultimo en arreglo: %s\n", last[last.size()-1].name);
                  }
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
                  { 
                        last_variable_type = INTEGER;
                  }
              | REAL_TIPO
                  { 
                        last_variable_type = FLOAT;
                  }
              | STRING_TIPO
                  { 
                        last_variable_type = STRING;
                  }
              | BOOLEAN_TIPO
                  { 
                        last_variable_type = BOOLEAN;
                  }
              ;

subprograma_declaraciones : subprograma_declaraciones subprograma_declaracion SEMICOLON
                          | /* empty */
                          ;

subprograma_declaracion : subprograma_encabezado declaraciones subprograma_declaraciones instruccion_compuesta
                        ;

subprograma_encabezado : FUNCTION 
                        {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        } 
                        identificador argumentos COLON estandar_tipo
                        {
                              insert_table(last_variable_type, last[last.size() - 1]);
                              last.clear()
                        }
                        SEMICOLON
                        {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        }
                       | PROCEDURE
                       {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                       } 
                       identificador argumentos SEMICOLON
                       {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                       }
                       ;

argumentos : LPAREN parametros_lista RPAREN 
           | /* empty */
           ;

parametros_lista : identificador_lista COLON tipo 
                  {
                        while (last.size() > 1) {
                              insert_table(last_variable_type, last[last.size() - 1]);
                              last.pop_back();
                        }
                  }
                 | parametros_lista SEMICOLON identificador_lista COLON tipo
                 ;

instruccion_compuesta : BEG {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        } 
                        instrucciones_opcionales 
                        END
                        { 
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        }
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

repeticion_instruccion : WHILE 
                        {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        } 
                        relop_expresion DO instrucciones
                        {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        }
                       | FOR
                        {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        } 
                        for_asignacion TO expresion DO instrucciones
                        {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        } 
                       | FOR
                       {
                              inc_scope();
                              printf("Scope changed to: %s", scope);
                        } 
                        for_asignacion DOWNTO expresion DO instrucciones
                        {
                              dec_scope();
                              printf("Scope changed to: %s", scope);
                        }
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

if_instruccion : IF 
                  {
                        inc_scope();
                        printf("Scope changed to: %s", scope);
                  } 
                  relop_expresion THEN instrucciones
                  {
                        dec_scope();
                        printf("Scope changed to: %s", scope);
                  }
               | IF 
                  {
                        inc_scope();
                        printf("Scope changed to: %s", scope);
                  }
               relop_expresion THEN instrucciones ELSE instrucciones
                  {
                        dec_scope();
                        printf("Scope changed to: %s", scope);
                  }
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
      ht_insert(ht, nombre, {mem_acum, type, bytesize, lugar, "abc", scope});
      mem_acum += bytesize;
      printf("Insertado correctamente\n");
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
      
      print_table(ht);
      return 0;
}