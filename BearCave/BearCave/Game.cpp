#include "Game.h"
#include <iostream>
void Game::initWindow()
{
	this->gameWindow = new sf::RenderWindow(sf::VideoMode(800, 600), "Same window level swap", sf::Style::Close | sf::Style::Titlebar);
	this->gameWindow->setFramerateLimit(60);
	this->gameWindow->setVerticalSyncEnabled(false);
}

void Game::initLevel()
{
	this->level = new Level_a();
}

Game::Game()
{
	this->levelNum = 1;
	this->lastLevel = levelNum;
	this->initWindow();

	this->initLevel();
}

Game::~Game()
{
	delete this->gameWindow;

	delete this->level;
}

const bool Game::windowOpened() const
{
	return this->gameWindow->isOpen();
}


void Game::Run()
{
	while (this->gameWindow->isOpen())
	{
		this->Update();

		this->Render();
	}
}

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
	while (this->gameWindow->pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			this->gameWindow->close();
		if (ev.type == sf::Event::MouseButtonPressed) {
			if (ev.mouseButton.button == sf::Mouse::Left) {
				if (this->levelNum != 2) {
					this->levelNum = 2;

				}
				else {
					this->levelNum = 1;
				}
				std::cout << levelNum << "\n";
			}
		}
	}
}

//Functions
void Game::Update()
{
	this->UpdateEventPolls();

	if(this->lastLevel != this->levelNum)
		this->UpdateLevel();

	this->level->Update();
}

void Game::Render()
{
	this->gameWindow->clear();

	this->level->Render(this->gameWindow);

	this->gameWindow->display();
}
