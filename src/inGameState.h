#ifndef inGameState_h__
#define inGameState_h__

#include "gameState.h"
#include <vector>

class Game;

class InGameState : public GameState
{
private:
	Game *game;

public:
	InGameState(Game *game);
	~InGameState();

	void Update( );

	void Draw( );
};


#endif // inGameState_h__
