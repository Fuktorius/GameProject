#include "Player.h"

void Player::initVariables()
{
	this->movementSpeed = 10.f;
}

void Player::initShape()
{
	this->shape.setFillColor(Color::Green);
	this->shape.setSize(Vector2f(50.f, 50.f));
}

Player::Player(float x, float y)
{
	this->shape.setPosition(x, y);
	this->initVariables();
	this->initShape();
}


Player::~Player() {

}

void Player::updateInput()
{
	//Keyboard input
//Left
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		this->shape.move(-this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D)) {
		this->shape.move(this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::W)) {
		this->shape.move(0.f, -this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S)) {
		this->shape.move(0.f, this->movementSpeed);
	}
}

void Player::update(RenderTarget* target)
{
	//Window bounds collision
	

	this->updateInput();
}

void Player::render(RenderTarget* target)
{
	target->draw(this->shape);
}
