#ifndef POINT_HPP
#define POINT_Hpp
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
		double getX();
		double getY();
		std::string ToString();	
	
		//mutators
		void setX(double x_);
		void setY(double y_);

		//calculate the distance between the instance and the origin/argument, respectively.
		double DistanceOrigin();
		double Distance(Point& p); 

};
#endif
