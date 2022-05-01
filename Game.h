#pragma once

#include <iostream>
#include <ctime>


#include "Player.h"

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

	void initVariables();
	void initWindow();

public:
	//Constructors / Destructors
	Game();
	~Game();
	//Accessors
	
	//Modifiers

	//Functions
	const bool running() const;
	void pollEvents();

	void update();
	void render();
};

