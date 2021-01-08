#pragma once

#include <string>
#include <cstdint>

namespace blur
{

    enum class Role : uint32_t
    {
        hero,
        monster
    };

    // save to file
    struct Character
    {
        std::string name;
        Role role;

        int health{100};
        int armor{1};
        int attack{1};
    };

    struct GameState
    {
        Character player;
        std::vector<Character> monsters{};

        State state;
    };

} // namespace blur