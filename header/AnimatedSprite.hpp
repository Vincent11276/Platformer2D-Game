#pragma once

#include <vector>
#include <unordered_map>
#include <iostream> // temporary

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "Animation.hpp"


typedef std::unordered_map<std::string, Animation> AnimationPack;

// typedef std::vector<Animation> AnimationPack;

class AnimatedSprite : public sf::Drawable, public sf::Transformable
{
private:
    AnimationPack   animationPack;
    sf::Clock       clock;

public:
    std::string     animation   = "";
    int             frame       = 0;
    bool            playing     = false;
    float           speedScale  = 1;
    bool            centered    = true;
    bool            resetFrameEverytimeYouPlay = true;

    AnimatedSprite();

    AnimatedSprite(AnimationPack &animPack);

    void addAnimation(std::string p_name, Animation &p_animation);

    void play(std::string name);

    void stop();

    void resetFrame();

    void nextFrame();

    void previousFrame();

    const Animation &getCurrentAnimation() const;

    int getFrameCount(std::string &animation);

    void update();

    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

};