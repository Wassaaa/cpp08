#include "MutantStack.hpp"
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>

void testBasicOperations()
{
    std::cout << "\n=== Testing Basic Operations ===\n";

    MutantStack<int> mstack;
    // Test push and top
    mstack.push(42);
    std::cout << "Top after push |42|: " << mstack.top() << std::endl;

    // Test pop
    mstack.push(17);
    std::cout << "Top before pop |17|: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Top after pop |42|: " << mstack.top() << std::endl;

    // Test size
    mstack.push(5);
    mstack.push(10);
    std::cout << "Size |3|: " << mstack.size() << std::endl;

    // Test empty
    std::cout << "Is empty |no|: " << (mstack.empty() ? "yes" : "no") << std::endl;
    while (!mstack.empty()) mstack.pop();
    std::cout << "Is empty after pops |yes|: " << (mstack.empty() ? "yes" : "no") << std::endl;
}

void testIterators()
{
    std::cout << "\n=== Testing Iterators ===\n";

    MutantStack<std::string> sstack;
    sstack.push("Hello");
    sstack.push("World");
    sstack.push("C++");
    sstack.push("Iterators");

    std::cout << "Forward iteration: ";
    for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "Modifying through iterator..." << std::endl;
    for (auto &s : sstack) {
        s = "Modified " + s;
    }

    std::cout << "After modification: ";
    for (const auto &s : sstack) {
        std::cout << s << " ";
    }
    std::cout << std::endl;
}

void compareWithList()
{
    std::cout << "\n=== Comparing with std::list ===\n";

    MutantStack<int> mstack;
    std::list<int> mlist;

    // Add same elements to both containers
    for (int i = 0; i < 5; i++) {
        int val = i * 10;
        mstack.push(val);
        mlist.push_back(val);
    }

    std::cout << "MutantStack contents: ";
    for (auto i : mstack) std::cout << i << " ";
    std::cout << std::endl;

    std::cout << "List contents: ";
    for (auto i : mlist) std::cout << i << " ";
    std::cout << std::endl;

    // Test reverse iteration with iterators
    std::cout << "MutantStack reverse: ";
    for (auto it = mstack.end(); it != mstack.begin();) {
        --it;
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    std::cout << "List reverse: ";
    for (auto it = mlist.end(); it != mlist.begin();) {
        --it;
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

// Test with STL algorithms
void testWithAlgorithms()
{
    std::cout << "\n=== Testing with STL Algorithms ===\n";

    MutantStack<int> mstack;
    for (int i = 1; i <= 10; i++) {
        mstack.push(i);
    }

    // Find an element
    auto it = std::find(mstack.begin(), mstack.end(), 5);
    std::cout << "Found element 5: " << (*it == 5 ? "yes" : "no") << std::endl;

    // Count elements
    int evens = std::count_if(mstack.begin(), mstack.end(), [](int n) { return n % 2 == 0; });
    std::cout << "Number of even elements: " << evens << std::endl;
}

void originalTest()
{
    std::cout << "\n=== Original Test ===\n";
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}

// Run all tests
int main()
{
    testBasicOperations();
    testIterators();
    compareWithList();
    testWithAlgorithms();
    originalTest();

    return 0;
}
