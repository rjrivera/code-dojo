#ifndef WATERTERRAIN_H
#define WATERTERRAIN_H


class waterTerrain : public baseTerrain{

	public:
		waterTerrain(); 	
		waterTerrain(const sf::Texture * image_, const sf::Texture * hlImage_);
		waterTerrain(const sf::Texture * image_, const sf::Texture * hlImage_, const sf::Texture * terrainInfo_);
		~waterTerrain();
		void print() override;
};


#endif
