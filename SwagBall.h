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

	void initShape(const RenderWindow& window);

public:
	SwagBall(const RenderWindow& window);
	virtual ~SwagBall();

	const CircleShape getShape() const;

	//Functions
	void update();
	void render(RenderTarget& target);
};

