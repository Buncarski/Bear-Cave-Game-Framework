#include "Level_b.h"

//Variable functions

void Level_b::initShape()
{
	this->shape.setRadius(10.f);
	this->shape.setFillColor(sf::Color::Red);
}

void Level_b::initGameObjects()
{

}

//Constructor/destructor

Level_b::Level_b()
{
	this->initShape();
}

Level_b::~Level_b()
{

}

//Functions

void Level_b::Update()
{

}

void Level_b::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
