#ifndef ST_H
#define ST_H

#include "headers.h"
#include "ast.h"

class SymbolTable{
public:
	std::string name;
	std::string reg;
	AST::DataType dType;
	int scope;
	SymbolTable();
	SymbolTable(std::string, std::string, AST::DataType, int);
	~SymbolTable();
};

#endif