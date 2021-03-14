#include "Game.h"

Game::Game(std::string windowName, std::string tileFileName, std::string snakeFileName, std::string fruitFileName, int tileSize, int tileCountX, int tileCountY) :
	m_width{ tileSize * tileCountX }, m_height{ tileSize * tileCountY },
	m_window(sf::VideoMode(m_width, m_height), windowName),
	m_tilemap(tileFileName, tileSize, tileCountX, tileCountY),
	m_snake(snakeFileName, fruitFileName, tileSize, m_width, m_height)
{
	
}

Game::~Game()
{

}

void Game::Play()
{
	m_window.setFramerateLimit(11);
	
	while (m_window.isOpen())
	{
		sf::Event evnt;
		while (m_window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			}
		}

		//Update
		m_snake.Update();

		//Draw
		m_window.clear();

		m_tilemap.Draw(m_window);
		m_snake.Draw(m_window);

		m_window.display();
	}
}