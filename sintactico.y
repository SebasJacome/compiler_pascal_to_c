%{
      #include <stdio.h>
      #include <vector>
      #include <string>
      #include <string.h>
      #include <cstring>
      #include "hash_table.h"
	#pragma warning(disable: 4013 4244 4267 4996)
	extern FILE * yyin;   
      extern int yylineno; 

      // yydebug = 1;
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
%}

%locations

%union {
      char* cadena;
}

%token <cadena> PROGRAM VAR CONST FUNCTION PROCEDURE BEG END ARRAY OF IF THEN ELSE 
%token <cadena> WHILE DO FOR TO DOWNTO READ READLN WRITE WRITELN AND OR NOT DIV MOD 
%token <cadena> LPAREN RPAREN LBRACKET RBRACKET PLUS MINUS ASTERISK SLASH 
%token <cadena> EQUALS COLON SEMICOLON COMMA PERIOD
%token <cadena> IDENTIFICADOR NUM_ENTERO INTEGER_TIPO REAL_TIPO STRING_TIPO BOOLEAN_TIPO
%token <cadena> EXP CADENA LESSTHAN GREATERTHAN LESSTHANEQUALS GREATERTHANEQUALS NOTEQUALS

%%

programa : PROGRAM
            {
                  scope = 0;
            } 
            identificador 
            {
                  insert_table_var_def(VOID, last[last.size() - 1]);
                  last.clear();
            }
            LPAREN identificador_lista
            {
                  for (unsigned int i = 0; i < last.size(); i++) {
                        insert_table_var_def(VOID, last[i]);
                  }
                  last.clear();
            } 
            RPAREN SEMICOLON declaraciones subprograma_declaraciones instruccion_compuesta PERIOD
            {
                  if (current_scope != 0) yyerror("Scope error, no se cerro el scope actual");
            }
            ;

identificador : IDENTIFICADOR 
                  { 
                        char* var_name = strdup($1);
                        int var_line = @1.last_line;
                        last.push_back({var_name, var_line}); 
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
                        {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(last_variable_type, last[i]);
                              }
                              last.clear();
                        }
                        | /* empty */

declaraciones_constantes : declaraciones_constantes CONST identificador EQUALS constante_entera SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_ENTERO, last[i]);
                              }
                              last.clear();
                         }
                         | declaraciones_constantes CONST identificador EQUALS constante_real SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_REAL, last[i]);
                              }
                              last.clear();
                        }
                         | declaraciones_constantes CONST identificador EQUALS CADENA SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_CADENA, last[i]);
                              }
                              last.clear();
                         }
                         | /* empty */
                         ;

tipo : estandar_tipo
     | ARRAY LBRACKET NUM_ENTERO PERIOD PERIOD NUM_ENTERO RBRACKET OF estandar_tipo
     {
            for (unsigned int i = 0; i < last.size(); i++) {
                  insert_table_defsize(last_variable_type, last[i], atoi($6) - atoi($3) + 1);
            }
            last.clear();
     }
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
                              scope++;
                              current_scope = scope;
                        } 
                        identificador argumentos COLON estandar_tipo
                        {
                              insert_table_var_def(last_variable_type, last[0]);
                              printf("Variable %s de tipo %d en linea %d\n", last[0].name, last_variable_type, last[0].line_used);
                              last.clear();
                        }
                        SEMICOLON
                       | PROCEDURE
                       {
                              scope++;
                              current_scope = scope;
                       } 
                       identificador argumentos SEMICOLON
                       {
                              insert_table_func_def(VOID, last[0]);
                              last.clear();
                       }
                       ;

argumentos : LPAREN parametros_lista RPAREN 
           | /* empty */
           ;

parametros_lista : identificador_lista COLON tipo 
                  {
                        while (last.size() > 1) {
                              insert_table_var_def(last_variable_type, last[last.size() - 1]);
                              last.pop_back();
                        }
                  }
                 | parametros_lista SEMICOLON identificador_lista COLON tipo
                 {
                        while (last.size() > 1) {
                              insert_table_var_def(last_variable_type, last[last.size() - 1]);
                              last.pop_back();
                        }
                  }
                 ;

instruccion_compuesta : BEG instrucciones_opcionales 
                        END
                        { 
                              current_scope = 0;
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

repeticion_instruccion : WHILE relop_expresion DO instrucciones
                       | FOR for_asignacion for_comportamiento expresion DO instrucciones
                       ;

for_comportamiento: TO 
                  | DOWNTO   
                  ;

lectura_instruccion : READ LPAREN identificador RPAREN
                    | READLN LPAREN identificador RPAREN
                    ;

escritura_instruccion : WRITE LPAREN CADENA COMMA identificador RPAREN
                        {
                              for (unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_used(last_variable_type, last[i]);
                              }
                              last.clear();
                        }
                      | WRITELN LPAREN CADENA COMMA identificador RPAREN
                        {
                              for (unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_used(last_variable_type, last[i]);
                              }
                              last.clear();
                        }
                      | WRITE LPAREN CADENA RPAREN
                      | WRITELN LPAREN CADENA RPAREN
                      | WRITE LPAREN CADENA COMMA expresion RPAREN
                      | WRITELN LPAREN CADENA COMMA expresion RPAREN
                      | WRITE LPAREN identificador RPAREN
                      {
                              for (unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_used(last_variable_type, last[i]);
                              }
                              last.clear();
                        }
                      | WRITELN LPAREN identificador RPAREN
                      {
                              for (unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_used(last_variable_type, last[i]);
                              }
                              last.clear();
                        }
                      ;

if_instruccion : IF relop_expresion THEN instrucciones instruccion_else
               ;

instruccion_else: |
                  ELSE instrucciones
                  ;

variable_asignacion : variable COLON EQUALS expresion
                    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();
                    }
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

constante_entera : signo NUM_ENTERO
                 ;

constante_real : signo NUM_ENTERO PERIOD NUM_ENTERO
               | signo EXP
               ;

%%

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
            yyerror("Error: variable ya declarada");
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
            yyerror("Error: variable no declarada");
      }
      else if (!ht_is_scope_less_than_defined(ht, identifier.name, index, current_scope)) {
            printf("Error: variable %s en scope diferente en linea %d\n", identifier.name, identifier.line_used);
            yyerror("Error: variable en scope diferente");
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

      print_table(ht);

      return 0;
}