#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include "Snake.h"
#include "Food.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
	Class that acts as the game engine
	Wrapper class.
*/

class Game
{
private:
	//Variables
	//Window
	sf::RenderWindow* window;
	sf::Event ev;

	//Game logic
	bool endGame;
	Snake snake;
	Food food;
	sf::Clock clock;
	float moveInterval;
	std::vector<BodyPart> board;

	//Private functions
	void initVariables();
	void initWindow();

public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Functions
	void pollEvents();
	void update();
	void render();

	//Accessors
	const bool running() const;
	const bool getEndGame() const;
};

