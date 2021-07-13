#include "Player.hpp"
#include "Node.hpp"
#include "AnimatedSprite.hpp"

class Player : public Node, 
{
public:
    AnimatedSprite animatedSprite;

    Player() 
    {
        // default..
        position = sf::Vector2f(50.0f, 50.0f);
    }

    void 
    
};