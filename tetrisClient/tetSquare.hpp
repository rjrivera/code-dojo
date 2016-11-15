#ifndef TETSQUARE_HPP
#define TETSQUARE_HPP
#include<string>
#include<iostream>
#include "tetShape.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class tetSquare : public tetShape{

	private:
		//std::vector<sf::Sprite> mySprites;		
	public:
	//	std::vector<sf::Sprite> mySprites;			
		//constructors
		tetSquare();
		tetSquare(double x_, double y_, const sf::Texture * blkText_); // you want a pass-by reference asper best practices. 
		explicit tetSquare(double z_);
		tetSquare(const tetSquare& sauce);
		//destructor
		~tetSquare() override;	
		//operator overloading
		tetSquare operator - () const;
		
		tetSquare operator * (double factor) const;
		tetSquare operator + (const tetSquare& p) const;
		bool operator == (const tetSquare& p) const;
		tetSquare& operator = (const tetSquare& source);
		tetSquare& operator *= (double factor); 
		friend std::ostream& operator<< (std::ostream& os, const tetSquare& source);
		//selectors
		double X() const override;
		double Y() const override;
		bool rBoundCheck(double x_) const override;
		bool lBoundCheck(double x_) const override;
		bool floorBoundCheck(std::vector<double>& y_) const override;
		
		void Draw() override;
		
		//mutators
		void X(double x_);
		void Y(double y_);
		void move(double x_, double y_) override;
		//calculate the distance between the instance and the origin/argument, respectively.
		double Distance() const;
		double Distance(const tetSquare& p) const; 

};

#endif
