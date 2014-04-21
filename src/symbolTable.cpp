#include "headers/symbolTable.h"

SymbolTable::SymbolTable(){

}

SymbolTable::SymbolTable(std::string _name, std::string _reg, AST::DataType _dType, int _scope){
	name = _name;
	reg = _reg;
	dType = _dType;
	scope = _scope;
}

SymbolTable::~SymbolTable(){

}
