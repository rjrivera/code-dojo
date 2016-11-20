#ifndef POINTARRAY_HPP
#define POINTARRAY_HPP
#include <iostream>
#include <string>
#include "ArrayException.hpp"
#include "OutOfBoundsException.hpp"
#include "UniqueSizeException.hpp"
#include "Array.hpp"
/*
	RELEASE NOTES v4-4b-1

	Template Point Array class 
*/

template<class Point> 
class PointArray : public Array<Point> {

	public:
		//constructors and destructors. 
		PointArray();
		PointArray(int size_);
		PointArray(const PointArray<Point>& source_);
		~PointArray();
		
		// accessor methods. 
		
		//int Size() const;
		
		Point GetElement(int index_) const;	
		int DefaultSize() const;
		double Length() const;
		// operator overloads
		PointArray& operator* (int index_);
		PointArray& operator+ (PointArray<Point>& index_);
		
		void DefaultSize(int index_);

};
#endif

