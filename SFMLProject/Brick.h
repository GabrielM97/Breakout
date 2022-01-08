#pragma once
#include "Entity.h"

class Brick : public Entity
{
public:
	Brick() = default;
	Brick(float x, float y, const char* texturePath);
	void Update(float deltaTime) override;
	sf::Sprite GetSprite() override { return m_sprite; };

	void CheckCollision(Entity & other) override;

	// Inherited via Entity
	virtual unsigned int GetTextureWidth() override;
	virtual unsigned int GetTextureHeight() override;

	inline bool GetIsDestroyed() const { return m_destroyed; };

private:

	bool m_destroyed{ false };
};

