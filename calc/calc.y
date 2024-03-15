%{
#include <iostream>
#include <string>
extern int yylex();
extern void yyerror(const char* s);
extern void PushNum(std::string& val);
extern void Compute(int op);

// Disable the warnings that Bison creates
#pragma warning(disable: 4065)
%}

/* This union describes all the different types we may want to store for a rule/token */
%union {
	std::string* string;
	int token;
}

/* Terminal symbols */
%token <string> TINTEGER
%token <token> TPLUS TMINUS TMULT TDIV TLPAREN TRPAREN
 
/* Expressions */
%type <token> expr

%left TPLUS TMINUS
%left TMULT TDIV

%%

expr		: expr TPLUS expr { std::cout << "+" << std::endl; Compute($2); }
			| expr TMINUS expr { std::cout << "-" << std::endl; Compute($2); }
			| expr TMULT expr { std::cout << "*" << std::endl; Compute($2); }
			| expr TDIV expr { std::cout << "/" << std::endl; Compute($2); }
			| TLPAREN expr TRPAREN { }
			| TINTEGER { std::cout << *($1) << std::endl; PushNum(*($1)); }
;

%%
