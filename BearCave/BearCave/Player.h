#pragma once
#include "GameObject.h"

class Player: public GameObject
{
private:
	float movementSpeed;

	float jumpHeight;

	sf::Vector2f movementVector;

	bool isGrounded;

	//Variable functions
	void initVariables();
	virtual void initTextures(std::string texturePath);
	virtual void initSprite(float xPos, float yPos);

public:
	//Constructors/Destructors
	Player();
	virtual ~Player();

	//Functions
	bool isAnyKeyPressed();
	const float getSpeed() const;
	const sf::Vector2f getMovementVector() const;

	void IsGrounded(bool groundedCheck);
	void resetMovementVectorY();

	void ApplyGravity();
	virtual void updateInput();
	virtual void updatePosition();
	virtual void Update() override;
	virtual void Render(sf::RenderTarget* target) override;
};

