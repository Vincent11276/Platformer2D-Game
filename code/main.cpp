#include <iostream>
#include <string>
#include <vector>


using namespace std;


#include <SFML/Graphics.hpp>

#include "AnimatedSprite.hpp"


int main()
{
    std::string spriteSheetPath = "C:\\Users\\Vincent\\Documents\\GitHub\\Platformer2D-Game\\assets\\Arts\\Intellect Devourer Sprites.png";

    sf::Texture texture;
    if (!texture.loadFromFile(spriteSheetPath))
        return EXIT_FAILURE;

    Animation idleAnimation;
    idleAnimation.fps = 12;
    if (!idleAnimation.loadSpriteSheet(texture, sf::Vector2i(32, 32), 8, false, 1))
        return EXIT_FAILURE;

    AnimatedSprite animatedSprite;
    animatedSprite.addAnimation("idle", idleAnimation);

    animatedSprite.scale(sf::Vector2f(10, 10));
    animatedSprite.play("idle");

    sf::RenderWindow window(sf::VideoMode(1280, 720), "Animated Sprite Demo");
    window.setVerticalSyncEnabled(true);

    sf::Font bigSpaceFont;
    if (!bigSpaceFont.loadFromFile("C:\\Users\\Vincent\\Documents\\GitHub\\Platformer2D-Game\\assets\\Fonts\\big-space-font\\BigSpace-rPKx.ttf"))
        return EXIT_FAILURE;

    sf::Text fpsText;
    fpsText.setFont(bigSpaceFont);
    fpsText.setFillColor(sf::Color::White);

    sf::Clock clock;

    while (window.isOpen()) 
    {
        float delta = clock.restart().asMicroseconds();

        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();

                default:
                    break;
            }
        }
        fpsText.setString(std::to_string(1000000.0f / delta));
        animatedSprite.update();

        window.clear();
        window.draw(animatedSprite);
        window.draw(fpsText);   
        window.display();
    }



    return EXIT_SUCCESS;
}