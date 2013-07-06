#include <SFML/Graphics.hpp>
#include <vector>
#include "game.h"
#include "ball.h"
#include <stdio.h>

int Game::xres = 0;
int Game::yres = 0;

sf::Color white (255, 255, 255, 255);  //white background

void Game::Run()
{

	//Clock stuff
	sf::Clock clock;
	sf::Int64 sum_time = 0;

	/////////
	///MAIN LOOP
	////////
	while( running )
	{
		// get passed time
		sum_time += clock.restart().asMicroseconds();
		
		// FIX 50Hz
		while( sum_time >= 20000 )
		{
			sum_time -= 20000;

			// események kezelése
			sf::Event event;
			while( window->pollEvent(event) )
			{
				switch( event.type )
				{
					
				case sf::Event::Closed :
					{
						running = false;
						break;
					}

					
				case sf::Event::Resized :
					{
						//Game::SetProjection(event.size.width, event.size.height);
						break;
					}

				}
			}


			//clear the window 
			window->clear(white);						
			// Update the current gamestate
			gamestates[currentState]->Update();
			// Render current gamestate
			gamestates[currentState]->Draw(window);		
			window->display();

		}  //end of while (sum time)

	}		//end of while(running)

}	//end of func.

//Add Player
void Game::AddPlayer( Player *newplayer )
{
	players.push_back(newplayer);
}


Game::~Game()
{
	for (int i=0; i<players.size(); i++)
		delete players[i];
	for (int i=0; i<gamestates.size(); i++)
		delete gamestates[i];

	delete window;
}

//INIT
Game::Game( const int &Xres /*= 1280*/, const int &Yres /*= 720*/ )
{
	xres = Xres;
	yres = Yres;

  wintex.loadFromFile("wintex.png");
  bounds.resize(4);
  
  float width = 20;

  bounds[0].winsprite.scale(sf::Vector2<float>(xres, width));
  bounds[0].normal = mm::vec2( 0, -1 );
  
  bounds[1].winsprite.scale(sf::Vector2<float>(xres, width));
  bounds[1].winsprite.move(0, yres - width);
  bounds[1].normal = mm::vec2( 0, 1 );
  
  bounds[2].winsprite.scale(sf::Vector2<float>(width, yres));
  bounds[2].normal = mm::vec2( 1, 0 );
  
  bounds[3].winsprite.scale(sf::Vector2<float>(width, yres));
  bounds[3].winsprite.move(xres - width, 0);
  bounds[3].normal = mm::vec2( -1, 0 );

  for( int c = 0; c < 4; ++c )
    bounds[c].winsprite.setTexture( wintex );

#ifdef _DEBUG

	sf::String windowTitle = "ph0ng --- DEBUG";
	
#else
	sf::String windowTitle = "ph0ng";
#endif
	window = new sf::RenderWindow(sf::VideoMode(xres, yres), windowTitle);

	gamestates.push_back(new InGameState(this));

	currentState = INGAME;
	running = true;
}
