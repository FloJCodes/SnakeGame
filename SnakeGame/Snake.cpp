#include "Snake.h"

//Constructors / Destructors
Snake::Snake()
{
	//Initializing Variables
	parts = { {1,5} };
	dir = RIGHT;
}

//Functions
void Snake::move()
{
	/*
		@return void

		Moves the snake in the current facing direction.
		-Clones current head
		-Shifts new head in the right direction
		-inserts new Head to the front of parts
		-deletes last element of parts
	*/

	BodyPart newHead = parts.front();
	if (dir == LEFT)
		newHead.x--;
	else if (dir == RIGHT)
		newHead.x++;
	else if (dir == UP)
		newHead.y--;
	else if (dir == DOWN)
		newHead.y++;
	parts.insert(parts.begin(), newHead);
	parts.pop_back();

	std::cout << "X: " << newHead.x << " Y: " << newHead.y << "\n";
}

void Snake::extend()
{
	/*
		@return void

		Extends the snake in the current facing direction.
		-Clones current head
		-Shifts new head in the right direction
		-inserts new Head to the front of parts
	*/

	BodyPart newHead = parts.front();
	if (dir == LEFT)
		newHead.x--;
	else if (dir == RIGHT)
		newHead.x++;
	else if (dir == UP)
		newHead.y--;
	else if (dir == DOWN)
		newHead.y++;
	parts.insert(parts.begin(), newHead);
}

void Snake::setDirection(Direction newDir)
{
	/*
		@return void

		Sets the current direction to the input newDir.
		-Checks if no illegal turns were made
	*/

	if ((dir == LEFT && newDir != RIGHT) ||
		(dir == RIGHT && newDir != LEFT) ||
		(dir == UP && newDir != DOWN) ||
		(dir == DOWN && newDir != UP))
	{
		dir = newDir;
	}
}

//Accessors
const std::vector<BodyPart>& Snake::getParts() const
{
	return parts;
}

int Snake::getHeadX() const
{
	return parts.front().x;
}

int Snake::getHeadY() const
{
	return parts.front().y;
}
