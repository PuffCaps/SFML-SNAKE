#pragma once

#include <SFML/Graphics.hpp>


class Tilemap
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;

	int m_tileSize;
	int m_tileCountX;
	int m_tileCountY;
public:
	Tilemap(std::string fileName, int tileSize, int tileCountX, int tileCountY);
	~Tilemap();
	
	void Draw(sf::RenderWindow& window);
};

