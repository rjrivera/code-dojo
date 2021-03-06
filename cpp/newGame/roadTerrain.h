#ifndef ROADTERRAIN_H
#define ROADTERRAIN_H


class roadTerrain : public baseTerrain{

	public:
		roadTerrain(); 	
		roadTerrain(const sf::Texture * image_, const sf::Texture * hlImage_);
		roadTerrain(const sf::Texture * image_, const sf::Texture * hlImage_, const sf::Texture * terrainInfo_);
		~roadTerrain();
		void print() override;
};


#endif
