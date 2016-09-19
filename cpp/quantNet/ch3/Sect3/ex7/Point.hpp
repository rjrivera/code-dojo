#ifndef POINT_HPP
#define POINT_HPP
class Point{

	private:
		double x,y;
	
	public:	 
		//constructors
		Point();
		Point(double x_, double y_);
		Point(const Point& sauce);
		//destructor
		~Point();	
		//selectors
		double X() const { return x; }
		double Y() const { return y; }
		std::string ToString() const;	
	
		//mutators
		void X(double x_); 
		void Y(double y_); 

		//calculate the distance between the instance and the origin/argument, respectively.
		double Distance() const;
		double Distance(const Point& p) const; 

};

inline void Point::X(double x_) {
	x = x_;
}

inline void Point::Y(double y_) {
	y = y_;
}

#endif
