#include "ball.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <mymath/mymath.h>
#include <stdio.h>
#include "Collision.h"

sf::Sprite& Ball::GetSprite()
{
	return sprite;
}

void Ball::Draw(sf::RenderWindow &Window) 
{
	Window.draw(sprite);
}

//update the position
void Ball::update()
{
	
 pos.x += movevector.x;
 pos.y += movevector.y;

sprite.setPosition(pos.x , pos.y);
}

void Ball::collision(Ball& inobject)
{
  if( Collision::BoundingBoxTest( this -> sprite, inobject.sprite) == true )
  {
    float l = mm::length(movevector);
    movevector = l * mm::reflect( movevector / l, mm::normalize(inobject.movevector) );
  }
}

void Ball::collision(sf::Sprite& inobject)
{
		if( Collision::BoundingBoxTest( this -> sprite, inobject) == true )
    {
			movevector.x *= -1;
			movevector.y *= -1;
		}
}

void Ball::collision(sf::Sprite& inobject, mm::vec2 n)
{
  if( Collision::BoundingBoxTest( this -> sprite, inobject) == true )
  {
    float l = mm::length(movevector);
    movevector = l * mm::reflect( movevector / l, n );
  }
}

Ball::Ball(mm::vec2 inposition, mm::vec2 move, std::string tex_filename) : pos(inposition), movevector(move)
{
	//BEta v0.1 - TEST
	//movevector.x = 5;
	//movevector.y = 2;
	
	
	tex.loadFromFile(tex_filename);
	sprite.setTexture(tex);
}


