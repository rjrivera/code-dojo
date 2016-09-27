#include "Array.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>

/*
private:
	int m_length;
	Point * m_data;
*/

Array::Array() {
	m_length = 10;
	//m_data = static_cast<Point*>(malloc(sizeof(Point)*m_length));
	m_data = new Point[m_length];
	

	for (int i = 0; i < m_length; i++) {
		m_data[i] = *(new Point());
		std::cout << m_data[i] << std::endl;
		//m_data++;
	}
	//resetting point to the base. 
	//m_data -= m_length*sizeof(Point);
}

Array::Array(int size_) {
	m_length = size_;
	//m_data = static_cast<Point*>(malloc(sizeof(Point)*m_length));
	m_data = new Point[m_length];

	for (int i = 0; i < m_length; i++) {
		m_data[i] = *(new Point());
		std::cout << m_data[i] << std::endl;
//		m_data++;
	}
	//resetting the pointer to the base of array. 
//	m_data -= m_length*sizeof(Point);
	
}	

Array::Array(const Array& source_) {
	//create the size of memory needed. 
	m_length = source_.length();
//	m_data = static_cast<Point*>(malloc(sizeof(Point)*m_length));
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

Array& Array::operator=(const Array& source_) {
	m_length = source_.length();
	// VV what I was doing before. 
	//m_data = static_cast<Point*>(malloc(sizeof(Point) * m_length));
	//INITIALIZE ARRAY OF OBJECTS. 
	m_data = new Point[m_length];

	Point * source = source_.arr();
	
	for (int i = 0; i < m_length; i++) {
		m_data[i] = source[i];
		//m_data++;
		//source++;
	}	
	//m_data -= sizeof(Point) * m_length;

	return *this;
}

Array::~Array() {//TODO: ask why badjuju happens when this occures. 
/*
	for (int i = 0; i < m_length; i++) {
		delete m_data[i];
		
	}*/
	//m_data -= sizeof(Point) * m_length;
	
	delete[] m_data; 
}

Point Array::point(int pos_) {
	return *(m_data + pos_);
}

int Array::length() const {
	return m_length;
}

//return the base pointer to the array. 
Point * Array::arr() const {
	return m_data;
}
