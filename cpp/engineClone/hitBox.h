#ifndef HITBOX_H
#define HITBOX_H
#include "Point.h"


/* Repurposed version of BCKTERRAIN_H 
 *
 */
class hitBox {

	public:
		Point * tL;
		Point * bR;
		std::chrono::milliseconds ttlTimer, ttlTrigger;	
		hitBox(); 	
		hitBox(Point& tL_, Point& bR_);
		~hitBox();
		void updateTiming(std::chrono::milliseconds deltaTime);
		void setTTL(std::chrono::milliseconds ttlTrigger_);
		void velX(double x_);
		void velY(double y_);
		bool intersect(hitBox& target_);
		
};


#endif
