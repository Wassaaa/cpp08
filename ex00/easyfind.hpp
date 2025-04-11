#pragma once

#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int val)
{
    typename T::iterator it;
    it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw std::runtime_error("value not found");
    return it;
}
