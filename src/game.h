#ifndef game_h
#define game_h

#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "gameState.h"
#include "inGameState.h"

enum GState
{
	//MENU,
	INGAME
};

class Game
{
public:

	static int xres;
	static int yres;

	sf::RenderWindow *window;
	std::vector<GameState*> gamestates;
	std::vector<Player*> players;
	bool running;
	GState currentState;

	Game(const int &Xres = 1280, const int &Yres = 720)		
	{
		xres = Xres;
		yres = Yres;

#ifdef _DEBUG
		sf::String windowTitle = "ph0ng --- DEBUG";

#else
		sf::String windowTitle = "ph0ng";
#endif

		window = new sf::RenderWindow(sf::VideoMode(xres, yres), windowTitle);

		gamestates.push_back(new InGameState(this));

		currentState = INGAME;
		running = true;
	}

	~Game()
	{
		for (int i=0; i<players.size(); i++)
			delete players[i];
		for (int i=0; i<gamestates.size(); i++)
			delete gamestates[i];

		delete window;
	}

	// gamestate.Addplayer(new Player(...))
	void AddPlayer(Player *newplayer) { players.push_back(newplayer); }
	void Run();
};

#endif