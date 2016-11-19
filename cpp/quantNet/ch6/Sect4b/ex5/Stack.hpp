#ifndef STACK_HPP
#define STACK_HPP

#include <string>
#include <iostream>
#include "Array.hpp"


template <class T>
class Stack {

	protected:
		Array<T> m_data;
		int size;
		int capacity;
		
	public:
		Stack();
		Stack(int size_);
		Stack(const Stack<T>& source);
		~Stack();
		T pop();
		T front() const;
		void push(T source);

};
#endif
