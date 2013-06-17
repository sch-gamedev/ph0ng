#include "player.h"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <mymath/mymath.h>
#include <math.h>


int Player::nextID = 0;

sf::Sprite& Player::GetSprite()
{
	return sprite;
}

void Player::Draw(sf::RenderWindow &Window) 
{
	Window.draw(sprite);
}

Player::Player( const string &imageName ) 
	:id(nextID++), alfa(0), r(200)
{

	//Sprite data:
	tex.loadFromFile(imageName);
	sprite.setTexture(tex);
	sprite.setRotation(90);
	
	//Positon:
	move(1);			//GANYOLAAASSS!!!!
	move(-1);
	firsthalf = true;

}

void Player::move(float angle){


	sprite.setOrigin(tex.getSize().x/2.0, 0);

//FIXME! 

	//firsthalf handleing
	/*
	if( alfa + angle > 180 && !sf::Keyboard::isKeyPressed(Keyboard::A) && firsthalf == true)
		firsthalf = false;
	
	if( alfa + angle < 180 && !sf::Keyboard::isKeyPressed(Keyboard::D) && firsthalf == false)
		firsthalf = true;
	
	if( alfa + angle> 360 && !sf::Keyboard::isKeyPressed(Keyboard::A) && firsthalf == false)
		firsthalf = true;
	
	if( alfa + angle< 360 && !sf::Keyboard::isKeyPressed(Keyboard::D)  && firsthalf == true)
		firsthalf = false;
	*/

	//Degree handle
	if(alfa + angle > 360 )
		alfa = 0;
	if(alfa + angle < 0)
		alfa = 360;

	alfa += angle;
	pos.x = r*cos(mm::radians(alfa));
	pos.y = r*sin(mm::radians(alfa));
	
	sprite.setRotation(360-(90-alfa));
}

void Player::update (){

	if( sf::Keyboard::isKeyPressed(sf::Keyboard::A) ){

		if( firsthalf == true)
		  move( -1 );
		else
		  move(  1 );
	}

	if( sf::Keyboard::isKeyPressed(sf::Keyboard::D )){

		if(firsthalf == true)
			move( 1 );
		else
			move( -1 );
	
	}
/*
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
		pos.y += 5;
	}
	
	if( sf::Keyboard::isKeyPressed(sf::Keyboard::W )){
		pos.y += -5;
	}
*/
	sprite.setPosition(pos.x + 1280/2.0, pos.y + 720/2.0);		//update the sprite position
}