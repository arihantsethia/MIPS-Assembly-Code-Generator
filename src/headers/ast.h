#ifndef AST_H
#define AST_H

#include <iostream>
#include <string>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <list>
#include <iomanip>


const static std::string opString[4]= {"*","/","+","-"};
const static std::string  condString[6] = {"<",">","=","<=",">=","!"};

class AST {
public:
	enum NodeType{
		OPERATION, CONDITION, VARIABLE, ASSIGN, A_WHILE, A_IF, BRANCH, CONSTANT, UNKNOWN
	};
	enum OpType{
		MUL, DIV, ADD, SUB
	};
	enum CondType{
		LT, GT, EQ, LTE , GTE , A_NOT
	};

	int childLength;
	void *data;
	NodeType nType;
	AST** childrens;
	AST();
	AST(const AST&);
	AST(int);
	AST(NodeType T, void* _data);
	AST(NodeType T, AST** _childrens, int length);
	AST(NodeType T, void*, AST** _childrens, int length);
	~AST();
	void setNode();
	void setNode(int);
	void setNode(NodeType T, void* _data);
	void setNode(NodeType T, AST** _childrens, int length);
	void setNode(NodeType T, void*, AST** _childrens, int length);
	
	AST* clone();
	void* clone(void*);
	AST& operator=(const AST& );
	void print();
};

#endif