#ifndef _BALL_H_
#define _BALL_H_

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <mymath/mymath.h>

class Ball{

private:

	mm::vec2 pos;
	sf::Texture tex;
	sf::Sprite spr;

	int speed;  

	void colldet(); // collision detection UPDATE hivja

public:

	Ball(const mm::vec2& p, const std::string& tex_filename);

	void update_pos(const mm::vec2& p);

	void update(); //csinálja a labda dolgait

	void draw();

	const sf::Sprite& GetSprite() const;

};
#endif