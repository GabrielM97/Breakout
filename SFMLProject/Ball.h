#pragma once
#include "Entity.h"

class Ball : public Entity
{
public:
	Ball() = default;
	Ball(float x, float y, const char* texturePath);
	void Update(float deltaTime) override;
	sf::Sprite GetSprite() override { return m_sprite; };
	void CheckCollision(Entity& other) override;

	inline bool GetIsBallOutOfBounds() const { return m_outOfBound; };
	inline void SetIsBallOutOfBounds(bool oob) { m_outOfBound = oob; };

	// Inherited via Entity
	virtual unsigned int GetTextureWidth() override;

	virtual unsigned int GetTextureHeight() override;

private:

	bool m_outOfBound{ false };

};

