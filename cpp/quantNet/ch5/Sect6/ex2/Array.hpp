#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Point.hpp"

/*
	RELEASE NOTES v3-6-2

	Implementing Exception Options of OutOfBoundsException::ArrayException

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
class Array{

	private:
		Point * m_data;
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
		Point GetElement(int index_) const;	
		// operator overloads
		Array& operator=(const Array& source_);
		const Point& operator[](int index_) const; //used for access
		Point& operator[](int index_); 

		// setters
		void SetElement(int index_, Point& target_);
};
#endif
