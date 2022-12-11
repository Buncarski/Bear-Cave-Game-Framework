#pragma once
#include "Animation.h"
#include <map>
#include <string>

class Animator
{
	std::map<std::string, Animation> animations;

	virtual Animation selectAnimation(std::string animName) = 0;
};

/*
TODO:
	-EXPAND AND IMPLEMENT ON ANIMATION AND ANIMATOR CLASS
	-THE IDEA IS TO HAVE THESE CLASSES BE USED AS ANIMATORS OF OBJECTS THAT HAVE ANIMATED SPRITES
*/