#pragma once
#include "GameObject.h"

class Player: public GameObject
{
private:
	float movementSpeed;

	//Variable functions
	void initVariables();
	virtual void initTextures(std::string texturePath);
	virtual void initSprite(float xPos, float yPos);

public:
	//Constructors/Destructors
	Player();
	virtual ~Player();

	//Functions
	bool isAnyKeyPressed();
	const float getSpeed() const;
	virtual void updateInput();
	virtual void updatePosition();
	virtual void Update() override;
	virtual void Render(sf::RenderTarget* target) override;
};

