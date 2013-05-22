

#include "ball.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <mymath/mymath.h>


const sf::Sprite& Ball::GetSprite() const
{
	return spr;
}

void Ball::draw()
{
	//window->draw(spr); //ezt kell csinalni!!! h rajzolodjon...
}

void Ball::update() /*csinálja a labda dolgait */
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

void Ball::update_pos( const mm::vec2& p )
{
	pos += p;
	spr.setPosition(pos.x, pos.y);
}

Ball::Ball( const mm::vec2& p, const std::string& tex_filename ) :pos(p)  //konstruktor
{
	tex.loadFromFile(tex_filename);
	spr.setTexture(tex);
}

void Ball::colldet()
{

}

