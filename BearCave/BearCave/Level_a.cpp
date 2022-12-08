#include "Level_a.h"

void Level_a::initShape()
{
	this->shape.setRadius(10.f);
	this->shape.setFillColor(sf::Color::Green);
}

Level_a::Level_a()
{
	this->initShape();
}

Level_a::~Level_a()
{

}

void Level_a::Update()
{

}

void Level_a::Render(sf::RenderTarget* target)
{
	target->draw(this->shape);
}
