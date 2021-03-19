#pragma once
#include <array>
#include <Qt>

class keyboardState
{   
public:
    inline static constexpr std::size_t maxKey = 0xff;
    bool getKeyState(Qt::Key key);
    void setKeyState(Qt::Key key, bool state);

private:
    std::array<bool, maxKey> keysState{false};
};

