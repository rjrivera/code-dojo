#ifndef TANK_H
#define TANK_H


class tank : public baseUnit{

	public:
		tank(); 	
		tank(const sf::Texture * image_, uint32_t player_);
		~tank();
		void print() override;
	//	void initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY) override;
};


#endif
