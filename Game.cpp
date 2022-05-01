#include "Game.h"

//using namespace sf;
//Private functions
void Game::initVariables()
{
	this->endGame = false;
}

void Game::initWindow()
{	
	this->videoMode = VideoMode(800, 600);
	this->window = new RenderWindow(this->videoMode, "Game Project", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
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

void Game::pollEvents()
{
	while (this->window->pollEvent(this->sfmlEvent)) {
		switch (this->sfmlEvent.type) {
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->sfmlEvent.key.code == Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Game::update()
{
	this->pollEvents();
	this->player.update(this->window);
}

void Game::render()
{
	this->window->clear();

	//Render 
	this->player.render(this->window);

	this->window->display();
}

//Functions
