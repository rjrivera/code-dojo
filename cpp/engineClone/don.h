#ifndef DON_H
#define DON_H


class don : public baseUnit{

	public:
		don(); 	
		don(std::vector<const sf::Texture *>& images_);
		~don();
		void print() override;
		void updateTiming(std::chrono::milliseconds deltaTime) override;
		void updateHitBox() override;
		void inputHandling() override;
//	private:
		bool getCooldown() override;
		bool burnCooldown() override;

};


#endif
