#include <string>
#include <iostream>
#include "Stack.hpp"
#include "StackFullException.hpp"
#include "StackEmptyException.hpp"

/*	RELEASE NOTES v.4-4b-6
 *
 *	Templated Stack class Amended to permit the userdefined storage capacity as a template parameter. 
 *
 * protected members
Array<T> m_data;
int size;
int capacity;
*/		
	
/*	Default Constructor
 *
 * */
template <class T, int capacity_>
Stack<T, capacity_>::Stack() : m_data(capacity_){
	//defaults to the default size of the array<T> class. 
	capacity = capacity_;
	size = -1; //empty data set
}
/*	copy constructor 
 *
 */
template <class T, int capacity_>
Stack<T, capacity_>::Stack(const Stack<T, capacity_>& source) {
	
	m_data = source.m_data;
	size = source.size;
	capacity = source.capacity;

}

/*
 * Destructor
 */
template <class T, int capacity_>
Stack<T, capacity_>::~Stack() {

}

/*
 * Mutator, pop's off the most recently pushed value 
 */
template <class T, int capacity_>
T Stack<T, capacity_>::pop() {

	if (size >= 0 ) {
		T temp = m_data[size];
		size--;
		return temp;
	}
	else throw StackEmptyException();
}

/*
 * returns the value at the most recently used value. 
 */
template <class T, int capacity_>
T Stack<T, capacity_>::front() const {
	return m_data[size];
}

/*
 * Mutator - pushes a value of type T to the next position of storage, if capacity permits. 
 */
template <class T, int capacity_>
void Stack<T, capacity_>::push(T source) {
	if (size<capacity-1)  {
		size++;
		m_data[size] = source;
	
	}
	else throw StackFullException();
}

