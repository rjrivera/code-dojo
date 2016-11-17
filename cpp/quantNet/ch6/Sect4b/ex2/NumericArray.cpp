#ifndef NUMERICARRAY_CPP
#define NUMERICARRAY_CPP

#include "NumericArray.hpp"
//#include "Array.hpp"
#include <iostream>
#include <string>

/*
private:
	int m_length;
	T * m_data;

	RELEASE NOTES v4-4b

	Templatized NumericArray class

*/


//template<class T>
//int NumericArray<T>::def_size = 10;

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

template<class T>
NumericArray<T>::~NumericArray() {
	
	//delete[] Array<T>::m_data;
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

template<class T>
void NumericArray<T>::DefaultSize(int index_) {
	Array<T>::def_size = index_;
}

template<class T>
int NumericArray<T>::DefaultSize() const {
	return Array<T>::def_size;
}

template<class T>
NumericArray<T>& NumericArray<T>::operator* (int index_) {
	for (int i = 0; i < Array<T>::m_length; i++) {
		Array<T>::m_data[i] *= index_;
	}
	return *this;
}

template<class T>
NumericArray<T>& NumericArray<T>::operator+(NumericArray<T>& index_) {
	if (Array<T>::m_length != index_.Array<T>::m_length )  {
		std::cout << "two candidate arrays for scaling not equal\n";
		return *this;
	}
	for (int i = 0; i < Array<T>::m_length; i++) {
		Array<T>::m_data[i] += index_.Array<T>::m_data[i];
	}
	return *this;
}


/*
 *
 *
assignment operator
*/
/*
template<class T>
Array<T>& Array<T>::operator=(const Array<T>& source_) {
	m_length = source_.Size();

	if (&source_ == this) {return *this;} //handle self-assignment. 
	//INITIALIZE ARRAY OF OBJECTS. 
	delete[] m_data;
	m_data = new T[m_length];
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source_.m_data[i]; //amended line. 
	}	

	return *this;
}
template<class T>
T& Array<T>::operator[](int index_) {
	if (index_ >= 0 && index_ <  m_length) {
		return m_data[index_];
	}
	else { throw OutOfBoundsException(index_);}
}	

template<class T>
const T& Array<T>::operator[](int index_) const {
	if (index_ >= 0 && index_ < m_length) { 
		return m_data[index_];
	} 
	else {	throw OutOfBoundsException(index_);}
	
}
template<class T>
Array<T>::~Array() {
	
	delete[] m_data; 
}

*/
/*
template<class T>
int Array<T>::Size() const {
	return m_length;
}

template<class T>
void Array<T>::SetElement(int index_, T& target_) {
	if (index_ >= 0 || index_ < m_length) { 
		m_data[index_] = target_;
	}
	else {throw OutOfBoundsException(index_);}

}
*/
//===========================
/*
template class Array<Point>;
template class Array<Circle>;
template class Array<Line>;
template class Array<int>;
*/

#endif
