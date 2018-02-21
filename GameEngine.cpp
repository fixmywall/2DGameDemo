//
// Created by Oliver Yang on 2/15/18.
//

#include "GameEngine.h"
#include "PlayableGameState.h"
#include "Player.h"

void GameEngine::run( sf::RenderWindow& window) {
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event;

        // handle events
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            mCurrentState->handleEvent(event);  // handle input
        }

        // update state
        if (clock.getElapsedTime() >= mRefreshPeriod) {
            mCurrentState->updateState(clock.getElapsedTime());
            clock.restart();
        }

        // render state
        window.clear();
        window.draw(*mCurrentState);
        window.display();
    }
}

GameEngine::GameEngine()
{
    PlayableGameState* gs = new PlayableGameState();
    gs->insertUnit(AbstractUnit::UPtr(new Player()));

    setCurrentState(AbstractGameState::UPtr(gs));

    mRefreshPeriod = sf::milliseconds(17);      // 50 hz refresh
}

void GameEngine::setCurrentState(AbstractGameState::UPtr state) {
    mCurrentState = std::move(state);
}
