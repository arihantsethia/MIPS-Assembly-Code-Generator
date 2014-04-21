#include "headers/ast.h"

AST::AST(){

}

AST::AST(const AST &otherNode){
	nType = otherNode.nType;
	dType = otherNode.dType;
	code = otherNode.code;
	reg = otherNode.reg;
	value = otherNode.value;
	revValue = otherNode.revValue;
	childLength = otherNode.childLength;
	data = clone(otherNode.data);
	childrens=NULL;
	if(childLength > 0){
		childrens = new AST*[childLength];
		for(int i=0;i<childLength;i++){
			childrens[i] = otherNode.childrens[i]->clone();
		}
	}
}

AST::AST(int length){
	code = "";
	reg = "";
	value = "";
	revValue = "";
	data = NULL;
	dType = _VOID;
	nType = AST::_EPSILON;
	childLength = length;
	if(length>0){
		childrens = new AST*[length];
	}
}
	
AST::AST(NodeType T, void* _data){
	code = "";
	reg = "";
	value = "";
	revValue = "";
	dType = _VOID;
	nType = T;
	childLength = 0;
	data = clone(_data);
}

AST::AST(NodeType T, AST** _childrens, int length){
	if(T==_STATEMENT || T==_WHILE || T==_IF || T==_ELSE || T==_ASSIGN || T==_BRANCH || T==_FUNCTION || T==_ARGLIST || T==_IDLIST || T==_ARG || T==_VAR){
		data = NULL;
	}
	code = "";
	reg = "";
	value = "";
	revValue = "";
	dType = _VOID;
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
	reg = "";
	value = "";
	revValue = "";
	nType = T;
	dType = _VOID;
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

void AST::print(){
	std::cout<<"NODE TYPE : ";
	if(nType ==_EPSILON){
		std::cout<<"EPSILON"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_CONSTANT){
		std::cout<<"CONSTANT"<<std::endl;
		std::cout<<"NODE CONTENT : "<<*static_cast<int*>(data)<<std::endl;
	}else if(nType ==_VARIABLE){
		std::cout<<"VARIABLE"<<std::endl;
		std::cout<<"NODE CONTENT : "<<*static_cast<std::string*>(data)<<std::endl;
	}else if(nType ==_OPERATION){
		std::cout<<"OPERATION"<<std::endl;
		std::cout<<"NODE CONTENT : "<<opString[*static_cast<int*>(data)]<<std::endl;
	}else if(nType ==_CONDITION){
		std::cout<<"CONDITION"<<std::endl;
		std::cout<<"NODE CONTENT : "<<condString[*static_cast<int*>(data)]<<std::endl;
	}else if(nType ==_ASSIGN){
		std::cout<<"ASSIGN"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_WHILE){
		std::cout<<"WHILE"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_IF){
		std::cout<<"IF"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_ELSE){
		std::cout<<"ELSE"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_BRANCH){
		std::cout<<"BRANCH"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_STATEMENT){
		std::cout<<"STATEMENT"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_FUNCTION){
		std::cout<<"FUNCTION"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_ARGLIST){
		std::cout<<"ARG LIST"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_ARG){
		std::cout<<"ARG D"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_VAR){
		std::cout<<"VAR D"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_IDLIST){
		std::cout<<"ID LIST"<<std::endl;
		std::cout<<"NODE CONTENT : EMPTY"<<std::endl;
	}else if(nType ==_FTYPE){
		std::cout<<"FUNCTION TYPE"<<std::endl;
		std::cout<<"NODE CONTENT : "<<dataString[*static_cast<int*>(data)]<<std::endl;
	}else if(nType ==_DTYPE){
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
		dType = otherNode.dType;		
		data = clone(otherNode.data);
		code = otherNode.code;
		reg = otherNode.reg;
		value = otherNode.value;
		revValue = otherNode.revValue;
		childLength = otherNode.childLength;
		for(int i=0;i<childLength;i++){
			childrens[i] = otherNode.childrens[i]->clone();
		}
	}
}

void* AST::clone(void* data){
	void* newPtr;
	if(nType ==_VARIABLE){
		newPtr = new std::string( *static_cast<std::string*> (data));
	}else if(nType ==_CONSTANT){
		newPtr = new int(*static_cast<int*>(data));
	}else if(nType==_OPERATION){
		newPtr = new OpType(*static_cast<OpType *>(data));
	}else if(nType==_CONDITION){
		newPtr = new CondType(*static_cast<CondType *>(data));
	}else if(nType==_DTYPE){
		newPtr = new DataType(*static_cast<DataType *>(data));
	}else if(nType==_FTYPE){
		newPtr = new DataType(*static_cast<DataType *>(data));
	}else{
		newPtr = NULL;
	}
	return newPtr;
}

void AST::setCode(std::string _code,std::string end){
	code = _code;
	if(end.length()>0){
		code += end; 
	}
}
void AST::addCode(std::string _code,std::string end){
	code += _code;
	if(end.length()>0){
		code += end; 
	}
}

std::string AST::getCode(){
	return code;
}

std::string AST::getValue(){
	std::stringstream s;
	if(nType ==_CONSTANT){
		if(dType ==_INT){
			s<< *static_cast<int*>(data);
		}else if(dType ==_FLOAT){
			s<< *static_cast<float*>(data);
		}else if(dType ==_BOOL){
			s<< *static_cast<bool*>(data);
		}
	}else if(reg!=""){
		s<<reg;
	}else if(value.length()>0){
		s<<value;
	}
	return s.str();
}

std::string AST::getRevValue(){
	return revValue;
}