#pragma once
#include "Entity.h"
class Player : public Entity
{
public:
	Player() = default;
	Player(float x, float y, const char * texturePath);
	void Update(float deltaTime) override;
	sf::Sprite GetSprite() override { return m_sprite; };

	void CheckCollision(Entity& other) override;

	// Inherited via Entity
	virtual unsigned int GetTextureWidth() override;
	virtual unsigned int GetTextureHeight() override;
};

