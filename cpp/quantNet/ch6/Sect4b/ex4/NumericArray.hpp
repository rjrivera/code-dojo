#ifndef NUMERICARRAY_HPP
#define NUMERICARRAY_HPP
#include <iostream>
#include <string>
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include "Array.hpp"
/*
	RELEASE NOTES v4-4b-1

	Template Numeric Array class 
*/

template<class T> 
class NumericArray : public Array<T> {

	public:
		//constructors and destructors. 
		NumericArray();
		NumericArray(int size_);
		NumericArray(const NumericArray<T>& source_);
		~NumericArray();
		
		// accessor methods. 
		
		//int Size() const;
		
		T GetElement(int index_) const;	
		int DefaultSize() const;
		// operator overloads
		NumericArray& operator* (int index_);
		NumericArray& operator+ (NumericArray<T>& index_);
		T DotProduct(NumericArray<T>& b_);		

		void DefaultSize(int index_);

};
#endif

