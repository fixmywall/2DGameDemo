//
// Created by Oliver Yang on 2/15/18.
//

#ifndef INC_2DGAMEDEMO_PLAYABLEGAMESTATE_H
#define INC_2DGAMEDEMO_PLAYABLEGAMESTATE_H

#include "AbstractGameState.h"
#include "AbstractUnit.h"
#include "TileMap.h"
#include "Camera.h"
#include <vector>
#include <memory>

class PlayableGameState : public AbstractGameState {
public:
    PlayableGameState();
    virtual void handleEvent(const sf::Event& event);
    virtual void updateState(const sf::Time& delta);
    virtual void draw(sf::RenderTarget& target, float interp = 0);
    void insertUnit(AbstractUnit::UPtr u);
    void setMap(const TileMap& map);
    void setCamera(Camera::SPtr camera);

private:
    std::vector<AbstractUnit::UPtr> mUnits;
    TileMap mMap;
    Camera::SPtr mCamera;
};


#endif //INC_2DGAMEDEMO_PLAYABLEGAMESTATE_H
