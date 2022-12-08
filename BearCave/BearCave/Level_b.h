#pragma once
#include "Level.h"
class Level_b : public Level
{
private:
	sf::CircleShape shape;
	void initShape();
public:
	Level_b();
	virtual ~Level_b();

	void Update() override;
	void Render(sf::RenderTarget* target) override;
};

