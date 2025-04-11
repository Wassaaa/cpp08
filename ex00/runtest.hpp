#pragma once

#include <iostream>

template <typename T>
void runTest(T &container, const std::string &containerName)
{
    std::cout << "Testing with " << containerName << ":\n";

    try {
        auto it = easyfind(container, 42);
        std::cout << "✅ Found value 42 at position: " << std::distance(container.begin(), it)
                  << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "❌ Error: " << e.what() << std::endl;
    }

    try {
        auto it = easyfind(container, 999);
        std::cout << "Found value 999 at position: " << std::distance(container.begin(), it)
                  << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "✅ Expected error: " << e.what() << std::endl;
    }

    std::cout << "----------------------------\n";
}
