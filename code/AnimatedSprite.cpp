#include "AnimatedSprite.hpp"
               

AnimatedSprite::AnimatedSprite()
{
    // Default..
}

AnimatedSprite::AnimatedSprite(AnimationPack &animPack) : AnimationPack{animPack}
{
    
}

void AnimatedSprite::play(int animIndex)
{
    animationIndex = animIndex;

    animations[animationIndex].resetFrame();

    playing = true;
}

void AnimatedSprite::play(std::string name)
{
    AnimatedSprite::play(AnimatedSprite::getIndexByName(name));
}


void AnimatedSprite::stop()
{
    playing = false;
}

void AnimatedSprite::update(float dt)
{
    if (playing)    
    {
        // if (clock.getElapsedTime().asSeconds() >= (1 / (spriteFrameSets[frameSetIndex].fps * speedScale)))
        // {
        //     spriteFrameSets[frameSetIndex].nextFrame();
        // }
    }
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(animations[animationIndex].frames[animations[animationIndex].frameIndex], states);
}
