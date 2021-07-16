#include "AnimatedSprite.hpp"
               

AnimatedSprite::AnimatedSprite()
{
    // Default..
}


AnimatedSprite::AnimatedSprite(AnimationPack &animPack)
    : animationPack(animPack) { }


void AnimatedSprite::addAnimation(std::string p_name, Animation &p_animation)
{
    animationPack.insert(std::make_pair(p_name, p_animation));
}

void AnimatedSprite::play(std::string p_animation)
{
    if (resetFrameEverytimeYouPlay) 
        resetFrame();

    animation = p_animation;
    playing = true;
}

void AnimatedSprite::stop()
{
    playing = false;
}

void AnimatedSprite::resetFrame()
{
    frame = 0;
}

void AnimatedSprite::nextFrame()
{
    frame = (frame + 1) % getFrameCount(animation);
}

void AnimatedSprite::previousFrame()
{
    if (frame == 0)
    {
        frame = getFrameCount(animation) - 1;
    }
    else frame--;
}

int AnimatedSprite::getFrameCount(std::string &p_animation)
{
    return animationPack[p_animation].frames.size();
}

void AnimatedSprite::update()
{
    if (playing)    
    {
        if (clock.getElapsedTime().asSeconds() >= (1 / (animationPack[animation].fps * speedScale)))
        {
            nextFrame();

            clock.restart();
        }
    }
}

const Animation &AnimatedSprite::getCurrentAnimation() const
{
    return animationPack.at(animation);
}

void AnimatedSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    states.transform *= getTransform();

    target.draw(getCurrentAnimation().frames[frame], states);
}
