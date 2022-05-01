#include "Game.h"

//using namespace sf;
//Private functions
void Game::initVariables()
{
	this->endGame = false;
	this->spawnTimerMax = 10.f;
	this->spawnTimer = this->spawnTimerMax;
	this->maxSwagBalls = 15;
	this->points=0;

}

void Game::initWindow()
{	
	this->videoMode = VideoMode(800, 600);
	this->window = new RenderWindow(this->videoMode, "Game Project", Style::Titlebar | Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initFont()
{
	this->font.loadFromFile("Font/Segoe UI.ttf");
	/*if (! this->font.loadFromFile("Font/Segoe UI.ttf")); {
		std::cout<<"! Error::Game::INITFONTS::COULD NOT LOAD Segoe UI.tff"<<std::endl;
	}*/
}

void Game::initText()
{
	//Gui text init
	this->guiText.setFont(this->font);
	this->guiText.setFillColor(Color(255,255,255,200));
	this->guiText.setCharacterSize(24);
	//this->guiText.setString("test");

}

//Constructors / Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initFont();
	this->initText();
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
	//Timer
	if (this->spawnTimer < this->spawnTimerMax)
		this->spawnTimer += 1.f;
	else {
		if (this->swagBalls.size() < this->maxSwagBalls) {
			this->swagBalls.push_back(SwagBall(*this->window, rand()%SwagBallTypes::NROFTYPES));
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
			switch (this->swagBalls[i].getType()) {
			case SwagBallTypes::DEFAULT:
				this->points++;
				break;
			case SwagBallTypes::DAMAGING:
				this->player.takeDamage(1);
				break;
			case SwagBallTypes::HEALING:
				this->player.gainHealth(1);
				break;
			}

		
			//Remove the ball
			this->swagBalls.erase(this->swagBalls.begin() + i);
		}
	}
}

void Game::updateGui()
{
	std::stringstream ss;

	ss << "- Points: " << this->points << "\n"
		<<"- Health: " <<this->player.getHp()<<" / "<<this->player.getHpMax()<<"\n";

	this->guiText.setString(ss.str());
}

void Game::update()
{
	this->pollEvents();

	this->spawnSwagBalls();
	this->player.update(this->window);
	this->updateCollision();
	this->updateGui();
}

void Game::renderGui(RenderTarget* target)
{
	target->draw(this->guiText);
}

void Game::render()
{
	this->window->clear();

	//Render 
	this->player.render(this->window);

	for (auto i : this->swagBalls) {
		i.render(*this->window);
	}
	//Render GUI
	this->renderGui(this->window);
	this->window->display();
}


