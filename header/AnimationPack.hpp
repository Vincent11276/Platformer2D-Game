#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Animation.hpp"



class AnimationPack
{
public:
    std::vector<Animation> animations;

    int animationIndex = 0;

    AnimationPack();

    Animation getCurrentAnimation();

    Animation getCurrentAnimation() const;

    int getIndexByName(std::string name);
};