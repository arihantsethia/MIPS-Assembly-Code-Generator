#ifndef UTILITY_H
#define UTILITY_H

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
#include <functional> 
#include <cctype>
#include <locale>

std::vector<std::string> tokenize(std::string, std::string);

static inline std::string ltrim(std::string s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
	return s;
}

static inline std::string rtrim(std::string s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
	return s;
}

static inline std::string trim(std::string s) {
	return ltrim(rtrim(s));
}

#endif