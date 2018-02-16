//
// Created by Oliver Yang on 2/15/18.
//

#ifndef INC_2DGAMEDEMO_GAMEENGINE_H
#define INC_2DGAMEDEMO_GAMEENGINE_H
#include <vector>
#include "AbstractGameState.h"

class GameEngine {
public:
    GameEngine();
    void run(sf::RenderWindow& window);
    void setCurrentState(AbstractGameState::UPtr state);

private:
    AbstractGameState::UPtr mCurrentState;
};


#endif //INC_2DGAMEDEMO_GAMEENGINE_H
