#ifndef GAME_H
#define GAME_H
#include<vector>

class Game {
private:

	void foo(std::vector<sf::Texture *>& text_container, std::string textType_);
	baseUnit * unitBuilder(std::vector<sf::Texture*>& unitTexts_, uint32_t unit_); 
	projectile * projBuilder(std::vector<sf::Texture*>& projTexts_, uint32_t unit_); 
	bckTerrain * worldBuilder(std::vector<sf::Texture*>& worldTexts_, uint32_t bkg_, Point tL_, Point bR_); 
	void activateEnemies(std::vector<baseUnit *> * enemies_, bckTerrain * curTerrain_);  
	void updateStage(std::vector<baseUnit *>&  enemies_, std::vector<bckTerrain *>& terrain_, baseUnit * don_);

public:
	Game(); 
	~Game(); 
	void iterateGameLoop();	
};
#endif
