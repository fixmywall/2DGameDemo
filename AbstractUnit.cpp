//
// Created by Oliver Yang on 2/13/18.
//

#include "AbstractUnit.h"

void AbstractUnit::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(mSprite);
}
