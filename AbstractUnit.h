//
// Created by Oliver Yang on 2/13/18.
//

#ifndef INC_2DGAMEDEMO_ABSTRACTUNIT_H
#define INC_2DGAMEDEMO_ABSTRACTUNIT_H

#include <SFML/Graphics.hpp>
#include <memory>

class AbstractUnit : public sf::Drawable {
public:
    typedef std::unique_ptr<AbstractUnit> UPtr;

    virtual void updateState(const sf::Time& delta) = 0;
    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    sf::Vector2f mMapPosition;  // position within map
    sf::Sprite mSprite;
};


#endif //INC_2DGAMEDEMO_ABSTRACTUNIT_H
