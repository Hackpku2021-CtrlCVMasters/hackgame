//
// Created by listerily on 5/8/21.
//

#ifndef PKU_GAME_CORE_KEYEVENTLISTENER_H
#define PKU_GAME_CORE_KEYEVENTLISTENER_H


class MainApplication;
class KeyEventListener
{
private:
    MainApplication* app;
public:
    explicit KeyEventListener(MainApplication&);
    ~KeyEventListener();

    bool isKeyPressed(int) const;
    bool isKeyDown(int) const;
    bool isKeyReleased(int) const;
    bool isKeyUp(int) const;
};


#endif //PKU_GAME_CORE_KEYEVENTLISTENER_H
