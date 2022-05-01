#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class SwagBall
{
private:
	CircleShape shape;

	void initShape();

public:
	SwagBall();
	virtual ~SwagBall();

	//Functions
	void update();
	void render(RenderTarget& target);
};

