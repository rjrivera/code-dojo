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
NumericArray<T>::NumericArray(const NumericArray<T>& source_) : Array<T>(source_){
}

/*
 * Destructor - does not delete anything, Array.cpp deletes memory
 */
template<class T>
NumericArray<T>::~NumericArray() {
	
}

/*
 * Static variable mutator for altering the class default size
 * */
template<class T>
void NumericArray<T>::DefaultSize(int index_) {
	Array<T>::DefaultSize(index_); // Array<T>::def_size = index_;
}

/*
 * Static Variable accessor for viewing the class default size. 
 */
template<class T>
int NumericArray<T>::DefaultSize() const {
	return Array<T>::DefaultSize();
	//return Array<T>::def_size;
}

template<class T>
NumericArray<T>& NumericArray<T>::operator= (const NumericArray<T>& source_) {
	return Array<T>::operator=(source_);//isn't quite right. 
	/*
	Array<T>::m_length = source_.m_length;

	for (int i = 0; i < Array<T>::m_length; i++) {
		Array<T>::m_data[i] = source_[i];
	}
	*/
	// return *this;
}


/*
 * Mutator - Scale the elements of the numeric array by a factor
 * */
template<class T>
const NumericArray<T>& NumericArray<T>::operator* (int index_) const{
	T temp = 0;
	for (int i = 0; i < Array<T>::Size(); i++) {
		//Array<T>::m_data[i] *= index_;
		//Use the accessor and mutator base methods to 
		//manipulate private member information. 
		temp = Array<T>::GetElement(i);
		temp *= index_;
		Array<T>::SetElement(index_, temp);
	}
	return *this;
}

/*
 *
 * Mutator, add the elements of two numeric arrays. Throw an exception if two arrays are not the same size. 
 *
 */
template<class T>
NumericArray<T>& NumericArray<T>::operator+(NumericArray<T>& index_) const{
	if (Array<T>::Size() != index_.Array<T>::Size() )  {
		throw UniqueSizeException();
		return *this;
	}
	T temp = 0;
	for (int i = 0; i < Array<T>::Size(); i++) {
		temp = Array<T>::GetElement(i);	
		temp += index_.Array<T>::GetElement(i);
		Array<T>::SetElement(i, temp);
		temp = 0;
	}
	return *this;
}

/*
 * Calculate the Dot Product of two arrays, throw an exception if not the same size. 
 */
template<class T>
const T NumericArray<T>::DotProduct(NumericArray<T>& b_) const{
	if (Array<T>::Size() != b_.Array<T>::Size())  {
		throw UniqueSizeException();
		return 0;
	}
	T dP = 0;
	T temp = 0;
	for (int i = 0; i < Array<T>::Size(); i++) {
		temp = b_.Array<T>::GetElement(i);
		temp *= Array<T>::GetElement(i); 
		dP += temp;
		temp = 0;
	}
	return dP;
}

#endif
