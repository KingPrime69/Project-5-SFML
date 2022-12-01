#pragma once

#define PLAYER_TEXTURE_PATH "sprite/player.png"

// Player walking sprites 
#define PLAYER_MOVE_LEFT                                                                                                        \
    {                                                                                                                            \
         sf::IntRect(28, 34, 17, 23), sf::IntRect(7, 33, 17, 23), sf::IntRect(28, 34, 17, 23), sf::IntRect(49, 34, 17, 23) \
    }

#define PLAYER_MOVE_UP                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(27, 60, 17, 25), sf::IntRect(6, 60, 17, 25), sf::IntRect(27, 60, 17, 25), sf::IntRect(49, 60, 17, 25) \
    }

#define PLAYER_MOVE_RIGHT                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(25, 89, 17, 25), sf::IntRect(4, 89, 17, 25), sf::IntRect(25, 89, 17, 25), sf::IntRect(46, 89, 17, 25) \
    }

#define PLAYER_MOVE_DOWN                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(26, 3, 17, 27), sf::IntRect(7, 2, 17, 27), sf::IntRect(26, 3, 17, 27), sf::IntRect(45, 2, 17, 27) \
    }


// Player running sprites
#define PLAYER_RUN_LEFT                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(114, 33, 17, 22), sf::IntRect(92, 33, 17, 22), sf::IntRect(114, 33, 17, 22), sf::IntRect(136, 33, 17, 22) \
    }

#define PLAYER_RUN_UP                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(114, 4, 17, 25), sf::IntRect(95, 4, 17, 25), sf::IntRect(114, 4, 17, 25), sf::IntRect(133, 4, 17, 25) \
    }

#define PLAYER_RUN_RIGHT                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(112, 86, 17, 22), sf::IntRect(91, 86, 17, 22), sf::IntRect(112, 86, 17, 22), sf::IntRect(133, 86, 17, 22) \
    }

#define PLAYER_RUN_DOWN                                                                                                        \
    {                                                                                                                            \
        sf::IntRect(114, 57, 16, 25), sf::IntRect(92, 58, 20, 25), sf::IntRect(114, 57, 16, 25), sf::IntRect(133, 57, 20, 25) \
    }