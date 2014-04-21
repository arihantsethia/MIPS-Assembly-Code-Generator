#ifndef GRAMMAR_H
#define GRAMMAR_H

#include "headers.h"
#include "ast.h"
#include "symbolTable.h"

extern char* yytext ;
extern int yylineno ;
extern int yylex(void);	

int yyerror(char *);
std::string getRegister();
std::string getLabel();
std::string getLabel(int);
std::string oppSymbol(std::string);
AST::DataType getDataType(std::string, int);
std::string getIdRegister(std::string, int);

static int lcount=0,rcount=0;
static int lastLabel =0;
static int scope=0;
static std::vector< std::map<std::string, SymbolTable> > symbolTable(100);

#endif