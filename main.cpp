#include <iostream>
#include <cstdlib>
#include <time.h>
#include "GameEngine.h"


int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Game");
    GameEngine game;

    game.run(window);


    return 0;
}