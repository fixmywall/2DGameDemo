//
// Created by Oliver Yang on 2/13/18.
//

#include "TileMap.h"
#include <tmxlite/Map.hpp>
#include <tmxlite/TileLayer.hpp>

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    states.transform *= getTransform();
    states.texture = &mTileset;
    target.draw(mVertices, states);
}

bool TileMap::load(const std::string &tsPath) {
    tmx::Map map;
    if (!map.load(tsPath)) {
        return false;
    }

    sf::Vector2f tileSize(map.getTileSize().x, map.getTileSize().y);
    sf::Vector2f tileCount(map.getTileCount().x, map.getTileCount().y);

    const auto& layers = map.getLayers();
    tmx::TileLayer* mainLayer = dynamic_cast<tmx::TileLayer*>(layers[0].get());
    auto& tileset = map.getTilesets().at(0);

    // load tileset image into sfml texture
    if (!mTileset.loadFromFile(tileset.getImagePath())) {
        return false;
    }

    //preallocate vertex array
    int spacing = tileset.getSpacing();                 // spacing between tiles in tileset
    int margins = tileset.getMargin();                  // margins around tiles in tileset
    mVertices.setPrimitiveType(sf::Quads);
    mVertices.resize(4 * tileCount.x * tileCount.y);
    auto& tiles = mainLayer->getTiles();
    for (int y = 0; y < tileCount.y; y++) {
        for (int x = 0; x < tileCount.x; x++) {
            int tileIndex = x + y * tileCount.x;
            int tileGid = tiles[tileIndex].ID;

            int gidOffset = tileGid - tileset.getFirstGID();

            // find position within tileset texture
            int tx = gidOffset % tileset.getColumnCount();
            int ty = gidOffset / tileset.getColumnCount();

            // four vertices
            sf::Vertex* quad = &mVertices[tileIndex * 4];

            // define vertices' corners relative to window
            quad[0].position = sf::Vector2f(x * tileSize.x, y * tileSize.y);        // topleft
            quad[1].position = sf::Vector2f((x+1) * tileSize.x, y * tileSize.y);    // topright
            quad[2].position = sf::Vector2f((x+1) * tileSize.x, (y+1) * tileSize.y);// botright
            quad[3].position = sf::Vector2f(x * tileSize.x, (y+1) * tileSize.y);    // botleft


            // define vertices' positions relative to texture
            int upperLeftX = tx * (tileSize.x + spacing) + margins;
            int upperLeftY = ty * (tileSize.y + spacing) + margins;
            int upperRightX = upperLeftX + tileSize.x - 1;
            int upperRightY = upperLeftY;
            int lowerRightX = upperRightX;
            int lowerRightY = upperRightY + tileSize.y - 1;
            int lowerLeftX = upperLeftX;
            int lowerLeftY = lowerRightY;

            quad[0].texCoords = sf::Vector2f(upperLeftX, upperLeftY);
            quad[1].texCoords = sf::Vector2f(upperRightX, upperRightY);
            quad[2].texCoords = sf::Vector2f(lowerRightX, lowerRightY);
            quad[3].texCoords = sf::Vector2f(lowerLeftX, lowerLeftY);
        }
    }


    return true;
}
