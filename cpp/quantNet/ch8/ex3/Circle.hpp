#ifndef CIRCLE_HPP
#define CIRLCE_HPP
#include <iostream>
#include "Point.hpp"
#include "Shape.hpp"
/*
	RELEASE NOTES v3-5-2
	
	ToString() amended to override base shape function

*/
class Circle : public Shape{ 

	private:
		Point center;
		double m_radius; //radius value must be >0
	

	public:
		Circle();
		Circle(Point center_, double rad_);
		~Circle() override;
		Circle(const Circle& source);

		Circle& operator= (const Circle& source);
		friend std::ostream& operator<< (std::ostream& os, const Circle& source);
		// view methods
		double Diameter() const;
		double Area() const;
		double Circumference() const;
		std::string ToString() const override;
		Point CentrePoint() const;
		double Radius() const;
		void Draw() override;

		// improving class by adding this compare function. 
		bool operator== (const Circle& source) const;

		// modifiers
		// choosing a diameter vice rad method to take advantage of overloading. 
		void Diameter(double diam_); 
		void Radius(double rad_);
		void CentrePoint(Point center_); 
		void Print() const override;
};

#endif
