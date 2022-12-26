#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class GameObject
{
protected:
	//Variables
	std::map<std::string, sf::Texture*> textures;
	sf::Sprite sprite;
	sf::Vector2f position;

public:
	//Constructor/destructor
	GameObject() = default;
	virtual ~GameObject() = default;

	//Getter functions
	sf::FloatRect getBounds() {
		return this->sprite.getGlobalBounds();
	}

	sf::Vector2f Center() {
		sf::Vector2f centerPos(this->sprite.getGlobalBounds().left + (this->sprite.getGlobalBounds().width / 2), 
			this->sprite.getGlobalBounds().top + (this->sprite.getGlobalBounds().height / 2));
	}

	virtual void SetPosition(sf::Vector2f vector) {
		this->position.x = vector.x;
		this->position.y = vector.y;
		sprite.setPosition(position);
	};

	virtual void SetPosition(const float x, const float y) {
		this->position.x = x;
		this->position.y = y;
		sprite.setPosition(position);
	};

	//Functions
	virtual void SetScale(float sX, float sY) {
		this->sprite.setScale(sX, sY);
	};

	virtual void Update() = 0;
	virtual void Render(sf::RenderTarget* target) = 0;
};

