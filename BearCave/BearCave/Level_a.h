#pragma once
#include "Level.h"
#include "Player.h"
class Level_a : virtual public Level
{
private:

	Player* player;
	//variable functions
	void initGameObjects() override;

public:
	//Constructor/destructor
	Level_a();
	virtual ~Level_a();


	//Functions
	void UpdateObjectCollisions() override;
	void Update() override;
	void Render(sf::RenderTarget* target) override;
};

