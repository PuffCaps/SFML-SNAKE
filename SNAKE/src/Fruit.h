#pragma once

#include <SFML/Graphics.hpp>
#include <random>
#include <iostream>

class Fruit
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	std::random_device m_random;

	int m_tileSize;
	int m_width;
	int m_height;

	float m_xPos;
	float m_yPos;

public:
	Fruit(std::string fileName, int tileSize, int width, int height);
	~Fruit();

	void Update();
	void Draw(sf::RenderWindow& window);
	void RandomizePosition();

	int getXPos() const { return m_xPos; }
	int getYPos() const { return m_yPos; }
};

