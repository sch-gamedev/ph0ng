#ifndef _BALL_H_
#define _BALL_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <mymath/mymath.h>

class Ball{

private:

	//
	mm::vec2 pos;
	int m;  //mass of the ball
	
	
	//SPRITE DATA:
	sf::Texture tex;
	sf::Sprite sprite;

public:

	Ball(const mm::vec2&, const std::string&, int);

	void update(sf::FloatRect); 

	void Draw(sf::RenderWindow&);

	const sf::Sprite& GetSprite() const;

};
#endif