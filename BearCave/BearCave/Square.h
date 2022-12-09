#pragma once
#include "GameObject.h"
#include <string>

class Square : virtual public GameObject
{
	//Variables

	//Variables - Texture change variables
	float currentTexture;
	float timerMax;
	float timer;

	//Init functions
	void initVariables();
	virtual void initTextures(std::string texturePath);
	virtual void initSprite(float xPos, float yPos);
public:
	//Constructors/destructor
	Square();
	Square(std::string texturePath, float xPos, float yPos);
	virtual ~Square();

	//Functions
	void setTexture(std::string textureKey);
	virtual void Update() override;
	virtual void Render(sf::RenderTarget * target) override;
};

