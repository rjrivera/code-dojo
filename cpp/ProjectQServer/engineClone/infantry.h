#ifndef INFANTRY_H
#define INFANTRY_H


class infantry : public baseUnit{

	public:
		infantry(); 	
		infantry(const sf::Texture * image_, uint32_t player_);
		~infantry();
		void print() override;
//		void initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY) override;
};


#endif
