#pragma once
#include "Level.h"
class Level_a : virtual public Level
{
private:
	sf::CircleShape shape;
	void initShape();
public:
	Level_a();
	virtual ~Level_a();

	void Update() override;
	void Render(sf::RenderTarget* target) override;


};

