#include "player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <mymath/mymath.h>
#include <math.h>

int Player::nextID = 0;

void Player::Draw(sf::RenderWindow &Window)  //kirajzolas MEGBESZELNI!!!!!
{
	//pos += p;
	sprite.setPosition(pos.x, pos.y);
	Window.draw(sprite);
}

Player::Player( const string &imageName ) 
	:/*pos.x(1280/2 + 100), pos.y(700/2 + 0), *//*alfa(0), */id(nextID++)
{

	alfa = 0;

	sprite.setRotation(90);
	pos.x = 1280/2 + 15;   // 150 pixel lesz az r
	pos.y = 700/2 + 0;
	tex.loadFromFile(imageName);
	sprite.setTexture(tex);


}

void Player::update (){

	if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ){
		
		// ROTATION COMES HERE
		pos.x += -5;
		//sprite.setRotation(sprite.getRotation() + alfa);
	}
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::D ))
		pos.x += 5;
	
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		pos.y += 5;

	if( sf::Keyboard::isKeyPressed(sf::Keyboard::W ))
		pos.y += -5;


	//sprite.setRotation(sprite.getRotation());
	sprite.setPosition(pos.x, pos.y);		//update the sprite position
}