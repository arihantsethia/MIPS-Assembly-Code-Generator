#include "headers/mipsGenerator.h"
#include "headers/utility.h"

MIPS::MIPS(){

}

MIPS::MIPS(std::string _fileName){
	std::ifstream in(_fileName.c_str());
	std::ofstream out(("mips_"+_fileName).c_str());
	std::string line,label;
	std::string::size_type pos;
	std::vector<std::string> tokens;
	while(!in.eof()){
		std::getline(in,line);
		label = "";
		if(hasLabel(line)){
			std::string::size_type pos = line.find(":");
			label = line.substr(0,pos);
			label = trim(label);
			line = line.substr(pos);
		}
		trim(line);
		tokens = tokenize(line," ");
	}
}

bool MIPS::hasLabel(std::string str){
	return true;
}