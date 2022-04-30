#include "Game.h"

using namespace sf;
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

void Game::update()
{
}

void Game::render()
{
}

//Functions
