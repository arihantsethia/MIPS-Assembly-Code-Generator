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
	static int lcount=0,rcount=0;

%}
	%union
	{
		class AST* node ;
		int number ;
		char* name ;
	}

	%type <node> EXPR RVALUE MAG TERM FACTOR COMPARE FUNCTION ARGLIST ARG FTYPE STMT DECLARATION DTYPE IDLIST WHILESTMT IFSTMT ELSEPART CMPDSTMT STMTLIST

	%token <number>		NUMBER
	%token <name>	ID
	%start FUNCTION
	
	%token AUTO   BREAK   CASE   CHAR   CONST   CONTINUE   DEFAULT   DO   DOUBLE   ELSE   ENUM   EXTERN   FLOAT   FOR   GOTO   IF   INT   LONG   REGISTER   RETURN   SHORT   SIGNED   SIZEOF   STATIC   STRUCT   SWITCH   TYPEDEF   UNION   UNSIGNED   VOID   VOLATILE   WHILE   PLUS   MINUS   TIMES   DIVIDE   MODULO   EQUALS   BITAND   BITOR   BITXOR   NOT   LESS   GREATER   HASH   DOLLAR   ATRATE   LS   RS   LB   RB   LP   RP   QMARK   COLON   DOT   SEMI   COMMA   PLUSEQ   MINUSEQ   TIMESEQ   DIVEQ   MODULOEQ   EMPEQ   AND   OR   REQUALS   NOTEQUAL   LESSEQ   GREATEREQ   INCR   DECR   LSHIFT   RSHIFT   OREQ   XOREQ   PTRREF   LSHIFTEQ   RSHIFTEQ REAL INTPTR 

	%nonassoc LOWER_THAN_ELSE
	%nonassoc ELSE

%%
	FUNCTION:	FTYPE ID LP ARGLIST RP CMPDSTMT
			{
				std::string funcName($2);
				AST **p = new AST*[4] ;
				p[0] = $1 ;
				p[1] = new AST(AST::VARIABLE,&funcName) ;
				p[2] = $4 ;
				p[3] = $6 ;
				$$ = new AST(AST::FUNC,p,4) ;
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
				$$ = new AST(AST::ARG_LIST,p,2) ;
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
				p[1] = new AST(AST::VARIABLE,&s) ;
				$$ = new AST(AST::ARGD,p,2) ;
			}
	;
	FTYPE:	INT 
			{
				AST::DataType x = AST::_INT;
				$$ = new AST(AST::F_TYPE,&x);
			}
			| VOID 
			{
				AST::DataType x = AST::_VOID ;
				$$ = new AST(AST::F_TYPE,&x);
			}
			| INTPTR
			{
				AST::DataType x = AST::_INTPTR ;
				$$ = new AST(AST::F_TYPE,&x);
			}
	;
	STMT:		WHILESTMT
			{
				$$ = $1 ;
			}
			|	EXPR SEMI
			{
				$$ = $1 ;
			}
			|	IFSTMT
			{
				$$ = $1 ;
			}
			|	CMPDSTMT
			{
				$$ = $1 ;
			}
			|	DECLARATION
			{
				$$ = $1 ;
			}
			|	SEMI
			{
				$$ = new AST(0) ;
			}
	;
	DECLARATION:	DTYPE IDLIST SEMI
			{
				AST **p = new AST*[2] ;
				p[0] = $1 ;
				p[1] = $2 ;
				$$ = new AST(AST::VARD,p,2) ;
			}
	;
	DTYPE:		INT
			{
				AST::DataType x = AST::_INT;
				$$ = new AST(AST::D_TYPE,&x);
			}
			|	INTPTR
			{
				AST::DataType x = AST::_INTPTR;
				$$ = new AST(AST::D_TYPE,&x);
			}
	;
	IDLIST:		ID
			{
				std::string s($1);
				$$ = new AST(AST::VARIABLE,&s) ;
			}
			|	ID LS NUMBER RS
			{
				AST **p = new AST*[2] ;
				std::string s($1);
				p[0] = new AST(AST::VARIABLE,&s) ;
				p[1] = new AST(AST::CONSTANT,&$3) ;
				$$ = new AST(AST::VARIABLE,p,2) ;

			}
			|	ID COMMA IDLIST
			{
				AST **p = new AST*[2] ;
				std::string s($1);
				p[0] = new AST(AST::VARIABLE,&s) ;
				p[1] = $3 ;
				$$ = new AST(AST::ID_LIST,p,2) ;
			}
			|	ID LS NUMBER RS COMMA IDLIST
			{
				AST **p = new AST*[3] ;
				std::string s($1);
				p[0] = new AST(AST::VARIABLE,&s) ;
				p[1] = new AST(AST::CONSTANT,&$3) ;
				p[2] = $6 ;
				$$ = new AST(AST::ID_LIST,p,3) ;

			}
	;
	WHILESTMT:	WHILE LP EXPR RP STMT
			{
				AST **p = new AST*[2] ;
				p[0] = $3 ;
				p[1] = $5 ;
				$$ = new AST(AST::BRANCH,p,2) ;
			}
	;
	IFSTMT:		IF LP EXPR RP STMT ELSEPART
			{
				AST **p = new AST*[3] ;
				p[0] = $3 ;
				p[1] = $5 ;
				p[2] = $6 ;
				$$ = new AST(AST::BRANCH,p,3) ;
			}
	;
	ELSEPART:	ELSE STMT
			{
				AST **p = new AST*[1] ;
				p[0] = $2 ;
				$$ = new AST(AST::A_ELSE,p,1) ;
			}
			|	%prec LOWER_THAN_ELSE
			{
				$$ = new AST(0) ;
			} 
	;
	CMPDSTMT:	LB STMTLIST RB
			{
					$$ = $2 ;
			}
	;
	STMTLIST:	STMT STMTLIST 
			{
				AST **p = new AST*[2] ;
				p[0] = $1 ;
				p[1] = $2 ;
				$$ = new AST(AST::STATEMENT,p,2);
			}
			|
			{
				$$ = new AST(0) ;
			}
	;
	EXPR:	ID EQUALS EXPR
			{
				std::string id($1);
				AST **p = new AST*[2];
				p[0] = new AST(AST::VARIABLE,&id);
				p[1] = $3; 
				$$ = new AST(AST::ASSIGN,p,2);
			}
			|RVALUE{
				$$ = $1 ;
			}
	;
	RVALUE:	RVALUE COMPARE MAG
			{
				$2->childLength=2;
				$2->childrens = new AST*[2];
				$2->childrens[0] = $1;
				$2->childrens[1] = $3;
				$$ = $2;
			}
			|MAG
			{				
				$$ = $1;
			}		
	;
	COMPARE:REQUALS	
			{
				AST::CondType x = AST::EQ ;
				$$ = new AST(AST::CONDITION,&x) ;		
			}
			|LESS
			{
				AST::CondType x = AST::LT ;
				$$ = new AST(AST::CONDITION,&x) ;
			}
			|GREATER
			{
				AST::CondType x = AST::GT ;
				$$ = new AST(AST::CONDITION,&x) ;
			}
			|LESSEQ
			{
				AST::CondType x = AST::LTE ;
				$$ = new AST(AST::CONDITION,&x) ;
			}
			|GREATEREQ{
				AST::CondType x = AST::GTE ;
				$$ = new AST(AST::CONDITION,&x) ;
			}
			|NOTEQUAL
			{
				AST::CondType x = AST::A_NOT ;
				$$ = new AST(AST::CONDITION,&x) ;
			}
	;
	MAG:	MAG PLUS TERM 
			{
				AST **n1 = new AST*[2];
				n1[0] = ($1);
				n1[1] = ($3);
				AST::OpType x = AST::ADD;
				$$ = new AST(AST::OPERATION,&x,n1,2) ;	
			}			
			|MAG MINUS TERM
			{
				AST **n1 = new AST*[2];
				n1[0] = $1;
				n1[1] = $3;
				AST::OpType x = AST::SUB;
				$$ = new AST(AST::OPERATION,&x,n1,2) ;	
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
				$$ = new AST(AST::OPERATION,&x,n1,2) ;
			}			
			|TERM DIVIDE FACTOR
			{
				AST **n1 = new AST*[2];
				n1[0] = $1;
				n1[1] = $3;
				AST::OpType x = AST::DIV;
				$$ = new AST(AST::OPERATION,&x,n1,2) ;	
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
			|MINUS FACTOR
			{
				AST::OpType x = AST::SUB;
				$$ = new AST(AST::OPERATION,&x,&$2,1) ;
			}
			|PLUS FACTOR 
			{
				AST **p = new AST*[1];
				p[0] = $2;
				AST::OpType x = AST::ADD;
				$$ = new AST(AST::OPERATION,&x,p,1) ;
			}
			|ID 
			{
				std::string s($1);
				$$ = new AST(AST::VARIABLE,&s) ;
			}
			|NUMBER 
			{
				$$ = new AST(AST::CONSTANT,&$1) ;
			}
	;

%%
std::string getRegister(){
	std::stringstream reg;
	reg<<"L"<<rcount++;
	return 	reg.str();
}

std::string getLabel(){
	std::stringstream label;
	label<<"L"<<lcount++;
	return 	label.str();
}

int yyerror(char *s){
	fprintf(stderr, "%s %s %d\n", s , yytext , yylineno );
	return 0;
}
	
int main(void)	{
	yyparse();
	return 0;
}