#include "headers/ast.h"

using namespace std;

int main(){
	string name = "as";
	AST n(AST::VARIABLE,&name);

	AST *n1 = new AST[2];

	string name1 = "a2";
	n1[0].setNode(AST::VARIABLE, &name1);

	int a = 5;
	n1[1].setNode(AST::CONSTANT, &a);

	AST n2(AST::ASSIGN, n1, 2);
	n2.print();
	return 0;
}