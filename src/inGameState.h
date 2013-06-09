#ifndef inGameState_h__
#define inGameState_h__

#include "gameState.h"
#include "ball.h"
#include <vector>

class Game;

class InGameState : public GameState
{
private:
	Game *game;

	Player player;

	std::vector<Ball*> Balls; //container of the balls... :P

public:
	InGameState(Game *game);
	~InGameState();

	void Update();

	void Draw(sf::RenderTarget*);
};


#endif // inGameState_h__
