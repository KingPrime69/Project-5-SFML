#include "Player.h"
#include "Config.h"


Player::Player(const sf::Texture& texture) :
    EntityAnimation(texture, std::vector<sf::IntRect>(PLAYER_MOVE_DOWN))
{
    this->_sprite.scale(5, 5);
    this->_sprite.setPosition(100.f, 100.f);
}
