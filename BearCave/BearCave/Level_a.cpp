#include <iostream>
#include "Level_a.h"
#include "Square.h"
#include "Player.h"

//Variable functions
void Level_a::initGameObjects()
{
	//this->gameObjects.push_back(new Square());
	this->gameObjects.push_back(new Square("Textures/sample_texture.png", 200.f, 300.f));
	this->gameObjects.back()->SetScale(2.f, 2.f);
	this->player = new Player();
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

void Level_a::UpdateObjectCollisions() //INTERGRATE THIS INTO UPDATE THERE IS NO NEED FOR DOUBLE LOOP HERE
{
	for (GameObject* go : gameObjects) {
		if (go->getBounds().intersects(player->getBounds())) {
			//Bottom object collision
			if (this->player->getBounds().top + this->player->getBounds().height > go->getBounds().top
				&& this->player->getBounds().top + this->player->getBounds().height < go->getBounds().top + (this->player->getSpeed()*2.f)) {
				std::cout << "bottom collision." << "\n";
				this->player->SetPosition(player->getBounds().left,
					go->getBounds().top - player->getBounds().height);
			}

			//Top object collsion
			if (go->getBounds().top + go->getBounds().height > this->player->getBounds().top
				&& this->player->getBounds().top > go->getBounds().top + go->getBounds().height - (this->player->getSpeed() * 2.f)) {
				std::cout << "your mom" << "\n";
				this->player->SetPosition(player->getBounds().left,
					go->getBounds().top + go->getBounds().height);
			}

			//Left object collision
			if (this->player->getBounds().left + this->player->getBounds().width > go->getBounds().left
				&& this->player->getBounds().left + this->player->getBounds().width < go->getBounds().left + (this->player->getSpeed() * 2.f)) {
				std::cout << "left collision" << "\n";
				this->player->SetPosition(go->getBounds().left - this->player->getBounds().width,
					this->player->getBounds().top);
			}

			//Right object collision
			if (this->player->getBounds().left < go->getBounds().left + go->getBounds().width
				&& this->player->getBounds().left > go->getBounds().left + go->getBounds().width - (2.f * this->player->getSpeed())) {
				std::cout << "right collision" << "\n";
				this->player->SetPosition(go->getBounds().left + go->getBounds().width,
					this->player->getBounds().top);
			}
		}
	}
}

//Functions
void Level_a::Update()
{
	this->player->Update();
	this->UpdateObjectCollisions();
	for (GameObject* go : gameObjects) {
		go->Update();
	}
}

void Level_a::Render(sf::RenderTarget* target)
{
	for (GameObject* go : gameObjects) {
		go->Render(target);
	}

	this->player->Render(target);
}
