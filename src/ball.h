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

	void colldet(){} // collision detection UPDATE hivja

public:

	Ball(const mm::vec2& p, const std::string& tex_filename):pos(p)  //konstruktor
	{
		tex.loadFromFile(tex_filename);
		spr.setTexture(tex);
	}

	void update_pos(const mm::vec2& p)
	{
		pos += p;
	}

	void update() //csinálja a labda dolgait
	{
		spr.setPosition(pos.x, pos.y);
	}

	void draw()
	{
		//window.draw(spr); //ezt kell csinalni!!! h rajzolodjon...
	}

};
#endif