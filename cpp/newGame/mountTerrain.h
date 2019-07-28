#ifndef MOUNTTERRAIN_H
#define MOUNTTERRAIN_H


class mountTerrain : public baseTerrain{

	public:
		mountTerrain(); 	
		mountTerrain(const sf::Texture * image_, const sf::Texture * hlImage_);
		mountTerrain(const sf::Texture * image_, const sf::Texture * hlImage_, const sf::Texture * terrainInfo_);
		~mountTerrain();
		void print() override;
};


#endif
