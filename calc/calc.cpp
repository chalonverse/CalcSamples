// calc.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "parser.hpp"
#include <stack>
#include <string>

std::stack<int> g_Stack;

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

	if (g_Stack.size() == 1)
	{
		std::cout << "Result = " << g_Stack.top() << std::endl;
	}
	
	// Close the file stream
	fclose(calcin);
	return 0;
}

void calcerror(const char* s)
{
	std::cout << s << std::endl;
}

void PushNum(std::string& val)
{
	int i = std::atoi(val.c_str());
	g_Stack.push(i);
}

void Compute(int op)
{
	int rhs = g_Stack.top();
	g_Stack.pop();
	int lhs = g_Stack.top();
	g_Stack.pop();

	int result = 0;
	switch (op)
	{
	case TPLUS:
		result = lhs + rhs;
		break;
	case TMINUS:
		result = lhs - rhs;
		break;
	case TMULT:
		result = lhs * rhs;
		break;
	case TDIV:
		result = lhs / rhs;
		break;
	default:
		break;
	}

	g_Stack.push(result);
}
