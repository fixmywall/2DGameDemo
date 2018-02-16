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
    // do something!!!
    double pixDelta = mCurrentSpeed * delta.asSeconds();

    double xDelta = pixDelta * cos(getAngleRad());
    double yDelta = -pixDelta * sin(getAngleRad());

    mSprite.move(xDelta, yDelta);
}

double MobileUnit::getAngleRad() const {
    return mMovementAngle * PI / 180.0;
}

int MobileUnit::getAngleDeg() const {
    return mMovementAngle;
}

MobileUnit::MobileUnit() : mMaxSpeed(0), mMovementAngle(0), mCurrentSpeed(0) {
}

MobileUnit::MobileUnit(double speed) : mMaxSpeed(speed), mMovementAngle(0), mCurrentSpeed(0) {
}

bool MobileUnit::movingUp() const {
    return (mMovementAngle % 360 == 90) &&
            (mCurrentSpeed > 0);
}

bool MobileUnit::movingDown() const {
    return (mMovementAngle  % 360 == 270) &&
           (mCurrentSpeed > 0);
}

bool MobileUnit::movingLeft() const {
    return (mMovementAngle  % 360 == 180) &&
           (mCurrentSpeed > 0);
}

bool MobileUnit::movingRight() const {
    return (mMovementAngle  % 360 == 0) &&
           (mCurrentSpeed > 0);
}
