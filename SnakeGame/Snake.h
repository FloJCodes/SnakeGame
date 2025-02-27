#pragma once

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

struct BodyPart
{
	int x, y;
};

enum Direction
{
	LEFT, RIGHT, UP, DOWN
};

class Snake
{
private:
	//Variables
	std::vector<BodyPart> parts;
	Direction dir;

public:
	//Constructors / Destructors
	Snake();

	//Functions
	void move();
	void extend();
	void setDirection(Direction newDir);

	//Accessors
	const std::vector<BodyPart>& getParts() const;
	int getHeadX() const;
	int getHeadY() const;
};

