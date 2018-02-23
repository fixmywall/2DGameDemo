#include <iostream>
#include <cstdlib>
#include <time.h>
#include "GameEngine.h"


int main()
{
    srand(time(NULL));

    sf::RenderWindow window(sf::VideoMode(1200, 1200), "Game");
    window.setVerticalSyncEnabled(true);
    //window.setFramerateLimit(60);
//    sf::View view(window.getView());
//    view.zoom(0.7);
//    window.setView(view);
    //window.setKeyRepeatEnabled(false);
    GameEngine game;

    game.run(window);


    return 0;
}