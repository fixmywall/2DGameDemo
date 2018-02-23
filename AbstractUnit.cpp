//
// Created by Oliver Yang on 2/13/18.
//

#include "AbstractUnit.h"


void AbstractUnit::setPosition(double x, double y) {
    mPos.x = x;
    mPos.y = y;
}

void AbstractUnit::setPosition(const sf::Vector2f &pos) {
    mPos = pos;
}
