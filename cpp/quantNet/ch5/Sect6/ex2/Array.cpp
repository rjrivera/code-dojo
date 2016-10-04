#include "Array.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

/*
private:
	int m_length;
	Point * m_data;

	RELEASE NOTES v3-6-2 

	Implemented Amendments made to Array.hpp creating an ABC ArrayException and derived class implementing the ABC OutOfBoundsException.

*/

/*
	DEFINING ARRAY EXCEPTION CLASS BEFORE ARRAY
*/

OutOfBoundsException::OutOfBoundsException() {
	m_index = -1;
}

OutOfBoundsException::OutOfBoundsException(int index_) {
	m_index = index_;
}

OutOfBoundsException::~OutOfBoundsException() {

}



std::string OutOfBoundsException::GetMessage() {
	return "The given index is out of bounds\n";
}

/*
default constructor - instantiates to size 10 Points. 
*/
Array::Array() {
	m_length = 10;
	m_data = new Point[m_length];
	

	for (int i = 0; i < m_length; i++) {
		m_data[i] = Point();
	}
}

/*
constructor with size
*/
Array::Array(int size_) {
	m_length = size_;
	m_data = new Point[m_length];

	for (int i = 0; i < m_length; i++) {
		m_data[i] = Point();
	}
}	

/*
copy constructor
*/
Array::Array(const Array& source_) {
	//create the size of memory needed. 
	m_length = source_.Size();

	m_data = new Point[m_length];
	//begin transcribing from source to target. 

	// ===== HW AMENDMENT ===
	// removing * and copying directly from source. 
	//	Point * source = source_.arr(); removed line
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source_.m_data[i]; //amended line
	}
}

/*
Accessor - get by index. same functionality as operator[]
*/

Point Array::GetElement(int index_) const {
	if (index_ >= 0 && index_ < m_length) { 
		return m_data[index_];
	}
	else { throw -1;}
}

/*
assignment operator
*/
Array& Array::operator=(const Array& source_) {
	m_length = source_.Size();

	//INITIALIZE ARRAY OF OBJECTS. 
	delete[] m_data;
	m_data = new Point[m_length];
	// ==== HW AMENDMENT ====
//	Point * source = source_.arr(); rm'd line
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source_.m_data[i]; //amended line. 
	}	

	return *this;
}

Point& Array::operator[](int index_) {
	if (index_ >= 0 && index_ <  m_length) {
		return m_data[index_];
	}
	else { throw OutOfBoundsException(index_);}
}	


const Point& Array::operator[](int index_) const {
	if (index_ >= 0 && index_ < m_length) { 
		return m_data[index_];
	} 
	else {	throw OutOfBoundsException(index_);}
	
}
Array::~Array() {
	
	delete[] m_data; 
}
int Array::Size() const {
	return m_length;
}

void Array::SetElement(int index_, Point& target_) {
	if (index_ >= 0 || index_ < m_length) { // ==== HW AMENDMENT
		m_data[index_] = target_;
	}
	else {throw OutOfBoundsException(index_);}

}

