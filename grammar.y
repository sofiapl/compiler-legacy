%{
#include <string.h>

#include "../bridges.h"
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
}

%type <pVoid> file identifier type
              top_stmts top_stmt stmts stmts_r
              stmt stmt_variable_define stmt_expression stmt_return
              expr expr_function expr_function_call expr_value expr_fetch expr_assign expr_when expr_op
              function_arg list_function_arg list_expr_nr list_expr
              when_body when_stmts when_stmt when_expr


%left ','
%right '!' '~'
%right T_EXP_OP
%left '*' '/' '%'
%left '+' '-'
%left T_SHL_OP T_SHR_OP T_USHR_OP
%left '<' T_GREQ_OP '>' T_LEEQ_OP
%left T_EQ_OP T_NEQ_OP
%left '&'
%left '^'
%left '|'
%left T_AND_OP
%left T_OR_OP
%right '=' T_PLAS_OP T_MIAS_OP T_MULAS_OP T_EXPAS_OP T_DIVAS_OP T_MODAS_OP T_SHLAS_OP T_SHRAS_OP T_USHRAS_OP T_BITANDAS_OP T_BITXORAS_OP T_BITORAS_OP
%right '(' ')'
%right '[' ']'
%right '{' '}'

%token T_VAR
%right T_IF T_ELSE T_WHEN
%right T_FUNCTION
%token T_RETURN
%token T_ARR_RIGHT

%token <pChar> T_LITERAL

%token <vChar> T_CHAR
%token <pChar> T_STRING
%token <pChar> T_NUMBER

%left T_UMINUS

%%

file
    : top_stmts { $$ = file = $1; }
    |           { $$ = file = makeNodesEmpty(); }
    ;

identifier
    : T_LITERAL { $$ = makeIdentifier($1); }
    ;

type
    : T_LITERAL { $$ = makeType($1); }
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
    : T_VAR identifier ':' type          { $$ = makeVariableDefineT($2, $4); }
    | T_VAR identifier '=' expr          { $$ = makeVariableDefineV($2, $4); }
    | T_VAR identifier ':' type '=' expr { $$ = makeVariableDefine($2, $4, $6); }
    ;

stmt_expression
    : expr      { /**/ }
    ;

stmt_return
    : T_RETURN expr { /**/ }
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
    ;

list_function_arg
    :                                       { $$ = makeNodesEmpty(); }
    | function_arg                          { $$ = makeNodes($1); }
    | list_function_arg ',' function_arg    { $$ = pushNode($1, $3); }
    ;

function_arg
    : identifier
    | identifier ':' type
    | identifier '=' expr
    | identifier ':' type '=' expr
    ;

expr_function_call
    : expr '(' list_expr_nr ')'
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
    : T_NUMBER
    | T_STRING
    | T_CHAR
    ;

expr_fetch
    : identifier
    ;

expr_assign
    : identifier '=' expr
    ;

expr_when
    : T_WHEN '(' expr ')' '{' when_body '}'
    | T_WHEN '{' when_body '}'
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
