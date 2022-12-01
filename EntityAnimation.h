#pragma once
#include "Entity.h"

class EntityAnimation : public Entity
{
protected:
    size_t _count;
    std::vector<sf::IntRect> _animation_pos;

    int _direction;
    bool _isMoving = false;
    bool _isRunning = false;
    int _countFrame;

public:
    EntityAnimation(const sf::Texture&, std::vector<sf::IntRect>);
    void nextAnimation(void);

    void setAnimation(std::vector <sf::IntRect>);
    void movingEntity();

    int getDirection();
    void setDirection(int newDirection);

    bool getMovement();
    void setMovement(bool newMoveState);

    bool getRunning();
    void setRunning();

    void animationSpeed(int frameRate);
};


