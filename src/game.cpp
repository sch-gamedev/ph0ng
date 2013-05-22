#include <SFML/Graphics.hpp>
#include <vector>
#include "game.h"
#include "ball.h"

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
					// ablak bezárása
				case sf::Event::Closed :
					{
						running = false;
						break;
					}

					// ablak átméretezõdött
				case sf::Event::Resized :
					{
						//Game::SetProjection(event.size.width, event.size.height);
						break;
					}

				case sf::Event::KeyPressed:
					{
						
					}
				}
			}


			window->clear(white);						
			// az aktuális játékállapot léptetése
			gamestates[currentState]->Update();
			// az aktuális játékállapot megjelenítése
			gamestates[currentState]->Draw(window);		
			window->display();

		}  //end of while (sum time)

	}		//end of while(running)

}	//end of func.

//Játékos hozzáadása
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



/*void Game::SetProjection(GLsizei Width_in, GLsizei Height_in)
{
	// vetítés beállítása
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1024, 0, 768, 1, -1);
	glMatrixMode(GL_MODELVIEW);

	// viewport beállítása a teljes ablakra
	glViewport(0, 0, Width_in, Height_in);
}*/
