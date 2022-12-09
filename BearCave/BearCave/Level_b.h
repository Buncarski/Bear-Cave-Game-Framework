#pragma once
#include "Level.h"
class Level_b : public Level
{
private:
	//Variables
	sf::CircleShape shape;
	void initShape();

	//Variable functions
	void initGameObjects() override;
public:
	//Constructor/destructor
	Level_b();
	virtual ~Level_b();


	//Functions
	void Update() override;
	void Render(sf::RenderTarget* target) override;
};

