#include "inGameState.h"
#include "game.h"
#include <vector>

using std::vector;

void InGameState::Update( )
{
	player.update();
}

void InGameState::Draw(sf::RenderTarget* rt)
{
	rt->draw(player.GetSprite());
}

InGameState::InGameState(Game *game)
	:player(/*mm::vec2(10,50), */"playertexture.png")
{
	this->game = game;
}

InGameState::~InGameState()
{
	
}
