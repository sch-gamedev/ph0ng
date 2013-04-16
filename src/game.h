#ifndef game_h
#define game_h

#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
public:
	static int xres;
	static int yres;

	Game(const int &Xres = 1280, const int &Yres = 720)		
	{
		xres = Xres;
		yres = Yres;
	}

	void Update(float dt);
	void Draw(sf::RenderWindow &Window);
};

#endif