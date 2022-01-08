#include "Brick.h"

Brick::Brick(float x, float y, const char* texturePath):
	Entity(x, y, texturePath)
{
}

void Brick::Update(float deltaTime)
{
}

void Brick::CheckCollision(Entity& other)
{
	if (m_sprite.getGlobalBounds().intersects(other.GetSprite().getGlobalBounds()))
	{
		m_destroyed = true;
	}
}

unsigned int Brick::GetTextureWidth()
{
	return m_texturWidth;
}

unsigned int Brick::GetTextureHeight()
{
	return m_textureHeight;
}
