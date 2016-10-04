#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>

/*
	RELEASE NOTES v3-5-1
	
	Amended ToString() function to be virtual
*/

class Shape{

	protected:
		double m_id;

	public:
		Shape();
		virtual ~Shape();
		Shape(const Shape& source_);
		Shape& operator= (const Shape& source_);
		// view methods
		virtual std::string ToString() const;
		double ID() const;

		// improving class by adding this compare function
		bool operator== (const Shape& source_) const;

		// modifiers
		// choosing a diameter vice rad method to take advantage of overloading. 
		void ID(double target_); 

};

#endif
