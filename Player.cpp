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

void Player::updateWindowBoundsCollision(const RenderTarget* target)
{
	//Leftd
	if (this->shape.getGlobalBounds().left <= 0.f)
		this->shape.setPosition(0.f, this->shape.getGlobalBounds().top);
	//Right
	if (this->shape.getGlobalBounds().left + this->shape.getGlobalBounds().width >= target->getSize().x)
		this->shape.setPosition(target->getSize().x - this->shape.getGlobalBounds().width, this->shape.getGlobalBounds().top);
	//Top
	if (this->shape.getGlobalBounds().top <= 0.f)
		this->shape.setPosition(this->shape.getGlobalBounds().left, 0.f);
	//Bottom
	if (this->shape.getGlobalBounds().top + this->shape.getGlobalBounds().height >= target->getSize().y)
		this->shape.setPosition(this->shape.getGlobalBounds().left, target->getSize().y - this->shape.getGlobalBounds().height);

}

void Player::update(const RenderTarget* target)
{

	this->updateInput();
	//Window bounds collision
	this->updateWindowBoundsCollision(target);

}

void Player::render(RenderTarget* target)
{
	target->draw(this->shape);
}
