cmake_minimum_required(VERSION 3.0)
project(pku_game_core)

set(CMAKE_CXX_STANDARD 14)

add_executable(pku_game_core src/game.h src/init.cc src/render.cc src/update.cc src/game.cc)

target_include_directories(pku_game_core
        PRIVATE
        ${CMAKE_SYSTEM_INCLUDE_PATH}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src)

target_link_directories(
        pku_game_core
        PRIVATE
        ${CMAKE_SYSTEM_LIBRARY_PATH}
)

target_link_libraries(
        pku_game_core
        PRIVATE
        GL
        pthread
        raylib
)
