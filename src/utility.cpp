#include "headers/utility.h"

// This function tokenizes the string on the basis of delimeters space or newline or cariage return.
std::vector<std::string> tokenize(std::string s, std::string sep){
	// Skip delimiters at beginning.
	std::string::size_type lastPos = s.find_first_not_of(sep, 0);
	// Find first "non-delimiter", which will be between lastPos and pos
	std::string::size_type pos = s.find_first_of(sep, lastPos); 
	std::vector<std::string> _tokens;
	while(pos != std::string::npos || lastPos != std::string::npos){
		_tokens.push_back(s.substr(lastPos,(pos - lastPos)));
		// Skip delimiters
		lastPos = s.find_first_not_of(sep, pos);
		// Find "non-delimiter", which will be between lastPos and pos
		pos = s.find_first_of(sep, lastPos); 
	}
	return _tokens;
}