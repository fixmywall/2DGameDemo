//
// Created by Oliver Yang on 2/15/18.
//

#include "PlayableGameState.h"

void PlayableGameState::handleEvent(const sf::Event &event) {
    for (auto& u: mUnits) {
        u->handleEvent(event);
    }
}

void PlayableGameState::updateState(const sf::Time &delta) {
    for (auto& u: mUnits) {
        u->updateState(delta);
    }
}

void PlayableGameState::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mMap);
    for (int i = 0; i < mUnits.size(); i++) {
        target.draw(*mUnits[i]);
    }

}

/**
 * Adds an Abstract Unit to game state while taking ownership of it
 * @param u Unique ptr to AbstracUnit
 */
void PlayableGameState::insertUnit(AbstractUnit::UPtr u) {
    mUnits.push_back(std::move(u));
}

/**
 * Default ctor. Loads a default map
 */
PlayableGameState::PlayableGameState() {
    mMap.load("map/desert.tmx");
}
