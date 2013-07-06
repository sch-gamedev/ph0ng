// ******************************************************************************
// *	Ph0ng minigame --- main.cpp
// *	Copyright (c) 2013 KSZK Game-Dev (see LICENSE.md for full license)
// *
// *	Entry point for the game, initializes SFML and subsystems.
// *
// ******************************************************************************



#include "game.h"


int main(char** argc, int argv)
{

	Game::get().Run();

	return 0;
}