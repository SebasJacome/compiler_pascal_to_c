%{
      #include <stdio.h>
      #include <iostream>
      #include <vector>
      #include <string>
      #include <string.h>
      #include <cstring>
      #include "hash_table.h"
      #include "codegen.h"
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

      bool warning = false;
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
      instrucciones_opcionales instrucciones_lista instrucciones repeticion_instruccion
      lectura_instruccion escritura_instruccion if_instruccion variable_asignacion
      for_asignacion variable procedure_instruccion relop_expresion relop_and relop_not relop_paren
      relop_expresion_simple expresion_lista expresion termino llamado_funcion factor signo constante_entera
      constante_real cadena numero

%%

programa : PROGRAM
            {     
                  scope = 0;
            } 
            identificador 
            {
                  insert_table_var_def(VOID, last[last.size() - 1]);
                  insert_table_var_used(VOID, {last[last.size() - 1].name, 0});
                  last.clear();
            }
            LPAREN identificador_lista
            {
                  for (unsigned int i = 0; i < last.size(); i++) {
                        insert_table_var_def(VOID, last[i]);
                        insert_table_var_used(VOID, {last[i].name, 0});
                  }
                  last.clear();
            } 
            RPAREN SEMICOLON contenido_programa PERIOD
            {
                  if (current_scope != 0) {
                        printf("Error, algun scope no se cerro correctamente");
                        warning = true;
                  }

                  Nodo* raiz = crearNodo(PROGRAMA);
                  
                  insertarNodoHijos(raiz, $3, $6, $10);
                  $$ = raiz; 

                  string vars = "";
                  if (ht_return_all_values_not_used(ht, vars)) {
                        printf("Warning: variables definidas, pero nunca usadas: %s\n", vars.c_str());
                        warning = 1;
                  }

                  imprimirArbol(raiz);

                  generar(raiz, warning);
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
                        $$ = $1;
                    }
                    | identificador_lista COMMA identificador
                    {
                        Nodo* temp = $1;
                        if(temp){
                              while(temp->hermano != nullptr){
                                    temp = temp->hermano;
                              }
                              agregarHermano(temp, $3);
                              $$ = $1;
                        }
                    }
                    ;

declaraciones : declaraciones_variables
              {
                  $$ = $1;
              }
              | declaraciones_constantes
              {
                  $$ = $1;
              }
              ;

declaraciones_variables : declaraciones_variables VAR identificador_lista COLON tipo SEMICOLON
                        {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(last_variable_type, last[i]);
                              }
                              last.clear();

                              Nodo* temp = $1;
                              if(temp){
                                    agregarHijo(temp, $3);
                                    agregarHijo($3, $5);
                                    $$ = $1;
                              }
                              else{
                                    Nodo* nodo = crearNodo(DECLARACIONES_VARIABLES);
                                    insertarNodoHijos(nodo, $1, $3);
                                    agregarHijo($3, $5);
                                    $$ = nodo;
                              }
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

                              Nodo* temp = $1;
                              if(temp){
                                    agregarHijo(temp, $3);
                                    agregarHijo($3, $5);
                                    $$ = $1;
                              }
                              else{
                                    Nodo* nodo = crearNodo(DECLARACIONES_CONSTANTES);
                                    insertarNodoHijos(nodo, $1, $3);
                                    agregarHijo($3, $5);
                                    $$ = nodo;
                              }
                         }
                         | declaraciones_constantes CONST identificador EQUALS constante_real SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_REAL, last[i]);
                              }
                              last.clear();

                              Nodo* temp = $1;
                              if(temp){
                                    agregarHijo(temp, $3);
                                    agregarHijo($3, $5);
                                    $$ = $1;
                              }
                              else{
                                    Nodo* nodo = crearNodo(DECLARACIONES_CONSTANTES);
                                    insertarNodoHijos(nodo, $1, $3);
                                    agregarHijo($3, $5);
                                    $$ = nodo;
                              }
                        }
                         | declaraciones_constantes CONST identificador EQUALS cadena SEMICOLON
                         {
                              for(unsigned int i = 0; i < last.size(); i++) {
                                    insert_table_var_def(CONST_CADENA, last[i]);
                              }
                              last.clear();

                              Nodo* temp = $1;
                              if(temp){
                                    agregarHijo(temp, $3);
                                    agregarHijo($3, $5);
                                    $$ = $1;
                              }
                              else{
                                    Nodo* nodo = crearNodo(DECLARACIONES_CONSTANTES);
                                    insertarNodoHijos(nodo, $1, $3);
                                    agregarHijo($3, $5);
                                    $$ = nodo;
                              }
                         }
                         | /* empty */
                         {
                              $$ = NULL;
                         }
                         ;

tipo : estandar_tipo
     {
      $$ = $1;
     }
     | ARRAY LBRACKET NUM_ENTERO PERIOD PERIOD NUM_ENTERO RBRACKET OF estandar_tipo
     {
      for (unsigned int i = 0; i < last.size(); i++) {
            insert_table_defsize(last_variable_type, last[i], ($6) - ($3));
      }
      last.clear();

      Nodo* nodo = crearNodo(ESTANDAR_TIPO);
      nodo->valorCadena = strdup($1);
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
                              Nodo* temp = $1;
                              if(temp){
                                    while(temp->hermano != nullptr){
                                          temp = temp->hermano;
                                    }
                                    agregarHermano(temp, $2);
                                    $$ = $1;
                              } else {
                                    Nodo* nodo = $2;
                                    insertarNodoHijos(nodo, $1);
                                    $$ = nodo;
                              }
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
            $$ = $2;
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
                  insertarNodoHijos(nodo, $1);
                  insertarNodoHijos($1, $3);
                  $$ = nodo;
                 }
                 | parametros_lista SEMICOLON identificador_lista COLON tipo
                 {
                  while (last.size() > 1) {
                        insert_table_var_def(last_variable_type, last[last.size() - 1]);
                        last.pop_back();
                  }

                  Nodo* temp = $1;
                  if(temp){
                        while(temp->hermano != nullptr){
                              temp = temp->hermano;
                        }
                        agregarHijo(temp, $3);
                        agregarHijo($3, $5);
                        $$ = $1;
                  }
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
                              $$ = $1;
                         }
                         | /* empty */
                         {
                              $$ = NULL;
                         }
                         ;

instrucciones_lista : instrucciones
                    {
                        $$ = $1;
                    }
                    | instrucciones_lista SEMICOLON instrucciones
                    {
                        Nodo* temp = $1;
                        if(temp){
                              while(temp->hermano != nullptr){
                                    temp = temp->hermano;
                              }
                              agregarHermano(temp, $3);
                              $$ = $1;
                        }
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
                       | FOR for_asignacion TO expresion DO instrucciones
                       {
                        Nodo* nodo = crearNodo(REPETICION_INSTRUCCION);
                        nodo->valorCadena = strdup("for++");
                        insertarNodoHijos(nodo, $2, $4, $6);
                        $$ = nodo;
                       }
                       | FOR for_asignacion DOWNTO expresion DO instrucciones
                       {
                        Nodo* nodo = crearNodo(REPETICION_INSTRUCCION);
                        nodo->valorCadena = strdup("for--");
                        insertarNodoHijos(nodo, $2, $4, $6);
                        $$ = nodo;
                       }
                       ;

lectura_instruccion : READ LPAREN identificador RPAREN
                    {
                        Nodo* nodo = crearNodo(LECTURA_INSTRUCCION);
                        nodo->valorCadena = strdup("read");
                        $$ = nodo;
                    }
                    | READLN LPAREN identificador RPAREN
                    {
                        Nodo* nodo = crearNodo(LECTURA_INSTRUCCION);
                        nodo->valorCadena = strdup("readln");
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

if_instruccion : IF relop_expresion THEN instrucciones ELSE instrucciones
               {
                  Nodo* nodo = crearNodo(IF_INSTRUCCION);
                  nodo->valorCadena = strdup("if");
                  insertarNodoHijos(nodo, $2, $4, $6);
                  $$ = nodo;
               }
               | IF relop_expresion THEN instrucciones
               {
                  Nodo* nodo = crearNodo(IF_INSTRUCCION);
                  nodo->valorCadena = strdup("if");
                  insertarNodoHijos(nodo, $2, $4);
                  $$ = nodo;
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
                  $$ = $1;
               }
               | variable
               {
                  $$ = $1;
               }
               ;

variable : identificador
         {
            $$ = $1;
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
                  Nodo* temp = $1;
                  if(temp){
                        while(temp->hermano != nullptr){
                              temp = temp->hermano;
                        }
                        agregarHermano(temp, $3);
                        $$ = $1;
                  }
                }
                | relop_and
                {
                  $$ = $1;
                }
                ;

relop_and : relop_and AND relop_not 
          {
            Nodo* temp = $1;
            if(temp){
                  while(temp->hermano != nullptr){
                        temp = temp->hermano;
                  }
                  agregarHermano(temp, $3);
                  $$ = $1;
            }
          }
          | relop_not
          {
            $$ = $1;
          }
          ;

relop_not : NOT relop_not
          {
            $$ = $2;
          }
          | relop_paren
          {
            $$ = $1;
          }
          ;

relop_paren : LPAREN relop_expresion RPAREN 
            {
                  $$ = $2;
            }
            | relop_expresion_simple
            {
                  $$ = $1;
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
                  $$ = $1;
                }
                | expresion_lista COMMA expresion
                {
                  Nodo* temp = $1;
                        if(temp){
                              while(temp->hermano != nullptr){
                                    temp = temp->hermano;
                              }
                              agregarHermano(temp, $3);
                              $$ = $1;
                        }
                }
                ;

expresion : termino
          {
            $$ = $1;
          }
          | expresion addop termino
          {
            Nodo* temp = $1;
            agregarHijo(temp, $2);
            agregarHijo($2, $3);
            $$ = $1;
          }
          ;

termino : factor
        {
            $$ = $1;
        }
        | termino mulop factor
        {
            Nodo* temp = $1;
            agregarHijo(temp, $2);
            agregarHijo($2, $3);
            $$ = $1;

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
            $$ = $1;
       }
       | identificador LBRACKET expresion RBRACKET
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $1, $3);
            $$ = nodo;
       }
       | llamado_funcion
       {
            $$ = $1;
       }
       | constante_entera
       {
            $$ = $1;
       }
       | constante_real
       {
            $$ = $1;
       }
       | signo factor
       {
            Nodo* nodo = crearNodo(FACTOR);
            insertarNodoHijos(nodo, $1, $2);
            $$ = nodo;
       }
       | LPAREN expresion RPAREN
       {
            $$ = $2;
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

constante_entera : signo numero
                 {
                  Nodo* nodo = crearNodo(CONSTANTE_ENTERA);
                  insertarNodoHijos(nodo, $1, $2);
                  $$ = nodo;
                 }
                 ;

numero: NUM_ENTERO
      {
            Nodo* nodo = crearNodo(NUMERO);
            std::string num = strdup($1);
            nodo->valorCadena = num[0];
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
            printf("Warning: variable %s ya declarada en linea %d\n", identifier.name, identifier.line_used);
            warning = true;
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
            printf("Warning: variable %s no declarada en linea %d\n", identifier.name, identifier.line_used);
            warning = true;
      }
      else if (!ht_is_scope_less_than_defined(ht, identifier.name, index, current_scope)) {
            printf("Warning: variable %s en scope diferente en linea %d\n", identifier.name, identifier.line_used);
            warning = true;
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
      //yydebug = 1;
      yyparse();

      // print_table(ht);

      return 0;
}