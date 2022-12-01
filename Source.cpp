#include <iostream>
#include <fstream>
#include <math.h>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include"Game.h"
#include "SpriteAnim.h"
#include "Player.h"
#include "Pokemon.h"
#include "Move.h"
#include "Combat.h"

#include "Config.h"

using namespace std;

int main()
{
    //Pokemon Tests

    Pokemon Sprigatito("Sprigatito", 5);

    Sprigatito.CheckLevelOpportunity();

    Pokemon Riolu ("Riolu", 5);
    Riolu.setMove(1, "Scratch");

    cout << "Name : " << Sprigatito.getName() << "\n";
    cout << "HP : " << Sprigatito.getCurrentHP() << "\n";
    cout << "Atk : " << Sprigatito.getCurrentAtk() << "\n";
    cout << "Def : " << Sprigatito.getCurrentDef() << "\n";
    cout << "SpeAtk : " << Sprigatito.getCurrentSpeAtk() << "\n";
    cout << "SpeDef : " << Sprigatito.getCurrentSpeDef() << "\n";
    cout << "Speed : " << Sprigatito.getCurrentSpeed() << "\n";
    cout << "NatureID : " << Sprigatito.getNatureID() << "\n";
    cout << "Nature : " << Sprigatito.getNatureName() << "\n\n";

    cout << "Name : " << Riolu.getName() << "\n";
    cout << "HP : " << Riolu.getCurrentHP() << "\n";
    cout << "Atk : " << Riolu.getCurrentAtk() << "\n";
    cout << "Def : " << Riolu.getCurrentDef() << "\n";
    cout << "SpeAtk : " << Riolu.getCurrentSpeAtk() << "\n";
    cout << "SpeDef : " << Riolu.getCurrentSpeDef() << "\n";
    cout << "Speed : " << Riolu.getCurrentSpeed() << "\n";
    cout << "NatureID : " << Riolu.getNatureID() << "\n";
    cout << "Nature : " << Riolu.getNatureName() << "\n\n";


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
    // Start the game loop
    //while (window.isOpen())
    //{
        //window.handleEvents();
        // Clear screen
        //window.clear();
        // Draw the sprite
        //count++;
        //if (count == 10) {
    //    //    salameche.setTextureRect(sf::IntRect(6 + 19 * frame, 2, 18, 27));
    //    //    count = 0;
    //    //    if (frame == 3)frame = 0;
    //    //    else frame++;
        //}

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