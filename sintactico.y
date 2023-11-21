%{
      #include <stdio.h>
      #include <vector>
      #include <string>
      #include <string.h>
      #include <cstring>
      #include "hash_table.h"
      #include "arbol_sintactico.h"
	#pragma warning(disable: 4013 4244 4267 4996)
	extern FILE * yyin;   
      extern int yylineno; 

      //yydebug = 1;
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

      typedef struct Nodo Nodo;
%}

%locations

%union {
      char* cadena;
      int entero;
      struct Nodo* nodo;
}

%token <nodo> 
      PROGRAM VAR CONST FUNCTION PROCEDURE BEG END ARRAY OF IF THEN ELSE 
      WHILE DO FOR TO DOWNTO READ READLN WRITE WRITELN AND OR NOT DIV MOD 
      LPAREN RPAREN LBRACKET RBRACKET PLUS MINUS ASTERISK SLASH 
      EQUALS COLON SEMICOLON COMMA PERIOD  
      INTEGER_TIPO REAL_TIPO STRING_TIPO BOOLEAN_TIPO
      EXP CADENA LESSTHAN GREATERTHAN LESSTHANEQUALS GREATERTHANEQUALS NOTEQUALS

%token <cadena> IDENTIFICADOR
%token <entero> NUM_ENTERO

%type <nodo> 
      programa contenido_programa relop addop mulop identificador_lista identificador declaraciones
      declaraciones_variables declaraciones_constantes tipo estandar_tipo subprograma_declaraciones
      subprograma_declaracion subprograma_encabezado argumentos parametros_lista instruccion_compuesta
      instrucciones_opcionales instrucciones_lista instrucciones repeticion_instruccion for_comportamiento
      lectura_instruccion escritura_instruccion if_instruccion instruccion_else variable_asignacion
      for_asignacion variable procedure_instruccion relop_expresion relop_and relop_not relop_paren
      relop_expresion_simple expresion_lista expresion termino llamado_funcion factor signo constante_entera
      constante_real

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
            RPAREN SEMICOLON contenido_programa PERIOD
            {
                  if (current_scope != 0) yyerror("Scope error, no se cerro el scope actual");

                  Nodo* raiz = crearNodo();
                  raiz->tipo = PROGRAMA;
                  // insertarNodoHijos(raiz, $3, $6, $10);
                  Nodo* prueba = crearNodo();
                  prueba->tipo = SIN_TIPO;
                  raiz->hijo[0] = prueba;
                  raiz->hijo[1] = prueba;
                  raiz->hijo[2] = $10;
                  $$ = raiz; 
                  imprimirArbol(raiz);
            }
            ;

contenido_programa : declaraciones subprograma_declaraciones instruccion_compuesta
                   {
                        Nodo* nodo = crearNodo();
                        nodo->tipo = CONTENIDO_PROGRAMA;
                        //insertarNodoHijos(nodo, $1, $2, $3);
                        Nodo* prueba = crearNodo();
                        prueba->tipo = SIN_TIPO;
                        nodo->hijo[0] = prueba;
                        nodo->hijo[1] = prueba;
                        nodo->hijo[2] = prueba;
                        $$ = nodo;
                   }
                    ;

identificador : IDENTIFICADOR 
                  {
                        char* var_name = strdup($1);
                        int var_line = @1.last_line;
                        last.push_back({var_name, var_line}); 

                        // ARBOL
                            
                  }
              ;

relop : AND 
      {
            // ARBOL
      }
      | OR 
      {
            // ARBOL
      }
      | EQUALS 
      {
            // ARBOL
      }
      | LESSTHAN 
      {
            // ARBOL
      }
      | GREATERTHAN 
      {
            // ARBOL
      }
      | LESSTHANEQUALS 
      {
            // ARBOL
      }
      | GREATERTHANEQUALS 
      {
            // ARBOL
      }
      | NOTEQUALS
      {
            // ARBOL
      }
      ;

addop : PLUS 
      {
            // ARBOL
      }
      | MINUS
      {
            // ARBOL
      }
      ;

mulop : ASTERISK 
      {
            // ARBOL
      }
      | SLASH 
      {
            // ARBOL
      }
      | DIV 
      {
            // ARBOL
      }
      | MOD
      {
            // ARBOL
      }
      ;

identificador_lista : identificador
                    {
                        // ARBOL
                    }
                    | identificador_lista COMMA identificador
                    {
                        // ARBOL
                    }
                    ;

declaraciones : declaraciones_variables
              {
                  // ARBOL
              }
              | declaraciones_constantes
              {
                  // ARBOL
              }
              ;

declaraciones_variables : declaraciones_variables VAR identificador_lista COLON tipo SEMICOLON
                        {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(last_variable_type, last[i]);
                              }
                              last.clear();

                              // ARBOL
                        }
                        | /* empty */
                        {
                              // ARBOL
                        }
                        ;

declaraciones_constantes : declaraciones_constantes CONST identificador EQUALS constante_entera SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_ENTERO, last[i]);
                              }
                              last.clear();

                              // ARBOL
                         }
                         | declaraciones_constantes CONST identificador EQUALS constante_real SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_REAL, last[i]);
                              }
                              last.clear();

                              // ARBOL
                        }
                         | declaraciones_constantes CONST identificador EQUALS CADENA SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_CADENA, last[i]);
                              }
                              last.clear();

                              // ARBOL
                         }
                         | /* empty */
                         {
                              // ARBOL
                         }
                         ;

tipo : estandar_tipo
     | ARRAY LBRACKET NUM_ENTERO PERIOD PERIOD NUM_ENTERO RBRACKET OF estandar_tipo
     {
      for (unsigned int i = 0; i < last.size(); i++) {
            insert_table_defsize(last_variable_type, last[i], ($6) - ($3) + 1);
      }
      last.clear();

      // ARBOL
     }
     ;

estandar_tipo : INTEGER_TIPO
              { 
                  last_variable_type = INTEGER;

                  // ARBOL
              }
              | REAL_TIPO
              { 
                  last_variable_type = FLOAT;

                  // ARBOL
              }
              | STRING_TIPO
              { 
                  last_variable_type = STRING;

                  // ARBOL
              }
              | BOOLEAN_TIPO
              { 
                  last_variable_type = BOOLEAN;

                  // ARBOL
              }
              ;

subprograma_declaraciones : subprograma_declaraciones subprograma_declaracion SEMICOLON
                          {
                              // ARBOL
                          }
                          | /* empty */
                          {
                              // ARBOL
                          }
                          ;

subprograma_declaracion : subprograma_encabezado declaraciones instruccion_compuesta
                        {
                              // ARBOL
                        }
                        ;

subprograma_encabezado : FUNCTION 
                        {
                              scope++;
                              current_scope = scope;
                        } 
                        identificador argumentos COLON estandar_tipo
                        {
                              insert_table_func_def(last_variable_type, last[0]);
                              last.clear();
                        }
                        SEMICOLON
                        {
                              // ARBOL
                        }
                       | PROCEDURE
                       {
                              scope++;
                              current_scope = scope;
                       } 
                       identificador argumentos SEMICOLON
                       {
                              insert_table_func_def(VOID, last[0]);
                              last.clear();

                              // ARBOL
                       }
                       ;

argumentos : LPAREN parametros_lista RPAREN 
           {
            // ARBOL
           }
           | /* empty */
           {
            // ARBOL
           }
           ;

parametros_lista : identificador_lista COLON tipo 
                 {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }

                  // ARBOL
                 }
                 | parametros_lista SEMICOLON identificador_lista COLON tipo
                 {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }

                  // ARBOL
                 }
                 ;

instruccion_compuesta : BEG instrucciones_opcionales 
                        END
                        { 
                              current_scope = 0;

                              // ARBOL
                        }
                        ;

instrucciones_opcionales : instrucciones_lista
                         {
                              // ARBOL
                         }
                         | /* empty */
                         {
                              // ARBOL
                         }
                         ;

instrucciones_lista : instrucciones
                    {
                        // ARBOL
                    }
                    | instrucciones_lista SEMICOLON instrucciones
                    {
                        // ARBOL
                    }
                    ;

instrucciones : variable_asignacion
              {
                  // ARBOL
              }
              | procedure_instruccion
              {
                  // ARBOL
              }
              | instruccion_compuesta
              {
                  // ARBOL
              }
              | if_instruccion
              {
                  // ARBOL
              }
              | repeticion_instruccion
              {
                  // ARBOL
              }
              | lectura_instruccion
              {
                  // ARBOL
              }
              | escritura_instruccion
              {
                  // ARBOL
              }
              ;

repeticion_instruccion : WHILE relop_expresion DO instrucciones
                       {
                        // ARBOL
                       }
                       | FOR for_asignacion for_comportamiento expresion DO instrucciones
                       {
                        // ARBOL
                       }
                       ;

for_comportamiento: TO 
                  {
                        // ARBOL
                  }
                  | DOWNTO   
                  {
                        // ARBOL
                  }
                  ;

lectura_instruccion : READ LPAREN identificador RPAREN
                    {
                        // ARBOL
                    }
                    | READLN LPAREN identificador RPAREN
                    {
                        // ARBOL
                    }
                    ;

escritura_instruccion : WRITE LPAREN CADENA COMMA identificador RPAREN
                      {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                      }
                      | WRITELN LPAREN CADENA COMMA identificador RPAREN
                      {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                      }
                      | WRITE LPAREN CADENA RPAREN
                      {
                        // ARBOL
                      }
                      | WRITELN LPAREN CADENA RPAREN
                      {
                        // ARBOL
                      }
                      | WRITE LPAREN CADENA COMMA expresion RPAREN
                      {
                        // ARBOL
                      }
                      | WRITELN LPAREN CADENA COMMA expresion RPAREN
                      {
                        // ARBOL
                      }
                      | WRITE LPAREN identificador RPAREN
                      {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                      }
                      | WRITELN LPAREN identificador RPAREN
                      {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                       }
                      ;

if_instruccion : IF relop_expresion THEN instrucciones instruccion_else
               {
                  // ARBOL
               }
               ;

instruccion_else: ELSE instrucciones
                  {
                        // ARBOL
                  }
                  | /* empty */
                  {
                        // ARBOL
                  }
                  ;

variable_asignacion : variable COLON EQUALS expresion
                    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        // ARBOL
                    }
                    ;

for_asignacion : variable_asignacion
               {
                  // ARBOL
               }
               | variable
               {
                  // ARBOL
               }
               ;

variable : identificador
         {
            // ARBOL
         }
         | identificador LBRACKET expresion RBRACKET
         {
            // ARBOL
         }
         ;

procedure_instruccion : identificador 
                      {
                        // ARBOL
                      }
                      | identificador LPAREN expresion_lista RPAREN
                      {
                        // ARBOL
                      }

relop_expresion : relop_expresion OR relop_and 
                {
                  // ARBOL
                }
                | relop_and
                {
                  // ARBOL
                }
                ;

relop_and : relop_and AND relop_not 
          {
            // ARBOL
          }
          | relop_not
          {
            // ARBOL
          }
          ;

relop_not : NOT relop_not
          {
            // ARBOL
          }
          | relop_paren
          {
            // ARBOL
          }
          ;

relop_paren : LPAREN relop_expresion RPAREN 
            {
                  // ARBOL
            }
            | relop_expresion_simple
            {
                  // ARBOL
            }
            ;

relop_expresion_simple : expresion relop expresion
                       {
                        // ARBOL
                       }

expresion_lista : expresion 
                {
                  // ARBOL
                }
                | expresion_lista COMMA expresion
                {
                  // ARBOL
                }
                ;

expresion : termino
          {
            // ARBOL
          }
          | expresion addop termino
          {
            // ARBOL
          }
          ;

termino : factor
        {
            // ARBOL
        }
        | termino mulop factor
        {
            // ARBOL
        }
        ;

llamado_funcion : identificador LPAREN expresion_lista RPAREN
                {
                  // ARBOL
                }
                ; 

factor : identificador
       {
            // ARBOL
       }
       | identificador LBRACKET expresion RBRACKET
       {
            // ARBOL
       }
       | llamado_funcion
       {
            // ARBOL
       }
       | constante_entera
       {
            // ARBOL
       }
       | constante_real
       {
            // ARBOL
       }
       | signo factor
       {
            // ARBOL
       }
       | LPAREN expresion RPAREN
       {
            // ARBOL
       }
       ;

signo : PLUS
      {
            // ARBOL
      }
      | MINUS
      {
            // ARBOL
      }
      | /* empty */
      {
            // ARBOL
      }
      ;

constante_entera : signo NUM_ENTERO
                 {
                  // ARBOL
                 }
                 ;

constante_real : signo NUM_ENTERO PERIOD NUM_ENTERO
               {
                  // ARBOL
               }
               | signo EXP
               {
                  // ARBOL
               }
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
            std::string errorS = "Error";
            char* errorC = new char[errorS.length() + 1];
            strcpy(errorC, errorS.c_str());
            yyerror(errorC);
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
            std::string errorS = "Error";
            char* errorC = new char[errorS.length() + 1];
            strcpy(errorC, errorS.c_str());
            yyerror(errorC);;
      }
      else if (!ht_is_scope_less_than_defined(ht, identifier.name, index, current_scope)) {
            printf("Error: variable %s en scope diferente en linea %d\n", identifier.name, identifier.line_used);
            std::string errorS = "Error";
            char* errorC = new char[errorS.length() + 1];
            strcpy(errorC, errorS.c_str());
            yyerror(errorC);
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

      printf("Ya acabe king\n");

      //print_table(ht);

      return 0;
}