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
	Event ev;

	//Private Functions
	void initVariables ();
	void initWindow();
public:
	//Constructors / Destructors
	Game();
	virtual ~Game();
	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};

