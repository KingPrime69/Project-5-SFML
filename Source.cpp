#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>


int main()
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 800), "SFML window");
    window.setFramerateLimit(60);

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("sprite/spriteSheet.png"))return EXIT_FAILURE;
    sf::Sprite laporeille(texture);
    laporeille.setTexture(texture);
    laporeille.setTextureRect(sf::IntRect(81, 25, 25, 27));
    laporeille.scale(5, 5);
    laporeille.setPosition(200, 300);

    sf::Sprite salameche(texture);
    salameche.setTexture(texture);
    salameche.setTextureRect(sf::IntRect(1044, 338, 11, 18));
    salameche.scale(5, 5);
    salameche.setPosition(500, 500);



    // Create a graphical text to display
    sf::Font font2;
    if (!font2.loadFromFile("pokemonSolid.ttf"))return EXIT_FAILURE;
    sf::Text text2("Pokémon", font2, 100);
    text2.setFillColor(sf::Color::Yellow);

    sf::Font font;
    if (!font.loadFromFile("pokemonHollow.ttf"))return EXIT_FAILURE;
    sf::Text text("Pokémon", font, 100);
    text.setFillColor(sf::Color::Blue);


    int count = 0;
    int frame = 0;
    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();
        // Draw the sprite
        count++;
        if (count == 15) {
            frame++;
            laporeille.setTextureRect(sf::IntRect(81+27*frame, 25, 25, 27));
            salameche.setTextureRect(sf::IntRect(1044 + 18 * frame, 338, 11, 18));
            count = 0;
            if (frame == 3)frame = 0;
        }
        window.draw(laporeille);
        window.draw(salameche);

        // Draw the string
        window.draw(text2);
        window.draw(text);
        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}