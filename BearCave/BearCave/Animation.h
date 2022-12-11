#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>

class Animation
{
protected:
	std::vector<sf::Texture*> animationTextures;
	int animationSpeed;

	Animation() = default;
	virtual ~Animation();

public:
	void addAnimationFrame(std::string texturePath);
};

/*
TODO:
	-EXPAND AND IMPLEMENT ON ANIMATION AND ANIMATOR CLASS
	-THE IDEA IS TO HAVE THESE CLASSES BE USED AS ANIMATORS OF OBJECTS THAT HAVE ANIMATED SPRITES
*/