//
// Created by Oliver Yang on 2/15/18.
//

#include "PlayableGameState.h"

void PlayableGameState::handleEvent(const sf::Event& event) {
    for (auto& u: mUnits) {
        u->handleEvent(event);
    }
}

void PlayableGameState::updateState(const sf::Time &delta) {
    for (auto& u: mUnits) {
        u->updateState(delta);
    }
}

void PlayableGameState::draw(sf::RenderTarget &target, float interp) {
    target.draw(mMap);
    for (int i = 0; i < mUnits.size(); i++) {
        mUnits[i]->draw(target, interp );
    }

    // set view centered at camera center
    sf::View centered = target.getView();
    centered.setCenter(mCamera->center());
    target.setView(centered);

}

/**
 * Adds an Abstract Unit to game state while taking ownership of it
 * @param u Unique ptr to AbstracUnit
 */
void PlayableGameState::insertUnit(AbstractUnit::UPtr u) {
    mUnits.push_back(std::move(u));
}

/**
 * Default ctor. Empty state, contains no map nor units
 */
PlayableGameState::PlayableGameState() {
}

void PlayableGameState::setMap(const TileMap &map) {
    mMap = map;
}

void PlayableGameState::setCamera(Camera::SPtr camera) {
    mCamera = camera;
}



