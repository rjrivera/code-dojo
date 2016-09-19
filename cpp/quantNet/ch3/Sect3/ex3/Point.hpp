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
		double X();
		double Y();
		std::string ToString();	
	
		//mutators
		void X(double x_);
		void Y(double y_);

		//calculate the distance between the instance and the origin/argument, respectively.
		double Distance();
		double Distance(const Point& p); 

};
#endif
