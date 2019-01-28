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

%}

W   [a-zA-Z_$]
N   [0-9]
hN  [0-9a-fA-F]
S   [ \b\n\t\f\r]

nPrefix     (0x|0b|0)
nSigning    u?
nLength     {N}*

%%

{S}         ;

(?i:"var")      { return T_VAR; }
(?i:"if")       { return T_IF; }
(?i:"else")     { return T_ELSE; }
(?i:"when")     { return T_WHEN; }
(?i:"function") { return T_FUNCTION; }
(?i:"return")   { return T_RETURN; }

(?i:"signed")   { return dupAndRet(T_SIGNED); }
(?i:"unsigned") { return dupAndRet(T_UNSIGNED); }
(?i:"bit")      { return dupAndRet(T_BIT); }
(?i:"byte")     { return dupAndRet(T_BYTE); }
(?i:"short")    { return dupAndRet(T_SHORT); }
(?i:"long")     { return dupAndRet(T_LONG); }
(?i:"int")      { return dupAndRet(T_INT); }
(?i:"float")    { return dupAndRet(T_FLOAT); }

(?i:"->")   { return T_ARR_RIGHT; }

"**"        { return T_EXP_OP; }
"<<"        { return T_SHL_OP; }
">>"        { return T_SHR_OP; }
">>>"       { return T_USHR_OP; }

"\""(.|{S})*"\""    {
    return dupAndRet(T_STRING_LITERAL);
}

"'""\\"?."'"    {
    yylval.vChar = yytext[1];
    return T_CHAR_LITERAL;
}

{W}({W}|{N})*   {
    return dupAndRet(T_NAME);
}

-?{N}+          {
    yylval.vInt = atoi(yytext);
    return T_NUMBER;
}

(?i:-?{nPrefix}?{hN}+{nSigning}([bsil]{nLength})?)  {
    return dupAndRet(T_INTEGER_LITERAL);
}

(?i:-?{nPrefix}?{hN}*\.?{hN}+(e[+-]?{hN}+)?{nSigning}([fd]{nLength})?)  {
    return dupAndRet(T_FLOAT_LITERAL);
}

.           { return * yytext; }

%%

int yywrap(void) {
    return 1;
}
