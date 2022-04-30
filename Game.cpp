#include "Game.h"


//Private functions
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::initWindow()
{	
	this->videoMode.height = 600;
	this->videoMode.width = 800;
	
	this->window = new RenderWindow(this->videoMode, "Game Project", Style::Titlebar | Style::Close | Style::Resize);
}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();

}

Game::~Game() {
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions

void Game::pollEvents()
{
	while (this->window->pollEvent(this->ev)) {
	switch (this->ev.type) {
	case Event::Closed:
			this->window->close();
		break;
	case Event::KeyPressed:
		if (this->ev.key.code == Keyboard::Escape)
			this->window->close();
		break;
	}
}
}

void Game::update()
{
	this->pollEvents();
}

void Game::render()
{
	/*
	@return void
	-clear old frame
	-render objects
	-display frame in window

	Renders the game objects.*/
	this->window->clear(Color(255, 0, 0, 255));
	//Draw Game Objects
	this->window->display();
}


