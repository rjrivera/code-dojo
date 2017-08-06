#ifndef INFANTRY_H
#define INFANTRY_H


class infantry : public baseUnit{

	public:
		infantry(); 	
		infantry(const sf::Texture * image_);
		~infantry();
		void print() override;
};


#endif
