#include <iostream>
#include "Level_a.h"
#include "Square.h"
#include "Player.h"

//Variable functions
void Level_a::initGameObjects()
{
	this->gameObjects.push_back(new Square());
	this->gameObjects.push_back(new Square("Textures/sample_texture.png", 0.f, 540.f));
	this->gameObjects.back()->SetScale(40.f, 2.f);
	this->gameObjects.push_back(new Player());
}

//Constructor/destructor
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

//Functions
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
