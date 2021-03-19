#include "keyboardstate.hpp"


bool keyboardState::getKeyState(Qt::Key key)
{
    return keysState[key];
}

void keyboardState::setKeyState(Qt::Key key, bool state)
{
    keysState[key] = state;
}
