#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
//#include "Point.hpp"

/*
	RELEASE NOTES v4-4a-1

	Template Array class 

*/
// =========== BEG EXCEPTION OBJECT DEF

class ArrayException {
	
	public:
		virtual std::string GetMessage() = 0; //make abstract

};

class OutOfBoundsException : public ArrayException {

	private: 
		int m_index;

	public: 
		OutOfBoundsException();
		OutOfBoundsException(int index_);
		~OutOfBoundsException();
		std::string GetMessage() override;

};

// ============ END EXCEPTION OBJECT DEF
template<class T> 
class Array{

	private:
		T * m_data;
		int m_length;
	public:
		//constructors and destructors. 
		Array();
		Array(int size_);
		Array(const Array& source_);
		~Array();
		
		// accessor methods. 
		//Point point(int pos_) const;
		int Size() const;
		// Point * arr() const; - rm' line for hw resub. 
		T GetElement(int index_) const;	
		// operator overloads
		Array& operator=(const Array& source_);
		const T& operator[](int index_) const; //used for access
		T& operator[](int index_); 

		// setters
		void SetElement(int index_, T& target_);
};


#ifndef ARRAY_CPP
#include "Array.cpp"

#endif
#endif
