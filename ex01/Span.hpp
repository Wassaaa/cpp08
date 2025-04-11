#pragma once

#include <vector>
#include <iterator>

class Span
{
public:
    Span();
    Span(unsigned int N);

    void addNumber(int n);
    unsigned int shortestSpan();
    unsigned int longestSpan();

    template <typename it>
    void addRange(it begin, it end)
    {
        unsigned int distance = std::distance(begin, end);
        if (_numbers.size() + distance > _numbers.capacity()) {
            throw std::runtime_error("Not enough capacity for this range");
        }
        _numbers.insert(_numbers.end(), begin, end);
    }

private:
    std::vector<int> _numbers;
};
