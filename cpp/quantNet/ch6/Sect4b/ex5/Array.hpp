#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <string>
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include "UniqueSizeException.hpp"
/*
	RELEASE NOTES v4-4a-1

	Template Array class 
*/

template<class T> 
class Array{

	protected:

		T * m_data;
		int m_length;
		static int def_size;
	public:
		
	
		//constructors and destructors. 
		Array();
		Array(int size_);
		Array(const Array<T>& source_);
		~Array();
		
		// accessor methods. 
		
		int Size() const;
		
		virtual T GetElement(int index_) const;	
		virtual int DefaultSize() const;
		// operator overloads
		virtual Array<T>& operator=(const Array<T>& source_);
		virtual const T& operator[](int index_) const; //used for access
		virtual T& operator[](int index_); 

		// setters
		virtual void SetElement(int index_, T& target_);
		virtual void DefaultSize(int index_);
};

// HW AMENDMENT INCLUDE SOURCE AT BOTTOM OF TEMPLATE HEADER
#ifndef ARRAY_CPP
#include "Array.cpp"

#endif

#endif

