#include "Game.h"

//using namespace sf;
//Private functions
void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 10;
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
//Functions
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

void Game::spawnSwagBalls()
{
	//Time
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else {
		if (this->swagBalls.size() < this->maxSwagBalls) {
			this->swagBalls.push_back(SwagBall(*this->window));
			this->spawnTimer = 0.f;
		}
	}
}

void Game::updateCollision()
{
	//Check the collision
	for (size_t i = 0; i < this->swagBalls.size(); i++) {
		if (this->player.getShape().getGlobalBounds().intersects(this->swagBalls[i].getShape().getGlobalBounds()))
		{
			this->swagBalls.erase(this->swagBalls.begin() + i);
		}
	}
}

void Game::update()
{
	this->pollEvents();

	this->spawnSwagBalls();
	this->player.update(this->window);
	this->updateCollision();
}

void Game::render()
{
	this->window->clear();

	//Render 
	this->player.render(this->window);

	for (auto i : this->swagBalls) {
		i.render(*this->window);
	}

	this->window->display();
}


