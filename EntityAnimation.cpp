#include "EntityAnimation.h"
#include "Config.h"
#include "iostream"

EntityAnimation::EntityAnimation(const sf::Texture& texture, std::vector<sf::IntRect> animation_pos) : Entity(texture)
{
    this->_count = 0;
    this->_animation_pos = animation_pos;

    if (animation_pos.size() <= 0)
        throw;

    this->_sprite.setTextureRect(this->_animation_pos[this->_count]);
}

void EntityAnimation::nextAnimation(void)
{
    this->_count++;

    if (this->_count >= this->_animation_pos.size())
        this->_count = 0;

    this->_sprite.setTextureRect(_animation_pos[this->_count]);
}


//
void EntityAnimation::setAnimation(std::vector<sf::IntRect> spriteAnimation)
{
    this->_animation_pos = spriteAnimation;
}

int EntityAnimation::getDirection() {
    return this->_direction;
}

void EntityAnimation::setDirection(int newDirection) {
    this->_direction = newDirection;
}

bool EntityAnimation::getMovement()
{
    return this->_isMoving;
}

bool EntityAnimation::getRunning() {
    return this->_isRunning;
}

void EntityAnimation::setMovement(bool newMoveState)
{
    this->_isMoving = newMoveState;
}

void EntityAnimation::setRunning() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::RShift)) {
        this->_isRunning = true;
        animationSpeed(5);
    }
    else
    {
        animationSpeed(10);
        this->_isRunning = false;
    }
}

void EntityAnimation::animationSpeed(int frameRate) {
    // std::cout << "FrameSpeed : " << frameRate << "\n";
    if (_countFrame % frameRate == 0)
    {
        this->nextAnimation();
        _countFrame = 0;
    }
    _countFrame++;
    std::cout << "countFrame : " << _countFrame << "\n";
}

void EntityAnimation::movingEntity() {
    setMovement(true);
    setRunning();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) {
        setDirection(1);
        if (_isRunning) {
            setAnimation(PLAYER_RUN_LEFT);
            getSprite().move(-20.f, 0.0f);
        }
        else {
            setAnimation(PLAYER_MOVE_LEFT);
            getSprite().move(-10.f, 0.0f);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z)) {
        setDirection(2);
        if (_isRunning) {
            setAnimation(PLAYER_RUN_UP);
            getSprite().move(0.0f, -20.0f);
        }
        else {
            setAnimation(PLAYER_MOVE_UP);
            getSprite().move(0.f, -10.0f);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        setDirection(3);
        if (_isRunning) {
            setAnimation(PLAYER_RUN_RIGHT);
            getSprite().move(20.f, 0.0f);
        }
        else {
            setAnimation(PLAYER_MOVE_RIGHT);
            getSprite().move(10.f, 0.0f);
        }
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        setDirection(4);
        if (_isRunning) {
            setAnimation(PLAYER_RUN_DOWN);
            getSprite().move(0.f, 20.0f);
        }
        else {
            setAnimation(PLAYER_MOVE_DOWN);
            getSprite().move(0.f, 10.0f);
        }
    }
    else {
        setMovement(false);
        int direction = getDirection();
        switch (direction) {
        case 1:
            setMovement(false);
            getSprite().setTextureRect(sf::IntRect(28, 34, 17, 23));
            break;
        case 2:
            setMovement(false);
            getSprite().setTextureRect(sf::IntRect(27, 60, 17, 25));
            break;
        case 3:
            setMovement(false);
            getSprite().setTextureRect(sf::IntRect(25, 89, 17, 23));
            break;
        case 4:
            setMovement(false);
            getSprite().setTextureRect(sf::IntRect(26, 3, 17, 27));
            break;
        default:
            break;
        }
    }
    //std::cout << "Direction : " << getDirection() << "\n";
}