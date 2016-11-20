#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP

#include "NumericArray.hpp"
#include "ArrayException.hpp"
#include "UniqueSizeException.hpp"
#include <iostream>
#include <string>

/*
private:
	int m_length;
	T * m_data;

	RELEASE NOTES v4-4b

	Templatized NumericArray class

*/

/*
 * Default Constructor
 */
template<class T> 
NumericArray<T>::NumericArray() : Array<T>() {
	
}

/*
constructor with size
*/
template<class T>
NumericArray<T>::NumericArray(int size_) : Array<T>(size_) {
}	

/*
copy constructor
*/
template<class T>
NumericArray<T>::NumericArray(const NumericArray<T>& source_) {
	//create the size of memory needed. 
	Array<T>::m_length = source_.Size();

	Array<T>::m_data = new T[Array<T>::m_length];
	//begin transcribing from source to target. 
	
	for (int i = 0; i < Array<T>::m_length; i++) {
		Array<T>::m_data[i] = source_.Array<T>::m_data[i]; 
	}
}

/*
 * Destructor - does not delete anything, Array.cpp deletes memory
 */
template<class T>
NumericArray<T>::~NumericArray() {
	
}

/*
Accessor - get by index. same functionality as operator[]
*/
template<class T>
T NumericArray<T>::GetElement(int index_) const {
	if (index_ >= 0 && index_ < Array<T>::m_length) { 
		return Array<T>::m_data[index_];
	}
	else { throw OutOfBoundsException(index_);}
}

/*
 * Static variable mutator for altering the class default size
 * */
template<class T>
void NumericArray<T>::DefaultSize(int index_) {
	Array<T>::def_size = index_;
}

/*
 * Static Variable accessor for viewing the class default size. 
 */
template<class T>
int NumericArray<T>::DefaultSize() const {
	return Array<T>::def_size;
}

/*
 * Mutator - Scale the elements of the numeric array by a factor
 * */
template<class T>
NumericArray<T>& NumericArray<T>::operator* (int index_) {
	for (int i = 0; i < Array<T>::m_length; i++) {
		Array<T>::m_data[i] *= index_;
	}
	return *this;
}

/*
 *
 * Mutator, add the elements of two numeric arrays. Throw an exception if two arrays are not the same size. 
 *
 */
template<class T>
NumericArray<T>& NumericArray<T>::operator+(NumericArray<T>& index_) {
	if (Array<T>::m_length != index_.Array<T>::m_length )  {
		throw UniqueSizeException();
		return *this;
	}
	for (int i = 0; i < Array<T>::m_length; i++) {
		Array<T>::m_data[i] += index_.Array<T>::m_data[i];
	}
	return *this;
}

/*
 * Calculate the Dot Product of two arrays, throw an exception if not the same size. 
 */
template<class T>
T NumericArray<T>::DotProduct(NumericArray<T>& b_) {
	if (Array<T>::m_length != b_.Array<T>::m_length )  {
		throw UniqueSizeException();
		return 0;
	}
	T dP = 0;
	for (int i = 0; i < Array<T>::m_length; i++) {
		dP += b_.Array<T>::m_data[i] * Array<T>::m_data[i];
	}
	return dP;

}

#endif
