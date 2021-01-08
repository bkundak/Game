#pragma once

#include <array>
#include <functional>

#include "prompt.h"

namespace blur
{
    enum class State : uint32_t
    {
        main = 0,
        forrest = 1,
        attacking = 2,
        shop = 3,
        exit = 4
    };

    // Template action return type
    struct Option
    {
        const char *text;
        std::function<State()> action;
    };

    // Template option type
    template <size_t N>
    struct Menu
    {
        std::array<Option, N> options;

        void print()
        {
            for (size_t i = 0; i < options.size(); i++)
            {
                blur::Printf("[%d] %s\n", i + 1, options[i].text);
            }
        }

        State prompt(std::string text)
        {
            print();
            auto option = InputInt(text, options.size());
            return activate(option - 1);
        }

        State activate(size_t index)
        {
            return options[index].action();
        }

        size_t size() const
        {
            return options.size();
        }
    };

    template <typename... options>
    constexpr auto make_menu(options... o) -> Menu<sizeof...(options)>
    {
        return Menu<sizeof...(options)>({o...});
    };

} // namespace blur