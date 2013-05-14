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
		spr.setPosition(pos.x, pos.y);
	}

	void update() //csinálja a labda dolgait
	{
		//spr.setPosition(pos.x, pos.y);

		if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
			update_pos(mm::vec2(-5,0));
		if( sf::Keyboard::isKeyPressed(sf::Keyboard::D ))
			update_pos(mm::vec2(5,0));
		if( sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			update_pos(mm::vec2(0, 5));
		if( sf::Keyboard::isKeyPressed(sf::Keyboard::W ))
			update_pos(mm::vec2(0, -5));
	}

	void draw()
	{
		//window->draw(spr); //ezt kell csinalni!!! h rajzolodjon...
	}

	const sf::Sprite& GetSprite() const
	{
		return spr;
	}

};
#endif