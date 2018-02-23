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
    virtual void draw(sf::RenderTarget& target, float interp = 0);

};


#endif //INC_2DGAMEDEMO_PLAYER_H
