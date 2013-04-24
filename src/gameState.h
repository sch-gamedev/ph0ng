#ifndef GameState_h__
#define GameState_h__

#include <SFML/Graphics/RenderWindow.hpp>
#include "player.h"

class GameState
{
public:
	virtual void Update() = 0;
	virtual void Draw() = 0;
};

#endif // GameState_h__
