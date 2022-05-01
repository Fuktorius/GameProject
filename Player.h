#pragma once


#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

using namespace sf;

class Player
{
private:
	RectangleShape shape;

	float movementSpeed;

	void initVariables();
	void initShape();
public:
	Player(float x = 0.f, float y= 0.f);
	virtual ~Player();

	void updateInput();
	void update(RenderTarget* target);
	void render(RenderTarget* target);
};

