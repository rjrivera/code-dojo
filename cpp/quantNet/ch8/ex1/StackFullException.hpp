#ifndef STACKFULLEXCEPTION_HPP
#define STACKFULLEXCEPTION_HPP
#include <iostream>
#include <string>
#include "StackException.hpp"

class StackFullException : public StackException {

	public:
		std::string getMessage() override;

};

#endif
