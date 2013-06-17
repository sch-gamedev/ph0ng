#include "inGameState.h"
#include "game.h"
#include <vector>

void InGameState::Update( )
{
	player.update();
	
	for(int i = 0; i < Balls.size(); ++i)
		Balls[i]->update();
	
	
	//////////////////////
	//Particle system BETA
	/////////////////////
	for(int ballindex = 0; ballindex < Balls.size(); ++ballindex ){
		
		for(int i = 0; i < Balls.size(); ++i){
		
  			if(i == ballindex && i + 1 < Balls.size() )		//do not call on itself
 				++i;

			if(i == ballindex && i + 1 >= Balls.size() )
				break;

			Balls[ballindex]->collusion( Balls[i]->GetSprite() );
		}//2nd for - end
	
	}//1st for - end

	for(int ballindex = 0; ballindex < Balls.size(); ++ballindex)
		Balls[ballindex]->collusion( player.GetSprite() );	//collusion with the player

}//fnc -end


void InGameState::Draw(sf::RenderTarget* rt)
{
	rt->draw(player.GetSprite());

	for(int i = 0; i < Balls.size(); ++i)
	  rt->draw(Balls[i]->GetSprite());
}

InGameState::InGameState(Game *game)
	:player(/*mm::vec2(10,50), */"playertexture.png")
{
	Balls.push_back(new Ball(mm::vec2(2,2), "balltexture.png"));

	this->game = game;
}

InGameState::~InGameState()
{
	
}
