#include "Span.hpp"
#include <stdexcept>
#include <limits>
#include <algorithm>

Span::Span()
{}

Span::Span(unsigned int N)
{
    _numbers.reserve(N);
}

void Span::addNumber(int n)
{
    if (_numbers.size() == _numbers.capacity())
        throw std::runtime_error("Maximum span capacity reached");
    _numbers.push_back(n);
}

unsigned int Span::shortestSpan()
{
    if (_numbers.size() < 2) {
        throw std::runtime_error("Need more than 2 numbers to find span");
    }

    // make a sorted copy of _numbers
    std::vector<int> sorted = _numbers;
    std::sort(sorted.begin(), sorted.end());

    unsigned int shortest = std::numeric_limits<unsigned int>::max();
    for (unsigned int i = 1; i < sorted.size(); i++) {
        unsigned int current = static_cast<unsigned int>(sorted[i] - sorted[i - 1]);
        shortest = std::min(shortest, current);
        if (shortest == 0)
            break;
    }
    return shortest;
}

unsigned int Span::longestSpan()
{
    if (_numbers.size() < 2) {
        throw std::runtime_error("Need more than 2 numbers to find span");
    }
    auto [min_it, max_it] = std::minmax_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(*max_it - *min_it);
}
