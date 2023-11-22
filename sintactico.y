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

%token <cadena> 
      PROGRAM VAR CONST FUNCTION PROCEDURE BEG END OF IF THEN ELSE 
      WHILE DO FOR TO DOWNTO READ READLN WRITE WRITELN AND OR NOT DIV MOD 
      LPAREN RPAREN LBRACKET RBRACKET PLUS MINUS ASTERISK SLASH 
      EQUALS COLON SEMICOLON COMMA PERIOD
      EXP CADENA LESSTHAN GREATERTHAN LESSTHANEQUALS GREATERTHANEQUALS NOTEQUALS
      IDENTIFICADOR ARRAY INTEGER_TIPO REAL_TIPO STRING_TIPO BOOLEAN_TIPO
      NUM_ENTERO

%type <nodo> 
      programa contenido_programa relop addop mulop identificador_lista identificador declaraciones
      declaraciones_variables declaraciones_constantes tipo estandar_tipo subprograma_declaraciones
      subprograma_declaracion subprograma_encabezado argumentos parametros_lista instruccion_compuesta
      instrucciones_opcionales instrucciones_lista instrucciones repeticion_instruccion for_comportamiento
      lectura_instruccion escritura_instruccion if_instruccion instruccion_else variable_asignacion
      for_asignacion variable procedure_instruccion relop_expresion relop_and relop_not relop_paren
      relop_expresion_simple expresion_lista expresion termino llamado_funcion factor signo constante_entera
      constante_real cadena

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
                  if (current_scope != 0) {
                        std::string errorS = "Error, algun scope no se cerro correctamente";
                        char* errorC = new char[errorS.length() + 1];
                        strcpy(errorC, errorS.c_str());
                        yyerror(errorC);
                  }

                  Nodo* raiz = crearNodo(PROGRAMA);
                  insertarNodoHijos(raiz, $3, $6, $10);
                  $$ = raiz; 
                  //imprimirArbol(raiz);
                  imprimirArbolSoloID(raiz);
            }
            ;

contenido_programa : declaraciones subprograma_declaraciones instruccion_compuesta
                   {
                        Nodo* nodo = crearNodo(CONTENIDO_PROGRAMA);
                        insertarNodoHijos(nodo, $1, $2, $3);
                        $$ = nodo;
                   }
                    ;

identificador : IDENTIFICADOR 
                  {
                        char* var_name = strdup($1);
                        int var_line = @1.last_line;
                        last.push_back({var_name, var_line}); 

                        Nodo* nodo = crearNodo(ID);
                        nodo->valorCadena = strdup($1);
                        $$ = nodo;
                            
                  }
              ;

relop : AND 
      {
            Nodo* nodo = crearNodo(RELOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | OR 
      {
            Nodo* nodo = crearNodo(RELOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | EQUALS 
      {
            Nodo* nodo = crearNodo(RELOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | LESSTHAN 
      {
            Nodo* nodo = crearNodo(RELOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | GREATERTHAN 
      {
            Nodo* nodo = crearNodo(RELOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | LESSTHANEQUALS 
      {
            Nodo* nodo = crearNodo(RELOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | GREATERTHANEQUALS 
      {
            Nodo* nodo = crearNodo(RELOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | NOTEQUALS
      {
            Nodo* nodo = crearNodo(RELOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      ;

addop : PLUS 
      {
            Nodo* nodo = crearNodo(ADDOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | MINUS
      {
            Nodo* nodo = crearNodo(ADDOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      ;

mulop : ASTERISK 
      {
            Nodo* nodo = crearNodo(MULOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | SLASH 
      {
            Nodo* nodo = crearNodo(MULOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | DIV 
      {
            Nodo* nodo = crearNodo(MULOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      | MOD
      {
            Nodo* nodo = crearNodo(MULOP);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      ;

cadena: CADENA
      {
            Nodo* nodo = crearNodo(CADENA_CONST);
            nodo->valorCadena = strdup($1);
            $$ = nodo;
      }
      ;

identificador_lista : identificador
                    {
                        Nodo* nodo = crearNodo(IDENTIFICADOR_LISTA);
                        insertarNodoHijos(nodo, $1);
                        $$ = nodo;
                    }
                    | identificador_lista COMMA identificador
                    {
                        Nodo* nodo = crearNodo(IDENTIFICADOR_LISTA);
                        insertarNodoHijos(nodo, $1, $3);
                        $$ = nodo;
                    }
                    ;

declaraciones : declaraciones_variables
              {
                  Nodo* nodo = crearNodo(DECLARACIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              | declaraciones_constantes
              {
                  Nodo* nodo = crearNodo(DECLARACIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              ;

declaraciones_variables : declaraciones_variables VAR identificador_lista COLON tipo SEMICOLON
                        {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(last_variable_type, last[i]);
                              }
                              last.clear();

                              Nodo* nodo = crearNodo(DECLARACIONES_VARIABLES);
                              insertarNodoHijos(nodo, $1, $3, $5);
                              $$ = nodo;
                        }
                        | /* empty */
                        {
                              $$ = NULL;
                        }
                        ;

declaraciones_constantes : declaraciones_constantes CONST identificador EQUALS constante_entera SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_ENTERO, last[i]);
                              }
                              last.clear();

                              Nodo* nodo = crearNodo(DECLARACIONES_CONSTANTES);
                              insertarNodoHijos(nodo, $1, $3, $5);
                              $$ = nodo;
                         }
                         | declaraciones_constantes CONST identificador EQUALS constante_real SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_REAL, last[i]);
                              }
                              last.clear();

                              Nodo* nodo = crearNodo(DECLARACIONES_CONSTANTES);
                              insertarNodoHijos(nodo, $1, $3, $5);
                              $$ = nodo;
                        }
                         | declaraciones_constantes CONST identificador EQUALS cadena SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_CADENA, last[i]);
                              }
                              last.clear();

                              Nodo* nodo = crearNodo(DECLARACIONES_CONSTANTES);
                              insertarNodoHijos(nodo, $1, $3);
                              $$ = nodo;
                         }
                         | /* empty */
                         {
                              $$ = NULL;
                         }
                         ;

tipo : estandar_tipo
     {
      Nodo* nodo = crearNodo(TIPO);
      insertarNodoHijos(nodo, $1);
      $$ = nodo;
     }
     | ARRAY LBRACKET NUM_ENTERO PERIOD PERIOD NUM_ENTERO RBRACKET OF estandar_tipo
     {
      for (unsigned int i = 0; i < last.size(); i++) {
            insert_table_defsize(last_variable_type, last[i], ($6) - ($3) + 1);
      }
      last.clear();

      Nodo* nodo = crearNodo(TIPO);
      nodo->valorCadena = strdup($1);
      insertarNodoHijos(nodo, $9);
      $$ = nodo;
     }
     ;

estandar_tipo : INTEGER_TIPO
              { 
                  last_variable_type = INTEGER;

                  Nodo* nodo = crearNodo(ESTANDAR_TIPO);
                  nodo->valorCadena = strdup($1);
                  $$ = nodo;
              }
              | REAL_TIPO
              { 
                  last_variable_type = FLOAT;

                  Nodo* nodo = crearNodo(ESTANDAR_TIPO);
                  nodo->valorCadena = strdup($1);
                  $$ = nodo;
              }
              | STRING_TIPO
              { 
                  last_variable_type = STRING;

                  Nodo* nodo = crearNodo(ESTANDAR_TIPO);
                  nodo->valorCadena = strdup($1);
                  $$ = nodo;
              }
              | BOOLEAN_TIPO
              { 
                  last_variable_type = BOOLEAN;

                  Nodo* nodo = crearNodo(ESTANDAR_TIPO);
                  nodo->valorCadena = strdup($1);
                  $$ = nodo;
              }
              ;

subprograma_declaraciones : subprograma_declaraciones subprograma_declaracion SEMICOLON
                          {
                              Nodo* nodo = crearNodo(SUBPROGRAMA_DECLARACIONES);
                              insertarNodoHijos(nodo, $1, $2);
                              $$ = nodo;
                          }
                          | /* empty */
                          {
                              $$ = NULL;
                          }
                          ;

subprograma_declaracion : subprograma_encabezado declaraciones instruccion_compuesta
                        {
                              Nodo* nodo = crearNodo(SUBPROGRAMA_DECLARACION);
                              insertarNodoHijos(nodo, $1, $2, $3);
                              $$ = nodo;
                        }
                        ;

subprograma_encabezado  : FUNCTION 
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
                              Nodo* nodo = crearNodo(SUBPROGRAMA_ENCABEZADO);
                              nodo->valorCadena = strdup("function");
                              insertarNodoHijos(nodo, $3, $4, $6);
                              $$ = nodo;
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

                              Nodo* nodo = crearNodo(SUBPROGRAMA_ENCABEZADO);
                              nodo->valorCadena = strdup("procedure");
                              insertarNodoHijos(nodo, $3, $4);
                              $$ = nodo;
                       }
                       ;

argumentos : LPAREN parametros_lista RPAREN 
           {
            Nodo* nodo = crearNodo(ARGUMENTOS);
            insertarNodoHijos(nodo, $2);
            $$ = nodo;
           }
           | /* empty */
           {
            $$ = NULL;
           }
           ;

parametros_lista : identificador_lista COLON tipo 
                 {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }

                  Nodo* nodo = crearNodo(PARAMETROS_LISTA);
                  insertarNodoHijos(nodo, $1, $3);
                  $$ = nodo;
                 }
                 | parametros_lista SEMICOLON identificador_lista COLON tipo
                 {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }

                  Nodo* nodo = crearNodo(PARAMETROS_LISTA);
                  insertarNodoHijos(nodo, $1, $3, $5);
                  $$ = nodo;
                 }
                 ;

instruccion_compuesta : BEG instrucciones_opcionales 
                        END
                        { 
                              current_scope = 0;

                              Nodo* nodo = crearNodo(INSTRUCCION_COMPUESTA);
                              insertarNodoHijos(nodo, $2);
                              $$ = nodo;
                        }
                        ;

instrucciones_opcionales : instrucciones_lista
                         {
                              Nodo* nodo = crearNodo(INSTRUCCIONES_OPCIONALES);
                              insertarNodoHijos(nodo, $1);
                              $$ = nodo;
                         }
                         | /* empty */
                         {
                              $$ = NULL;
                         }
                         ;

instrucciones_lista : instrucciones
                    {
                        Nodo* nodo = crearNodo(INSTRUCCIONES_LISTA);
                        insertarNodoHijos(nodo, $1);
                        $$ = nodo;
                    }
                    | instrucciones_lista SEMICOLON instrucciones
                    {
                        Nodo* nodo = crearNodo(INSTRUCCIONES_LISTA);
                        insertarNodoHijos(nodo, $1, $3);
                        $$ = nodo;
                    }
                    ;

instrucciones : variable_asignacion
              {
                  Nodo* nodo = crearNodo(INSTRUCCIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              | procedure_instruccion
              {
                  Nodo* nodo = crearNodo(INSTRUCCIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              | instruccion_compuesta
              {
                  Nodo* nodo = crearNodo(INSTRUCCIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              | if_instruccion
              {
                  Nodo* nodo = crearNodo(INSTRUCCIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              | repeticion_instruccion
              {
                  Nodo* nodo = crearNodo(INSTRUCCIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              | lectura_instruccion
              {
                  Nodo* nodo = crearNodo(INSTRUCCIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              | escritura_instruccion
              {
                  Nodo* nodo = crearNodo(INSTRUCCIONES);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
              }
              ;

repeticion_instruccion : WHILE relop_expresion DO instrucciones
                       {
                        Nodo* nodo = crearNodo(REPETICION_INSTRUCCION);
                        nodo->valorCadena = strdup("while");
                        insertarNodoHijos(nodo, $2, $4);
                        $$ = nodo;
                       }
                       | FOR for_asignacion for_comportamiento expresion DO instrucciones
                       {
                        Nodo* nodo = crearNodo(REPETICION_INSTRUCCION);
                        nodo->valorCadena = strdup("for");
                        insertarNodoHijos(nodo, $2, $4);
                        $$ = nodo;
                       }
                       ;

for_comportamiento: TO 
                  {
                        Nodo* nodo = crearNodo(FOR_COMPORTAMIENTO);
                        nodo->valorCadena = strdup($1);
                        $$ = nodo;
                  }
                  | DOWNTO   
                  {
                        Nodo* nodo = crearNodo(FOR_COMPORTAMIENTO);
                        nodo->valorCadena = strdup($1);
                        $$ = nodo;
                  }
                  ;

lectura_instruccion : READ LPAREN identificador RPAREN
                    {
                        Nodo* nodo = crearNodo(LECTURA_INSTRUCCION);
                        nodo->valorCadena = strdup("read");
                        insertarNodoHijos(nodo, $3);
                        $$ = nodo;
                    }
                    | READLN LPAREN identificador RPAREN
                    {
                        Nodo* nodo = crearNodo(LECTURA_INSTRUCCION);
                        nodo->valorCadena = strdup("readln");
                        insertarNodoHijos(nodo, $3);
                        $$ = nodo;
                    }
                    ;

escritura_instruccion : WRITE LPAREN cadena COMMA identificador RPAREN
                      {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        Nodo* nodo = crearNodo(ESCRITURA_INSTRUCCION);
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, $3, $5);
                        $$ = nodo;
                      }
                      | WRITELN LPAREN cadena COMMA identificador RPAREN
                      {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        Nodo* nodo = crearNodo(ESCRITURA_INSTRUCCION);
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, $3, $5);
                        $$ = nodo;
                      }
                      | WRITE LPAREN cadena RPAREN
                      {
                        Nodo* nodo = crearNodo(ESCRITURA_INSTRUCCION);
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, $3);
                        $$ = nodo;
                      }
                      | WRITELN LPAREN cadena RPAREN
                      {
                        Nodo* nodo = crearNodo(ESCRITURA_INSTRUCCION);
                        nodo->valorCadena = strdup("writeln");
                        insertarNodoHijos(nodo, $3);
                        $$ = nodo;
                      }
                      | WRITE LPAREN cadena COMMA expresion RPAREN
                      {
                        Nodo* nodo = crearNodo(ESCRITURA_INSTRUCCION);
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, $3, $5);
                        $$ = nodo;
                      }
                      | WRITELN LPAREN cadena COMMA expresion RPAREN
                      {
                        Nodo* nodo = crearNodo(ESCRITURA_INSTRUCCION);
                        nodo->valorCadena = strdup("writeln");
                        insertarNodoHijos(nodo, $3, $5);
                        $$ = nodo;
                      }
                      | WRITE LPAREN identificador RPAREN
                      {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        Nodo* nodo = crearNodo(ESCRITURA_INSTRUCCION);
                        nodo->valorCadena = strdup("write");
                        insertarNodoHijos(nodo, $3);
                        $$ = nodo;
                      }
                      | WRITELN LPAREN identificador RPAREN
                      {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        Nodo* nodo = crearNodo(ESCRITURA_INSTRUCCION);
                        nodo->valorCadena = strdup("writeln");
                        insertarNodoHijos(nodo, $3);
                        $$ = nodo;
                       }
                      ;

if_instruccion : IF relop_expresion THEN instrucciones instruccion_else
               {
                  Nodo* nodo = crearNodo(IF_INSTRUCCION);
                  nodo->valorCadena = strdup("if");
                  insertarNodoHijos(nodo, $2, $4, $5);
                  $$ = nodo;
               }
               ;

instruccion_else: ELSE instrucciones
                  {
                        Nodo* nodo = crearNodo(IF_INSTRUCCION);
                        nodo->valorCadena = strdup("else");
                        insertarNodoHijos(nodo, $2);
                        $$ = nodo;
                  }
                  | /* empty */
                  {
                        $$ = NULL;
                  }
                  ;

variable_asignacion : variable COLON EQUALS expresion
                    {
                        for (unsigned int i = 0; i < last.size(); i++) {
                              insert_table_var_used(last_variable_type, last[i]);
                        }
                        last.clear();

                        Nodo* nodo = crearNodo(VARIABLE_ASIGNACION);
                        insertarNodoHijos(nodo, $1, $4);
                        $$ = nodo;
                    }
                    ;

for_asignacion : variable_asignacion
               {
                  Nodo* nodo = crearNodo(FOR_ASIGNACION);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
               }
               | variable
               {
                  Nodo* nodo = crearNodo(FOR_ASIGNACION);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
               }
               ;

variable : identificador
         {
            Nodo* nodo = crearNodo(VARIABLE);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
         }
         | identificador LBRACKET expresion RBRACKET
         {
            Nodo* nodo = crearNodo(VARIABLE);
            insertarNodoHijos(nodo, $1, $3);
            $$ = nodo;
         }
         ;

procedure_instruccion : identificador 
                      {
                        Nodo* nodo = crearNodo(PROCEDURE_INSTRUCCION);
                        insertarNodoHijos(nodo, $1);
                        $$ = nodo;
                      }
                      | identificador LPAREN expresion_lista RPAREN
                      {
                        Nodo* nodo = crearNodo(PROCEDURE_INSTRUCCION);
                        insertarNodoHijos(nodo, $1, $3);
                        $$ = nodo;
                      }

relop_expresion : relop_expresion OR relop_and 
                {
                  Nodo* nodo = crearNodo(RELOP_EXPRESION);
                  insertarNodoHijos(nodo, $1, $3);
                  $$ = nodo;
                }
                | relop_and
                {
                  Nodo* nodo = crearNodo(RELOP_EXPRESION);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
                }
                ;

relop_and : relop_and AND relop_not 
          {
            Nodo* nodo = crearNodo(RELOP_AND);
            insertarNodoHijos(nodo, $1, $3);
            $$ = nodo;
          }
          | relop_not
          {
            Nodo* nodo = crearNodo(RELOP_AND);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
          }
          ;

relop_not : NOT relop_not
          {
            Nodo* nodo = crearNodo(RELOP_NOT);
            insertarNodoHijos(nodo, $2);
            $$ = nodo;
          }
          | relop_paren
          {
            Nodo* nodo = crearNodo(RELOP_NOT);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
          }
          ;

relop_paren : LPAREN relop_expresion RPAREN 
            {
                  Nodo* nodo = crearNodo(RELOP_PAREN);
                  insertarNodoHijos(nodo, $2);
                  $$ = nodo;
            }
            | relop_expresion_simple
            {
                  Nodo* nodo = crearNodo(RELOP_PAREN);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
            }
            ;

relop_expresion_simple : expresion relop expresion
                       {
                        Nodo* nodo = crearNodo(RELOP_EXPRESION_SIMPLE);
                        insertarNodoHijos(nodo, $1, $2, $3);
                        $$ = nodo;
                       }

expresion_lista : expresion 
                {
                  Nodo* nodo = crearNodo(EXPRESION_LISTA);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
                }
                | expresion_lista COMMA expresion
                {
                  Nodo* nodo = crearNodo(EXPRESION_LISTA);
                  insertarNodoHijos(nodo, $1, $3);
                  $$ = nodo;
                }
                ;

expresion : termino
          {
            Nodo* nodo = crearNodo(EXPRESION);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
          }
          | expresion addop termino
          {
            Nodo* nodo = crearNodo(EXPRESION);
            insertarNodoHijos(nodo, $1, $2, $3);
            $$ = nodo;
          }
          ;

termino : factor
        {
            Nodo* nodo = crearNodo(TERMINO);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
        }
        | termino mulop factor
        {
            Nodo* nodo = crearNodo(TERMINO);
            insertarNodoHijos(nodo, $1, $2, $3);
            $$ = nodo;
        }
        ;

llamado_funcion : identificador LPAREN expresion_lista RPAREN
                {
                  Nodo* nodo = crearNodo(LLAMADO_FUNCION);
                  insertarNodoHijos(nodo, $1, $3);
                  $$ = nodo;
                }
                ; 

factor : identificador
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
       }
       | identificador LBRACKET expresion RBRACKET
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $1, $3);
            $$ = nodo;
       }
       | llamado_funcion
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
       }
       | constante_entera
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
       }
       | constante_real
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $1);
            $$ = nodo;
       }
       | signo factor
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $1, $2);
            $$ = nodo;
       }
       | LPAREN expresion RPAREN
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $2);
            $$ = nodo;
       }
       ;

signo : PLUS
      {
            Nodo* nodo = crearNodo(SIGNO);
            nodo->valorCadena = strdup("+");
            $$ = nodo;
      }
      | MINUS
      {
            Nodo* nodo = crearNodo(SIGNO);
            nodo->valorCadena = strdup("-");
            $$ = nodo;
      }
      | /* empty */
      {
            $$ = NULL;
      }
      ;

constante_entera : signo NUM_ENTERO
                 {
                  Nodo* nodo = crearNodo(CONSTANTE_ENTERA);
                  nodo->valorCadena = strdup($2);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
                 }
                 ;

constante_real : signo NUM_ENTERO PERIOD NUM_ENTERO
               {
                  Nodo* nodo = crearNodo(CONSTANTE_REAL);
                  nodo->valorCadena = strdup($2);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
               }
               | signo EXP
               {
                  Nodo* nodo = crearNodo(CONSTANTE_REAL);
                  nodo->valorCadena = strdup($2);
                  insertarNodoHijos(nodo, $1);
                  $$ = nodo;
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
            std::string errorS = "Error, variable redefinida";
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
            std::string errorS = "Error, variable no definida";
            char* errorC = new char[errorS.length() + 1];
            strcpy(errorC, errorS.c_str());
            yyerror(errorC);;
      }
      else if (!ht_is_scope_less_than_defined(ht, identifier.name, index, current_scope)) {
            printf("Error: variable %s en scope diferente en linea %d\n", identifier.name, identifier.line_used);
            std::string errorS = "Error, variable no declarada en scope";
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
      std::string vacio = "";
      char* vacioC = new char[vacio.length() + 1];
      strcpy(vacioC, vacio.c_str());
      data_value datos = {mem_acum, type, bytesize, lugar, vacioC, current_scope};
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

      printf("Arbol creado exitosamente\n");

      // print_table(ht);

      return 0;
}