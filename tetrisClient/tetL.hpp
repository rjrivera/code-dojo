#ifndef TETL_HPP
#define TETL_HPP
#include <string>
#include <iostream>
#include "tetShape.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class tetL : public tetShape{

	private:
	
	public:
		//constructors
		tetL();
		tetL(double x_, double y_, const sf::Texture * blkText_);
		explicit tetL(double z_);
		tetL(const tetL& sauce);
		//destructor
		~tetL() override;	
		//operator overloading
		tetL operator - () const;
		
		tetL operator * (double factor) const;
		tetL operator + (const tetL& p) const;
		bool operator == (const tetL& p) const;
		tetL& operator = (const tetL& source);
		tetL& operator *= (double factor); 
		friend std::ostream& operator<< (std::ostream& os, const tetL& source);
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
		double Distance(const tetL& p) const; 

};

#endif
