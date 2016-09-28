#include "Array.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

/*
private:
	int m_length;
	Point * m_data;
*/
/*
default constructor - instantiates to size 10 Points. 
*/
Array::Array() {
	m_length = 10;
	//m_data = static_cast<Point*>(malloc(sizeof(Point)*m_length));
	m_data = new Point[m_length];
	

	for (int i = 0; i < m_length; i++) {
		m_data[i] = Point();
	//	std::cout << m_data[i] << std::endl;
		//m_data++;
	}
	//resetting point to the base. 
	//m_data -= m_length*sizeof(Point);
}

/*
constructor with size
*/
Array::Array(int size_) {
	m_length = size_;
	//m_data = static_cast<Point*>(malloc(sizeof(Point)*m_length));
	m_data = new Point[m_length];

	for (int i = 0; i < m_length; i++) {
		m_data[i] = Point();
	//	std::cout << m_data[i] << std::endl;
//		m_data++;
	}
	//resetting the pointer to the base of array. 
//	m_data -= m_length*sizeof(Point);
	
}	

/*
copy constructor
*/
Array::Array(const Array& source_) {
	//create the size of memory needed. 
	m_length = source_.Size();

	m_data = new Point[m_length];
	//begin transcribing from source to targer. 
	//create working copies of array pointers. 
	Point * source = source_.arr();
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source[i];
		//m_data++;
		//source++;
	}
//	m_data -= sizeof(Point)*m_length;

}

/*
Accessor - get by index. same functionality as operator[]
*/

Point Array::GetElement(int index_) const {
	return m_data[index_];
}

/*
assignment operator
*/
Array& Array::operator=(const Array& source_) {
	m_length = source_.Size();

	//INITIALIZE ARRAY OF OBJECTS. 
	delete[] m_data;
	m_data = new Point[m_length];

	Point * source = source_.arr();
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source[i];
	}	

	return *this;
}

const Point& Array::operator[](int index_) {
	return m_data[index_];
}	

Array::~Array() {
/*
	for (int i = 0; i < m_length; i++) {
		delete m_data[i];
		
	}*/
	//m_data -= sizeof(Point) * m_length;
	
	delete[] m_data; 
}
/* marked redundent to GetElement(int)
Point Array::point(int pos_) const{
	return m_data[pos_];
}
*/
int Array::Size() const {
	return m_length;
}

//return the base pointer to the array. 
Point * Array::arr() const {
	return m_data;
}

void Array::SetElement(int index_, Point * target_) {
	Point point = Point();
	point = *target_;
	m_data[index_] = point;

}
