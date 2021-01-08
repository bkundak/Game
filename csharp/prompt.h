#pragma once

#include <iostream>
#include <string>
#include <string_view>

namespace blur
{

    template <typename... Args>
    void Printf(const char *format, Args &&... args)
    {
        printf(format, std::forward<Args>(args)...);
    }

    std::string InputString(std::string_view prompt)
    {
        Printf(prompt.data());

        std::string str;
        std::cin >> str;
        return str;
    }

    int InputInt(std::string_view prompt, int max)
    {
        Printf(prompt.data());

        int index = 0;
        while (index < 1 || index > max)
        {
            std::cin >> index;
        };
        return index;
    }
} // namespace blur