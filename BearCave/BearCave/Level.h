#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "GameObject.h"
#include <vector>

class Level
{
protected:
	std::vector<GameObject*> gameObjects;

	virtual void initGameObjects() = 0;
public:
	Level() = default;
	virtual ~Level() = default;

	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

