#pragma once
#include "Level.h"
class Level_a : virtual public Level
{
private:

	//variable functions
	void initGameObjects() override;

public:
	//Constructor/destructor
	Level_a();
	virtual ~Level_a();


	//Functions
	void Update() override;
	void Render(sf::RenderTarget* target) override;
};

