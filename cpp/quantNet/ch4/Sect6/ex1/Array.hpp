#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Point.hpp"

namespace RobRivera {

	namespace Containers {

class Array{

	private:
		CAD::Point * m_data;
		int m_length;
	public:
		//constructors and destructors. 
		Array();
		Array(int size_);
		Array(const Array& source_);
		~Array();
		
		// accessor methods. 
		//CAD::Point point(int pos_); obsolete - GetElement
		int Size() const;
		CAD::Point * arr() const;
		CAD::Point GetElement(int index_) const;	
		// operator overloads
		Array& operator=(const Array& source_);
		const CAD::Point& operator[](int index_);

		// setters
		void SetElement(int index_, CAD::Point * target_);
};

	};
};
#endif
