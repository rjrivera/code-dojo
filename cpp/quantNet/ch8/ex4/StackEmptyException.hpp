#ifndef STACKEMPTYEXCEPTION_HPP
#define STACKEMPTYEXCEPTION_HPP
#include <iostream>
#include <string>
#include "StackException.hpp"

class StackEmptyException : public StackException {

	public:
		std::string getMessage() override;

};

#endif
