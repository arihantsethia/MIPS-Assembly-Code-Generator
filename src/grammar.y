%{
	#include "headers/grammar.h"
	AST **node;
%}
	%union
	{
		class AST* vNode;
		int vInt;
		float vFloat;
		bool vBool;
		char* vId;
	}

	%type <vNode>	EXPR	MAG	TERM	FACTOR	COMPARE	FUNCTION	ARGLIST	ARG	FTYPE	STMT	DECLARATION	DTYPE	IDLIST	WHILESTMT	IFSTMT	ELSEPART	CMPDSTMT	STMTLIST	ASSIGN

	%token <vInt>	NUMBER
	%token <vId>	ID
	%token <vBool>	BOOLEAN
	%token <vFloat> DECIMAL
	%start STMT
	
	%token	AUTO	BOOL	CHAR	ELSE	FLOAT	IF	INT	LONG	RETURN	SIGNED	WHILE	PLUS	MINUS	TIMES	DIVIDE	EQUALS	NOT	LESS	GREATER	LS	RS	LB	RB	LP	RP	COLON	DOT	SEMI	COMMA	AND	OR	REQUALS	NOTEQUAL	LESSEQ	GREATEREQ

	%nonassoc LOWER_THAN_ELSE
	%nonassoc ELSE

%%
FUNCTION: FTYPE ID LP ARGLIST RP CMPDSTMT {
			std::string id($2);
			node = new AST*[4];
			node[0] = $1;
			node[1] = new AST(AST::_VARIABLE,&id);
			node[2] = $4;
			node[3] = $6;
			$$ = new AST(AST::_FUNCTION,node,4);
		}
		;
ARGLIST: ARG{
			$$ = $1;
		}
		|ARG COMMA ARGLIST {
			node = new AST*[2];
			node[0] = $1;
			node[1] = $3;
			$$ = new AST(AST::_ARGLIST,node,2);
		}
		| {
			$$ = new AST(0);
		}
		;
ARG: DTYPE ID {
		std::string id($2);
		node = new AST*[2];
		node[0] = $1;
		node = new AST(AST::_VARIABLE,&id);
		$$ = new AST(AST::_ARG,node,2);
	}
	;
FTYPE: INT {
		AST::DataType x = AST::_INT;
		$$ = new AST(AST::_FTYPE,&x);
		$$->dType = AST::_INT;
	}
	| FLOAT {
		AST::DataType x = AST::_FLOAT;
		$$ = new AST(AST::_FTYPE,&x);
		$$->dType = AST::_FLOAT;
	}
	| BOOL {
		AST::DataType x = AST::_BOOL;
		$$ = new AST(AST::_FTYPE,&x);
		$$->dType = AST::_BOOL;
	}
	;
STMT: WHILESTMT {
		$$ = $1;
	}
	|ASSIGN SEMI {
		$$ = $1;
	}
	|IFSTMT {
		$$ = $1;
	}
	|CMPDSTMT {
		$$ = $1;
	}
	|DECLARATION {
		$$ = $1;
	}
	|SEMI {
		$$ = new AST(0);
	}
	;
DECLARATION: DTYPE IDLIST SEMI {
				node = new AST*[2];
				node[0] = $1;
				node[1] = $2;
				$$ = new AST(AST::_VAR,node,2);
			}
			;
DTYPE: INT {
			AST::DataType x = AST::_INT;
			$$ = new AST(AST::_DTYPE,&x);
			$$->dType = AST::_INT;
		}
		| FLOAT {
			AST::DataType x = AST::_FLOAT;
			$$ = new AST(AST::_FTYPE,&x);
			$$->dType = AST::_FLOAT;
		}
		| BOOL {
			AST::DataType x = AST::_BOOL;
			$$ = new AST(AST::_FTYPE,&x);
			$$->dType = AST::_BOOL;
		}
		;
IDLIST:	ID {
			std::string id($1);
			if(getDataType(id,scope)!=AST::_VOID){
				return 1;
			}
			$$ = new AST(AST::_VARIABLE,&id);
		}
		|ID LS NUMBER RS {
			std::string id($1);
			node = new AST*[2];
			node[0] = new AST(AST::_VARIABLE,&id);
			node[1] = new AST(AST::_CONSTANT,&$3);
			$$ = new AST(AST::_VARIABLE,node,2);
		}
		|ID COMMA IDLIST {
			std::string id($1);
			if((getDataType(id,scope) != $3->dType) || (getDataType(id,scope) != AST::_VOID)){
				return 1;
			}
			node = new AST*[2];
			node[0] = new AST(AST::_VARIABLE,&id);
			node[1] = $3;
			$$ = new AST(AST::_IDLIST,node,2);
		}
		|ID LS NUMBER RS COMMA IDLIST {
			std::string id($1);
			node = new AST*[3];
			node[0] = new AST(AST::_VARIABLE,&id);
			node[1] = new AST(AST::_CONSTANT,&$3);
			node[2] = $6;
			$$ = new AST(AST::_IDLIST,node,3);
		}
		;
WHILESTMT: WHILE LP EXPR RP STMT {
				if($3->dType != AST::_BOOL || $5->dType != AST::_VOID){
					return 1;
				}
				node = new AST*[2];
				node[0] = $3;
				node[1] = $5;
				std::string label = getLabel();
				$$ = new AST(AST::_BRANCH,node,2);
				$$->setCode($3->getCode());
				$$->addCode(label+": if "+$3->getRevValue()+" goto "+getLabel());
				$$->addCode($5->getCode(),"");
				$$->addCode("goto "+label);
				$$->addCode(getLabel(lcount)+": ","");
			}
			;
IFSTMT:	IF LP EXPR RP STMT ELSEPART {
			if($3->dType != AST::_BOOL || $5->dType != AST::_VOID || $6->dType != AST::_VOID){
				return 1;
			}
			node = new AST*[3];
			node[0] = $3;
			node[1] = $5;
			node[2] = $6;
			$$ = new AST(AST::_BRANCH,node,3);
			$$->setCode($3->getCode());
			$$->addCode("if "+$3->getRevValue()+" goto "+getLabel());
			$$->addCode($5->getCode(),"");
			$$->addCode(getLabel(lcount)+": "+$6->getCode());
			$$->dType = AST::_VOID;
		}
		;
ELSEPART:ELSE STMT {
			node = new AST*[1];
			node[0] = $2;
			$$ = new AST(AST::_ELSE,node,1);
			$$->addCode($2->getCode());
			$$->dType = AST::_VOID;
		}
		|%prec LOWER_THAN_ELSE {
			$$ = new AST(0);
			$$->dType = AST::_VOID;
		} 
		;
CMPDSTMT: LB STMTLIST RB {
			$$ = $2;
			$$->dType = AST::_VOID;
		}
		;
STMTLIST: STMT STMTLIST {
			if($1->dType != AST::_VOID || $2->dType != AST::_VOID){
				return 1;
			}
			node = new AST*[2];
			node[0] = $1;
			node[1] = $2;
			$$ = new AST(AST::_STATEMENT,node,2);
			$$->setCode($1->getCode()+$2->getCode(),"");
			$$->dType = AST::_VOID;
		}
		| {
			$$ = new AST(0);
		}
		;
ASSIGN:	ID EQUALS EXPR {
			std::string id($1);
			if(getDataType(id,scope) == AST::_VOID || getDataType(id,scope) != $3->dType){
				return 1;
			}
			node = new AST*[2];
			node[0] = new AST(AST::_VARIABLE,&id);
			node[1] = $3;
			$$ = new AST(AST::_ASSIGN,node,2);
			$$->setCode($3->getCode(),"");
			$$->addCode(id+" := "+$3->getValue());
			$$->dType =AST::_VOID;
		}
		;
EXPR: EXPR COMPARE MAG {
		if( ($1->dType == $3->dType) && ($1->dType != AST::_VOID) ){
			return 1;
		}
		$$ = $2;
		$$->childLength=2;
		$$->childrens = new AST*[2];
		$$->childrens[0] = $1;
		$$->childrens[1] = $3;
		$$->setCode($1->getCode(),"");
		$$->setCode($3->getCode(),"");
		$$->value = $1->getValue()+$2->getCode()+$3->getValue()	;
		$$->revValue = $1->getValue()+oppSymbol($2->getCode())+$3->getValue();
		$$->dType = AST::_BOOL;
	}
	|MAG {
		$$ = $1;
	}
	|BOOLEAN{
		$$ = new AST(AST::_CONSTANT,&$1);
		SS->dType = AST::_BOOL;
	}
	;
COMPARE:REQUALS	{
		AST::CondType x = AST::EQ;
		$$ = new AST(AST::_CONDITION,&x);
		$$->setCode(" == ","");
	}
	|LESS {
		AST::CondType x = AST::LT;
		$$ = new AST(AST::_CONDITION,&x);
		$$->setCode(" < ","");
	}
	|GREATER {
		AST::CondType x = AST::GT;
		$$ = new AST(AST::_CONDITION,&x);
		$$->setCode(" >= ","");
	}
	|LESSEQ {
		AST::CondType x = AST::LTE;
		$$ = new AST(AST::_CONDITION,&x);
		$$->setCode(" <= ","");
	}
	|GREATEREQ {
		AST::CondType x = AST::GTE;
		$$ = new AST(AST::_CONDITION,&x);
		$$->setCode(" >= ","");
	}
	|NOTEQUAL {
		AST::CondType x = AST::NT;
		$$ = new AST(AST::_CONDITION,&x);
		$$->setCode(" != ","");
	}
	;
MAG: MAG PLUS TERM {
		if( ($1->dType != $3->dType) && ($1->dType != AST::_VOID) ){
			return 1;
		}
		node = new AST*[2];
		node[0] = ($1);
		node[1] = ($3);
		AST::OpType x = AST::ADD;
		$$ = new AST(AST::_OPERATION,&x,node,2);
		$$->reg = getRegister();
		$$->setCode($1->getCode(),"");
		$$->addCode($3->getCode(),"");
		$$->addCode($$->getValue()+" := "+$1->getValue()+" + "+$3->getValue());	
	}
	|MAG MINUS TERM {
		if( ($1->dType != $3->dType) && ($1->dType != AST::_VOID) ){
			return 1;
		}
		node = new AST*[2];
		node[0] = $1;
		node[1] = $3;
		AST::OpType x = AST::SUB;
		$$ = new AST(AST::_OPERATION,&x,node,2);
		$$->reg = getRegister();
		$$->setCode($1->getCode(),"");
		$$->addCode($3->getCode(),"");
		$$->addCode($$->getValue()+" := "+$1->getValue()+" - "+$3->getValue());	
	}
	|TERM {
		$$ = $1;
	}
	;
TERM: TERM TIMES FACTOR {
		if( ($1->dType != $3->dType) && ($1->dType != AST::_VOID) ){
			return 1;
		}
		node = new AST*[2];
		node[0] = $1;
		node[1] = $3;
		AST::OpType x = AST::MUL;
		$$ = new AST(AST::_OPERATION,&x,node,2);
		$$->reg = getRegister();
		$$->setCode($1->getCode(),"");
		$$->addCode($3->getCode(),"");
		$$->addCode($$->getValue()+" := "+$1->getValue()+" * "+$3->getValue());
	}
	|TERM DIVIDE FACTOR {
		if( ($1->dType != $3->dType) && ($1->dType != AST::_VOID) ){
			return 1;
		}
		node = new AST*[2];
		node[0] = $1;
		node[1] = $3;
		AST::OpType x = AST::DIV;
		$$ = new AST(AST::_OPERATION,&x,node,2);	
		$$->reg = getRegister();
		$$->setCode($1->getCode(),"");
		$$->addCode($3->getCode(),"");
		$$->addCode($$->getValue()+" := "+$1->getValue()+" / "+$3->getValue());
	}			
	|FACTOR {
		$$ = $1;
	}
	;
FACTOR:	LP EXPR RP {
			$$  = $2;
		}
		|ID {
			std::string id($1);
			$$ = new AST(AST::_VARIABLE,&id);
			if(getDataType(id,scope)==AST::_VOID){
				return 1;
			}
			$$->reg = getIdRegister(id,scope);
			$$->dType = getDataType(id,scope);
		}
		|NUMBER {
			$$ = new AST(AST::_CONSTANT,&$1);
			$$->dType = AST::_INT;
		}
		|DECIMAL {
			$$ = new AST(AST::_CONSTANT,&$1);
			$$->dType = AST::_FLOAT;
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
	label<<"L"<<++lcount;
	return 	label.str();
}

std::string getLabel(int lastLabel){
	std::stringstream label;
	label<<"L"<<lastLabel;
	return label.str();
}

std::string oppSymbol(std::string str){
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

AST::DataType getDataType(std::string id, int _scope){
	
}

std::string getIdRegister(std::string id, int _scope){
	
}

int yyerror(char *s){
	fprintf(stderr, "%s %s %d\n", s , yytext , yylineno );
	return 0;
}

int main(void) {
	yyparse();
	return 0;
}