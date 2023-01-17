#include "Player.h"
#include <iostream>
void Player::initVariables()
{
	this->isGrounded = false;
	this->position.x = 200.f;
	this->position.y = 200.f;
	this->movementSpeed = 3.f;
	this->jumpHeight = 20.f;

	this->movementVector.x = 0.f;
	this->movementVector.y = 0.f;
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

const sf::Vector2f Player::getMovementVector() const
{
	return this->movementVector;
}

void Player::IsGrounded(bool groundedCheck)
{
	if (groundedCheck) {
		this->isGrounded = true;
	}
	else {
		this->isGrounded = false;
	}
}

void Player::resetMovementVectorY()
{
	movementVector.y = 0.f;
}

void Player::ApplyGravity()
{
	this->movementVector.y += 1.f;
}

void Player::updateInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		this->position.x += this->movementSpeed * -1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		this->position.x += this->movementSpeed * 1.f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && isGrounded) {
		movementVector.y -= jumpHeight;
	}
}

void Player::updatePosition()
{
	this->position.y += movementVector.y;
	this->sprite.setPosition(this->position.x, this->position.y);
}

void Player::Update()
{
	this->ApplyGravity();
	std::cout << this->movementVector.y << "\n";
	this->updateInput();
	this->updatePosition();
}

void Player::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
