#include "player.h"

int Player::nextID = 0;

void Player::lmove(){		// balra mozgatas

}
void Player::rmove(){} //jobbra mozgatas

void Player::Draw(sf::RenderWindow &Window)  //kirajzolas MEGBESZELNI!!!!!
{
	Window.draw(sprite);
}