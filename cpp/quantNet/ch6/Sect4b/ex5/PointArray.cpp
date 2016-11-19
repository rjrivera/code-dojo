#ifndef POINTARRAY_CPP
#define POINTARRAY_CPP

#include "PointArray.hpp"

#include <iostream>
#include <string>

/*
private:
	int m_length;
	T * m_data;

	RELEASE NOTES v4-4b

	Templatized PointArray class

*/


//template<class T>
//int NumericArray<T>::def_size = 10;

template<class Point> 
PointArray<Point>::PointArray() : Array<Point>() {
	
}

/*
constructor with size
*/
template<class Point>
PointArray<Point>::PointArray(int size_) : Array<Point>(size_) {
}	

/*
copy constructor
*/
template<class Point>
PointArray<Point>::PointArray(const PointArray<Point>& source_) {
	//create the size of memory needed. 
	Array<Point>::m_length = source_.Size();

	Array<Point>::m_data = new Point[Array<Point>::m_length];
	//begin transcribing from source to target. 
	
	for (int i = 0; i < Array<Point>::m_length; i++) {
		Array<Point>::m_data[i] = source_.Array<Point>::m_data[i]; 
	}
}

template<class Point>
PointArray<Point>::~PointArray() {
	
	//delete[] Array<T>::m_data;
}

/*
Accessor - get by index. same functionality as operator[]
*/
template<class Point>
Point PointArray<Point>::GetElement(int index_) const {
	if (index_ >= 0 && index_ < Array<Point>::m_length) { 
		return Array<Point>::m_data[index_];
	}
	else { throw OutOfBoundsException(index_);}
}

template<class Point>
double PointArray<Point>::Length() const {
	double val = 0;
	for (int i = 1; i < Array<Point>::m_length; i++) {
		val += Array<Point>::m_data[i-1].Distance(Array<Point>::m_data[i]);
	
	}
	return val;
}

template<class Point>
void PointArray<Point>::DefaultSize(int index_) {
	Array<Point>::def_size = index_;
}

template<class Point>
int PointArray<Point>::DefaultSize() const {
	return Array<Point>::def_size;
}

template<class Point>
PointArray<Point>& PointArray<Point>::operator* (int index_) {
	for (int i = 0; i < Array<Point>::m_length; i++) {
		Array<Point>::m_data[i] *= index_;
	}
	return *this;
}

template<class Point>
PointArray<Point>& PointArray<Point>::operator+(PointArray<Point>& index_) {
	if (Array<Point>::m_length != index_.Array<Point>::m_length )  {
		std::cout << "two candidate arrays for scaling not equal\n";
		return *this;
	}
	for (int i = 0; i < PointArray<Point>::m_length; i++) {
		Array<Point>::m_data[i] += index_.Array<Point>::m_data[i];
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
