#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameObject.h"
#include <vector>

class Level
{
protected:
	//Variables
	std::vector<GameObject*> gameObjects; //Vector containing level objects
	sf::Event levelEv;

	//Variable functions
	virtual void initGameObjects() = 0;
public:
	//Constructor/destructor
	Level() = default;
	virtual ~Level() = default;

	//Functions
	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

