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


/*
 *Default Constructor
 */

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

/*
 * Destructor
 */
template<class Point>
PointArray<Point>::~PointArray() {
	
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

/*
 * Accessor - returns the calculated distance traveled traversing the points from index 0 to final point. 
 */
template<class Point>
double PointArray<Point>::Length() const {
	double val = 0;
	for (int i = 1; i < Array<Point>::m_length; i++) {
		val += Array<Point>::m_data[i-1].Distance(Array<Point>::m_data[i]);
	
	}
	return val;
}

/*
 * Static variable mutator altering the class definition for the default size. 
 */
template<class Point>
void PointArray<Point>::DefaultSize(int index_) {
	Array<Point>::def_size = index_;
}

/*
 * Static variable accessor returning the current value of the default size variable. 
 */
template<class Point>
int PointArray<Point>::DefaultSize() const {
	return Array<Point>::def_size;
}

/**
 * Mutator operator overload, scales all points by the same factor (index_)
 */
template<class Point>
PointArray<Point>& PointArray<Point>::operator* (int index_) {
	for (int i = 0; i < Array<Point>::m_length; i++) {
		Array<Point>::m_data[i] *= index_;
	}
	return *this;
}

/*
 *Mutator function adding all points with their respective points in the parameter Array<Point>
 */

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



#endif
