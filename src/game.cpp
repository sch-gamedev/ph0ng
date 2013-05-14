#include <SFML/Graphics.hpp>
#include <vector>
#include "game.h"
#include "ball.h"

int Game::xres = 0;
int Game::yres = 0;

void Game::Run()
{
	Ball b(mm::vec2(10,50), "tex.png");
	float amount = 5;

	// main loop
	sf::Clock clock;
	sf::Int64 sum_time = 0;
	while( running )
	{
		// elõzõ frame óta eltelt idõ lekérdezése
		sum_time += clock.restart().asMicroseconds();
		
		// fix 50 Hz-cel fusson a program
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
			window->clear();
			// az aktuális játékállapot léptetése
			gamestates[currentState]->Update();
			// az aktuális játékállapot megjelenítése
			gamestates[currentState]->Draw(window);
			window->display();
		}
	}
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
