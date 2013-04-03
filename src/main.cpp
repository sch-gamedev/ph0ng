// ******************************************************************************
// *	Ph0ng minigame --- main.cpp
// *	Copyright (c) 2013 KSZK Game-Dev (see LICENSE.md for full license)
// *
// *	Entry point for the game, initializes SFML and subsystems.
// *
// ******************************************************************************

#include <SFML/Graphics.hpp>

int main(char** argc, int argv)
{
#ifdef _DEBUG
	sf::String windowTitle = "ph0ng --- DEBUG";
#else
	sf::String windowTitle = "ph0ng";
#endif

	sf::RenderWindow window(sf::VideoMode(800, 600), windowTitle);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}

		window.clear(sf::Color(127, 0, 0, 255));
		window.display();
	}

	return 0;
}