#include <string>
#include <iostream>
#include "Stack.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

/*	RELEASE NOTES v.4-4b-4
 *
 *	Templated Stack class implemented for ex4 of HW6 using another Templated class as a data member. 
 *
 * protected members
Array<T> m_data;
int size;
int capacity;
*/		
	
/*	Default Constructor
 *
 * */
template <class T>
Stack<T>::Stack() {
	//defaults to the default size of the array<T> class. 
	m_data();// = Array<T>();
	capacity = m_data.m_length;
	size = -1; //empty data set. 
}

/*
 *	Constructor with size initialized manually. 
 */
template <class T>
Stack<T>::Stack(int size_) : m_data(size_), capacity(size_)  {
	
	//m_data(size_);// = Array<T>(size_);
	size = -1; // empty dataset

}

/*	copy constructor 
 *
 */
template <class T>
Stack<T>::Stack(const Stack<T>& source) {
	
	m_data = source.m_data;
	size = source.size;
	capacity = source.capacity;

}

template <class T>
Stack<T>::~Stack() {

}

template <class T>
T Stack<T>::pop() {
	try {
		if (size >= 0 ) {
			T temp = m_data[size];
			size--;
			return temp;
		}
		else throw StackEmptyException();
	}
	catch(StackEmptyException e) {
		std::cout << e.getMessage() << std::endl;
	}
}

template <class T>
T Stack<T>::front() const {
	return m_data[size];
}

template <class T>
void Stack<T>::push(T source) {
	try {
		if (size<capacity-1)  {
			size++;
			m_data[size] = source;
		
		}
		else throw StackFullException();
	}	
	catch(StackFullException e) {
		std::cout << e.getMessage() << std::endl;
	}
}

