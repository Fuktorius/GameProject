#include <iostream>
#include "Game.h"


using namespace std;
using namespace sf;

int main() {
	//Window
	RenderWindow window(VideoMode(800, 600), "Game Project", Style::Titlebar | Style::Close | Style::Resize);
	Event ev{};

	//Game loop
	while (window.isOpen())
	{
		//Event Polling
		while (window.pollEvent(ev)) {
			switch (ev.type) {
			case Event::Closed:
					window.close();
				break;
			case Event::KeyPressed:
				if (ev.key.code == Keyboard::Escape)
					window.close();
				break;
			}
		}
		//Update

		//Render
		window.clear( Color::Yellow); //Clear Old Frame

		//Draw Your Game

		window.display(); //Tell app that window is done drawing
	}

	//End of application
	return 0;
}