#pragma once

#include <SFML/Graphics.hpp>

#include "Tilemap.h"
#include "Snake.h"

class Game
{
private:
	int m_width;
	int m_height;

private:
	sf::RenderWindow m_window;
	Tilemap m_tilemap;
	Snake m_snake;

public:
	Game(std::string windowName, std::string tileFileName, std::string snakeFileName, std::string fruitFileName, int tileSize, int tileCountX, int tileCountY);
	~Game();

	void Play();
};

