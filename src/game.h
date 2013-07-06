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
protected:
  Game(const int &Xres = 1280, const int &Yres = 720); //singleton
  Game(const Game&);
  Game(Game&&);
  Game& operator=(const Game&);
  ~Game();

public:

	static int xres;
	static int yres;

	sf::RenderWindow *window;
	std::vector<GameState*> gamestates;
	std::vector<Player*> players;

  sf::Texture wintex;
  struct winbound
  {
    mm::vec2 normal;
    sf::Sprite winsprite;
  };

  std::vector< winbound > bounds;

	bool running;
	GState currentState;

	// gamestate.Addplayer(new Player(...))
	void AddPlayer(Player *newplayer);
	
	// MAIN LOOP 
	void Run();

  static Game& get()
  {
    static Game instance;
    return instance;
  }
};

#endif