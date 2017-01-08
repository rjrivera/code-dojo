#ifndef TETL_HPP
#define TETL_HPP
#include <string>
#include <iostream>
#include "tetShape.hpp"
#include <SFML/Graphics.hpp>
#include <vector>

class tetL : public tetShape{

	protected:
		virtual bool morphCheck(std::vector<std::vector<bool>>& grid) override; 

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
		bool rBoundCheck(double x_,std::vector<std::vector<bool>>& grid) const override;
		bool lBoundCheck(double x_, std::vector<std::vector<bool>>& grid) const override;
		bool floorBoundCheck(std::vector<std::vector<bool>>& y_) const override;
		void amendGrid(std::vector<std::vector<bool>>& grid) const override;
		virtual void morph(std::vector<std::vector<bool>>& grid) override;
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
		double Distance(const tetL& p) const; 

};

#endif
