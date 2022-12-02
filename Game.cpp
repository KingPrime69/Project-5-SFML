#include "Game.h"
#include "Player.h"
#include "Config.h"

Game::Game() : window(sf::VideoMode(1200, 800), "Poke moon")
{
    this->window.setFramerateLimit(60);
    this->viewManager = new ViewManager(&this->window);
}

Game::~Game()
{

}

void Game::setWindow(int width, int height, const char* windowName)
{
    this->window.setSize(sf::Vector2u(width, height));
}


sf::Vector2u Game::getSize()
{
    return this->window.getSize();
}

 

void Game::handleEvents(void)
{
    sf::Event event;
    while (this->window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            this->window.close();
    }
}

// Used to draw an entity in the game
/*void Game::drawEntity(const Entity& entity)
{
    this->window.draw(entity.getSprite());
}*/


int Game::run()
{
    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite/player (1).png"))return EXIT_FAILURE;


    //anim.createSprite(1, 0, 13, 16, 200, 300);

    //sf::Sprite salameche(texture);
    //salameche.setTexture(texture);
    //salameche.setTextureRect(sf::IntRect(6, 2, 18, 27));
    //salameche.scale(5, 5);
    //salameche.setPosition(300, 300);


    // Player creation & movement test
    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile(PLAYER_TEXTURE_PATH))
    {
        // error...
    }
    Player player = Player(playerTexture);
    player.setDirection(4); // Sets player's direction to the south
    
    while (this->window.isOpen())
    {
        this->handleEvents();
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

        // Checks is a key is pressed before moving the player
        if (sf::Keyboard::isKeyPressed)
        {
            player.movingEntity();
        }
        
        // Redraws the player in the window
        //this->drawEntity(player);


        this->viewManager->swapViewButton();
        this->viewManager->SwapViewKeyboard();
        this->viewManager->drawCurrentView();
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

