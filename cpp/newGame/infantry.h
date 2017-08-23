#ifndef INFANTRY_H
#define INFANTRY_H


class infantry : public baseUnit{

	public:
		infantry(); 	
		infantry(const sf::Texture * image_);
		~infantry();
		void print() override;
		void initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY) override;
		void defineGridSprite(const sf::Texture * image);

};


#endif
