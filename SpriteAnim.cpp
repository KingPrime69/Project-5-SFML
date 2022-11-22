#include "SpriteAnim.h"



SpriteAnim::SpriteAnim()
{
}

SpriteAnim::~SpriteAnim()
{
}

int SpriteAnim::createSprite(int x, int y, int width, int height, int pX, int pY)
{
    sf::Texture texture;
    if (!texture.loadFromFile("sprite/spriteSheet.png"))return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(x, y, width, height));
    sprite.scale(5, 5);
    sprite.setPosition(pX, pY);
}

void SpriteAnim::playAnim(int increment)
{
    window.draw(laporeille);
}
