#ifndef PLANE_H
#define PLANE_H


class plane : public baseUnit{

	public:
		plane(); 	
		plane(const sf::Texture * image_);
		~plane();
		void print() override;
		void initMoveGrids(int32_t mvtRemaining, uint32_t curX, uint32_t curY) override;
};


#endif
