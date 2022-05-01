#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

enum SwagBallTypes {DEFAULT = 0, DAMAGING, HEALING, NROFTYPES};

using namespace sf;

class SwagBall
{
private:
	CircleShape shape;
	int type;
	void initShape(const RenderWindow& window);

public:
	SwagBall(const RenderWindow& window, int type);
	virtual ~SwagBall();
	//Accessor
	const CircleShape getShape() const;
	const int& getType() const;

	//Functions
	void update();
	void render(RenderTarget& target);
};

