#ifndef MIPS_H
#define MIPS_H

#include <iostream>
#include <string>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <utility>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstring>
#include <list>
#include <iomanip>


class MIPS{
private:

public:
	MIPS();
	MIPS(std::string);
	std::string getLabel();
	std::string getRegister();
	void freeRegister(std::string);
	bool hasLabel(std::string);
};

#endif