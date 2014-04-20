#include "headers/mipsGenerator.h"
#include "headers/utility.h"
#include "keywords.h"
#include "mipsLex.h"

MIPS::MIPS(){

}

MIPS::MIPS(std::string _fileName){
	keywords = {{"if",true},{"goto",true},{"param",true},{"call",true}};
	std::ofstream out(("mips_"+_fileName).c_str());
	freopen(file_name.c_str(), "r", stdin);
	string s;
	generateCode();
	fclose(stdin);
}

void generateCode(){
	string tempName,tempVar;
	if(match(REGISTER)){
		tempName.assign(yytext,yytext+yyleng);
		advance();
		if(match(EQUALS)){
			advance();
			tempVar = getExpression();
		}
	}
}

bool match(int token) {
	if(currentId == -1)
		currentId = yylex();
	return token == currentId;
}

void advance(void){
	/* Advance the lookahead to the next
	   input symbol.                               */
	currentId = yylex();
}