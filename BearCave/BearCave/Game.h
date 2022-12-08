#pragma once
#include "Level_a.h"
#include "Level_b.h"

class Game
{
private:
	//Attributes
	sf::RenderWindow* gameWindow;
	sf::Event ev;

	Level* level;
	int levelNum;
	int lastLevel;

	void initWindow();
	void initLevel();

public:
	//Constructor and destructor
	Game();
	virtual ~Game();

	//
	const bool windowOpened() const;

	//Functions
	void Run();

	void UpdateLevel();
	void UpdateEventPolls();
	void Update();
	void Render();


};

