#include "hitBox.h"


/* Repurposed version of BCKTERRAIN_H 
 *
 */
hitBox::hitBox() 	{
	// NOP
	tL = new Point();
	bR = new Point();
}

hitBox::hitBox(Point& tL_, Point& bR_) {
	*tL = tL_;
	*bR = bR_;
}

hitBox::hitBox(Point * tL_, Point * bR_) {
 	tL = tL_;
	bR = bR_;
}


hitBox::~hitBox(){ 
	// I should probably begin defining delete functionslol 
	delete tL;
	delete bR;
}

void hitBox::updateTiming(std::chrono::milliseconds deltaTime) {
	ttlTimer += deltaTime;

}

void hitBox::setTTL(std::chrono::milliseconds ttlTrigger_) {
	ttlTrigger = ttlTrigger_;
}

void hitBox::velX(double x_) {
	tL->X(x_ + tL->X());
	bR->X(x_ + bR->X());
}

void hitBox::velY(double y_) {
	tL->Y(y_ + tL->Y());
	bR->Y(y_ + bR->Y());
}

bool hitBox::intersect(hitBox& target_){
	std::cout << "Checking intersection of two hitboxes\n";
	if (tL->Y() <= target_.tL->Y() && bR->Y() >target_.tL->Y() &&
		tL->X() >= target_.tL->X() && tL->X() < target_.bR->X()  ) 
		return true;

	return false;
}


