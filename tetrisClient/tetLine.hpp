#ifndef TETLINE_HPP
#define TETLINE_HPP
#include <string>
#include <iostream>
#include "tetShape.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class tetLine : public tetShape{

	private:
	
	public:
		//constructors
		tetLine();
		tetLine(double x_, double y_, const sf::Texture * blkText_);
		explicit tetLine(double z_);
		tetLine(const tetLine& sauce);
		//destructor
		~tetLine() override;	
		//operator overloading
		tetLine operator - () const;
		
		tetLine operator * (double factor) const;
		tetLine operator + (const tetLine& p) const;
		bool operator == (const tetLine& p) const;
		tetLine& operator = (const tetLine& source);
		tetLine& operator *= (double factor); 
		friend std::ostream& operator<< (std::ostream& os, const tetLine& source);
		//selectors
		double X() const override;
		double Y() const override;
		bool rBoundCheck(double x_) const;
				

		void Draw() override;
		
		//mutators
		void X(double x_);
		void Y(double y_);
		void move(double x_, double y_) override;
		//calculate the distance between the instance and the origin/argument, respectively.
		double Distance() const;
		double Distance(const tetLine& p) const; 

};

#endif
