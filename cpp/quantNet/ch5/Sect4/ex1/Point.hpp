#ifndef POINT_HPP
#define POINT_HPP
#include<string>
#include<iostream>
class Point{

	private:
		double x,y;
	
	public:	 
		//constructors
		Point();
		Point(double x_, double y_);
		explicit Point(double z_);
		Point(const Point& sauce);
		//destructor
		~Point();	
		//operator overloading
		Point operator - () const;
		
		Point operator * (double factor) const;
		Point operator + (const Point& p) const;
		bool operator == (const Point& p) const;
		Point& operator = (const Point& sourc);
		Point& operator *= (double factor); 
		friend std::ostream& operator<< (std::ostream& os, const Point& source);
		//selectors
		double X() const;
		double Y() const;
		std::string ToString() const;	
	
		//mutators
		void X(double x_);
		void Y(double y_);

		//calculate the distance between the instance and the origin/argument, respectively.
		double Distance() const;
		double Distance(const Point& p) const; 

};

#endif
