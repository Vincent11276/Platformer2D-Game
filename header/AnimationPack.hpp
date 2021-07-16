#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Animation.hpp"



class AnimationPack : public std::unordered_map<std::string, Animation>
{
public:
    void addAnimation(std::string name, Animation animation);

    AnimationPack();
};