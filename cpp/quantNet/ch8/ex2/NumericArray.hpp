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
		
		int DefaultSize() const;
		// operator overloads
		NumericArray& operator= (const NumericArray<T>& source_);
		const NumericArray& operator* (int index_) const;
		NumericArray& operator+ (NumericArray<T>& index_) const;
		const T DotProduct(NumericArray<T>& b_) const;		

		void DefaultSize(int index_);

};
#endif

