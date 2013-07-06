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

			Balls[ballindex]->collision( Balls[i]->GetSprite() );
		}//2nd for - end
	
	}//1st for - end

	for(int ballindex = 0; ballindex < Balls.size(); ++ballindex)
		Balls[ballindex]->collision( player.GetSprite() );	//collision with the player

  /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    Game::get().bounds[0].winsprite.move(-10, 0);
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    Game::get().bounds[0].winsprite.move(10, 0);*/

  for(int ballindex = 0; ballindex < Balls.size(); ++ballindex)
    for( int c = 0; c < Game::get().bounds.size(); ++c )
      Balls[ballindex]->collision( Game::get().bounds[c].winsprite, Game::get().bounds[c].normal);
}//fnc -end


void InGameState::Draw(sf::RenderTarget* rt)
{
  for( int c = 0; c < Game::get().bounds.size(); ++c )
    rt->draw(Game::get().bounds[c].winsprite);

	for(int i = 0; i < Balls.size(); ++i)
	  rt->draw(Balls[i]->GetSprite());

  rt->draw(player.GetSprite());
}

InGameState::InGameState(Game *game)
	:player(/*mm::vec2(10,50), */"playertexture.png")
{
	Balls.push_back(new Ball(mm::vec2(20,40), mm::vec2(1, 5), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(20,60), mm::vec2(2, 5), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(20,80), mm::vec2(3, 5), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(20,100), mm::vec2(4, 5), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(20,120), mm::vec2(5, 5), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(40,20), mm::vec2(5, 1), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(60,20), mm::vec2(5, 2), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(80,20), mm::vec2(5, 3), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(100,20), mm::vec2(5, 4), "balltexture.png"));
  Balls.push_back(new Ball(mm::vec2(120,20), mm::vec2(5, 5), "balltexture.png"));

	this->game = game;
}

InGameState::~InGameState()
{
	
}
