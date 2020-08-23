#ifndef _INVALID_BRACKET_EXCEPTION_
#define _INVALID_BRACKET_EXCEPTION_

#include<exception>
using namespace std ;

class invalid_bracket_exception : public std::exception{
public:
	invalid_bracket_exception(){

	}
	const char* what(){
		return "Program reached in an invalid_bracket." ;
	}
};

#endif