#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class GameObject
{
protected:
	std::map<std::string, sf::Texture*> textures;
	sf::Sprite sprite;
public:
	GameObject() = default;
	virtual ~GameObject() = default;

	//Functions
	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

