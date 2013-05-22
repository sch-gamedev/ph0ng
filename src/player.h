#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string.h>
#include <mymath/mymath.h>


using namespace sf;
using std::string;

class Player{

private:
	static int nextID;
	const int id;
	//enum fajta { sima , hajlott };   // ha szeretnen tobb felet csinalni

	mm::vec2 pos;
	int alfa;  // mennyire van elfordulva FOKban

	Texture tex;
	Sprite sprite;

public:
	
	/*a kepernyo kozepe a kozeppont es 100 pixelnyire van a kozepponttol*/
	Player(const string &imageName);

	const sf::Sprite& GetSprite() const
	{
		return sprite;
	}

	void update();

	void Draw(RenderWindow &Window);  
};

#endif