%{
#include <stdio.h>
#include <string.h>
#include "parser.tab.h"
%}

%%
[ \t\r]+                    { }

"if"                        { return IF; }
"else"                      { return ELSE; }
"while"                     { return WHILE; }
"for"                       { return FOR; }

"sqrt"                      { yylval.cvar[0] = 's'; return FUNC; }
"pow"                       { yylval.cvar[0] = 'p'; return FUNC; }
"log"                       { yylval.cvar[0] = 'l'; return FUNC; }
"exp"                       { yylval.cvar[0] = 'e'; return FUNC; }
"sin"                       { yylval.cvar[0] = 'i'; return FUNC; }
"cos"                       { yylval.cvar[0] = 'c'; return FUNC; }
"tan"                       { yylval.cvar[0] = 't'; return FUNC; }
"abs"                       { yylval.cvar[0] = 'a'; return FUNC; }

"=="                        { return EQ; }
"!="                        { return NE; }
"<="                        { return LE; }
">="                        { return GE; }
"&&"                        { return AND; }
"||"                        { return OR; }
"!"                         { return NOT; }

"+="                        { return PEQ; }
"-="                        { return MEQ; }
"*="                        { return TEQ; }
"/="                        { return DEQ; }
"%="                        { return MODEQ; }

\$[a-zA-Z_][a-zA-Z0-9_]*    { strcpy(yylval.cvar, yytext); return VAR; }
[0-9]+                      { strcpy(yylval.cvar, yytext); return NUM; }

[-+*/%<>=;(){},]            { return yytext[0]; }

\n                          { }

.                           { printf("Invalid character: %s\n", yytext); }

%%

int yywrap() { return 1; }