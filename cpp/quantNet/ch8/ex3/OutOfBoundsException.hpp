#ifndef OUTOFBOUNDSEXCEPTION_HPP
#define OUTOFBOUNDSEXCEPTION_HPP
#include "ArrayException.hpp"

class OutOfBoundsException : public ArrayException {

	private: 
		int m_index;

	public: 
		OutOfBoundsException();
		OutOfBoundsException(int index_);
		~OutOfBoundsException();
		std::string GetMessage() override;

};
#endif

