//
// Created by Oliver Yang on 2/13/18.
//

#ifndef INC_2DGAMEDEMO_PLAYER_H
#define INC_2DGAMEDEMO_PLAYER_H
#include "MobileUnit.h"
#include "Camera.h"

class Player : public MobileUnit {
private:
    Camera::SPtr mCamera;   // camera centered around player
public:
    Player();
    virtual void handleEvent(const sf::Event& event);
    virtual void updateState(const sf::Time& delta);
    void attachCamera(Camera::SPtr camera);
    virtual void setPosition(double x, double y);
    virtual void move(double x, double y);

};


#endif //INC_2DGAMEDEMO_PLAYER_H
