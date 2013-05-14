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
		// el�z� frame �ta eltelt id� lek�rdez�se
		sum_time += clock.restart().asMicroseconds();
		
		// fix 50 Hz-cel fusson a program
		while( sum_time >= 20000 )
		{
			sum_time -= 20000;

			// esem�nyek kezel�se
			sf::Event event;
			while( window->pollEvent(event) )
			{
				switch( event.type )
				{
					// ablak bez�r�sa
				case sf::Event::Closed :
					{
						running = false;
						break;
					}

					// ablak �tm�retez�d�tt
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
			// az aktu�lis j�t�k�llapot l�ptet�se
			gamestates[currentState]->Update();
			// az aktu�lis j�t�k�llapot megjelen�t�se
			gamestates[currentState]->Draw(window);
			window->display();
		}
	}
}

/*void Game::SetProjection(GLsizei Width_in, GLsizei Height_in)
{
	// vet�t�s be�ll�t�sa
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1024, 0, 768, 1, -1);
	glMatrixMode(GL_MODELVIEW);

	// viewport be�ll�t�sa a teljes ablakra
	glViewport(0, 0, Width_in, Height_in);
}*/
