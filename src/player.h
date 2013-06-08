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

	//ID:
	static int nextID;
	const int id;


	//POSITION:
	
	mm::vec2 pos;
	float alfa;  //rotation 
	float r;  
	bool firsthalf;		//true if the player is in the first 2 querters of the screen

	//Sprite data:
	Texture tex;
	Sprite sprite;


public:
	
	Player(const string &imageName);	//CTOR

	const sf::Sprite& GetSprite() const
	{
		return sprite;
	}
	void move(float angle);

	void update();						//input handling

	void Draw(RenderWindow &Window);	//render function 


};

#endif