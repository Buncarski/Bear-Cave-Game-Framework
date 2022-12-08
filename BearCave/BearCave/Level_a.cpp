#include <iostream>
#include "Level_a.h"
#include "Square.h"
void Level_a::initGameObjects()
{
	this->gameObjects.push_back(new Square());
	 this->gameObjects.push_back(new Square("Textures/sample_texture.png", 40.f, 40.f));
}

Level_a::Level_a()
{
	this->initGameObjects();
}

Level_a::~Level_a()
{
	for (GameObject* go : gameObjects) {
		delete go;
	}
}

void Level_a::Update()
{
	for (GameObject* go : gameObjects) {
		go->Update();
	}
}

void Level_a::Render(sf::RenderTarget* target)
{
	for (GameObject* go : gameObjects) {
		go->Render(target);
	}
}
