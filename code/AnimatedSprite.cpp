#include "AnimatedSprite.hpp"


int AnimatedSprite::getIndexByName(std::string name)
{
    for (int i = 0; i < spriteFrameSets.size(); i++)
    {
        if (spriteFrameSets[i].name == name)
        {
            return i;
        }
    }
    return -1;
}

void AnimatedSprite::play(int index)
{
    frameSetIndex = index;

    playing = true;
}

void AnimatedSprite::play(std::string name)
{
    AnimatedSprite::play(AnimatedSprite::getIndexByName(name));
}

void AnimatedSprite::update(float dt)
{
    if (playing)
    {
        if (clock.getElapsedTime().asSeconds() >= (1 / spriteFrameSets[frameSetIndex].fps))
        {
            spriteFrameSets[frameSetIndex].nextFrame();
        }
    }
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(sf::Sprite(spriteFrameSets[frameSetIndex].frames[spriteFrameSets[frameSetIndex].index]), states);
}
