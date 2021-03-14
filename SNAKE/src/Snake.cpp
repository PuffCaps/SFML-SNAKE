#include "Snake.h"

Snake::Snake(std::string fileName, std::string fruitFileName, int tileSize, int width, int height) :
	m_gameOver{ false },
	m_width{ width }, m_height{ height },
	m_tileSize{ tileSize },
	m_isFruitEaten{ false },
	m_direction{ Direction::STOP },
	m_xPos{ static_cast<float>(width / 2) }, m_yPos{ static_cast<float>(height / 2) },
	m_fruit(fruitFileName, tileSize, width, height)
{
	if (!m_texture.loadFromFile(fileName))
	{
		std::cout << "Snake image load error \"" << fileName << "\".\n";
	}
	
	sf::Sprite sprite;
	sprite.setTexture(m_texture);
	sprite.setPosition(m_xPos, m_yPos);
	m_body.push_back(sprite);
}

Snake::~Snake()
{

}

void Snake::Update()
{
	FruitEatCheck();

	if (!m_gameOver)
	{
		m_fruit.Update();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			m_direction = Direction::LEFT;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			m_direction = Direction::RIGHT;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			m_direction = Direction::UP;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			m_direction = Direction::DOWN;
		}

		switch (m_direction)
		{
		case Direction::LEFT:
			MoveSnake(static_cast<float>(-m_tileSize), 0.0f);
			break;
		case Direction::RIGHT:
			MoveSnake(static_cast<float>(m_tileSize), 0.0f);
			break;
		case Direction::UP:
			MoveSnake(0.0f, static_cast<float>(-m_tileSize));
			break;
		case Direction::DOWN:
			MoveSnake(0.0f, static_cast<float>(m_tileSize));
			break;
		}
	}
}

void Snake::MoveSnake(float x, float y)
{
	m_xPos += x;
	m_yPos += y;

	CollisionDetect();

	sf::Sprite sprite;
	if (!m_gameOver)
	{
		sprite.setTexture(m_texture);
		sprite.setPosition(m_xPos, m_yPos);

		if (m_isFruitEaten)
		{
			m_body.push_back(sprite);
		}
		else
		{
			m_body.pop_front();
			m_body.push_back(sprite);
		}
	}
}

void Snake::FruitEatCheck()
{
	if (abs(m_xPos - m_fruit.getXPos()) < 0.1f &&
		abs(m_yPos - m_fruit.getYPos()) < 0.1f)
	{
		m_isFruitEaten = true;
		m_fruit.RandomizePosition();
	}
	else
	{
		m_isFruitEaten = false;
	}
}

void Snake::CollisionDetect()
{
	if (m_xPos >= m_width || m_xPos < 0 ||
		m_yPos >= m_height || m_yPos < 0)
	{
		m_gameOver = true;
	}

	for (int index = 0; index < m_body.size() - 1; index++)
	{
		if (abs(m_body[index].getPosition().x - m_xPos) < 0.1f &&
			abs(m_body[index].getPosition().y - m_yPos) < 0.1f)
		{
			m_gameOver = true;
		}
	}
}


void Snake::Draw(sf::RenderWindow& window)
{
	m_fruit.Draw(window);
	
	for (auto& element : m_body)
	{
		window.draw(element);
	}
}