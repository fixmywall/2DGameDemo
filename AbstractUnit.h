//
// Created by Oliver Yang on 2/13/18.
//

#ifndef INC_2DGAMEDEMO_ABSTRACTUNIT_H
#define INC_2DGAMEDEMO_ABSTRACTUNIT_H

#include <SFML/Graphics.hpp>
#include <memory>

class AbstractUnit {
public:
    typedef std::unique_ptr<AbstractUnit> UPtr;

    virtual void updateState(const sf::Time& delta) = 0;
    virtual void handleEvent(const sf::Event& event) = 0;
    virtual void draw(sf::RenderTarget& target, float interp = 0) = 0;
    void setPosition(double x, double y);
    void setPosition(const sf::Vector2f& pos);
    virtual const sf::Vector2f& getPosition() const = 0;
    virtual void move(double x, double y) = 0;

protected:
    sf::Sprite mSprite;
    sf::Vector2f mPos;
};


#endif //INC_2DGAMEDEMO_ABSTRACTUNIT_H
