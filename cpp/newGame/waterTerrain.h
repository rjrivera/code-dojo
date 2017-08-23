#ifndef WATERTERRAIN_H
#define WATERTERRAIN_H


class waterTerrain : public baseTerrain{

	public:
		waterTerrain(); 	
		waterTerrain(const sf::Texture * image_);
		~waterTerrain();
		void print() override;
};


#endif
