#include "Animation.hpp"


void Animation::resetFrame()
{
    frameIndex = 0;
}

void Animation::nextFrame()
{
    if (frameIndex > frames.size())
    {
        frameIndex = 0;
    }
    else frameIndex++;
    
}

void Animation::previousFrame()
{
    if (frameIndex == 0)
    {
        frameIndex = frames.size() - 1;
    }
    else frameIndex--;
}

