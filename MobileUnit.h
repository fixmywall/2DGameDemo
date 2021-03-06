//
// Created by Oliver Yang on 2/14/18.
//

#ifndef INC_2DGAMEDEMO_MOBILEUNIT_H
#define INC_2DGAMEDEMO_MOBILEUNIT_H
#include "AbstractUnit.h"

class MobileUnit : public AbstractUnit {
protected:
    const double PI = 3.141592653589;
    double mMaxSpeed;           // max speed (pixels/sec)
    sf::Vector2i mDirection;     // velocity unit vector
    double mCurrentSpeed;         // 0 east, 90 north, etc. [deg]
    bool mMoving;
    sf::Vector2f mLastDrawPosition;

public:
    MobileUnit();
    MobileUnit(double maxSpeed);
    double getSpeed() const;
    double getAngleRad() const;
    int getAngleDeg() const;
    virtual void updateState(const sf::Time& delta);
    virtual const sf::Vector2f& getPosition() const;
    virtual void move(double x, double y);
    bool moving() const;
    virtual void draw(sf::RenderTarget& target, float interp = 0);

};


#endif //INC_2DGAMEDEMO_MOBILEUNIT_H
