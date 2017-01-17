#ifndef STACKEXCEPTION_HPP
#define STACKEXCEPTION_HPP
#include <iostream>
#include <string>

class StackException{

	public:
		virtual std::string getMessage() = 0;

};

#endif
