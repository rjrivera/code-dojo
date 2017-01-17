#include <iostream>
#include "UniqueSizeException.hpp"

UniqueSizeException::UniqueSizeException() {
}

UniqueSizeException::UniqueSizeException(int index_) {
}

UniqueSizeException::~UniqueSizeException() {

}



std::string UniqueSizeException::GetMessage() {
	return "The given arrays are not equal size\n";
}


