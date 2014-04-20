%{
	#include <stdio.h>
	#include <string.h>
	#include <string>
	#include <sstream>
	#include "headers/ast.h"
	extern char* yytext ;
	extern int yylineno ;
	extern int yylex(void);	
	int yyerror(char *);
	std::string getRegister();
	std::string getLabel();
	std::string getLabel(int);
	std::string opposite(std::string);
	static int lcount=0,rcount=0;
	static int lastLabel =0;
	std::string code ="";
%}
	%union
	{
		class AST* node ;
		int number ;
		char* name ;
	}

	%type <node> EXPR MAG TERM FACTOR COMPARE FUNCTION ARGLIST ARG FTYPE STMT DECLARATION DTYPE IDLIST WHILESTMT IFSTMT ELSEPART CMPDSTMT STMTLIST ASSIGN

	%token <number>		NUMBER
	%token <name>	ID
	%start STMT
	
	%token AUTO   BREAK   CASE   CHAR   CONST   CONTINUE   DEFAULT   DO   DOUBLE   ELSE   ENUM   EXTERN   FLOAT   FOR   GOTO   IF   INT   LONG   REGISTER   RETURN   SHORT   SIGNED   SIZEOF   STATIC   STRUCT   SWITCH   TYPEDEF   UNION   UNSIGNED   VOID   VOLATILE   WHILE   PLUS   MINUS   TIMES   DIVIDE   MODULO   EQUALS   BITAND   BITOR   BITXOR   NOT   LESS   GREATER   HASH   DOLLAR   ATRATE   LS   RS   LB   RB   LP   RP   QMARK   COLON   DOT   SEMI   COMMA   PLUSEQ   MINUSEQ   TIMESEQ   DIVEQ   MODULOEQ   EMPEQ   AND   OR   REQUALS   NOTEQUAL   LESSEQ   GREATEREQ   INCR   DECR   LSHIFT   RSHIFT   OREQ   XOREQ   PTRREF   LSHIFTEQ   RSHIFTEQ REAL INTPTR 

	%nonassoc LOWER_THAN_ELSE
	%nonassoc ELSE

%%
	FUNCTION:	FTYPE ID LP ARGLIST RP CMPDSTMT
			{
				std::string funcName($2);
				AST **p = new AST*[4] ;
				p[0] = $1 ;
				p[1] = new AST(AST::_VARIABLE,&funcName) ;
				p[2] = $4 ;
				p[3] = $6 ;
				$$ = new AST(AST::_FUNCTION,p,4) ;
				$$->print() ;
			}
	;
	ARGLIST:	ARG
			{
				$$ = $1 ;
			}
			|	ARG COMMA ARGLIST
			{
				AST **p = new AST*[2] ;
				p[0] = $1 ;
				p[1] = $3 ;
				$$ = new AST(AST::_ARGLIST,p,2) ;
			}
			|
			{
				$$ = new AST(0) ;
			}
	;
	ARG:	DTYPE ID
			{
				AST **p = new AST*[2] ;
				p[0] = $1 ;
				std::string s($2);
				p[1] = new AST(AST::_VARIABLE,&s) ;
				$$ = new AST(AST::_ARG,p,2) ;
			}
	;
	FTYPE:	INT 
			{
				AST::DataType x = AST::_INT;
				$$ = new AST(AST::_FTYPE,&x);
			}
			| VOID 
			{
				AST::DataType x = AST::_VOID ;
				$$ = new AST(AST::_FTYPE,&x);
			}
			| INTPTR
			{
				AST::DataType x = AST::_INTPTR ;
				$$ = new AST(AST::_FTYPE,&x);
			}
	;
	STMT:	WHILESTMT
			{
				$$ = $1 ;				
				std::cout<<$$->getCode()<<std::endl;
			}
			|ASSIGN SEMI
			{
				$$ = $1 ;
			}
			|IFSTMT
			{
				$$ = $1 ;
			}
			|CMPDSTMT
			{
				$$ = $1;
			}
			|DECLARATION
			{
				$$ = $1 ;
			}
			|SEMI
			{
				$$ = new AST(0) ;
			}
	;
	DECLARATION: DTYPE IDLIST SEMI
			{
				AST **p = new AST*[2] ;
				p[0] = $1 ;
				p[1] = $2 ;
				$$ = new AST(AST::_VAR,p,2) ;
			}
	;
	DTYPE:	INT
			{
				AST::DataType x = AST::_INT;
				$$ = new AST(AST::_DTYPE,&x);
			}
			|INTPTR
			{
				AST::DataType x = AST::_INTPTR;
				$$ = new AST(AST::_DTYPE,&x);
			}
	;
	IDLIST:	ID
			{
				std::string s($1);
				$$ = new AST(AST::_VARIABLE,&s) ;
			}
			|ID LS NUMBER RS
			{
				AST **p = new AST*[2] ;
				std::string s($1);
				p[0] = new AST(AST::_VARIABLE,&s) ;
				p[1] = new AST(AST::_CONSTANT,&$3) ;
				$$ = new AST(AST::_VARIABLE,p,2) ;
			}
			|ID COMMA IDLIST
			{
				AST **p = new AST*[2] ;
				std::string s($1);
				p[0] = new AST(AST::_VARIABLE,&s) ;
				p[1] = $3 ;
				$$ = new AST(AST::_IDLIST,p,2) ;
			}
			|ID LS NUMBER RS COMMA IDLIST
			{
				AST **p = new AST*[3] ;
				std::string s($1);
				p[0] = new AST(AST::_VARIABLE,&s) ;
				p[1] = new AST(AST::_CONSTANT,&$3) ;
				p[2] = $6 ;
				$$ = new AST(AST::_IDLIST,p,3) ;
			}
	;
	WHILESTMT:	WHILE LP EXPR RP STMT
			{
				AST **p = new AST*[2] ;
				p[0] = $3 ;
				p[1] = $5 ;
				$$ = new AST(AST::_BRANCH,p,2) ;
				$$->setCode($3->getCode());
				$$->label = getLabel();
				$$->addCode($$->label+": if "+$3->getRevValue()+" goto "+getLabel());
				$$->addCode($5->getCode(),"");
				$$->addCode("goto "+$$->label);
				$$->addCode(getLabel(lcount)+": ","");
			}
	;
	IFSTMT:	IF LP EXPR RP STMT ELSEPART
			{
				AST **p = new AST*[3] ;
				p[0] = $3 ;
				p[1] = $5 ;
				p[2] = $6 ;
				$$ = new AST(AST::_BRANCH,p,3) ;
				$$->setCode($3->getCode());
				$$->addCode("if "+$3->getRevValue()+" goto "+getLabel());
				$$->addCode($5->getCode(),"");
				$$->addCode(getLabel(lcount)+": "+$6->getCode());
			}
	;
	ELSEPART:ELSE STMT
			{
				AST **p = new AST*[1] ;
				p[0] = $2 ;
				$$ = new AST(AST::_ELSE,p,1) ;
				$$->addCode($2->getCode());
			}
			|%prec LOWER_THAN_ELSE
			{
				$$ = new AST(0) ;
			} 
	;
	CMPDSTMT:	LB STMTLIST RB
			{
					$$ = $2 ;
			}
	;
	STMTLIST:STMT STMTLIST 
			{
				AST **p = new AST*[2] ;
				p[0] = $1 ;
				p[1] = $2 ;
				$$ = new AST(AST::_STATEMENT,p,2);
				$$->setCode($1->getCode()+$2->getCode(),"");
			}
			|
			{
				$$ = new AST(0) ;
			}
	;
	ASSIGN:	ID EQUALS EXPR
			{
				std::string id($1);
				AST **p = new AST*[2];
				p[0] = new AST(AST::_VARIABLE,&id);
				p[1] = $3;
				$$ = new AST(AST::_ASSIGN,p,2);
				$$->setCode($3->getCode(),"");
				$$->addCode(id+" := "+$3->getValue());
			}
			;
	EXPR:	EXPR COMPARE MAG
			{
				std::string condition($2->getCode());
				$2->childLength=2;
				$2->childrens = new AST*[2];
				$2->childrens[0] = $1;
				$2->childrens[1] = $3;
				$$ = $2;
				$$->setCode($1->getCode(),"");
				$$->setCode($3->getCode(),"");
				$$->value = $1->getValue()+condition+$3->getValue()	;
				$$->revValue = $1->getValue()+opposite(condition)+$3->getValue();	
			}
			|MAG
			{				
				$$ = $1;
			}		
	;
	COMPARE:REQUALS	
			{
				AST::CondType x = AST::EQ ;
				$$ = new AST(AST::_CONDITION,&x) ;
				$$->setCode(" == ","");
			}
			|LESS
			{
				AST::CondType x = AST::LT ;
				$$ = new AST(AST::_CONDITION,&x) ;
				$$->setCode(" < ","");
			}
			|GREATER
			{
				AST::CondType x = AST::GT ;
				$$ = new AST(AST::_CONDITION,&x) ;
				$$->setCode(" >= ","");
			}
			|LESSEQ
			{
				AST::CondType x = AST::LTE ;
				$$ = new AST(AST::_CONDITION,&x) ;
				$$->setCode(" <= ","");
			}
			|GREATEREQ{
				AST::CondType x = AST::GTE ;
				$$ = new AST(AST::_CONDITION,&x) ;
				$$->setCode(" >= ","");
			}
			|NOTEQUAL
			{
				AST::CondType x = AST::NT ;
				$$ = new AST(AST::_CONDITION,&x) ;
				$$->setCode(" != ","");
			}
	;
	MAG:	MAG PLUS TERM 
			{
				AST **n1 = new AST*[2];
				n1[0] = ($1);
				n1[1] = ($3);
				AST::OpType x = AST::ADD;
				$$ = new AST(AST::_OPERATION,&x,n1,2) ;	
				$$->reg = getRegister();
				$$->setCode($1->getCode(),"");
				$$->addCode($3->getCode(),"");
				$$->addCode($$->getValue()+" := "+$1->getValue()+" + "+$3->getValue());	
			}			
			|MAG MINUS TERM
			{
				AST **n1 = new AST*[2];
				n1[0] = $1;
				n1[1] = $3;
				AST::OpType x = AST::SUB;
				$$ = new AST(AST::_OPERATION,&x,n1,2) ;
				$$->reg = getRegister();
				$$->setCode($1->getCode(),"");
				$$->addCode($3->getCode(),"");
				$$->addCode($$->getValue()+" := "+$1->getValue()+" - "+$3->getValue());	
			}			
			|TERM 
			{
				$$ = $1 ;	
			}			
	;
	TERM:	TERM TIMES FACTOR
			{
				AST **n1 = new AST*[2];
				n1[0] = $1;
				n1[1] = $3;
				AST::OpType x = AST::MUL;
				$$ = new AST(AST::_OPERATION,&x,n1,2) ;
				$$->reg = getRegister();
				$$->setCode($1->getCode(),"");
				$$->addCode($3->getCode(),"");
				$$->addCode($$->getValue()+" := "+$1->getValue()+" * "+$3->getValue());
			}			
			|TERM DIVIDE FACTOR
			{
				AST **n1 = new AST*[2];
				n1[0] = $1;
				n1[1] = $3;
				AST::OpType x = AST::DIV;
				$$ = new AST(AST::_OPERATION,&x,n1,2) ;	
				$$->reg = getRegister();
				$$->setCode($1->getCode(),"");
				$$->addCode($3->getCode(),"");
				$$->addCode($$->getValue()+" := "+$1->getValue()+" / "+$3->getValue());
			}			
			|FACTOR
			{
				$$ = $1 ;
			}
	;
	FACTOR:	LP EXPR RP
			{
				$$  = $2 ;
			}
			|ID 
			{
				std::string s($1);
				$$ = new AST(AST::_VARIABLE,&s) ;
				$$->reg = getRegister();
				code = $$->getValue() + " := "+$$->getValue();
				$$->setCode(code);
			}
			|NUMBER 
			{
				$$ = new AST(AST::_CONSTANT,&$1);
			}
	;

%%
std::string getRegister(){
	std::stringstream reg;
	reg<<"R"<<rcount++;
	return 	reg.str();
}

std::string getLabel(){
	std::stringstream label;
	label<<"L"<<++lcount<<"";
	return 	label.str();
}

std::string getLabel(int lastLabel){
	std::stringstream label;
	label<<"L"<<lastLabel<<"";
	return 	label.str();
}

std::string opposite(std::string str){
	if(str==" == ")
		return " != ";
	if(str==" >= ")
		return " < ";
	if(str==" <= ")
		return " > ";
	if(str==" > ")
		return " <= ";
	if(str==" < ")
		return " >= ";
	if(str==" != ")
		return " == ";
}

int yyerror(char *s){
	fprintf(stderr, "%s %s %d\n", s , yytext , yylineno );
	return 0;
}
	
int main(void)	{
	yyparse();
	return 0;
}