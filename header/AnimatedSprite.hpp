#pragma once

#include <vector>

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "AnimationPack.hpp"



class AnimatedSprite : public sf::Drawable, public sf::Transformable, public AnimationPack
{
public:
    bool            playing;
    float           speedScale;
    bool            centered;
    
    AnimatedSprite();

    AnimatedSprite(AnimationPack &anims);

    void play(int index=0);

    void play(std::string name);

    void stop();

    void update(float dt);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};