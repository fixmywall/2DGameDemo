//
// Created by Oliver Yang on 2/21/18.
//

#ifndef INC_2DGAMEDEMO_CAMERA_H
#define INC_2DGAMEDEMO_CAMERA_H

#include <SFML/Graphics.hpp>
#include <memory>

class Camera {
private:
    sf::Vector2f mCenter;     // center position [pixels] relative to map

public:
    typedef std::shared_ptr<Camera> SPtr;

    void move(double x, double y);
    void move(sf::Vector2f);
    void setCenter(double x, double y);
    void setCenter(sf::Vector2f);
    const sf::Vector2f& center() const;
};


#endif //INC_2DGAMEDEMO_CAMERA_H
