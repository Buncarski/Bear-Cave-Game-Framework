#include "Game.h"
#include <iostream>

//Variable functions
void Game::initWindow()
{
	this->gameWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Bear cave", sf::Style::Close | sf::Style::Titlebar);
	this->gameWindow->setFramerateLimit(60);
	this->gameWindow->setVerticalSyncEnabled(false);
}

void Game::initLevel()
{
	this->levelNum = 1;
	this->lastLevel = levelNum;

	this->level = new Level_a();
}

//Constructor/destructor
Game::Game()
{
	this->initWindow();

	this->initLevel();
}

Game::~Game()
{
	delete this->gameWindow;

	delete this->level;
}

//Functions
void Game::Run()
{
	while (this->gameWindow->isOpen())
	{
		this->Update();

		this->Render();
	}
}

/*
	UpdateLevel: creates a new level based on control variable
		-control variable: levelNum
*/
void Game::UpdateLevel()
{
	if (levelNum != 1) {
		this->level = new Level_b();
	}
	else {
		this->level = new Level_a();
	}

	this->lastLevel = this->levelNum;
}

void Game::UpdateEventPolls() 
{
	while (this->gameWindow->pollEvent(gameEv))
	{
		if (gameEv.type == sf::Event::Closed)
			this->gameWindow->close();
		if (gameEv.type == sf::Event::MouseButtonPressed) {
			std::cout << levelNum << "\n";
		}
	}
}

void Game::Update()
{
	this->UpdateEventPolls();

	if(this->lastLevel != this->levelNum) //Currently levels swap based on mouse click - temporary -TODO: better level swap
		this->UpdateLevel();

	this->level->Update();
}

void Game::Render()
{
	this->gameWindow->clear();

	this->level->Render(this->gameWindow);

	this->gameWindow->display();
}
