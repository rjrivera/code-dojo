#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Point.hpp"
class Array{

	private:
		Point * m_data;
		int m_length;
	public:
		Array();
		Array(int size_);
		Array(const Array& source_);
		~Array();
		
		Point point(int pos_);
		int length() const;
		Point * arr() const;
		Array& operator=(const Array& source_);

};
#endif
