#include <iostream>
#include <string>
#include "StackEmptyException.hpp"

std::string StackEmptyException::getMessage() {
	return "Stack is empty, not popping";

}


