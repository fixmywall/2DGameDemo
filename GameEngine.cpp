//
// Created by Oliver Yang on 2/15/18.
//
#include "GameEngine.h"
#include "PlayableGameState.h"
#include "Player.h"
#include "TileMap.h"

//void GameEngine::run( sf::RenderWindow& window) {
//    sf::Clock clock;
//    sf::Time currentTime = clock.getElapsedTime();
//
//    // game loop
//    while (window.isOpen()) {
//        sf::Time newTime = clock.getElapsedTime();
//        sf::Time frameTime = clock.getElapsedTime() - currentTime;
//        currentTime = newTime;
//
//
//        // handle input
//        sf::Event event;
//        while (window.pollEvent(event)) {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//                return;
//            }
//
//            mCurrentState->handleEvent(event);  // handle input
//        }
//
//        // update state
//        while (frameTime > sf::Time::Zero) {
//            // deklta time is minimum of dt and frame time
//            sf::Time deltaTime;
//            if (frameTime > mRefreshPeriod) {
//                deltaTime = mRefreshPeriod;
//            }
//            else {
//                deltaTime = frameTime;
//            }
//            frameTime -= deltaTime;
//
//            mCurrentState->updateState(deltaTime);
//        }
//
//
//        // render state
//        window.clear();
//        window.draw(*mCurrentState);
//        window.display();
//    }
//}

void GameEngine::run( sf::RenderWindow& window) {
    sf::Clock clock;
    sf::Time currentTime = clock.getElapsedTime();
    sf::Time accumulator = sf::Time::Zero;

    // game loop
    while (window.isOpen()) {
        sf::Time newTime = clock.getElapsedTime();
        sf::Time frameTime = clock.getElapsedTime() - currentTime;
        currentTime = newTime;
        accumulator += frameTime;


        // handle input
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }

            mCurrentState->handleEvent(event);  // handle input
        }

        // update state
        while (accumulator >= mRefreshPeriod) {
            mCurrentState->updateState(mRefreshPeriod);
            accumulator -= mRefreshPeriod;
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
    Camera::SPtr camera(new Camera());
    TileMap map;
    map.load("map/desert.tmx");
    gs->setMap(map);
    gs->setCamera(camera);

    Player* p = new Player;
    p->attachCamera(camera);
    sf::Vector2f position(map.size().x, map.size().y);
    p->setPosition(position.x, position.y);

    gs->insertUnit(AbstractUnit::UPtr(p));

    setCurrentState(AbstractGameState::UPtr(gs));

    mRefreshPeriod = sf::milliseconds(16);      // 60 hz refresh
}

void GameEngine::setCurrentState(AbstractGameState::UPtr state) {
    mCurrentState = std::move(state);
}
