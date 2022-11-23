#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "Menu.h"
#include "test.h"
#include "SpriteAnim.h"


int main()
{   
    Game window;
    Menu menu;
    test test;

    menu.initComponent(window.getSize().x, window.getSize().x);
    test.initComponent();
    //SpriteAnim anim;

    // Create the main window
    //sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window");
    //window.setFramerateLimit(60);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite/sprite-Starter.png"))return EXIT_FAILURE;


    //anim.createSprite(1, 0, 13, 16, 200, 300);

    //sf::Sprite salameche(texture);
    //salameche.setTexture(texture);
    //salameche.setTextureRect(sf::IntRect(66, 1, 13, 16));
    //salameche.scale(5, 5);
    //salameche.setPosition(300, 300);



    // Create a graphical text to display


    int count = 0;
    int frame = 0;
    // Start the game loop
    while (window.isOpen())
    {
        window.handleEvents();
        // Clear screen
        window.clear();
        // Draw the sprite
        //count++;
        //if (count == 20) {
        //    salameche.setTextureRect(sf::IntRect(66 + 16 * frame, 1, 13, 16));
        //    count = 0;
        //    if (frame == 3)frame = 0;
        //    else frame++;
        //}

        // Draw the string
        for (unsigned int i = 0; i < menu.componentTextList.size(); i++)window.drawText(menu.componentTextList[i]);

        for (unsigned int i = 0; i < test.compSpriteList.size(); i++)window.drawSprite(test.compSpriteList[i]);
        //window.drawSprite(salameche);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}