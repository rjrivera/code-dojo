#ifndef PLAINTERRAIN_H
#define PLAINTERRAIN_H


class plainTerrain : public baseTerrain{

	public:
		plainTerrain(); 	
		plainTerrain(const sf::Texture * image_, const sf::Texture * hlImage_);
		plainTerrain(const sf::Texture * image_, const sf::Texture * hlImage_, const sf::Texture * terrainInfo_);
		~plainTerrain();
		void print() override;
};


#endif
