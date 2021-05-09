//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_MOUSELISTENER_H
#define PKU_GAME_CORE_MOUSELISTENER_H


class MainApplication;
class MouseListener
{
private:
    MainApplication* app;
    int x, y;
public:
    explicit MouseListener(MainApplication&);
    ~MouseListener();

    int getMouseX();
    int getMouseY();
    int getMouseOffsetX();
    int getMouseOffsetY();
    void showCursor();
    void hideCursor();
    void enableCursor();
    void disableCursor();

    bool isCursorHidden() const;
    bool isMouseLeftPressed() const;
    bool isMouseRightPressed() const;
    bool isMouseMiddlePressed() const;
};


#endif //PKU_GAME_CORE_MOUSELISTENER_H
