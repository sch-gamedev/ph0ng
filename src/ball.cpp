#include "ball.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <mymath/mymath.h>


const sf::Sprite& Ball::GetSprite() const
{
	return sprite;
}

void Ball::Draw(sf::RenderWindow &Window) 
{
	Window.draw(sprite);
}

//update the position
void Ball::update(sf::FloatRect inhitbox)
{
	//WRITE MEE
	
}



Ball::Ball( const mm::vec2& p, const std::string& tex_filename, int m = 5) :pos(p)
{
	tex.loadFromFile(tex_filename);
	sprite.setTexture(tex);
}


