#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

int main() {
	//Window
	Window window(VideoMode(640, 480), "Game Project", Style::Titlebar | Style::Close | Style::Resize);
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
	}

	//End of application
	return 0;
}