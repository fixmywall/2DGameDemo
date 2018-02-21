//
// Created by Oliver Yang on 2/13/18.
//

#ifndef INC_2DGAMEDEMO_PLAYER_H
#define INC_2DGAMEDEMO_PLAYER_H
#include "MobileUnit.h"

class Player : public MobileUnit {
private:

public:
    Player();
    virtual void handleEvent(const sf::Event& event);
    virtual void updateState(const sf::Time& delta);

};


#endif //INC_2DGAMEDEMO_PLAYER_H
