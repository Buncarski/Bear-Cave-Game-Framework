#include "Player.h"

void Player::initVariables()
{
	this->x = 200.f;
	this->y = 200.f;
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
	this->initSprite(this->x, this->y);
}

Player::~Player()
{
}


//Functions

void Player::updateInput()
{
	
}

void Player::updatePosition()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->sprite.move(this->movementSpeed * -1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		this->sprite.move(0.f, this->movementSpeed * -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		this->sprite.move(0.f, this->movementSpeed * 1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->sprite.move(this->movementSpeed * 1.f, 0.f);
}

void Player::Update()
{
	this->updatePosition();
}

void Player::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
