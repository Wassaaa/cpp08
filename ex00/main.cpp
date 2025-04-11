#include "easyfind.hpp"
#include "runtest.hpp"
#include <vector>
#include <list>
#include <set>
#include <deque>

int main()
{
    // runTest will always look for value 42 and 999, expecting to find 42 and not find 999
    // Test with vector
    std::vector<int> vec = {10, 20, 30, 44, 50, 321};
    runTest(vec, "std::vector");

    // Test with list
    std::list<int> lst = {10, 20, 30, 42, 50};
    runTest(lst, "std::list");

    // Test with set
    std::set<int> s = {10, 20, 30, 42, 50};
    runTest(s, "std::set");

    // Test with deque
    std::deque<int> deq = {10, 20, 30, 42, 50};
    runTest(deq, "std::deque");

    return 0;
}
