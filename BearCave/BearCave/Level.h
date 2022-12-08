#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Level
{
	//Base level class
public:
	Level() = default;
	Level(Level const&) = default;
	virtual ~Level() = default;

	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

