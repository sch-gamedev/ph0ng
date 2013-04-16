#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <string.h>

using namespace sf;
using std::string;

class Player{

private:

	//enum fajta { sima , hajlott };   // ha szeretnén tobb felet csinalni
 	int x;
	int y;
	int alfa;  // mennyire van elfordulva FOKban

	Texture tex;
	Sprite sprite;

public:
	
	/*a kepernyo kozepe a kozeppont es 100 pixelnyire van a kozepponttol*/
	Player(const string &imageName)   //konstruktor
		:x(1280/2 + 100), y(700/2 + 0), alfa(0)
	{
		tex.loadFromFile(imageName);
		sprite.setTexture(tex);
	}
  
	void lmove(); // balra mozgatas

	void rmove(); //jobbra mozgatas

	void Draw(RenderWindow &Window);  //kirajzolas MEGBESZELNI!!!!!
};
#endif