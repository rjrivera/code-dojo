#ifndef TETSHAPE_HPP
#define TETSHAPE_HPP
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
/*
	RELEASE NOTES v0.1
	
	Parent Class used to base other shapes off of. 
*/

class tetShape{

	protected:
		double m_id;
		int pos, maxPos;		
		bool onFloor_;
		std::vector<sf::Sprite> mySprites;

	public:

	//	std::vector<sf::Sprite> mySprites;
	//	std::vector<int> myInts;
		double x, y;
		tetShape();
		tetShape(double x_, double y_);
		virtual ~tetShape();
		tetShape(const tetShape& source_);
		tetShape& operator= (const tetShape& source_);
		// view methods
		double ID() const;
		virtual double X() const;
		virtual double Y() const;
		virtual bool onFloor() const = 0;
		// improving class by adding this compare function
		bool operator== (const tetShape& source_) const;
		virtual bool rBoundCheck(double x_, std::vector<std::vector<bool>>& grid) const;
		virtual bool lBoundCheck(double x_, std::vector<std::vector<bool>>& grid) const;
		virtual bool floorBoundCheck(std::vector<std::vector<bool>>& y_) const;
		virtual void amendGrid(std::vector<std::vector<bool>>& grid) const;
		virtual void Draw();		
		virtual void onFloor(bool val);
		virtual std::vector<sf::Sprite>& getSprites();
		// modifiers
		// choosing a diameter vice rad method to take advantage of overloading. 
		void ID(double target_); 
		virtual void move(double x_, double y_);

};

#endif
