#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "SpriteAnim.h"


int main()
{   
    Game window;
    SpriteAnim anim;

    // Create the main window
    //sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window");
    //window.setFramerateLimit(60);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite/sprite-Starter.png"))return EXIT_FAILURE;


    anim.createSprite(1, 0, 13, 16, 200, 300);

    sf::Sprite salameche(texture);
    salameche.setTexture(texture);
    salameche.setTextureRect(sf::IntRect(66, 1, 13, 16));
    salameche.scale(5, 5);
    salameche.setPosition(500, 500);



    // Create a graphical text to display
    sf::Font font2;
    if (!font2.loadFromFile("pokemonSolid.ttf"))return EXIT_FAILURE;
    sf::Text text2("Pokiiiimon", font2, 100);
    text2.setFillColor(sf::Color::Yellow);

    sf::Font font;
    if (!font.loadFromFile("pokemonHollow.ttf"))return EXIT_FAILURE;
    sf::Text text("Pokiiiimon", font, 100);
    text.setFillColor(sf::Color::Blue);


    int count = 0;
    int frame = 0;
    // Start the game loop
    while (window.isOpen())
    {
        window.handleEvents();
        // Clear screen
        window.clear();
        // Draw the sprite
        count++;
        if (count == 20) {
            salameche.setTextureRect(sf::IntRect(66 + 16 * frame, 1, 13, 16));
            count = 0;
            if (frame == 3)frame = 0;
            else frame++;
        }
        window.drawSprite(salameche);

        // Draw the string
        window.drawText(text2);
        window.drawText(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}