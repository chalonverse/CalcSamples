// calc.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "node.h"
#include "parser.hpp"
#include <stack>
#include <string>

extern Node* g_Result;

extern int calcparse();
extern FILE* calcin;

int main(int argc, char* argv[])
{
	// Read input from first command line parameter
	calcin = fopen(argv[1], "r");
	if (calcin == nullptr)
	{
		std::cout << "File not found: " << argv[1] << std::endl;
		return 0;
	}
	calcparse();
	if (g_Result != nullptr)
	{
		std::cout << "Result = ";
		g_Result->debugOut();
		std::cout << std::endl;
	}
	
	// Close the file stream
	fclose(calcin);
	
	return 0;
}

void calcerror(const char* s)
{
	std::cout << s << std::endl;
}
