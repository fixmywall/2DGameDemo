//
// Created by Oliver Yang on 2/13/18.
//

#include "Player.h"

Player::Player() : MobileUnit(80){
    sf::Texture* t = new sf::Texture;
    t->loadFromFile("sprites/player.png");
    mSprite.setTexture(*t);
    mSprite.scale(0.3, 0.3);
}

void Player::handleEvent(const sf::Event &event) {
    if (event.type == sf::Event::KeyPressed) {
        sf::Keyboard::Key key = event.key.code;

        // up key
        if (key == sf::Keyboard::W) {
            mCurrentSpeed = mMaxSpeed;
            if (movingLeft()) {
                mMovementAngle = 135;
            }
            else if (movingRight()) {
                mMovementAngle = 45;
            }
            else {
                mMovementAngle = 90;
            }
        }

        // down key
        else if (key == sf::Keyboard::S) {
            mCurrentSpeed = mMaxSpeed;
            if (movingLeft()) {
                mMovementAngle = 225;
            }
            else if (movingRight()) {
                mMovementAngle = 315;
            }
            else {
                mMovementAngle = 270;
            }
        }

        // left key
        else if (key == sf::Keyboard::A) {
            mCurrentSpeed = mMaxSpeed;
            if (movingUp()) {
                mMovementAngle = 135;
            }
            else if (movingDown()) {
                mMovementAngle = 225;
            }
            else {
                mMovementAngle = 180;
            }
        }

        // right key
        else if (key == sf::Keyboard::D) {
            mCurrentSpeed = mMaxSpeed;
            if (movingUp()) {
                mMovementAngle = 45;
            }
            else if (movingDown()) {
                mMovementAngle = 315;
            }
            else {
                mMovementAngle = 0;
            }
        }

    }
}
