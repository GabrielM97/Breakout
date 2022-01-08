#include "Player.h"

extern const int WIDTH;
extern const int HEIGHT;

Player::Player(float x, float y, const char* texturePath) : 
	Entity(x, y,texturePath)
{
	//m_dir = sf::Vector2f(-1.f, 1.f);
	speed = 300.f;
}

void Player::Update(float deltaTime)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//m_sprite.move(-1.f * deltaTime * speed, 0.f);
		m_dir = sf::Vector2f(-1.f, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//m_sprite.move(1.f * deltaTime * speed, 0.f);
		m_dir = sf::Vector2f(1.f, 0.f);
	}

	if ((m_sprite.getPosition().x <= 0 + (m_texturWidth / 2)) ||
		(m_sprite.getPosition().x >= WIDTH - (m_texturWidth / 2)))
	{
		m_dir.x *= -1.f;
	}

	m_sprite.move(m_dir * deltaTime * speed);
		
}

void Player::CheckCollision(Entity& other)
{
}

unsigned int Player::GetTextureWidth()
{
	return m_texturWidth;
}

unsigned int Player::GetTextureHeight()
{
	return m_textureHeight;
}


