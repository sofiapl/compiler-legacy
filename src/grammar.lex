%{
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include <bridges.h>

#include "y.tab.h"

extern void yyerror(char *);

int dupAndRet(int ret) {
    yylval.pChar = strdup(yytext);
    return ret;
}

// TODO Fix pattrens

%}

W   [a-zA-Z_$]
N   [0-9]
hN  [0-9a-fA-F]
S   [ \b\n\t\f\r]

nPrefix     (0x|0b|0)

%%

({S}|"//".*)+   ;
(?s:"/*".*"*/") ;

"var"       { return T_VAR; }
"if"        { return T_IF; }
"else"      { return T_ELSE; }
"when"      { return T_WHEN; }
"function"  { return T_FUNCTION; }
"return"    { return T_RETURN; }

"signed"    { return dupAndRet(T_SIGNED); }
"unsigned"  { return dupAndRet(T_UNSIGNED); }
"bit"       { return dupAndRet(T_BIT); }
"byte"      { return dupAndRet(T_BYTE); }
"short"     { return dupAndRet(T_SHORT); }
"long"      { return dupAndRet(T_LONG); }
"int"       { return dupAndRet(T_INT); }
"float"     { return dupAndRet(T_FLOAT); }

"->"        { return T_ARR_RIGHT; }

"**"        { return T_EXP_OP; }
"<<"        { return T_SHL_OP; }
">>"        { return T_SHR_OP; }
">>>"       { return T_USHR_OP; }

"\""(.|{S})*"\""    {
    return dupAndRet(T_STRING_LITERAL);
}

"'""\\"[\\bntfr']|."'"  {
    yylval.vChar = yytext[1];
    return T_CHAR_LITERAL;
}

{W}({W}|{N})*   {
    return dupAndRet(T_NAME);
}

-?{N}+          {
    yylval.pChar = yytext;
    return T_NUMBER;
}

(?i:-?{nPrefix}?{hN}+u?([bsil]{N}*)?)  {
    yylval.pVoid = parseIntegerLiteral(yytext);
    return T_INTEGER_LITERAL;
}

(?i:-?{nPrefix}?{hN}*\.?{hN}*u?([fd]{N}*)?)  {
    yylval.pVoid = parseFloatLiteral(yytext);
    return T_FLOAT_LITERAL;
}

.           { return * yytext; }

%%

int yywrap(void) {
    return 1;
}
