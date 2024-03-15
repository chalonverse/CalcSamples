%{
#include <iostream>
#include <string>
#include "node.h"
extern int yylex();
extern void yyerror(const char* s);
extern void PushNum(std::string& val);
extern void Compute(int op);

Node* g_Result = nullptr;

// Disable the warnings that Bison creates
#pragma warning(disable: 4065)
%}

/* This union describes all the different types we may want to store for a rule/token */
%union {
	Node* node;
	std::string* string;
	int token;
}

/* Terminal symbols */
%token <string> TINTEGER
%token <token> TPLUS TMINUS TMULT TDIV TLPAREN TRPAREN TRESULT TEQUALS
 
/* Expressions */
%type <node> expr

%left TPLUS TMINUS
%left TMULT TDIV

%%

result		: TRESULT TEQUALS expr { g_Result = $3; }
;

expr		: expr TPLUS expr { $$ = new NAdd($1, $3); }
			| expr TMINUS expr { $$ = new NSub($1, $3); }
			| expr TMULT expr { $$ = new NMult($1, $3); }
			| expr TDIV expr { $$ = new NDiv($1, $3); }
			| TLPAREN expr TRPAREN { $$ = $2; }
			| TINTEGER { $$ = new NInteger(*($1)); }
;

%%
