#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
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

	void initVariables();
	void initWindow();

public:
	//Constructors / Destructors
	Game();
	~Game();
	//Accessors
	
	//Modifiers

	//Functions
	void update();
	void render();
};

