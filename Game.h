#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
/*
	Class that acts as the game engine. 
	Wrapper Class.
*/

class Game
{
private:

	//Private Functions
	void initVariables ();
	void initWindow();
public:
	//Constructors / Destructors
	Game();
	virtual ~Game();

	//Functions
	void update();
	void render();
};

