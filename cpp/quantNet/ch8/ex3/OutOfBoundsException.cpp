#include <iostream>
#include "OutOfBoundsException.hpp"

OutOfBoundsException::OutOfBoundsException() {
	m_index = -1;
}

OutOfBoundsException::OutOfBoundsException(int index_) {
	m_index = index_;
}

OutOfBoundsException::~OutOfBoundsException() {

}



std::string OutOfBoundsException::GetMessage() {
	return "The given index is out of bounds\n";
}


