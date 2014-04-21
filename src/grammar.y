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
	%start _STMT
	
	%token	AUTO	BOOL	CHAR	ELSE	FLOAT	IF	INT	LONG	RETURN	SIGNED	WHILE	PLUS	MINUS	TIMES	DIVIDE	EQUALS	NOT	LESS	GREATER	LS	RS	LB	RB	LP	RP	COLON	DOT	SEMI	COMMA	AND	OR	REQUALS	NOTEQUAL	LESSEQ	GREATEREQ

	%nonassoc LOWER_THAN_ELSE
	%nonassoc ELSE

%%

START: _START
_START: FUNCTION{
	
		}
		|DECLARATION{

		}
		|FUNCTION _START{

		}
		|DECLARATION _START{

		}

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
		node[1] = new AST(AST::_VARIABLE,&id);
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
_STMT : STMTLIST {std::cout<<$1->getCode()<<std::endl;}
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
				recursiveSetType($2,$1->dType);
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
			if(isDeclared(id)){
				std::cout<<"Variable already declared before"<<std::endl;
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
			if(isDeclared(id) || (getDataType(id) != AST::_VOID)){
				std::cout<<"Type Mismatch Error"<<std::endl;
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
					std::cout<<"Type Mismatch Error " << std::endl;
					return 1;
				}
				node = new AST*[2];
				node[0] = $3;
				node[1] = $5;
				std::string label = getLabel();
				$$ = new AST(AST::_BRANCH,node,2);
				$$->setCode($3->getCode(),"");
				$$->addCode(label+":");
				$$->addCode("if "+$3->getRevValue()+" goto "+getLabel());
				$$->addCode($5->getCode(),"");
				$$->addCode("goto "+label);
				$$->addCode(getLabel(lcount)+":");
			}
			;
IFSTMT:	IF LP EXPR RP STMT ELSEPART {
			if($3->dType != AST::_BOOL || $5->dType != AST::_VOID || $6->dType != AST::_VOID){
				std::cout<<"Type Mismatch Error"<<std::endl;
				return 1;
			}
			node = new AST*[3];
			node[0] = $3;
			node[1] = $5;
			node[2] = $6;
			$$ = new AST(AST::_BRANCH,node,3);
			std::cout<<"Asd"<<$3->dType<<std::endl;
			$$->setCode($3->getCode(),"");
			$$->addCode("if "+$3->getRevValue()+" goto "+getLabel());
			$$->addCode($5->getCode(),"");
			$$->addCode(getLabel(lcount)+": \n"+$6->getCode(),"");
			$$->dType = AST::_VOID;
		}
		;
ELSEPART:ELSE STMT {
			if($2->dType != AST::_VOID){
				std::cout<<"Type Mismatch Error"<<std::endl;
				return 1;
			}
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
CMPDSTMT: _LB STMTLIST _RB {
			$$ = $2;
			$$->dType = AST::_VOID;
		}
		;
_LB: LB {
		scope = scope+1;
	}
_RB: RB {
		scope = scope-1;
	}
STMTLIST: STMT STMTLIST {
			if($1->dType != AST::_VOID || $2->dType != AST::_VOID){
				std::cout<<"Type Mismatch Error"<<std::endl;
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
			if(getDataType(id) == AST::_VOID || getDataType(id) != $3->dType){
				std::cout<<"Type Mismatch Error or Variable Not Declared Error Line : "<<yylineno<<std::endl;
				return 1;
			}
			node = new AST*[2];
			node[0] = new AST(AST::_VARIABLE,&id);
			node[1] = $3;
			$$ = new AST(AST::_ASSIGN,node,2);
			$$->setCode($3->getCode(),"");
			$$->addCode(getIdRegister(id)+" := "+$3->getValue());
			$$->dType =AST::_VOID;
		}
		;
EXPR: EXPR COMPARE MAG {
		if( ($1->dType != $3->dType) || ($1->dType == AST::_VOID) || ($3->dType == AST::_VOID) ){
			std::cout<<"Type Mismatch Error Line : "<<yylineno<<std::endl;
			return 1;
		}
		std::string condition = $2->getCode();
		$$ = $2;
		$$->childLength=2;
		$$->childrens = new AST*[2];
		$$->childrens[0] = $1;
		$$->childrens[1] = $3;
		$$->setCode($1->getCode(),"");
		$$->setCode($3->getCode(),"");
		$$->value = $1->getValue()+condition+$3->getValue()	;
		$$->revValue = $1->getValue()+oppSymbol(condition)+$3->getValue();
		$$->dType = AST::_BOOL;
	}
	|MAG {
		$$ = $1;
		$$->revValue = $$->reg +" == "+"0";
	}
	|BOOLEAN{
		$$ = new AST(AST::_CONSTANT,&$1);
		$$->dType = AST::_BOOL;
		if($1){
			$$->value="true";
			$$->revValue = "false";;
		} else{
			$$->value = "false";
			$$->revValue = "true";
		}
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
		if( ($1->dType != $3->dType) || ($1->dType == AST::_VOID) || ($3->dType == AST::_VOID) ){
			std::cout<<"Type Mismatch Error Line : "<<yylineno<<std::endl;
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
		$$->dType = $1->dType;	
	}
	|MAG MINUS TERM {
		if( ($1->dType != $3->dType) || ($1->dType == AST::_VOID) || ($3->dType == AST::_VOID) ){
			std::cout<<"Type Mismatch Error Line : "<<yylineno<<std::endl;
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
		$$->dType = $1->dType;
	}
	|TERM {
		$$ = $1;
	}
	;
TERM: TERM TIMES FACTOR {
		if( ($1->dType != $3->dType) || ($1->dType == AST::_VOID) || ($3->dType == AST::_VOID) ){
			std::cout<<"Type Mismatch Error Line : "<<yylineno<<std::endl;
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
		$$->dType = $1->dType;
	}
	|TERM DIVIDE FACTOR {
		if( ($1->dType != $3->dType) || ($1->dType == AST::_VOID) || ($3->dType == AST::_VOID) ){
			std::cout<<"Type Mismatch Error Line : "<<yylineno<<std::endl;
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
		$$->dType = $1->dType;
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
			if(getDataType(id)==AST::_VOID){
				std::cout<<"Variable Not Declared Error Line : "<<yylineno<<std::endl;
				return 1;
			}
			$$->reg = getIdRegister(id);
			$$->dType = getDataType(id);
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

void recursiveSetType(AST* node, AST::DataType dType){
	std::string reg;
	if(node->childLength == 0){
		reg = getRegister();
		addToScope(*static_cast<std::string*>(node->data),reg,dType);
		return ;
	}
	recursiveSetType(node->childrens[0],dType);
	recursiveSetType(node->childrens[1],dType);
}

void addToScope(std::string id, std::string reg, AST::DataType dType){
	SymbolTable *symbolTableEntry = new SymbolTable(id,reg,dType,scope);
	symbolTable[scope][id] = *symbolTableEntry;
}

AST::DataType getDataType(std::string id){
	for(int i=scope; i>=0; i--) {
		if(symbolTable[i].find(id)!=symbolTable[i].end()) {
			return symbolTable[i][id].dType;
		}
	}
	return AST::_VOID;
}

bool isDeclared(std::string id){
	if(symbolTable[scope].find(id)!=symbolTable[scope].end()) {
		return true;
	}
	return false;
}

std::string getIdRegister(std::string id){
	for(int i=scope; i>=0; i--) {
		if(symbolTable[i].find(id)!=symbolTable[i].end()) {
			return symbolTable[i][id].reg;
		}
	}
}

int yyerror(char *s){
	fprintf(stderr, "%s %s %d\n", s , yytext , yylineno );
	return 0;
}

int main(void) {
	yyparse();
	return 0;
}