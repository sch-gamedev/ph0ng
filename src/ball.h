#ifndef _BALL_H_
#define _BALL_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <mymath/mymath.h>

class Ball{

private:

	
	mm::vec2 movevector;
	mm::vec2 pos;
	int m;  //mass of the ball
	
	
	//SPRITE DATA:
	sf::Texture tex;
	sf::Sprite sprite;

public:

	Ball(mm::vec2, mm::vec2 move, std::string);

	void update(); 
	void collision(sf::Sprite&);
  void collision(sf::Sprite&, mm::vec2 n);
  void collision(Ball&);

	void Draw(sf::RenderWindow&);

	 sf::Sprite& GetSprite();

};
#endif