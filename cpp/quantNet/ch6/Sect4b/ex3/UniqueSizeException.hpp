#ifndef UNIQUESIZEEXCEPTION_HPP
#define UNIQUESIZEEXCEPTION_HPP
#include "ArrayException.hpp"

class UniqueSizeException : public ArrayException {

	private: 
		

	public: 
		UniqueSizeException();
		UniqueSizeException(int index_);
		~UniqueSizeException();
		std::string GetMessage() override;

};
#endif

