#ifndef INFANTRY_H
#define INFANTRY_H


class infantry : public baseUnit{

	public:
		infantry(); 	
		infantry(const sf::Texture * image_);
		~infantry();
		void print() override;
		void initMoveGrids(uint32_t mvtRemaining) override;
		void defineGridSprite(const sf::Texture image);

};


#endif
