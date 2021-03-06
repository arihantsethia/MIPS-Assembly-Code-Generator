#ifndef AST_H
#define AST_H

#include "headers.h"

const static std::string opString[4]= {"*","/","+","-"};
const static std::string  condString[6] = {"<",">","=","<=",">=","!"};
const static std::string  dataString[4] = {"INT","BOOL","FLOAT","VOID"};
class AST {
public:
	enum NodeType{
		_EPSILON, _CONSTANT, _VARIABLE, _OPERATION, _CONDITION, _ASSIGN, _WHILE, _IF, _ELSE, _BRANCH, _STATEMENT, _FUNCTION, _ARGLIST, _ARG, _VAR, _FTYPE, _DTYPE, _IDLIST
	};
	enum OpType{
		MUL, DIV, ADD, SUB
	};
	enum CondType{
		LT, GT, EQ, LTE , GTE , NT
	};
	enum DataType{
		_INT, _BOOL, _FLOAT, _VOID
	};
	int childLength;
	void *data;
	NodeType nType;
	DataType dType;
	AST** childrens;
	std::string code;
	std::string reg;
	std::string value;
	std::string revValue;
	AST();
	AST(const AST&);
	AST(int);
	AST(NodeType T, void* _data);
	AST(NodeType T, AST** _childrens, int length);
	AST(NodeType T, void*, AST** _childrens, int length);
	~AST();
	
	AST* clone();
	void* clone(void*);
	AST& operator=(const AST& );
	void print();
	void addCode(std::string,std::string end="\n");
	std::string getCode();
	void setCode(std::string,std::string end="\n");
	std::string getValue();
	std::string getRevValue();
};

#endif