cmake_minimum_required(VERSION 3.9)
project(2DGameDemo)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_CXX_FLAGS "-O3")

aux_source_directory(tmxlite/src TMX_SRC_LIST)
aux_source_directory(tmxlite/src/detail XML_SRC_LIST)

set(SOURCE_FILES main.cpp TileMap.cpp TileMap.h Player.cpp Player.h AbstractUnit.cpp AbstractUnit.h AbstractGameState.cpp AbstractGameState.h MobileUnit.cpp MobileUnit.h PlayableGameState.cpp PlayableGameState.h GameEngine.cpp GameEngine.h Camera.cpp Camera.h)

add_executable(2DGameDemo ${SOURCE_FILES} ${TMX_SRC_LIST} ${XML_SRC_LIST})

# resource files
configure_file(arial.ttf arial.ttf COPYONLY)
configure_file(map/desert.tsx map/desert.tsx COPYONLY)
configure_file(map/desert.tmx map/desert.tmx COPYONLY)
configure_file(map/tmw_desert_spacing.png map/tmw_desert_spacing.png COPYONLY)
configure_file(sprites/player.png sprites/player.png COPYONLY)


# sfml library
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/SFML/cmake/Modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(2DGameDemo ${SFML_LIBRARIES})
endif()

# tmxlite
include_directories(tmxlite/include)
include_directories(tmxlite/src/detail)     # pugiXML

