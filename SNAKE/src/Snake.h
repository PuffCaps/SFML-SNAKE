#pragma once

#include <SFML/Graphics.hpp>
#include <deque>
#include "Fruit.h"

class Snake
{
private:
	enum class Direction
	{
		STOP,
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

private:
	bool m_gameOver;

	int m_width;
	int m_height;
	int m_tileSize;

	bool m_isFruitEaten;

	sf::Texture m_texture;
	Direction m_direction;

	float m_xPos;
	float m_yPos;

	Fruit m_fruit;
	std::deque<sf::Sprite> m_body;

	//Function
	void MoveSnake(float x, float y);
	void FruitEatCheck();
	void CollisionDetect();

public:
	Snake(std::string fileName, std::string fruitFileName, int tileSize, int width, int height);
	~Snake();

	void Update();

	void Draw(sf::RenderWindow& window);
};

