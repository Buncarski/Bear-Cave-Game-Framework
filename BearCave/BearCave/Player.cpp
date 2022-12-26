#include "Player.h"
#include <iostream>
void Player::initVariables()
{
	this->position.x = 200.f;
	this->position.y = 200.f;
	this->movementSpeed = 3.f;
}

void Player::initTextures(std::string texturePath)
{
	this->textures["DEFAULT"] = new sf::Texture();
	this->textures["DEFAULT"]->loadFromFile(texturePath);
}

void Player::initSprite(float xPos, float yPos)
{
	this->sprite.setTexture(*this->textures["DEFAULT"]);
	this->sprite.setPosition(xPos, yPos);
}

//Constructors/Destructors
Player::Player()
{
	this->initVariables();
	this->initTextures("Textures/player_sprite.jpg");
	this->initSprite(this->position.x, this->position.y);
}

Player::~Player()
{
}


//Functions

bool Player::isAnyKeyPressed()
{
	for (int k = -1; k < sf::Keyboard::KeyCount; ++k)
	{
		if (sf::Keyboard::isKeyPressed(static_cast<sf::Keyboard::Key>(k)))
			return true;
	}
	return false;
}

const float Player::getSpeed() const
{
	return this->movementSpeed;
}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->position.x += this->movementSpeed * -1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->position.x += this->movementSpeed * 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->position.y += this->movementSpeed * -1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->position.y += this->movementSpeed * 1.f;
}

void Player::updatePosition()
{
	this->sprite.setPosition(this->position.x, this->position.y);
}

void Player::Update()
{
	std::cout << "X: " << this->position.x << "\n";
	this->updateInput();
	this->updatePosition();
}

void Player::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
