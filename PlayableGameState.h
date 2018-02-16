//
// Created by Oliver Yang on 2/15/18.
//

#ifndef INC_2DGAMEDEMO_PLAYABLEGAMESTATE_H
#define INC_2DGAMEDEMO_PLAYABLEGAMESTATE_H

#include "AbstractGameState.h"
#include "AbstractUnit.h"
#include "TileMap.h"
#include <vector>
#include <memory>

class PlayableGameState : public AbstractGameState {
public:
    PlayableGameState();
    virtual void handleEvent(const sf::Event& event);
    virtual void updateState(const sf::Time& delta);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    void insertUnit(AbstractUnit::UPtr u);

private:
    std::vector<AbstractUnit::UPtr> mUnits;
    TileMap mMap;

};


#endif //INC_2DGAMEDEMO_PLAYABLEGAMESTATE_H
