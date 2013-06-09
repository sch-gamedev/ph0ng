#include "inGameState.h"
#include "game.h"
#include <vector>

void InGameState::Update( )
{
	player.update();
	
	//////////////////////
	//Particle system BETA
	/////////////////////
	for(int ballindex = 0; ballindex < Balls.size(); ++ballindex ){
		
		for(int i = 0; i < Balls.size(); ++i){
		
			if(i == ballindex)		//do not call on itself
				++i;

			Balls[ballindex]->update(Balls[i]->GetSprite().getGlobalBounds());
		}//2nd for - end
	
	}//1st for - end

	//for(int ballindex = 0; ballindex < Balls.size(); ++ballindex)
		//player.colldet(*Balls[ballindex]);		//collusion with the player

}//fnc -end


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
