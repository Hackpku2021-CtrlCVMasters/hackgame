cmake_minimum_required(VERSION 3.0)
project(pku_game_core)

set(CMAKE_CXX_STANDARD 20)

find_package(Boost)

add_executable(pku_game_core src/game.h src/init.cc src/render.cc src/update.cc src/game.cc)

if(Boost_FOUND)
    target_include_directories(pku_game_core PRIVATE
            ${Boost_INCLUDE_DIR})
    target_link_libraries(pku_game_core PRIVATE
            ${Boost_LIBRARIES})
else()
    message(FATAL_ERROR 'Boost not found.')
endif()

target_include_directories(pku_game_core
        PRIVATE
        ${CMAKE_SYSTEM_INCLUDE_PATH}
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/src)

if(CMAKE_SYSTEM_NAME MATCHES "Windows")
    target_link_directories(
            pku_game_core
            PRIVATE
            ${CMAKE_SYSTEM_LIBRARY_PATH}
            ${PROJECT_SOURCE_DIR}/lib
    )

    target_link_libraries(
            pku_game_core
            PRIVATE
            pthread
            raylib
            curl
            winmm
    )
else()
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
            curl
            raylib
    )
endif()


