//
// Created by listerily on 5/8/21.
//

#include "KeyEventListener.h"
#include "../include/raylib.h"


bool KeyEventListener::isKeyPressed(int key) const {
    return ::IsKeyPressed(key);
}

bool KeyEventListener::isKeyDown(int key) const {
    return ::IsKeyDown(key);
}

bool KeyEventListener::isKeyReleased(int key) const {
    return ::IsKeyReleased(key);
}

bool KeyEventListener::isKeyUp(int key) const {
    return ::IsKeyUp(key);
}

KeyEventListener::KeyEventListener(MainApplication & __app) {
    app = &__app;
}

KeyEventListener::~KeyEventListener() {
}