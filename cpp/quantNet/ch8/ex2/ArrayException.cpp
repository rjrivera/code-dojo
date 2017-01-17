#include <iostream>
#include <string>
#include "ArrayException.hpp"


class ArrayException {
	
	public:
		virtual std::string GetMessage() = 0; //make abstract

};


