#include "headers/ast.h"

AST::AST(){

}

AST::AST(const AST &otherNode){
	nType = otherNode.nType;	
	data = clone(otherNode.data);
	code = otherNode.code;
	childLength = otherNode.childLength;
	for(int i=0;i<childLength;i++){
		childrens[i] = otherNode.childrens[i]->clone();
	}
}

AST::AST(int length){
	data = NULL;
	code = "";
	nType = AST::EPSILON;
	childLength = length;
	if(length>0){
		childrens = new AST*[length];
	}
}
	
AST::AST(NodeType T, void* _data){
	code = "";
	nType = T;
	childLength = 0;
	data = clone(_data);
}

AST::AST(NodeType T, AST** _childrens, int length){
	if(T==STATEMENT || T==A_WHILE || T==A_IF || T==A_ELSE || T==ASSIGN || T==BRANCH || T==FUNC || T==ARG_LIST || T==ID_LIST || T==ARGD || T==VARD){
		data = NULL;
	}
	code = "";
	nType = T;
	childLength = length;
	if(length > 0){
		childrens = new AST*[length];
		for(int i=0;i<length;i++){
			childrens[i] = _childrens[i]; 
		}
	}
}

AST::AST(NodeType T, void* _data, AST** _childrens, int length){
	code = "";
	nType = T;
	childLength = length;
	data = clone(_data);
	if(length > 0){
		childrens = new AST*[length];
		for(int i=0;i<length;i++){
			childrens[i] = _childrens[i]; 
		}
	}
}

AST::~AST(){

}

void AST::setNode(int length){
	data = NULL;
	nType = AST::EPSILON;
	childLength = length;
	if(length>0){
		childrens = new AST*[length];
	}
}
	
void AST::setNode(NodeType T, void* _data){
	nType = T;
	data = clone(_data);
	childLength = 0;
}

void AST::setNode(NodeType T, AST** _childrens, int length){
	if(T==A_WHILE){
		data = NULL;
	}else if(T==A_IF){
		data = NULL;
	}else if(T==ASSIGN){
		data = NULL;
	}else if(T==BRANCH){
		data = NULL;
	}
	nType = T;
	childLength = length;
	if(length > 0){
		childrens = new AST*[length];
		for(int i=0;i<length;i++){
			childrens[i] = _childrens[i]; 
		}
	}
}

void AST::setNode(NodeType T, void* _data, AST** _childrens, int length){
	nType = T;
	childLength = length;
	data = clone(_data);
	if(length > 0){
		childrens = new AST*[length];
		for(int i=0;i<length;i++){
			childrens[i] = _childrens[i]; 
		}
	}
}

void AST::print(){
	std::cout<<"NODE TYPE : ";
	if(nType == EPSILON){
		std::cout<<"EPSILON"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == CONSTANT){
		std::cout<<"CONSTANT"<<std::endl;
		std::cout<<"NODE CONTENT : "<<*static_cast<int*>(data)<<std::endl;
	}else if(nType == VARIABLE){
		std::cout<<"VARIABLE"<<std::endl;
		std::cout<<"NODE CONTENT : "<<*static_cast<std::string*>(data)<<std::endl;
	}else if(nType == OPERATION){
		std::cout<<"OPERATION"<<std::endl;
		std::cout<<"NODE CONTENT : "<<opString[*static_cast<int*>(data)]<<std::endl;
	}else if(nType == CONDITION){
		std::cout<<"CONDITION"<<std::endl;
		std::cout<<"NODE CONTENT : "<<condString[*static_cast<int*>(data)]<<std::endl;
	}else if(nType == ASSIGN){
		std::cout<<"ASSIGN"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == A_WHILE){
		std::cout<<"WHILE"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == A_IF){
		std::cout<<"IF"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == A_ELSE){
		std::cout<<"ELSE"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == BRANCH){
		std::cout<<"BRANCH"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == STATEMENT){
		std::cout<<"STATEMENT"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == FUNC){
		std::cout<<"FUNCTION"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == ARG_LIST){
		std::cout<<"ARG LIST"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == ARGD){
		std::cout<<"ARG D"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == VARD){
		std::cout<<"VAR D"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == ID_LIST){
		std::cout<<"ID LIST"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType == F_TYPE){
		std::cout<<"FUNCTION TYPE"<<std::endl;
		std::cout<<"NODE CONTENT : "<<dataString[*static_cast<int*>(data)]<<std::endl;
	}else if(nType == D_TYPE){
		std::cout<<"DATA TYPE"<<std::endl;
		std::cout<<"NODE CONTENT : "<<dataString[*static_cast<int*>(data)]<<std::endl;
	}
	std::cout<<"NODE CHILDRENS LENGTH: "<<childLength<<std::endl;
	for(int i=0; i < childLength; i++){
		std::cout<<"START CHILDREN : "<<i<<std::endl;
		childrens[i]->print();
		std::cout<<"END CHILDREN : "<<i<<std::endl;
	}
}

AST* AST::clone(){
	return new AST(*this);
}

AST& AST::operator=(const AST& otherNode){
	if(&otherNode!=this){
		nType = otherNode.nType;		
		data = clone(otherNode.data);
		childLength = otherNode.childLength;
		for(int i=0;i<childLength;i++){
			delete childrens[i];
		}
		for(int i=0;i<childLength;i++){
			childrens[i] = otherNode.childrens[i]->clone();
		}
	}
}

void* AST::clone(void* data){
	void* newPtr;
	if(nType == VARIABLE){
		newPtr = new std::string( *static_cast<std::string*> (data));
	}else if(nType == CONSTANT){
		newPtr = new int(*static_cast<int*>(data));
	}else if(nType==OPERATION){
		newPtr = new OpType(*static_cast<OpType *>(data));
	}else if(nType==CONDITION){
		newPtr = new CondType(*static_cast<CondType *>(data));
	}else if(nType==D_TYPE){
		newPtr = new DataType(*static_cast<DataType *>(data));
	}else if(nType==F_TYPE){
		newPtr = new DataType(*static_cast<DataType *>(data));
	}
	return newPtr;
}

void AST::resetCode(std::string _code){
	code = _code;
}
void AST::addCode(std::string _code){
	code += _code;
}

std::string AST::getCode(){
	return code;
}