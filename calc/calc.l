%option nounistd

%{
#include <string>
#include <iostream>
#ifdef _WIN32
#include <io.h>
#else
#include <unistd.h>
#endif
#include "parser.hpp"
extern YYSTYPE calclval;
#define SAVE_TOKEN calclval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (calclval.token = t)
extern "C" int yywrap() { return 1; }

// Disable warnings
#pragma warning(disable: 4018)
#pragma warning(disable: 4996)
%}

%%

[ \t\n]					{ }
[0-9]+					{ SAVE_TOKEN; return TINTEGER; }

"+"						{ return TOKEN(TPLUS); }
"-"						{ return TOKEN(TMINUS); }
"*"						{ return TOKEN(TMULT); }
"/"						{ return TOKEN(TDIV); }
"("						{ return TOKEN(TLPAREN); }
")"						{ return TOKEN(TRPAREN); }

%{
/* Do not add any of your own tokens below this line!!!! */
%}

.						{ std::cout << "ERROR: Unknown token '" << yytext << std::endl; yyterminate(); }

%%
