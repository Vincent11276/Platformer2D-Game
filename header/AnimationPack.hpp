#pragma once

#include <vector>
#include <string>

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Texture.hpp>
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

    bool loadSpriteSheet(std::string &path, sf::Vector2i frameSize, bool append=false);
};