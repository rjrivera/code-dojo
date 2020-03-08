#ifndef BARRACKSTERRAIN_H
#define BARRACKSTERRAIN_H


class barracksTerrain : public baseTerrain{

	public:
		barracksTerrain(); 	
		barracksTerrain(const sf::Texture * image_, const sf::Texture * hlImage_);
		barracksTerrain(const sf::Texture * image_, const sf::Texture * hlImage_, const sf::Texture * terrainInfo_);
		~barracksTerrain();
		void print() override;
};


#endif
