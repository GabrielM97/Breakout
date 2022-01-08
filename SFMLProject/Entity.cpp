#include "Entity.h"

Entity::Entity(float x, float y, const char* texturePath)
{
	//load desired texture
	if (m_texture.loadFromFile(texturePath))
	{
		m_sprite.setTexture(m_texture);
		m_sprite.setOrigin(sf::Vector2f(m_texture.getSize().x / 2.f, m_texture.getSize().y / 2.f));
		m_sprite.setPosition(sf::Vector2f(x, y));

		m_texturWidth = m_sprite.getTexture()->getSize().x;
		m_textureHeight = m_sprite.getTexture()->getSize().y;
	}
}
