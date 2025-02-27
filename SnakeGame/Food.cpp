#include "Food.h"

//Constructors / Destructors
Food::Food()
{
	//Initializing Variables
	foodX = 10;
	foodY = 5;
}

//Functions
void Food::spawn(int coordX, int coordY)
{
	foodX = coordX;
	foodY = coordY;
}

//Accessors
int Food::getFoodX()
{
	return foodX;
}

int Food::getFoodY()
{
	return foodY;
}