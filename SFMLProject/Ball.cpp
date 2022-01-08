#include "Ball.h"
#include "Sounds.h"

extern const int WIDTH;
extern const int HEIGHT;

Ball::Ball(float x, float y, const char* texturePath):
	Entity(x, y, texturePath)
{
	m_dir = sf::Vector2f(-1.f, -1.f);
	speed = 250 ;

	Sounds::RegisterSound("ball", "sfx-pop3.wav");
}

void Ball::Update(float deltaTime)
{
	m_sprite.move(sf::Vector2f(m_dir * deltaTime * speed));

	//std::cout << ballWidth << "  " << ballHeight << "\n";

	if ((m_sprite.getPosition().x <= 0 + (m_texturWidth / 2)) ||
		(m_sprite.getPosition().x >= WIDTH - (m_texturWidth / 2)))
	{
		Sounds::PlayerRegisteredSound("ball");
		m_dir.x *= -1.f;
	}
	else if ((m_sprite.getPosition().y <= 0 + (m_textureHeight / 2)))
	{
		m_dir.y *= -1;
		Sounds::PlayerRegisteredSound("ball");
	}
	else if ((m_sprite.getPosition().y >= HEIGHT + (m_textureHeight / 2)))
	{
		m_outOfBound = true;
	}
}
void Ball::CheckCollision(Entity& other)
{
	if (m_sprite.getGlobalBounds().intersects(other.GetSprite().getGlobalBounds()))
	{
		Sounds::PlayerRegisteredSound("ball");
		m_dir.y *= -1;
	}
}

unsigned int Ball::GetTextureWidth()
{
	return m_texturWidth;
}

unsigned int Ball::GetTextureHeight()
{
	return m_textureHeight;
}

