#pragma once

#include <cstdlib>
#include <ctime>

#include <SFML/Graphics.hpp>

class Food
{
private:
	//Variables
	int foodX, foodY;

public:
	//Constructors / Destructors
	Food();

	//Functions
	void spawn(int coordX, int coordY);

	//Accessors
	int getFoodX();
	int getFoodY();
};