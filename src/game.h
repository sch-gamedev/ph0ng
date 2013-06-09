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

	Game(const int &Xres = 1280, const int &Yres = 720);
	~Game();

	// gamestate.Addplayer(new Player(...))
	void AddPlayer(Player *newplayer);
	
	// MAIN LOOP 
	void Run();
};

#endif