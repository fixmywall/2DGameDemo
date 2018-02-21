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
    // calculate new position
    if (moving()) {
        double pixDelta = mCurrentSpeed * delta.asSeconds();

        double angleRad = getAngleRad();
        double xDelta = pixDelta * cos(angleRad);
        double yDelta = -pixDelta * sin(angleRad);

        mSprite.move(xDelta, yDelta);
    }
}

double MobileUnit::getAngleRad() const {
    return atan2(mDirection.y, mDirection.x);
}

int MobileUnit::getAngleDeg() const {
    return getAngleRad() * 180 / PI;
}

MobileUnit::MobileUnit() : mMaxSpeed(0), mCurrentSpeed(0) {
}

MobileUnit::MobileUnit(double speed) : mMaxSpeed(speed), mCurrentSpeed(0) {
}


bool MobileUnit::moving() const {
    return mMoving;
}

