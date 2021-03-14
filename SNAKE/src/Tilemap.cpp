#include "Tilemap.h"
#include <iostream>

Tilemap::Tilemap(std::string fileName, int tileSize, int tileCountX, int tileCountY) :
	m_tileSize{ tileSize }, m_tileCountX{ tileCountX }, m_tileCountY{ tileCountY }
{
	if (!m_texture.loadFromFile(fileName))
	{
		std::cout << "Tile image load error \"" << fileName << "\".\n";
	}

	m_sprite.setTexture(m_texture);
}

Tilemap::~Tilemap()
{

}

void Tilemap::Draw(sf::RenderWindow& window)
{
	for (int row = 0; row < m_tileCountY; row++)
	{
		for (int col = 0; col < m_tileCountX; col++)
		{
			m_sprite.setPosition(col * m_tileSize, row * m_tileSize);
			window.draw(m_sprite);
		}
	}
}