#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class GameObject
{
protected:
	//Variables
	std::map<std::string, sf::Texture*> textures;
	sf::Sprite sprite;
public:
	//Constructor/destructor
	GameObject() = default;
	virtual ~GameObject() = default;

	//Functions
	virtual void SetScale(float sX, float sY) {
		this->sprite.setScale(sX, sY);
	};

	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

