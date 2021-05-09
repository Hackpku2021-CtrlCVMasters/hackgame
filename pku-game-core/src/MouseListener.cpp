//
// Created by listerily on 5/8/21.
//

#include "MouseListener.h"
#include "../include/raylib.h"

MouseListener::MouseListener(MainApplication & __app) {
    app = &__app;
    x = ::GetMouseX();
    y = ::GetMouseY();
}

MouseListener::~MouseListener() {
}

int MouseListener::getMouseX() {
    return x = ::GetMouseX();
}

int MouseListener::getMouseY() {
    return y = ::GetMouseY();
}

int MouseListener::getMouseOffsetX() {
    int t = x;
    
    x = ::GetMouseX();
    return x - t;
}

int MouseListener::getMouseOffsetY() {
    int t = y;

    y = ::GetMouseY();
    return y - t;
}

void MouseListener::showCursor() {
    ::ShowCursor();
}

void MouseListener::hideCursor() {
    ::HideCursor();
}

void MouseListener::enableCursor() {
    ::EnableCursor();
}

void MouseListener::disableCursor() {
    ::DisableCursor();
}

bool MouseListener::isCursorHidden() const {
    return ::IsCursorHidden();
}

bool MouseListener::isMouseLeftPressed() const {
    return ::IsMouseButtonPressed(MOUSE_LEFT_BUTTON);
}

bool MouseListener::isMouseRightPressed() const {
    return ::IsMouseButtonPressed(MOUSE_RIGHT_BUTTON);
}

bool MouseListener::isMouseMiddlePressed() const {
    return ::IsMouseButtonPressed(MOUSE_MIDDLE_BUTTON);
}

