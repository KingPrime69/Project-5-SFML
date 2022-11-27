#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include"Game.h"
#include "SpriteAnim.h"


int main()
{   
    //Window window;
    //Menu menu;
    //test test;

    //menu.initComponent(window.getSize().x, window.getSize().x);
    //test.initComponent();
    //SpriteAnim anim;

    Game game;
    game.run();
    // Create the main window
    //sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window");
    //window.setFramerateLimit(60);

    // Load a sprite to display
    //sf::Texture texture;
    //if (!texture.loadFromFile("sprite/player (1).png"))return EXIT_FAILURE;


    //anim.createSprite(1, 0, 13, 16, 200, 300);

    //sf::Sprite salameche(texture);
    //salameche.setTexture(texture);
    //salameche.setTextureRect(sf::IntRect(6, 2, 18, 27));
    //salameche.scale(5, 5);
    //salameche.setPosition(300, 300);


    // Create a graphical text to display


    //int count = 0;
    //int frame = 0;
    //int frame2 = 0;
    //// Start the game loop
    //while (window.isOpen())
    //{
    //    window.handleEvents();
    //    // Clear screen
    //    window.clear();
    //    // Draw the sprite
    //    //count++;
    //    //if (count == 10) {
    //    //    salameche.setTextureRect(sf::IntRect(6 + 19 * frame, 2, 18, 27));
    //    //    count = 0;
    //    //    if (frame == 3)frame = 0;
    //    //    else frame++;
    //    //}

    //    // Draw the string
    //    for (unsigned int i = 0; i < menu.componentTextList.size(); i++)window.drawText(menu.componentTextList[i]);

    //    for (unsigned int i = 0; i < test.compSpriteList.size(); i++)window.drawSprite(test.compSpriteList[i]);
    //    //window.drawSprite(salameche);
    //    //window.drawSprite(salameche);
    //    // Update the window
    //    window.display();
    //}
    //return EXIT_SUCCESS;
}