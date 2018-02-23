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

public:
    MobileUnit();
    MobileUnit(double maxSpeed);
    double getSpeed() const;
    double getAngleRad() const;
    int getAngleDeg() const;
    virtual void updateState(const sf::Time& delta);
    virtual void setPosition(double x, double y);
    virtual const sf::Vector2f& getPosition() const;
    virtual void move(double x, double y);

    bool moving() const;
    bool movingUp() const;
    bool movingDown() const;
    bool movingLeft() const;
    bool movingRight() const;

};


#endif //INC_2DGAMEDEMO_MOBILEUNIT_H
