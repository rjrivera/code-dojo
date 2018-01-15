#ifndef DON_H
#define DON_H


class don : public baseUnit{

	public:
		don(); 	
		don(std::vector<const sf::Texture *>& images_);
		~don();
		void print() override;
		void updateTiming(std::chrono::milliseconds deltaTime) override;
		void updateOffHitBox() override;
		void updateDefHitBox() override;
		void inputHandling() override;
		void fireProjectile( projectile * proj ) override;
		void hbCheck( std::vector<  baseUnit *> * enemies ) override;

//	private:
		bool getCooldown() override;
		bool burnCooldown() override;

};


#endif
