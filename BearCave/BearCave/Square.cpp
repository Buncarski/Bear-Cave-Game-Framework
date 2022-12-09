#include "Square.h"
#include <iostream>

//Variable functions

void Square::initVariables()
{
	this->currentTexture = 0.f;
	this->timerMax = 60.f;
	this->timer = 0.f;
}


void Square::initTextures(std::string texturePath)
{
	//Load a texture from file
	this->textures["SQUARE0"] = new sf::Texture();
	this->textures["SQUARE0"]->loadFromFile("Textures/sample_texture.png");
	this->textures["SQUARE1"] = new sf::Texture();
	this->textures["SQUARE1"]->loadFromFile("Textures/sample_texture_mirrored.png");
}

void Square::initSprite(float xPos, float yPos)
{
	this->sprite.setTexture(*this->textures["SQUARE0"]);
	this->sprite.setPosition(xPos, yPos);
}

//Constructors/destructor

Square::Square()
{
	this->initVariables();
	this->initTextures("Textures/sample_texture.png");
	this->initSprite(0.f, 0.f);
}

Square::Square(std::string texturePath, float xPos, float yPos)
{
	this->initVariables();
	this->initTextures(texturePath);
	this->initSprite(xPos, yPos);
}

Square::~Square()
{
	for (auto& i : this->textures) {
		delete i.second;
	}
}

//Functions

void Square::setTexture(std::string textureKey)
{
	this->sprite.setTexture(*this->textures[textureKey]);
}

/*
	Update: Currently used as a rough way to set up dynamic texture swapping
		-temporary use
		-TODO: Animator/Animation class
*/

void Square::Update()
{
	if (this->timer >= this->timerMax) {
		if (this->currentTexture == 0) {
			this->setTexture("SQUARE1");
			this->currentTexture = 1;
		}
		else {
			this->setTexture("SQUARE0");
			this->currentTexture = 0;
		}
		this->timer = 0.f;
	}

	this->timer++;
}

void Square::Render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}
