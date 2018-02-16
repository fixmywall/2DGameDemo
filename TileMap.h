//
// Created by Oliver Yang on 2/13/18.
//

#ifndef INC_2DGAMEDEMO_TILEMAP_H
#define INC_2DGAMEDEMO_TILEMAP_H
#include <SFML/Graphics.hpp>

class TileMap : public sf::Drawable, public sf::Transformable {
public:
    bool load(const std::string& tsPath);

protected:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    sf::VertexArray mVertices;  // vertex array representing the map
    sf::Texture mTileset;       // tileset texture

};


#endif //INC_2DGAMEDEMO_TILEMAP_H
