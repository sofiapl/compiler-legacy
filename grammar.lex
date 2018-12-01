%{
#include <stdlib.h>
#include <string.h>

#include "y.tab.h"

extern void yyerror(char *);
%}

W  [a-zA-Z_$]
N  [0-9]
hN [0-9a-fA-F]
S  [ \b\n\t\f\r]

%%

{S}         ;

(?i:"var")  { return T_VAR; }
(?i:"if")   { return T_IF; }
(?i:"else") { return T_ELSE; }
(?i:"when") { return T_WHEN; }
(?i:"function") { return T_FUNCTION; }
(?i:"return")   { return T_RETURN; }
(?i:"->")   { return T_ARR_RIGHT; }

"**"        { return T_EXP_OP; }
"<<"        { return T_SHL_OP; }
">>"        { return T_SHR_OP; }
">>>"       { return T_USHR_OP; }

"\""(.|{S})*"\""    {
    yylval.pChar = strdup(yytext);
    return T_STRING;
}

"'"."'"         {
    yylval.vChar = yytext[1];
    return T_CHAR;
}

{W}({W}|{N})*   {
    yylval.pChar = strdup(yytext);
    return T_LITERAL;
}

(?i:(0x|0b|0)?({hN}+|{hN}*\.{hN}+(e[+-]?{hN}+)?)u?([ilfd]{N}+)?)    {
    yylval.pChar = strdup(yytext);
    return T_NUMBER;
}

.           { return * yytext; }

%%

int yywrap(void) {
    return 1;
}
