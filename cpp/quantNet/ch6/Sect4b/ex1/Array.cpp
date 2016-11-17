#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.hpp"
#include <iostream>
#include <string>

/*
private:
	int m_length;
	T * m_data;

	RELEASE NOTES v3-4a-1

	Templatized Array class

*/

/*
	DEFINING ARRAY EXCEPTION CLASS BEFORE ARRAY
*/

template<class T>
int Array<T>::def_size = 10;

template<class T> 
Array<T>::Array() {
	m_length = def_size;
	m_data = new T[def_size];
	

	for (int i = 0; i < m_length; i++) {
		m_data[i] = T();
	}
}

/*
constructor with size
*/
template<class T>
Array<T>::Array(int size_) {
	m_length = size_;
	m_data = new T[m_length];

	for (int i = 0; i < m_length; i++) {
		m_data[i] = T();
	}
}	

/*
copy constructor
*/
template<class T>
Array<T>::Array(const Array<T>& source_) {
	//create the size of memory needed. 
	m_length = source_.Size();

	m_data = new T[m_length];
	//begin transcribing from source to target. 
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source_.m_data[i]; 
	}
}

/*
Accessor - get by index. same functionality as operator[]
*/
template<class T>
T Array<T>::GetElement(int index_) const {
	if (index_ >= 0 && index_ < m_length) { 
		return m_data[index_];
	}
	else { throw OutOfBoundsException(index_);}
}

template<class T>
void Array<T>::DefaultSize(int index_) {
	def_size = index_;
}

template<class T>
int Array<T>::DefaultSize() const {
	return def_size;
}

/*
 *
 *
assignment operator
*/
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

//===========================
/*
template class Array<Point>;
template class Array<Circle>;
template class Array<Line>;
template class Array<int>;
*/

#endif
