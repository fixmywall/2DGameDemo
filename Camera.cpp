//
// Created by Oliver Yang on 2/21/18.
//

#include "Camera.h"

void Camera::move(double x, double y) {
    mCenter.x += x;
    mCenter.y += y;
}

void Camera::move(sf::Vector2f pix) {
    mCenter += pix;
}

void Camera::setCenter(double x, double y) {
    mCenter.x = x;
    mCenter.y = y;
}

void Camera::setCenter(sf::Vector2f pos) {
    mCenter = pos;
}

const sf::Vector2f &Camera::center() const {
    return mCenter;
}
