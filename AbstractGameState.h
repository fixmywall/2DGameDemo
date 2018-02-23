//
// Created by Oliver Yang on 2/14/18.
//

#ifndef INC_2DGAMEDEMO_ABSTRACTGAMESTATE_H
#define INC_2DGAMEDEMO_ABSTRACTGAMESTATE_H
#include <SFML/Graphics.hpp>
#include <memory>

class AbstractGameState  {
public:
    typedef std::shared_ptr<AbstractGameState> UPtr;

    virtual void handleEvent(const sf::Event &event) = 0;
    virtual void updateState(const sf::Time& delta) = 0;
    virtual void draw(sf::RenderTarget& target, float interp = 0) = 0;
};


#endif //INC_2DGAMEDEMO_ABSTRACTGAMESTATE_H
