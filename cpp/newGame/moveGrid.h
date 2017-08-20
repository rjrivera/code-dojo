#ifndef MOVEGRID_H
#define MOVEGRID_H
#include"baseGFX.h"

class moveGrid : public baseGFX {

	public:
		moveGrid(); 	
		moveGrid(const sf::Texture * image_, uint32_t initX, uint32_t initY);
		~moveGrid();
		void print() override;
};


#endif
