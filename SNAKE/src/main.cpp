#include <SFML/Graphics.hpp>

#include "Game.h"


int main()
{
	Game game("SNAKE", "whiteBlock.png", "greenBlock.png", "fruit.png", 16, 60, 30);
	game.Play();
}