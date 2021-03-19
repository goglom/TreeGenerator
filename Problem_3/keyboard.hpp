#pragma once
#include <array>
#include <Qt>

class Keyboard
{   
public:
    inline static constexpr int maxKey = 0xff;
    bool getKeyState(Qt::Key key);
    void setKeyState(Qt::Key key, bool state);


private:
    std::array<bool, maxKey> keysState{false};
};

