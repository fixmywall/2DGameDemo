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
    double mCurrentSpeed;       // current speed (pixels/sec)
    int mMovementAngle;         // degrees

public:
    MobileUnit();
    MobileUnit(double maxSpeed);
    double getSpeed() const;
    double getAngleRad() const;
    int getAngleDeg() const;
    virtual void updateState(const sf::Time& delta);
    bool movingUp() const;
    bool movingDown() const;
    bool movingLeft() const;
    bool movingRight() const;

};


#endif //INC_2DGAMEDEMO_MOBILEUNIT_H
