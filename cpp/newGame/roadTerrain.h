#ifndef ROADTERRAIN_H
#define ROADTERRAIN_H


class roadTerrain : public baseTerrain{

	public:
		roadTerrain(); 	
		roadTerrain(const sf::Texture * image_);
		~roadTerrain();
		void print() override;
};


#endif
