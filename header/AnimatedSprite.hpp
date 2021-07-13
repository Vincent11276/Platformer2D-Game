#pragma once

#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>


#include "Node.hpp"
#include "SpriteFrames.hpp"


class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
public:
    SpriteFrames    frames;
    int             frameIndex;
    bool            playing;
    float           speedScale;
    bool            centered;
    
    AnimatedSprite();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    int getIndexByName(std::string name);

};