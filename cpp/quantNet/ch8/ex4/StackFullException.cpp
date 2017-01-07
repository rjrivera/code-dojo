#include <iostream>
#include <string>
#include "StackFullException.hpp"

std::string StackFullException::getMessage() {
	return "Stack is at Capacity, not Pushing";

}


