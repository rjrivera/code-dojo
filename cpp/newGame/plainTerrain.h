#ifndef PLAINTERRAIN_H
#define PLAINTERRAIN_H


class plainTerrain : public baseTerrain{

	public:
		plainTerrain(); 	
		plainTerrain(const sf::Texture * image_);
		~plainTerrain();
		void print() override;
};


#endif
