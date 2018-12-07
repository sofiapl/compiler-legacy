%{
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "bridges.h"
extern void * file;

int yydebug = 1;

extern int yylex(void);
extern void yyerror(char *);
%}

%debug

%union {
    char   vChar;
    char * pChar;

    void * pVoid;

    int vInt;
    bool vBool;
    unsigned char vUChar;
}

%type <pVoid> file identifier
              type type_numeric
              top_stmts top_stmt stmts stmts_r
              stmt stmt_variable_define stmt_expression stmt_return
              expr expr_function expr_function_call expr_value expr_fetch expr_assign expr_when expr_op
              function_arg list_function_arg list_expr_nr list_expr
              when_body when_stmts when_stmt when_expr

%type <pChar> identifier_token
%type <vBool> type_numeric_signed type_numeric_integer
%type <vUChar> type_numeric_bits

%left ','
%right '!' '~'
%right T_EXP_OP
%left '*' '/' '%'
%left '+' '-'
%left T_SHL_OP T_SHR_OP T_USHR_OP
%left '<' T_GE_OP '>' T_LE_OP
%left T_EQ_OP T_NE_OP
%left '&'
%left '^'
%left '|'
%left T_AND_OP
%left T_OR_OP
%right T_ARR_RIGHT
%right '=' T_PL_AS_OP T_MI_AS_OP T_MUL_AS_OP T_EXP_AS_OP T_DIV_AS_OP T_MOD_AS_OP T_SHL_AS_OP T_SHR_AS_OP T_USHR_AS_OP T_AND_AS_OP T_XOR_AS_OP T_OR_AS_OP
%right '(' ')'
%right '[' ']'
%right '{' '}'

%token T_VAR
%right T_IF T_ELSE T_WHEN
%right T_FUNCTION
%token T_RETURN

%token <pChar> T_SIGNED T_UNSIGNED
%token <pChar> T_BIT T_BYTE T_SHORT T_LONG
%token <pChar> T_INT T_FLOAT

%token <pChar> T_NAME
%token <vInt> T_NUMBER

%token <vChar> T_CHAR_LITERAL
%token <pChar> T_STRING_LITERAL
%token <pChar> T_INTEGER_LITERAL
%token <pChar> T_FLOAT_LITERAL

%left T_UMINUS

%%

file
    : top_stmts { $$ = file = $1; }
    |           { $$ = file = makeNodesEmpty(); }
    ;

identifier
    : identifier_token { $$ = makeIdentifier($1); }
    ;

identifier_token
    : T_NAME
    | T_SIGNED
    | T_UNSIGNED
    | T_BIT
    | T_BYTE
    | T_SHORT
    | T_LONG
    | T_INT
    | T_FLOAT
    ;

type
    : type_numeric  /*
    | type_array
    | type_function */
    ;

type_numeric
    : type_numeric_signed                                           { $$ = makeNumericType(1, $1,    0,  false); }
    | type_numeric_bits                                             { $$ = makeNumericType(2, false, $1, false); }
    | type_numeric_integer                                          { $$ = makeNumericType(4, false, 0,  $1);    }
    | type_numeric_signed type_numeric_bits                         { $$ = makeNumericType(3, $1,    $2, false); }
    | type_numeric_signed type_numeric_integer                      { $$ = makeNumericType(5, $1,    0,  $2);    }
    | type_numeric_bits type_numeric_integer                        { $$ = makeNumericType(6, false, $1, $1);    }
    | type_numeric_signed type_numeric_bits type_numeric_integer    { $$ = makeNumericType(7, $1,    $2, $3);    }
    ;

type_numeric_signed
    : T_SIGNED      { $$ = true; }
    | T_UNSIGNED    { $$ = false; }
    ;

type_numeric_bits
    : T_NUMBER
    | T_BIT     { $$ = 1; }
    | T_BYTE    { $$ = 8; }
    | T_SHORT   { $$ = 16; }
    | T_LONG    { $$ = 64; }
    ;

type_numeric_integer
    : T_INT     { $$ = true; }
    | T_FLOAT   { $$ = false; }
    ;

top_stmts
    : top_stmt              { $$ = makeNodes($1); }
    | top_stmts top_stmt    { $$ = pushNode($1, $2); }
    ;

top_stmt
    : stmt_variable_define
    ;

stmts
    :           { $$ = makeNodesEmpty(); }
    | stmts_r
    ;

stmts_r
    : stmt          { $$ = makeNodes($1); }
    | stmts_r stmt  { $$ = pushNode($1, $2); }
    ;

stmt
    : stmt_variable_define
    | stmt_expression
    | stmt_return
    ;

stmt_variable_define
    : T_VAR identifier ':' type          { $$ = makeVariableDefineStmtT($2, $4); }
    | T_VAR identifier '=' expr          { $$ = makeVariableDefineStmtV($2, $4); }
    | T_VAR identifier ':' type '=' expr { $$ = makeVariableDefineStmt($2, $4, $6); }
    ;

stmt_expression
    : expr      { $$ = makeExpressionStmt($1); }
    ;

stmt_return
    : T_RETURN expr { $$ = makeReturnStmt($2); }
    ;

expr
    : expr_function
    | expr_function_call
    | expr_value
    | expr_fetch
    | expr_assign
    | expr_when
    | expr_op
    ;

expr_function
    : T_FUNCTION '(' list_function_arg ')' '{' stmts '}'
            { /**/ }
    ;

list_function_arg
    :                                       { $$ = makeNodesEmpty(); }
    | function_arg                          { $$ = makeNodes($1); }
    | list_function_arg ',' function_arg    { $$ = pushNode($1, $3); }
    ;

function_arg
    : identifier                    { /**/ }
    | identifier ':' type           { /**/ }
    | identifier '=' expr           { /**/ }
    | identifier ':' type '=' expr  { /**/ }
    ;

expr_function_call
    : expr '(' list_expr_nr ')' { /**/ }
    ;

list_expr_nr
    :           { $$ = makeNodesEmpty(); }
    | list_expr
    ;

list_expr
    : expr                  { $$ = makeNodes($1); }
    | list_expr ',' expr    { $$ = pushNode($1, $3); }
    ;

expr_value
    : T_NUMBER          { /**/ }
    | T_INTEGER_LITERAL { /**/ }
    | T_FLOAT_LITERAL   { /**/ }
    | T_STRING_LITERAL  { /**/ }
    | T_CHAR_LITERAL    { /**/ }
    ;

expr_fetch
    : identifier    { /**/ }
    ;

expr_assign
    : identifier '=' expr   { /**/ }
    ;

expr_when
    : T_WHEN '(' expr ')' '{' when_body '}' { /**/ }
    | T_WHEN '{' when_body '}'              { /**/ }
    ;

when_body
    :               { $$ = makeNodesEmpty(); }
    | when_stmts
    ;

when_stmts
    : when_stmt             { $$ = makeNodes($1); }
    | when_stmts when_stmt  { $$ = pushNode($1, $2); }
    ;

when_stmt
    : expr T_ARR_RIGHT when_expr
    | T_ELSE T_ARR_RIGHT when_expr
    ;

when_expr
    : stmt
    | '{' expr '}'
    | '{' stmts_r expr '}'
    ;

expr_op
    : '!' expr
    | '~' expr
    | '-' expr %prec T_UMINUS
    | expr '+' expr
    | expr '-' expr
    | expr '*' expr
    | expr '/' expr
    | '(' expr ')'              { $$ = $2; }
    ;

%%

void yyerror(char *s) {
    fprintf(stderr, "%s\n", s);
}
