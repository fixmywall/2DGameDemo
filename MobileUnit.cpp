//
// Created by Oliver Yang on 2/14/18.
//

#include "MobileUnit.h"
#include <cmath>

double MobileUnit::getSpeed() const {
    return mMaxSpeed;
}

// updates position based on speed
void MobileUnit::updateState(const sf::Time &delta) {
    mLastDrawPosition = getPosition();      // store prev position

    // calculate new position
    if (moving()) {
        double pixDelta = mCurrentSpeed * delta.asSeconds();

        double angleRad = getAngleRad();
        double xDelta = pixDelta * cos(angleRad);
        double yDelta = -pixDelta * sin(angleRad);

        move(xDelta, yDelta);
    }
}

double MobileUnit::getAngleRad() const {
    return atan2(mDirection.y, mDirection.x);
}

int MobileUnit::getAngleDeg() const {
    return getAngleRad() * 180 / PI;
}

MobileUnit::MobileUnit() : mMaxSpeed(0), mCurrentSpeed(0), mLastDrawPosition(0.0f, 0.0f) {
}

MobileUnit::MobileUnit(double speed) : mMaxSpeed(speed), mCurrentSpeed(0) {
}


bool MobileUnit::moving() const {
    return mMoving;
}

void MobileUnit::move(double x, double y) {
    mPos.x += x;
    mPos.y += y;
}


void MobileUnit::draw(sf::RenderTarget &target, float interp) {
    // get interp
    sf::Vector2f pos = getPosition();
    sf::Vector2f posInterp;
    posInterp = pos * interp + mLastDrawPosition * (1.0f - interp);
    mSprite.setPosition(posInterp);

    target.draw(mSprite);
}

const sf::Vector2f &MobileUnit::getPosition() const {
    return mPos;
}



