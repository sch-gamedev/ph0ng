#include "inGameState.h"
#include "game.h"
#include <vector>

using std::vector;

void InGameState::Update( )
{
	b.update();
}

void InGameState::Draw(sf::RenderTarget* rt)
{
	rt->draw(b.GetSprite());
}

InGameState::InGameState(Game *game):
	b(mm::vec2(10,50), "tex.png")
{
	this->game = game;
}

InGameState::~InGameState()
{
	
}
