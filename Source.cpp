#include <iostream>
#include "Game.h"


using namespace std;
using namespace sf;

int main() {
	//Window
	///RenderWindow window(VideoMode(800, 600), "Game Project", Style::Titlebar | Style::Close | Style::Resize);
	///Event ev{};

	//Init game engine
	Game game;

	//Game loop
	while (game.running())
	{
		//////////////////event polling
		////////////////while (window.pollevent(ev)) {
		////////////////	switch (ev.type) {
		////////////////	case event::closed:
		////////////////			window.close();
		////////////////		break;
		////////////////	case event::keypressed:
		////////////////		if (ev.key.code == keyboard::escape)
		////////////////			window.close();
		////////////////		break;
		////////////////	}
		////////////////}
	 
		//Update
		game.update();
		//Render
		game.render();
		//window.clear( Color::Yellow); //Clear Old Frame

		//Draw Your Game

		//window.display(); //Tell app that window is done drawing
	}

	//End of application
	return 0;
}