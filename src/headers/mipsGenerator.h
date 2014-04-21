#ifndef MIPS_H
#define MIPS_H

#include "headers.h"

class MIPS{
private:
	static int currentId = -1;
	static std::map<std::string,bool> keywords;
	static std::map<std::string,std::string> registerMapping;
public:
	MIPS();
	MIPS(std::string);
	std::string getLabel();
	std::string getRegister();
	void freeRegister(std::string);
	bool hasLabel(std::string);
};

#endif