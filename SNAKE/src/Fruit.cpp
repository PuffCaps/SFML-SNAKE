#include "Fruit.h"

Fruit::Fruit(std::string fileName, int tileSize, int width, int height) :
	m_tileSize{ tileSize },
	m_width{ width }, m_height{ height }
{
	if (!m_texture.loadFromFile(fileName))
	{
		std::cout << "Fruit image load error \"" << fileName << "\".\n";
	}

	m_sprite.setTexture(m_texture);

	srand(m_random());
	
	m_xPos = (rand() % (m_width / m_tileSize) * m_tileSize);
	m_yPos = (rand() % (m_height / m_tileSize) * m_tileSize);
}

Fruit::~Fruit()
{

}

void Fruit::Update()
{
	m_sprite.setPosition(static_cast<float>(m_xPos), static_cast<float>(m_yPos));
}

void Fruit::Draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

void Fruit::RandomizePosition()
{
	m_xPos = (rand() % (m_width / m_tileSize) * m_tileSize);
	m_yPos = (rand() % (m_height / m_tileSize) * m_tileSize);
}