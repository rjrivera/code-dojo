#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
/*
	RELEASE NOTES v4-4a-1

	Template Array class 

*/


template<class T> 
class Array{

	private:
		T * m_data;
		int m_length;
	public:
		//constructors and destructors. 
		Array();
		Array(int size_);
		Array(const Array<T>& source_);
		~Array();
		
		// accessor methods. 
		
		int Size() const;
		T GetElement(int index_) const;	

		// operator overloads
		
		Array<T>& operator=(const Array<T>& source_);
		const T& operator[](int index_) const; //used for access
		T& operator[](int index_); 

		// setters
		void SetElement(int index_, T& target_);
};

#endif

