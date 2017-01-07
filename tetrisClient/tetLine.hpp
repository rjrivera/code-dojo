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
		bool rBoundCheck(double x_, std::vector<std::vector<bool>>& grid) const override;
		bool lBoundCheck(double x_, std::vector<std::vector<bool>>& grid) const override;
		bool floorBoundCheck(std::vector<std::vector<bool>>& y_) const override;
		void amendGrid(std::vector<std::vector<bool>>& grid) const override;
		bool onFloor() const override;
		virtual std::vector<sf::Sprite>& getSprites() override;


		void Draw() override;
		
		//mutators
		void X(double x_);
		void Y(double y_);
		void move(double x_, double y_) override;
		void onFloor(bool val) override;
		//calculate the distance between the instance and the origin/argument, respectively.
		double Distance() const;
		double Distance(const tetLine& p) const; 

};

#endif
