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
void Ball::update()
{
	
 pos.x += movevector.x;
 pos.y += movevector.y;

sprite.setPosition(pos.x , pos.y);
}

 int step = 10;		//slow it down a little

void Ball::collusion(sf::FloatRect inhitbox)
{


	if(step == 10){
	if(sprite.getGlobalBounds().intersects(inhitbox) == true){
		//BETA v0.1
		movevector.x *= -1;
		movevector.y *= -1;
	}
 	if(step > 0)
 	  step--;
 	else 
 	 step = 10;
	}
}

Ball::Ball(mm::vec2 inposition, std::string tex_filename) :pos(inposition)
{
	//BEta v0.1 - TEST
	movevector.x = -2;
	movevector.y = -2;
	
	
	tex.loadFromFile(tex_filename);
	sprite.setTexture(tex);
}


