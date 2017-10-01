#ifndef MOVEGRID_H
#define MOVEGRID_H
#include"baseGFX.h"

class moveGrid : public baseGFX {

	public:
		moveGrid(); 	
//WARNING: the moveGrid object really needs to be made via factory simply because of the nature of asset distribution.
		moveGrid(const sf::Texture * image_, uint32_t initX, uint32_t initY);
		~moveGrid();
		void print() override;
};


#endif
