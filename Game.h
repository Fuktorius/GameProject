#pragma once

#include <iostream>
#include <ctime>


#include "Player.h"
#include "SwagBall.h"
#include <sstream>
#include <vector>

using namespace sf;
/*
	Class that acts as the game engine. 
	Wrapper Class.
*/

class Game
{
private:
	//Variables
	//Window
	RenderWindow* window;
	VideoMode videoMode;
	bool endGame;
	Event sfmlEvent;

	Player player;

	int points;
	Font font;
	Text guiText;

	std::vector<SwagBall> swagBalls;
	float spawnTimerMax;
	float spawnTimer;
	int maxSwagBalls;

	void initVariables();
	void initWindow();
	void initFont();
	void initText();

public:
	//Constructors / Destructors
	Game();
	~Game();
	//Accessors
	
	//Modifiers

	//Functions
	const bool running() const;
	void pollEvents();

	void spawnSwagBalls();
	void updateCollision();
	void updateGui();
	void update();

	void renderGui(RenderTarget* target);
	void render();
};

