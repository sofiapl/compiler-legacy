%{
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "y.tab.h"
#include "../bridges.h"

extern void yyerror(char *);
%}

W  [a-zA-Z_$]
N  [0-9]
hN [0-9a-fA-F]
S  [ \b\n\t\f\r]

%%

{S}         ;

(?i:"var")      { return T_VAR; }
(?i:"if")       { return T_IF; }
(?i:"else")     { return T_ELSE; }
(?i:"when")     { return T_WHEN; }
(?i:"function") { return T_FUNCTION; }
(?i:"return")   { return T_RETURN; }
(?i:"signed")   { return T_SIGNED; }
(?i:"unsigned") { return T_UNSIGNED; }
(?i:"bit")      { return T_BIT; }
(?i:"byte")     { return T_BYTE; }
(?i:"short")    { return T_SHORT; }
(?i:"long")     { return T_LONG; }
(?i:"int")      { return T_INT; }
(?i:"float")    { return T_FLOAT; }

(?i:"->")   { return T_ARR_RIGHT; }

"**"        { return T_EXP_OP; }
"<<"        { return T_SHL_OP; }
">>"        { return T_SHR_OP; }
">>>"       { return T_USHR_OP; }

"\""(.|{S})*"\""    {
    yylval.pChar = strdup(yytext);
    return T_STRING_LITERAL;
}

"'"."'"         {
    yylval.vChar = yytext[1];
    return T_CHAR_LITERAL;
}

{W}({W}|{N})*   {
    yylval.pChar = strdup(yytext);
    return T_NAME;
}

{N}+            {
    yylval.vInt = atoi(yytext);
    return T_NUMBER;
}

(?i:(0x|0b|0)?({hN}+|{hN}*\.{hN}+(e[+-]?{hN}+)?)u?([bsilfd]{N}*)?)    {
    yylval.pChar = strdup(yytext);
    return T_NUMBER_LITERAL;
}

.           { return * yytext; }

%%

int yywrap(void) {
    return 1;
}
