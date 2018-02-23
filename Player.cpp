//
// Created by Oliver Yang on 2/13/18.
//

#include "Player.h"

Player::Player() : MobileUnit(270){
    sf::Texture* t = new sf::Texture;
    t->loadFromFile("sprites/player.png");
    mSprite.setTexture(*t);
    mSprite.scale(0.3, 0.3);
}

void Player::handleEvent(const sf::Event& event){
    if (event.type == sf::Event::KeyPressed) {      // key pressed
        sf::Keyboard::Key key = event.key.code;
    }

    // key released
    else if (event.type == sf::Event::KeyReleased) {
        sf::Keyboard::Key key = event.key.code;
    }
}

void Player::updateState(const sf::Time& delta) {
    // check if movement keys are pressed

    mMoving = false;
    mDirection.x = 0;
    mDirection.y = 0;

    // movement keys
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        mCurrentSpeed = mMaxSpeed;
        mMoving = true;
        mDirection.y += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        mCurrentSpeed = mMaxSpeed;
        mMoving = true;
        mDirection.y -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        mCurrentSpeed = mMaxSpeed;
        mMoving = true;
        mDirection.x -= 1;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        mCurrentSpeed = mMaxSpeed;
        mMoving = true;
        mDirection.x += 1;
    }


    MobileUnit::updateState(delta);
}

void Player::attachCamera(Camera::SPtr camera) {
    mCamera = camera;
}

void Player::setPosition(double x, double y) {
    mCamera->setCenter(x, y);
    MobileUnit::setPosition(x, y);
}

void Player::move(double x, double y) {
    MobileUnit::move(x, y);
    mCamera->setCenter(this->getPosition());
}
