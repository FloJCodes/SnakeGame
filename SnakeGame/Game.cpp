#include "Game.h"

const int WIDTH = 600;
const int HEIGHT = 600;
const int GRID_SIZE = 30;

//Private functions
void Game::initVariables()
{
	//Initializing Variables
	//Window
	this->window = nullptr;

	//Game logic
	this->endGame = false;
	Snake snake;
	Food food;
	moveInterval = 0.1f;
}

void Game::initWindow()
{
	//Initializing Game Window
	this->window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), "Snake!");
	this->window->setFramerateLimit(60);
}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
}

Game::~Game()
{
	delete this->window;
}

//Functions
void Game::pollEvents()
{
	/*
		@return void

		Gets events from user and performs the right actions.
		-Closes the window if Escape is pressed
		-Sets direction if w,a,s,d or a direction key is pressed
	*/

	while (this->window->pollEvent(this->ev))
	{
		if (this->ev.type == sf::Event::Closed)
			this->window->close();
		else if (this->ev.type == sf::Event::KeyPressed)
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			else if (ev.key.code == sf::Keyboard::Left || ev.key.code == sf::Keyboard::A)
				snake.setDirection(LEFT);
			else if (ev.key.code == sf::Keyboard::Right || ev.key.code == sf::Keyboard::D)
				snake.setDirection(RIGHT);
			else if (ev.key.code == sf::Keyboard::Up || ev.key.code == sf::Keyboard::W)
				snake.setDirection(UP);
			else if (ev.key.code == sf::Keyboard::Down || ev.key.code == sf::Keyboard::S)
				snake.setDirection(DOWN);
	}
}

void Game::update()
{
	/*
		@return void

		Updates the game and all its parts and ends it if needed.
		-Moves the snake if the time has hit the moveInterval
		-Extends the snake if the head has hit food
		-Modifies the board vector so it only contains fields with no snake in it
		-Places new food in one of those fields
		-Sets endGame to true if the snake hits a corner or itself
	*/

	sf::Time elapsed = clock.getElapsedTime();
	this->pollEvents();

	if (this->endGame == false)
	{
		if (elapsed.asSeconds() >= moveInterval)
		{
			snake.move();

			if (snake.getHeadX() == food.getFoodX() && snake.getHeadY() == food.getFoodY())
			{
				snake.extend();

				board = {};
				for (int i = 1; i <= WIDTH / GRID_SIZE - 1; ++i) {
					for (int j = 1; j <= HEIGHT / GRID_SIZE - 1; ++j) {
						board.push_back({ i, j });
					}
				}

				std::vector<BodyPart> parts = snake.getParts();
				
				for (int i = 0; i < parts.size(); i++)
				{
					for (int j = 0; j < board.size(); j++)
					{
						if (board[j].x == parts[i].x && board[j].y == parts[i].y)
							board.erase(board.begin() + j);
					}
				}

				int index = rand() % board.size();
				food.spawn(board[index].x, board[index].y);
			}
			clock.restart();
		}
	}

	//End game conditions
	/*
	if (snake.getHeadX() <= 0 || snake.getHeadX() >= WIDTH / GRID_SIZE || snake.getHeadY() <= 0 || snake.getHeadY() >= HEIGHT / GRID_SIZE)
	{
		this->endGame = true;
	}

	const auto parts = snake.getParts();
	for (size_t i = 1; i < parts.size(); i++)
	{
		if (snake.getHeadX() == parts[i].x && snake.getHeadY() == parts[i].y)
			this->endGame = true;
	}
	*/
}

void Game::render()
{
	/*
		@return void

		Renders the game objects

		- clears old frame
		- renders snake and food
		- displays frame in window
	*/

	this->window->clear();

	for (const auto& part : snake.getParts())
	{
		sf::RectangleShape snakeRect(sf::Vector2f(GRID_SIZE, GRID_SIZE));
		snakeRect.setPosition(part.x * GRID_SIZE, part.y * GRID_SIZE);
		snakeRect.setFillColor(sf::Color::Blue);
		this->window->draw(snakeRect);
	}

	sf::RectangleShape foodRect(sf::Vector2f(GRID_SIZE, GRID_SIZE));
	foodRect.setPosition(food.getFoodX() * GRID_SIZE, food.getFoodY() * GRID_SIZE);
	foodRect.setFillColor(sf::Color::Magenta);
	this->window->draw(foodRect);

	this->window->display();
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}