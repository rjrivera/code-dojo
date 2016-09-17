#ifndef POINT_HPP
#define POINT_Hpp
class Point{

	private:
		int x,y;
	
	public:	 
		//constructors
		Point();
		Point(int x_, int y_);
		
		//selectors
		int getX();
		int getY();
		std::string ToString();	
	
		//mutators
		int setX(int x_);
		int setY(int y_);

};
#endif
