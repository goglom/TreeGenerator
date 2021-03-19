#include "keyboard.hpp"


bool Keyboard::getKeyState(Qt::Key key)
{
    if (key >= maxKey)
        return false;

    return keysState[key];
}

void Keyboard::setKeyState(Qt::Key key, bool state)
{
    if (key >= maxKey)
        return;

    keysState[key] = state;
}
