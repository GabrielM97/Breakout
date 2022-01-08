#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Entity
{
public:
	Entity() = default;
	Entity(float x, float y, const char* texturePath);

	virtual inline sf::Sprite GetSprite() = 0;
	virtual inline unsigned int GetTextureWidth() = 0;
	virtual inline unsigned int GetTextureHeight() = 0;

	virtual void Update(float deltaTime) = 0;

	virtual void CheckCollision(Entity& other) = 0;

protected:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	unsigned int m_texturWidth;
	unsigned int m_textureHeight;

	float speed{ 200.f };

	sf::Vector2f m_dir;
};

