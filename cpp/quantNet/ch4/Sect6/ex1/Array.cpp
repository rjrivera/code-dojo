#include "Array.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

namespace RobRivera {
	namespace Containers{

/*
private:
	int m_length;
	Point * m_data;
*/
/*
default constructor - instantiates an array of size 10 points. 
*/
Array::Array() {
	m_length = 10;
	m_data = new CAD::Point[m_length];
	

	for (int i = 0; i < m_length; i++) {
		m_data[i] = CAD::Point();
	}
	
}

/*
Constructor instantiates array of size size_
*/
Array::Array(int size_) {
	m_length = size_;
	m_data = new CAD::Point[m_length];

	for (int i = 0; i < m_length; i++) {
		m_data[i] = CAD::Point();
	}
	
}	

/*
copy constructor
*/
Array::Array(const Array& source_) {
	//create the size of memory needed. 
	m_length = source_.Size();

	m_data = new CAD::Point[m_length];
	//begin transcribing from source to targer. 
	//create working copies of array pointers. 
	CAD::Point * source = source_.arr();
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source[i];
		
	}

}

/*
Accessor method - redudant with [] operator. 
returns Point element at index_. 
*/
CAD::Point Array::GetElement(int index_) const {
	return m_data[index_];
}

/*
assignement operator providing a deep copy of source array source_ 
*/

Array& Array::operator=(const Array& source_) {
	m_length = source_.Size();

	//INITIALIZE ARRAY OF OBJECTS. 
	delete[] m_data;
	m_data = new CAD::Point[m_length];

	CAD::Point * source = source_.arr();
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source[i];
	}	

	return *this;
}
/*
operator[] overload returning Point element at index_
*/
const CAD::Point& Array::operator[](int index_) {
	return m_data[index_];
}	

/*
destructor
*/
Array::~Array() {

	
	delete[] m_data; 
}

/*redundent with operator[] and GetElement(int index) OBSOLETE
CAD::Point Array::point(int pos_) {
	return m_data[pos_]; 
}
*/

/*
Accessor - returns size of Container (regardless if empty point slots)
*/
int Array::Size() const {
	return m_length;
}

//return the base pointer to the array. added to specifications by author for developmental testing. 
CAD::Point * Array::arr() const {
	return m_data;
}

/*
Mutator - set index_ position to Point of value (*target_)
*/
void Array::SetElement(int index_, CAD::Point * target_) {
	CAD::Point point = CAD::Point(); //
	point = *(target_);
	m_data[index_] = point;

}



	}
}
