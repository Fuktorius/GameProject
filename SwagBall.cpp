#include "SwagBall.h"


void SwagBall::initShape(const RenderWindow& window)
{
	this->shape.setRadius(static_cast<float>(rand()%10+10));
	Color color(rand()%255 +1,rand() % 255 + 1,rand() % 255 + 1);
	this->shape.setFillColor(color);
	this->shape.setPosition(Vector2f(static_cast<float>(rand()%window.getSize().x-this->shape.getGlobalBounds().width),
		static_cast<float>(rand() % window.getSize().y - this->shape.getGlobalBounds().height)));
}

SwagBall::SwagBall(const RenderWindow& window)
{
	this->initShape(window);
}


SwagBall::~SwagBall() {

}

void SwagBall::update()
{
}

void SwagBall::render(RenderTarget& target)
{
	target.draw(this->shape);
}
