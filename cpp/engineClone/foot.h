#ifndef FOOT_H
#define FOOT_H


class foot : public baseUnit{

	public:
		foot(); 	
		foot(std::vector<const sf::Texture *>& images_);
		~foot();
		void print() override;
		void updateTiming(std::chrono::milliseconds deltaTime) override;
		void inputHandling() override;
//	private:
		bool getCooldown() override;
		bool burnCooldown() override;

};


#endif
