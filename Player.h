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
	int hp;
	int hpMax;
	//int points;

	void initVariables();
	void initShape();
public:
	Player(float x = 0.f, float y= 0.f);
	virtual ~Player();
	//ACCESSORS
	const RectangleShape& getShape() const;
	const int& getHp() const;
	const int& getHpMax() const;

	//FUNCTIONS
	void takeDamage(const int damage);
	void gainHealth(const int health);

	void updateInput();
	void updateWindowBoundsCollision(const RenderTarget* target);
	void update(const RenderTarget* target);
	void render(RenderTarget* target);
};

