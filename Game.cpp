#include "Game.h"

Game::Game()
{

}

int Game::run()
{
    // Load a sprite to display
    //sf::Texture texture;
    //if (!texture.loadFromFile("sprite/player (1).png"))return EXIT_FAILURE;


    //anim.createSprite(1, 0, 13, 16, 200, 300);

    //sf::Sprite salameche(texture);
    //salameche.setTexture(texture);
    //salameche.setTextureRect(sf::IntRect(6, 2, 18, 27));
    //salameche.scale(5, 5);
    //salameche.setPosition(300, 300);

    
    while (this->window.isOpen())
    {
        this->window.handleEvents();
        // Clear screen
        this->window.clear();
        // Draw the sprite
        //count++;
        //if (count == 10) {
        //    salameche.setTextureRect(sf::IntRect(6 + 19 * frame, 2, 18, 27));
        //    count = 0;
        //    if (frame == 3)frame = 0;
        //    else frame++;
        //}

        // Draw the string

        //this->window.drawSprite(salameche);

        //for (unsigned int i = 0; i < menu.componentTextList.size(); i++)this->window.drawText(menu.componentTextList[i]);

        //for (unsigned int i = 0; i < test.compSpriteList.size(); i++)this->window.drawSprite(test.compSpriteList[i]);
        
        //window.drawSprite(salameche);
        //window.drawSprite(salameche);
        // Update the window
        this->window.display();
    }
    return EXIT_SUCCESS;
}
