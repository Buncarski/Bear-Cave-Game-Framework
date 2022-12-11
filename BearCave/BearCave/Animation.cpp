#include "Animation.h"

Animation::~Animation()
{
	for (auto& i : animationTextures) {
		delete i;
	}
}

void Animation::addAnimationFrame(std::string texturePath)
{
	animationTextures.push_back(new sf::Texture());
	animationTextures.back()->loadFromFile(texturePath);
}
