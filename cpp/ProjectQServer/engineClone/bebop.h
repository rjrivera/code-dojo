#ifndef BEBOP_H
#define BEBOP_H
#include "projectile.h"

class bebop : public baseUnit{

	public:
		bebop(); 	
		bebop(std::vector<const sf::Texture *>& images_);
		~bebop();
		void print() override;
		void updateTiming(std::chrono::milliseconds deltaTime) override;
		void updateBehavior() override;
		void updateDefHitBox() override;
		void updateOffHitBox() override;
		void inputHandling() override;
		void fireProjectile( projectile * proj ) override;
		void hbCheck( std::vector< baseUnit * > * enemies) override;
		void toPlayerDef();

//	private:
		bool getCooldown() override;
		bool burnCooldown() override;

};


#endif
