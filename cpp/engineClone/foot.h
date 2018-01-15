#ifndef FOOT_H
#define FOOT_H
#include "projectile.h"

class foot : public baseUnit{

	public:
		foot(); 	
		foot(std::vector<const sf::Texture *>& images_);
		~foot();
		void print() override;
		void updateTiming(std::chrono::milliseconds deltaTime) override;
		void updateBehavior() override;
		void updateDefHitBox() override;
		void updateOffHitBox() override;
		void inputHandling() override;
		void fireProjectile( projectile * proj ) override;
		void hbCheck( std::vector< baseUnit * > * enemies) override;

//	private:
		bool getCooldown() override;
		bool burnCooldown() override;

};


#endif
